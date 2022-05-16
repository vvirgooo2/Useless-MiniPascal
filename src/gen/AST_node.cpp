#include "../ast/AST_node.h"
/*---------------------------Expr-------------------------*/
llvm::Value* BinExpr::CodeGen(CodeGenContext &context){
    cout<<"Generating BinExpr..."<<endl;
    llvm::Value *L = lhs->CodeGen(context);
    llvm::Value *R = rhs->CodeGen(context);

    if(L->getType()->isDoubleTy() || R->getType()->isDoubleTy()){
        if(!L->getType()->isDoubleTy()){
            L = context.builder.CreateSIToFP(L,context.builder.getDoubleTy());
        }
        if(!R->getType()->isDoubleTy()){
            R = context.builder.CreateSIToFP(R,context.builder.getDoubleTy());
        }
        if(op == "PLUS") 
            return context.builder.CreateFAdd(L,R,"add");
        else if(op=="MINUS") 
            return context.builder.CreateFSub(L,R,"sub");
        else if(op=="MUL") 
            return context.builder.CreateFMul(L,R,"mul");
        else if(op=="MOD")
            return context.builder.CreateFRem(L,R,"mod");
        else if(op=="DIV")
            return context.builder.CreateFDiv(L,R,"div");
        else if(op=="LT")
            return context.builder.CreateFCmpULT(L,R,"lt_cmp");
        else if(op=="GT")
            return context.builder.CreateFCmpUGT(L,R,"gt_cmp");
        else if(op=="LE")
            return context.builder.CreateFCmpULE(L,R,"le_cmp");
        else if(op=="GE")
            return context.builder.CreateFCmpUGE(L,R,"ge_cmp");
        else if(op=="EQUAL")
            return context.builder.CreateFCmpUEQ(L,R,"eq_cmp");
        else if(op=="UNEQUAL")
            return context.builder.CreateFCmpUNE(L,R,"ne_cmp");
        else
            throw std::runtime_error("Unknown F operation");
    }
    /* GE, GT, LE, LT, EQUAL, UNEQUAL,
                PLUS, MINUS, OR, MUL, 
                DIV, MOD, AND*/
    if(op == "PLUS") 
        return context.builder.CreateAdd(L,R,"add");
    else if(op=="MINUS") 
        return context.builder.CreateSub(L,R,"sub");
    else if(op=="MUL") 
        return context.builder.CreateMul(L,R,"mul");
    else if(op=="MOD")
        return context.builder.CreateSRem(L,R,"mod");
    else if(op=="DIV")
        return context.builder.CreateSDiv(L,R,"div");
    else if(op=="LT")
        return context.builder.CreateICmpSLT(L,R,"lt_cmp");
    else if(op=="GT")
        return context.builder.CreateICmpSGT(L,R,"gt_cmp");
    else if(op=="LE")
        return context.builder.CreateICmpSLE(L,R,"le_cmp");
    else if(op=="GE")
        return context.builder.CreateICmpSGE(L,R,"ge_cmp");
    else if(op=="EQUAL")
        return context.builder.CreateICmpEQ(L,R,"eq_cmp");
    else if(op=="UNEQUAL")
        return context.builder.CreateICmpNE(L,R,"ne_cmp");
    else if(op=="AND")
        return context.builder.CreateAnd(L,R,"and");
    else if(op=="OR")
        return context.builder.CreateOr(L,R,"or");
    else if(op=="XOR")
        return context.builder.CreateXor(L,R,"xor");
    else
        throw std::runtime_error("Unknown I operation");
    
    return NULL;
}

llvm::Value* UnaryExpr::CodeGen(CodeGenContext &context){
    if(op == "NOT")
        return context.builder.CreateNot(this->getExprNode()->CodeGen(context));
    else 
        throw std::runtime_error("Unknown Unary operation");
    return NULL;
}

llvm::Value* FunCallExpr::CodeGen(CodeGenContext &context){
    cout<<"CodeGen FuncallExpression..."<<endl;
    
    return NULL;
}

llvm::Value* ArrayExpr::CodeGen(CodeGenContext &context){
    return NULL;
}

//Need to modify 
llvm::Value* IDExpr::CodeGen(CodeGenContext &context){
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
            return llvm::ConstantFP::get(context.module->getContext(), llvm::APFloat(this->getFloatValue()));
        }
    }
    else if(type=="var"){
        if(context.genpointer==false) return context.builder.CreateLoad(context.getValue(this->getVarName()));
        else return context.getValue(this->getVarName());
    }
    return NULL;
}


llvm::Value* DeclPart::CodeGen(CodeGenContext &context){
    this->getVarListNode()->CodeGen(context);
    this->getFuncPartNode()->CodeGen(context);
    return NULL;
}

/*-----------------------------Function Declare------------------------*/
llvm::Value* FuncDeclList::CodeGen(CodeGenContext &context){
    auto list=this->getFuncList();
    for(auto iter=list.begin(); iter!=list.end(); iter++){
      auto ret=  (*iter)->CodeGen(context);
    }
    return NULL;
}

llvm::Value* OneFuncDecl::CodeGen(CodeGenContext &context){
    return NULL;
}


/* ---------------------------Stmt and Mainpart----------------------------*/
llvm::Value* ExecPart::CodeGen(CodeGenContext &context){
    return this->getStmtListNode()->CodeGen(context);
}

llvm::Value* StmtList::CodeGen(CodeGenContext &context){
    auto list = this->getStmtList();
    for(auto stmt: list){
        auto ret = stmt->CodeGen(context);
    }
    return NULL;
}

llvm::Value* AssignStmt::CodeGen(CodeGenContext &context){
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

llvm::Value* ForStmt::CodeGen(CodeGenContext &context){
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
    context.builder.CreateBr(body);

    context.builder.SetInsertPoint(body);
    context.pushBlock(body,next);
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

    auto oldtop = context.getTopBlock();
    auto nextBlock = new CodeGenBlock();
    nextBlock->locals = oldtop->locals;
    nextBlock->block = next;
    context.popBLock();
    context.pushCodeGenBlock(nextBlock);
    
    context.builder.SetInsertPoint(next);
    return ret;
}
llvm::Value *SysCall(FuncCallStmt* call,CodeGenContext &context){
    if(call->getFuncName()=="write"||call->getFuncName()=="writeln"){
        return NULL;
    }
}


llvm::Value* FuncCallStmt::CodeGen(CodeGenContext &context){
    cout<<"Generating FuncCallStmt..."<<endl;
    if(this->getFuncName()=="write"||this->getFuncName()=="writeln"){
        SysCall(this,context);
    }
    return NULL;
}

llvm::Value* RepeatStmt::CodeGen(CodeGenContext &context){
    cout<<"Generating RepeatStmt...."<<endl;
    auto body = llvm::BasicBlock::Create(context.module->getContext(),"repeatbody",context.curfunction);
    auto end = llvm::BasicBlock::Create(context.module->getContext(),"end",context.curfunction);
    auto next = llvm::BasicBlock::Create(context.module->getContext(),"next",context.curfunction);
    context.builder.CreateBr(body);
    context.builder.SetInsertPoint(body);
    context.pushBlock(body,next);
    this->getLoopStmtNode()->CodeGen(context);
    context.builder.CreateBr(end);
    context.popBLock();

    context.builder.SetInsertPoint(end);
    auto test = this->getConditionExprNode()->CodeGen(context);
    auto ret = context.builder.CreateCondBr(test,next,body);

    //next replace top block
    auto oldtop = context.getTopBlock();
    auto nextBlock = new CodeGenBlock();
    nextBlock->locals = oldtop->locals;
    nextBlock->block = next;
    context.popBLock();
    context.pushCodeGenBlock(nextBlock);
    
    return ret;
}

llvm::Value* WhileStmt::CodeGen(CodeGenContext &context){
    cout<<"Generating while statement..."<<endl;
    auto wb = llvm::BasicBlock::Create(context.module->getContext(),"whileentry",context.curfunction);
    auto loop = llvm::BasicBlock::Create(context.module->getContext(),"whilebody",context.curfunction);
    auto next = llvm::BasicBlock::Create(context.module->getContext(),"next",context.curfunction);

    context.builder.CreateBr(wb);
    context.builder.SetInsertPoint(wb);
    auto condition = this->getConditionExprNode()->CodeGen(context);
    auto ret = context.builder.CreateCondBr(condition,loop,next);

    context.builder.SetInsertPoint(loop);
    context.pushBlock(loop,next);
    this->getStmtListNode()->CodeGen(context);
    context.builder.CreateBr(wb);
    context.popBLock();

    context.builder.SetInsertPoint(next);
    
    //next replace top block
    auto oldtop = context.getTopBlock();
    auto nextBlock = new CodeGenBlock();
    nextBlock->locals = oldtop->locals;
    nextBlock->block = next;
    context.popBLock();
    context.pushCodeGenBlock(nextBlock);
    
    return ret;
}

llvm::Value* ElseStmt::CodeGen(CodeGenContext &context){
    return this->getStmtListNode()->CodeGen(context);
}

llvm::Value* IfStmt::CodeGen(CodeGenContext &context){

    cout<<"Generating IfStmt..."<<endl;
    llvm::Value* test = this->getConditionNode()->CodeGen(context);
    auto btrue=llvm::BasicBlock::Create(context.module->getContext(),"then",context.curfunction);
    auto bfalse=llvm::BasicBlock::Create(context.module->getContext(),"else",context.curfunction);
    auto next=llvm::BasicBlock::Create(context.module->getContext(),"next",context.curfunction);

    context.builder.CreateCondBr(test,btrue,bfalse);
    context.builder.SetInsertPoint(btrue);
    this->getStmtListNode()->CodeGen(context);
    context.builder.CreateBr(next);
    
    context.builder.SetInsertPoint(bfalse);
    if(this->getElseStmtNode()!=NULL){
        this->getElseStmtNode()->CodeGen(context);
    }
    context.builder.CreateBr(next);

    context.builder.SetInsertPoint(next);
    
    //next replace top block
    auto oldtop = context.getTopBlock();
    auto nextBlock = new CodeGenBlock();
    nextBlock->locals = oldtop->locals;
    nextBlock->block = next;
    context.popBLock();
    context.pushCodeGenBlock(nextBlock);
    
    return NULL;
}



/**--------------------- Value Declare-------------------------*/

llvm::Value* VarDeclList::CodeGen(CodeGenContext &context){
    vector<VarDecl*> list = this->getList();
    for(auto it=list.begin(); it!=list.end();it++){
       (*it)->CodeGen(context);
    }
    return NULL;
}
llvm::Value* createArray(CodeGenContext &context, ArrayType* typenode,vector<string> namelist){
    return NULL;
}
llvm::Value* createGlobalArray(CodeGenContext &context, ArrayType* typenode,vector<string> namelist){
    return NULL;
}

llvm::Type* getLLVMtype(MyType* typenode,CodeGenContext &context){
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
        string t = ((ArrayType*)typenode)->getTypeName();
        // todo
    }
    return NULL;
}

llvm::Value* VarDecl::CodeGen(CodeGenContext &context){
    auto list=this->getIDListNode()->getList();
    MyType* tn= this->getTypeNode();
    //global
    if(context.isGlobal){
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
                ret = new llvm::GlobalVariable(*context.module,ty,false,llvm::GlobalVariable::ExternalLinkage,constant,*i);
                cout<<"create: "<<*i<<endl;
            }
                return ret; 
        }
        else{
            //array type
            return createGlobalArray(context,(ArrayType*)tn,list);
        }
    }
    //not global
    else {
        if(tn->getClass()=="simpletype"){
            auto type_ = getLLVMtype(tn,context);
            llvm::Value * ret;
            for(auto i=list.begin(); i!=list.end(); i++){
                ret = context.builder.CreateAlloca(type_,nullptr,*i);
                cout<<"Create local"<<*i<<endl;
                context.locals()[*i]=ret;
            }
            return ret;
        }
        else {
            return createArray(context,(ArrayType*)tn,list);
        }
    }
}



/* -------------------------------No Need To Implement-----------------------------*/
llvm::Value* IDList::CodeGen(CodeGenContext &context){
    return NULL;
}

llvm::Value* MyType::CodeGen(CodeGenContext &context){
    return NULL;
}

llvm::Value* SimpleType::CodeGen(CodeGenContext &context){
    return NULL;
}

llvm::Value* ArrayType::CodeGen(CodeGenContext &context){
    return NULL;
}

llvm::Value* Program::CodeGen(CodeGenContext &context){
    return NULL;
}


llvm::Value* BreakStmt::CodeGen(CodeGenContext &context){
    return NULL;
}

llvm::Value* ParaList::CodeGen(CodeGenContext &context){
    return NULL;
}

llvm::Value* FuncHead::CodeGen(CodeGenContext &context){
    return NULL;
}

llvm::Value* FuncBody::CodeGen(CodeGenContext &context){
    return NULL;
}
llvm::Value* ProgHead::CodeGen(CodeGenContext &context){
    return NULL;
}
//function's parameters 
llvm::Value* ExprList::CodeGen(CodeGenContext &context){
    return NULL;
}





