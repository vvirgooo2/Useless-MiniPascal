#include "../ast/AST_node.h"
/*---------------------------------Expr-------------------------*/
llvm::Value* ExprList::CodeGen(CodeGenContext &context){
    return NULL;
}

llvm::Value* BinExpr::CodeGen(CodeGenContext &context){
    return NULL;
}

llvm::Value* UnaryExpr::CodeGen(CodeGenContext &context){
    return NULL;
}

llvm::Value* FunCallExpr::CodeGen(CodeGenContext &context){
    return NULL;
}

llvm::Value* ArrayExpr::CodeGen(CodeGenContext &context){
    return NULL;
}

llvm::Value* IDExpr::CodeGen(CodeGenContext &context){
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
       (*iter)->CodeGen(context);
    }
    return NULL;
}

llvm::Value* OneFuncDecl::CodeGen(CodeGenContext &context){
    return NULL;
}

llvm::Value* FuncHead::CodeGen(CodeGenContext &context){
    return NULL;
}

llvm::Value* FuncBody::CodeGen(CodeGenContext &context){
    return NULL;
}

llvm::Value* ParaList::CodeGen(CodeGenContext &context){
    return NULL;
}


/* ---------------------------Stmt and Mainpart-----------------------------*/
llvm::Value* ExecPart::CodeGen(CodeGenContext &context){
    this->getStmtListNode()->CodeGen(context);
    return NULL;
}

llvm::Value* StmtList::CodeGen(CodeGenContext &context){
    auto list = this->getStmtList();
    for(auto stmt: list){
        stmt->CodeGen(context);
    }
    return NULL;
}

llvm::Value* AssignStmt::CodeGen(CodeGenContext &context){
    return NULL;
}

llvm::Value* ForStmt::CodeGen(CodeGenContext &context){
    return NULL;
}

llvm::Value* FuncCallStmt::CodeGen(CodeGenContext &context){
    return NULL;
}

llvm::Value* RepeatStmt::CodeGen(CodeGenContext &context){
    return NULL;
}

llvm::Value* WhileStmt::CodeGen(CodeGenContext &context){
    return NULL;
}

llvm::Value* ElseStmt::CodeGen(CodeGenContext &context){
    return NULL;
}

llvm::Value* IfStmt::CodeGen(CodeGenContext &context){
    return NULL;
}

llvm::Value* BreakStmt::CodeGen(CodeGenContext &context){
    return NULL;
}


/**------------------     Value Declare-------------------------*/

llvm::Value* VarDeclList::CodeGen(CodeGenContext &context){
    vector<VarDecl*> list = this->getList();
    for(int i=0;i<list.size();i++){
        list[i]->CodeGen(context);
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
        if(name=="integer"||name=="longint"){
            return context.builder.getInt32Ty();
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
        else if(name=="string"){
            return llvm::ArrayType::get(context.builder.getInt8Ty(),256);
        }
    }
    else{
        string t = ((ArrayType*)typenode)->getTypeName();
        // todo
    }
}

llvm::Value* VarDecl::CodeGen(CodeGenContext &context){
    auto list=this->getIDListNode()->getList();
    MyType* tn= this->getTypeNode();
    //global
    if(context.isGlobal){
        if(tn->getClass()=="simpletype"){
            if(((SimpleType*)tn)->getSimpleTypeName()=="string"){
                ArrayType* arn = new ArrayType("char");
                arn->pushNewDim(0,255);
                return createGlobalArray(context,arn,list);
            }
            else{
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
        }
        else{
            //array type
            return createGlobalArray(context,(ArrayType*)tn,list);
        }
    }
    //not global
    else {
        if(tn->getClass()=="simpletype"){
            if(((SimpleType*)tn)->getSimpleTypeName()=="string"){
                ArrayType* arn = new ArrayType("char");
                arn->pushNewDim(0,255);
                return createArray(context,arn,list);
            }
            else{
                auto type_ = getLLVMtype(tn,context);
                llvm::Value * ret;
                for(auto i=list.begin(); i!=list.end(); i++){
                    ret = context.builder.CreateAlloca(type_,nullptr,*i);
                }
                return ret;
            }
        }
        else {
            return createArray(context,(ArrayType*)tn,list);
        }
    }
}



/* -------------------------------__Rubbish-----------------------------*/
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






