#include "../ast/AST_node.h"
llvm::Type* getLLVMtype(MyType* typenode,genContext &context);
/*---------------------------Expr-------------------------*/
llvm::Value* BinExpr::CodeGen(genContext &context){
    cout<<"Generating BinExpr..."<<endl;
    llvm::Value *L = lhs->CodeGen(context);
    llvm::Value *R = rhs->CodeGen(context);
    if(L==NULL) throw std::runtime_error("Left Expr Generate Error!");
    if(R==NULL) throw std::runtime_error("Right Expr Generate Error!");
    if(L->getType()->isDoubleTy() || R->getType()->isDoubleTy()){
        if(!L->getType()->isDoubleTy()){
            L = context.builder.CreateSIToFP(L,context.builder.getDoubleTy());
        }
        if(!R->getType()->isDoubleTy()){
            R = context.builder.CreateSIToFP(R,context.builder.getDoubleTy());
        }
        if(op == "PLUS")     return context.builder.CreateFAdd(L,R,"add");
        else if(op=="MINUS") return context.builder.CreateFSub(L,R,"sub");
        else if(op=="MUL")   return context.builder.CreateFMul(L,R,"mul");
        else if(op=="DIV")   return context.builder.CreateFDiv(L,R,"div");
        else if(op=="MOD")   return context.builder.CreateFRem(L,R,"mod");
        else if(op=="LT")    return context.builder.CreateFCmpULT(L,R,"lt");
        else if(op=="GT")    return context.builder.CreateFCmpUGT(L,R,"gt");
        else if(op=="LE")    return context.builder.CreateFCmpULE(L,R,"le");
        else if(op=="GE")    return context.builder.CreateFCmpUGE(L,R,"ge");
        else if(op=="EQUAL") return context.builder.CreateFCmpUEQ(L,R,"eq");
        else if(op=="NE")    return context.builder.CreateFCmpUNE(L,R,"ne");
        else throw std::runtime_error("Unknown Float operation: "+op);
    }
    else{
        if(op == "PLUS")     return context.builder.CreateAdd(L,R,"add");
        else if(op=="MINUS") return context.builder.CreateSub(L,R,"sub");
        else if(op=="MUL")   return context.builder.CreateMul(L,R,"mul");
        else if(op=="DIV")   return context.builder.CreateSDiv(L,R,"div");
        else if(op=="MOD")   return context.builder.CreateSRem(L,R,"mod");
        else if(op=="LT")    return context.builder.CreateICmpSLT(L,R,"lt");
        else if(op=="GT")    return context.builder.CreateICmpSGT(L,R,"gt");
        else if(op=="LE")    return context.builder.CreateICmpSLE(L,R,"le");
        else if(op=="GE")    return context.builder.CreateICmpSGE(L,R,"ge");
        else if(op=="EQUAL") return context.builder.CreateICmpEQ(L,R,"eq");
        else if(op=="NE")    return context.builder.CreateICmpNE(L,R,"ne");
        else if(op=="AND")   return context.builder.CreateAnd(L,R,"and");
        else if(op=="OR")    return context.builder.CreateOr(L,R,"or");
        else if(op=="XOR")   return context.builder.CreateXor(L,R,"xor");
        else throw std::runtime_error("Unknown I operation: "+op);
    }
    return NULL;
}

llvm::Value* UnaryExpr::CodeGen(genContext &context){
    cout<<"Generating Unary"<<endl;
    if(op == "NOT")
        return context.builder.CreateNot(this->getExprNode()->CodeGen(context));
    else if(op == "SUB")
        return context.builder.CreateNeg(this->getExprNode()->CodeGen(context));
    else throw std::runtime_error("Unknown Unary operation: "+ op);
    return NULL;
}

llvm::Value* FunCallExpr::CodeGen(genContext &context){
    cout<<"CodeGen FuncallExpression..."<<endl;
    auto callee = context.getFunction(this->getFuncName());
    if(callee==NULL){
        throw std::runtime_error("No Function called: "+this->getFuncName());
    }
    vector<llvm::Value*> args;
    for(auto it : this->getExprListNode()->getExprList()){
        args.push_back(it->CodeGen(context));
    }
    return context.builder.CreateCall(callee,args);
}

llvm::Value* ArrayExpr::CodeGen(genContext &context){
    // get index
    bool ptr = context.genpointer;
    context.genpointer=false;
    auto index = this->getIndexExprNode()->CodeGen(context);
    context.genpointer=ptr;

    // get record
    auto arrptr = context.getValue(this->getArrayName());
    string funcname = context.curfunction->getName();
    string arrayname  = this->getArrayName();
    int start = context.getArrayRecord(arrayname).first;

    // get true index 
    auto sr = context.builder.getInt32(start);
    auto trueindex=context.builder.CreateSub(index,sr,"sub");
    auto zero = llvm::ConstantInt::get(context.builder.getInt32Ty(),0);

    //return 
    if(context.genpointer)
        return context.builder.CreateInBoundsGEP(arrptr,{zero,trueindex});
    else 
        return context.builder.CreateLoad(context.builder.CreateInBoundsGEP(arrptr,{zero,trueindex}));
}

llvm::Value* IDExpr::CodeGen(genContext &context){
    if(type=="Imm"){
        if(this->immtype=="bool"){
            return llvm::ConstantInt::get(context.builder.getInt1Ty(),this->getBooleanValue(),true);
        }
        else if(this->immtype=="integer"){
            return llvm::ConstantInt::get(context.builder.getInt32Ty(),this->getIntValue(),true);
        }
        else if(this->immtype=="longint"){
            return llvm::ConstantInt::get(context.builder.getInt64Ty(),this->getLongIntValue(),true);
        }
        else if(this->immtype=="char"){
            return llvm::ConstantInt::get(context.builder.getInt8Ty(),this->getCharValue(),true);
        }
        else if(this->immtype=="real"){
            return llvm::ConstantFP::get(context.builder.getDoubleTy(), (this->getDoubleValue()));
        }
        else if(this->immtype=="string"){
            auto temstr = llvm::ConstantDataArray::getString(context.builder.getContext(),this->str);
            auto tempglobal = new llvm::GlobalVariable(*context.module,
                llvm::ArrayType::get(context.builder.getInt8Ty(),this->str.size()+1),
                false,llvm::GlobalValue::ExternalLinkage,temstr,".tempstr"
            );
            auto gp = context.module->getGlobalVariable((string)tempglobal->getName());
            llvm::Value *zero = llvm::ConstantInt::get(context.builder.getInt32Ty(),0);
            return context.builder.CreateInBoundsGEP(gp, {zero, zero});
        }
        else throw std::runtime_error("Unknown constant type: "+this->getType());
    }
    else if(type=="var"){
        if(context.genpointer==false) return context.builder.CreateLoad(context.getValue(this->getVarName()));
        else return context.getValue(this->getVarName());
    }
    else throw runtime_error("Unknown type for IDEXPR: "+type);
}


llvm::Value* DeclPart::CodeGen(genContext &context){
    this->getVarListNode()->CodeGen(context);
    cout<<"enter funcList"<<endl;
    this->getFuncPartNode()->CodeGen(context);
    return NULL;
}

/*-----------------------------Function Declare------------------------*/
llvm::Value* FuncDeclList::CodeGen(genContext &context){
    auto list=this->getFuncList();
    for(auto iter=list.begin(); iter!=list.end(); iter++){
        (*iter)->CodeGen(context);
    }
    return NULL;
}

llvm::Value* OneFuncDecl::CodeGen(genContext &context){
    //check
    if(context.module->getFunction(this->getFuncDeclNode()->getFuncName())){
        throw std::runtime_error("ReDefination of function: "+this->getFuncDeclNode()->getFuncName());
    }
    
    //create function
    cout<<"Generating OneFuncDecl "+ this->getFuncDeclNode()->getFuncName()<<endl;
    vector<llvm::Type *> para_types;
    auto list = this->getFuncDeclNode()->getParaList()->getParaList();
    for(auto it:list){
        VarDecl *onedecl = it;
        vector<string> ids = onedecl->getIDListNode()->getList();
        MyType* type = onedecl->getTypeNode();
        if(type->getClass()=="arraytype")
            throw runtime_error("Unspport array type parameters.");
        llvm::Type *llvmty = getLLVMtype(type,context);
        for(uint32_t i=0;i<ids.size();i++){
            para_types.push_back(llvmty);
        }
    }
    llvm::Type *rettype = getLLVMtype(this->getFuncDeclNode()->getRetType(),context);
    llvm::FunctionType *func_type = llvm::FunctionType::get(rettype,llvm::makeArrayRef(para_types),false);
    llvm::Function *function = llvm::Function::Create(func_type,llvm::Function::ExternalLinkage,
        this->getFuncDeclNode()->getFuncName(),context.module);
    
    //generate
    llvm::BasicBlock* entry = llvm::BasicBlock::Create(context.module->getContext(),"entry",function);
    context.curfunction = function;
    auto  old_block = context.builder.GetInsertBlock();
    context.setfuncrecord(this->getFuncDeclNode()->getFuncName(),function);
    context.FuncStack.push_back(function);
    

    context.pushBlock(entry);
    context.builder.SetInsertPoint(entry);
    
    //initial para
    context.isGlobal=false;
    llvm::Value *para_values;
    auto valueiter = function->arg_begin();
    for(auto decl :this->getFuncDeclNode()->getParaList()->getParaList()){
        decl->CodeGen(context);
        for(auto id: decl->getIDListNode()->getList()){
            para_values = valueiter;
            valueiter++;
            para_values->setName(id);
            context.builder.CreateStore(para_values,context.getValue(id));
        }
    }

    //alloca return value
    auto r = context.builder.CreateAlloca(rettype,0,function->getName());
    if(rettype->isIntegerTy())
        context.builder.CreateStore(context.builder.getInt32(0),r);
    else if(rettype->isDoubleTy())
        context.builder.CreateStore(llvm::ConstantFP::get(rettype,0.0),r);
    context.isGlobal=true;
    //body
    this->getFuncBodyNode()->CodeGen(context);

    //return
    cout<<"Create return"<<endl;
    context.builder.CreateRet(context.builder.CreateLoad(r,false,""));

    //return context
    while(context.BlockStack.back()->block!=old_block)
        context.popBLock();
    context.builder.SetInsertPoint(old_block);
    context.FuncStack.pop_back();
    context.curfunction = context.FuncStack.back();
    return NULL;
}

llvm::Value* FuncBody::CodeGen(genContext &context){
    this->getDeclPartNode()->CodeGen(context);
    this->getExecPartNode()->CodeGen(context);
    cout<<"Body Genend"<<endl;
    return NULL;
}


/* ---------------------------Stmt and Mainpart----------------------------*/
llvm::Value* ExecPart::CodeGen(genContext &context){
    return this->getStmtListNode()->CodeGen(context);
}

llvm::Value* StmtList::CodeGen(genContext &context){
    auto list = this->getStmtList();
    for(auto stmt: list){
        stmt->CodeGen(context);
    }
    return NULL;
}

llvm::Value* AssignStmt::CodeGen(genContext &context){
    cout<<"Generate AssignStmt..."<<endl;

    context.genpointer=true;
    auto lhs = this->getLeftExprNode()->CodeGen(context);
    
    context.genpointer=false;
    auto rhs = this->getRightExprNode()->CodeGen(context);
    
    auto ltype = lhs->getType()->getPointerElementType();
    auto rtype = rhs->getType();
    if(ltype->isDoubleTy()&&rtype->isIntegerTy()){
        rhs = context.builder.CreateSIToFP(rhs,context.builder.getDoubleTy());
    }
    else if(ltype->isIntegerTy(32)&&rtype->isDoubleTy()){
        rhs = context.builder.CreateFPToSI(rhs,context.builder.getInt32Ty());
    }
    context.builder.CreateStore(rhs,lhs);
    return rhs;
}


llvm::Value *SysCall(FuncCallStmt* call,genContext &context){
    if(call->getFuncName()=="write"||call->getFuncName()=="writeln"||call->getFuncName()=="write10d"){
        string format;
        vector<llvm::Value*>  args;
        for(auto arg: call->getParaExprListNode()->getExprList()){
            auto r = arg->CodeGen(context);
            if(r==NULL) return NULL;
            if(r->getType()==context.builder.getInt32Ty()){
                if(call->getFuncName()=="write10d") format += "%10d";
                else format += "%d";
                args.push_back(r);
            }
            else if(r->getType()==context.builder.getInt8Ty()){
                format += "%c";
                args.push_back(r);
            }
            else if(r->getType()->isDoubleTy()){
                format += "%.1lf";
                args.push_back(r);
            }
            else if(r->getType()==context.builder.getInt8PtrTy()){
                format += "%s";
                args.push_back(r);
            }
        }
        if(call->getFuncName()=="writeln") format+="\n";
        auto format_const = llvm::ConstantDataArray::getString(context.builder.getContext(),format);
        auto format_var = new llvm::GlobalVariable(*context.module,
                llvm::ArrayType::get(context.builder.getInt8Ty(),format.size()+1),
                false,llvm::GlobalValue::ExternalLinkage,format_const,"_tempstr"
            );
        auto zero = llvm::ConstantInt::get(context.builder.getInt32Ty(),0);
        vector<llvm::Constant*> indices;
        indices.push_back(zero);
        indices.push_back(zero);

        auto var_ref = llvm::ConstantExpr::getGetElementPtr(format_var->getValueType(), format_var, indices);

        args.insert(args.begin(), var_ref);
        auto call = context.builder.CreateCall(context.printf_func, llvm::makeArrayRef(args), "");
        return call;
    }
    else if(call->getFuncName()=="read" || call->getFuncName()=="readln"){
        cout<<"CallRead"<<endl;
        string format;
        vector<llvm::Value*> args;
        for(auto exp :call->getParaExprListNode()->getExprList()){
            context.genpointer = true;
            auto r = exp->CodeGen(context);
            context.genpointer = false;
            if(r->getType()->getPointerElementType()==context.builder.getInt32Ty()){
                format += "%d";
                args.push_back(r);
            }
            else if(r->getType()->getPointerElementType()==context.builder.getInt8Ty()){
                format += "%c";
                args.push_back(r);
            }
            else if(r->getType()->getPointerElementType()->isDoubleTy()){
                format += "%lf";
                args.push_back(r);
            }
            else throw std::runtime_error("Not Support Other Type");
        }
        auto format_const = llvm::ConstantDataArray::getString(context.builder.getContext(),format);
        auto format_var = new llvm::GlobalVariable(*context.module,
                llvm::ArrayType::get(context.builder.getInt8Ty(),format.size()+1),
                false,llvm::GlobalValue::ExternalLinkage,format_const,"_tempstr"
            );
        auto zero = llvm::ConstantInt::get(context.builder.getInt32Ty(),0);
        vector<llvm::Constant*> indices;
        indices.push_back(zero);
        indices.push_back(zero);

        auto var_ref = llvm::ConstantExpr::getGetElementPtr(format_var->getValueType(), format_var,indices);
        args.insert(args.begin(), var_ref);
        auto call = context.builder.CreateCall(context.scanf_func, llvm::makeArrayRef(args), "");
        return call;
    }
    return NULL;
}


llvm::Value* FuncCallStmt::CodeGen(genContext &context){
    cout<<"Generating FuncCallStmt..."<<endl;
    if(this->getFuncName()=="write"||this->getFuncName()=="writeln"|| this->getFuncName()=="write10d"){
        return SysCall(this,context);
    }
    else if(this->getFuncName()=="read"||this->getFuncName()=="readln"){
        return SysCall(this,context);
    }
    else{
        // user's function
        auto Funcall = new FunCallExpr(this->getFuncName(),this->getParaExprListNode());
        return Funcall->CodeGen(context);
    }
    return NULL;
}
llvm::Value* ForStmt::CodeGen(genContext &context){
    cout<<"Generating ForStmt..."<<endl;
    auto entry = llvm::BasicBlock::Create(context.builder.getContext(),"forentry",context.curfunction);
    auto body = llvm::BasicBlock::Create(context.builder.getContext(),"forbody",context.curfunction);
    auto end  = llvm::BasicBlock::Create(context.builder.getContext(),"forend",context.curfunction);
    auto next = llvm::BasicBlock::Create(context.builder.getContext(),"next",context.curfunction);

    context.builder.CreateBr(entry);
    context.builder.SetInsertPoint(entry);
    auto loopvar =new IDExpr("var",(string)this->var); 
    auto init_assign = new AssignStmt(loopvar,this->getStartExprNode());
    init_assign->CodeGen(context);
    auto testGT = new BinExpr("GT",loopvar,this->endexpr);
    context.builder.CreateCondBr(testGT->CodeGen(context),next,body);

    context.builder.SetInsertPoint(body);
    context.pushBlock(body,next,end);
    this->getLoopStmtNode()->CodeGen(context);
    context.builder.CreateBr(end);
    context.popBLock();

    context.builder.SetInsertPoint(end);
    auto int1 = new IDExpr("Imm",1);
    auto addstmt = new BinExpr("PLUS",loopvar,int1);
    auto as = new AssignStmt(loopvar,addstmt);
    as->CodeGen(context);
    auto testGE = new BinExpr("GT",loopvar,this->endexpr);
    auto test = testGE->CodeGen(context);
    auto ret = context.builder.CreateCondBr(test,next,body);
    
    context.builder.SetInsertPoint(next);
    context.ReplaceTopBlock(next);
    return ret;
}

llvm::Value* RepeatStmt::CodeGen(genContext &context){
    cout<<"Generating RepeatStmt...."<<endl;
    auto body = llvm::BasicBlock::Create(context.module->getContext(),"repeatbody",context.curfunction);
    auto end = llvm::BasicBlock::Create(context.module->getContext(),"end",context.curfunction);
    auto next = llvm::BasicBlock::Create(context.module->getContext(),"next",context.curfunction);
    context.builder.CreateBr(body);
    context.builder.SetInsertPoint(body);
    context.pushBlock(body,next,end);
    this->getLoopStmtNode()->CodeGen(context);
    context.builder.CreateBr(end);
    context.popBLock();

    context.builder.SetInsertPoint(end);

    auto test = this->getConditionExprNode()->CodeGen(context);
    auto ret = context.builder.CreateCondBr(test,next,body);

    context.builder.SetInsertPoint(next);
    context.ReplaceTopBlock(next);
    return ret;
}

llvm::Value* WhileStmt::CodeGen(genContext &context){
    cout<<"Generating while statement..."<<endl;
    auto entry = llvm::BasicBlock::Create(context.module->getContext(),"whileentry",context.curfunction);
    auto loop = llvm::BasicBlock::Create(context.module->getContext(),"whilebody",context.curfunction);
    auto next = llvm::BasicBlock::Create(context.module->getContext(),"next",context.curfunction);

    context.builder.CreateBr(entry);
    context.builder.SetInsertPoint(entry);
    auto condition = this->getConditionExprNode()->CodeGen(context);
    auto ret = context.builder.CreateCondBr(condition,loop,next);

    context.builder.SetInsertPoint(loop);
    context.pushBlock(loop,next,entry);
    this->getStmtListNode()->CodeGen(context);
    context.builder.CreateBr(entry);
    context.popBLock();

    context.builder.SetInsertPoint(next);
    context.ReplaceTopBlock(next);
    return ret;
}

llvm::Value* ElseStmt::CodeGen(genContext &context){
    if(this->getStmtListNode()!=NULL)
        return this->getStmtListNode()->CodeGen(context);
    else return NULL;
}

llvm::Value* IfStmt::CodeGen(genContext &context){

    cout<<"Generating IfStmt..."<<endl;
    llvm::Value* test = this->getConditionNode()->CodeGen(context);
    auto blocktrue=llvm::BasicBlock::Create(context.module->getContext(),"then",context.curfunction);
    auto blockfalse=llvm::BasicBlock::Create(context.module->getContext(),"else",context.curfunction);
    auto next=llvm::BasicBlock::Create(context.module->getContext(),"next",context.curfunction);

    context.builder.CreateCondBr(test,blocktrue,blockfalse);
    context.builder.SetInsertPoint(blocktrue);
    this->getStmtListNode()->CodeGen(context);
    if(context.breakif==false) context.builder.CreateBr(next);
    else {
        context.builder.CreateBr(context.getTopBlock()->Breakto);
        context.breakif=false;
    }
    
    context.builder.SetInsertPoint(blockfalse);
    if(this->getElseStmtNode()!=NULL){
        cout<<"Generate Else"<<endl;
        this->getElseStmtNode()->CodeGen(context);
    }
    context.builder.CreateBr(next);

    context.builder.SetInsertPoint(next);
    
    //next replace top block
    context.ReplaceTopBlock(next);
    return NULL;
}

llvm::Value* BreakStmt::CodeGen(genContext &context){
    if(context.getTopBlock()->Breakto==NULL)
        throw std::runtime_error("BreakStmt not in Any loop body");
    context.breakif=true;
    return NULL;
}



/**--------------------- Value Declare-------------------------*/

llvm::Value* VarDeclList::CodeGen(genContext &context){
    vector<VarDecl*> list = this->getList();
    for(auto it=list.begin(); it!=list.end();it++){
       (*it)->CodeGen(context);
    }
    return NULL;
}
llvm::Value* createArray(genContext &context, MyType* typenode,vector<string> namelist){
    ArrayType* node = (ArrayType*) typenode;
    int len=node->getIndexArrage().second - node->getIndexArrage().first+1;
    string name = node->getTypeName();
    llvm::Type* simpletype = getLLVMtype(new SimpleType(name),context);
    string funcname  = context.curfunction->getName();
    for(string it:namelist){
        context.builder.CreateAlloca(llvm::ArrayType::get(simpletype,len),NULL,it);
        context.setArrayRecord(funcname+"/"+it,node->getIndexArrage().first,node->getIndexArrage().second);
    }
    return NULL;
}
llvm::Value* createGlobalArray(genContext &context, MyType* typenode,vector<string> namelist){
    ArrayType* node = (ArrayType*) typenode;
    int len=node->getIndexArrage().second - node->getIndexArrage().first+1;
    string name = node->getTypeName();
    llvm::Type* simpletype = getLLVMtype(new SimpleType(name),context);
    
    llvm::Constant* init;
    if(simpletype->isIntegerTy())
        init = llvm::ConstantInt::get(simpletype,0);
    else if(simpletype->isDoubleTy())
        init = llvm::ConstantFP::get(simpletype,0.0);
    else throw std::runtime_error("Unknown ArrayElementType: "+name);
    std::vector<llvm::Constant*> initv;
    for(int i=0;i<len;i++)
        initv.push_back(init);

    llvm::Constant* initarr = llvm::ConstantArray::get(llvm::ArrayType::get(simpletype,len),initv);
    string funcname  = context.curfunction->getName();
    string path = context.getpath();
    for(string it:namelist){
        context.setArrayRecord(path+it,node->getIndexArrage().first,node->getIndexArrage().second);
        auto r = new llvm::GlobalVariable(*context.module,initarr->getType(),false,llvm::GlobalValue::ExternalLinkage,0,path+it);
        r->setInitializer(initarr);
        cout<<"Create GlobalArray: "+it<<endl;
    }   
    return NULL;
}

llvm::Type* getLLVMtype(MyType* typenode,genContext &context){
    string name;
    if(typenode->getClass()=="simpletype"){
        name = ((SimpleType*)typenode)->getSimpleTypeName();
        if(name=="integer"){
            return context.builder.getInt32Ty();
        }
        else if(name=="longint"){
            return context.builder.getInt64Ty();
        }
        else if(name=="bool"){
            return context.builder.getInt1Ty();
        }
        else if(name=="char"){
            return context.builder.getInt8Ty();
        }
        else if(name=="real"){
            return context.builder.getDoubleTy();
        }
    }
    else{
        name = ((ArrayType*)typenode)->getTypeName();
        int s=((ArrayType*)typenode)->getIndexArrage().first;
        int e=((ArrayType*)typenode)->getIndexArrage().second;
        return llvm::ArrayType::get(getLLVMtype(new SimpleType(name),context),e-s+1);
    }
    throw runtime_error("Unknown type"+ name);
    return NULL;
}

llvm::Value* VarDecl::CodeGen(genContext &context){
    auto list=this->getIDListNode()->getList();
    MyType* tn= this->getTypeNode();
    //global
    if(context.isGlobal){
        string path = context.getpath();
        if(tn->getClass()=="simpletype"){
                auto *ty = getLLVMtype(tn,context);
                llvm::Constant *constant;
                if(ty->isIntegerTy()){
                    constant = llvm::ConstantInt::get(ty,0);
                }
                else if(ty->isDoubleTy()){
                    constant = llvm::ConstantFP::get(ty,0.0);
                }
                llvm::Value * ret;
                for(auto i=list.begin(); i!=list.end(); i++){
                    string varname = path+*i;
                    ret = new llvm::GlobalVariable(*context.module,ty,false,llvm::GlobalVariable::ExternalLinkage,constant,varname);
                    cout<<"create global: "<<varname<<endl;
                }
                return ret; 
            }
            else{
                //array type
                return createGlobalArray(context,tn,list);
            }
    }
    else {
        if(tn->getClass()=="simpletype"){
            auto type_ = getLLVMtype(tn,context);
            llvm::Value * ret;
            for(auto i=list.begin(); i!=list.end(); i++){
                ret = context.builder.CreateAlloca(type_,nullptr,*i);
                cout<<"Create local: "<<*i<<endl;
            }
            return ret;
        }
        else {
            return createArray(context,(ArrayType*)tn,list);
        }
    }
}



/* -------------------------------No Need To Implement-----------------------------*/
llvm::Value* IDList::CodeGen(genContext &context){
    return NULL;
}

llvm::Value* MyType::CodeGen(genContext &context){
    return NULL;
}

llvm::Value* SimpleType::CodeGen(genContext &context){
    return NULL;
}

llvm::Value* ArrayType::CodeGen(genContext &context){
    return NULL;
}

llvm::Value* Program::CodeGen(genContext &context){
    return NULL;
}

llvm::Value* ParaList::CodeGen(genContext &context){
    return NULL;
}

llvm::Value* FuncHead::CodeGen(genContext &context){
    return NULL;
}


llvm::Value* ProgHead::CodeGen(genContext &context){
    return NULL;
}
//function's parameters 
llvm::Value* ExprList::CodeGen(genContext &context){
    return NULL;
}





