#include "../ast/AST_node.h"

llvm::Value* ExprList::CodeGen(CodeGenContext &context){
    
}

llvm::Value* BinExpr::CodeGen(CodeGenContext &context){
    
}

llvm::Value* UnaryExpr::CodeGen(CodeGenContext &context){
    
}

llvm::Value* FunCallExpr::CodeGen(CodeGenContext &context){
    
}

llvm::Value* ArrayExpr::CodeGen(CodeGenContext &context){
    
}

llvm::Value* IDExpr::CodeGen(CodeGenContext &context){
    
}

llvm::Value* Program::CodeGen(CodeGenContext &context){
    
}

llvm::Value* DeclPart::CodeGen(CodeGenContext &context){
    return NULL;
}

llvm::Value* FuncDeclList::CodeGen(CodeGenContext &context){
    
}

llvm::Value* OneFuncDecl::CodeGen(CodeGenContext &context){
    
}

llvm::Value* FuncHead::CodeGen(CodeGenContext &context){
    
}

llvm::Value* FuncBody::CodeGen(CodeGenContext &context){
    
}

llvm::Value* ExecPart::CodeGen(CodeGenContext &context){
    
}

llvm::Value* StmtList::CodeGen(CodeGenContext &context){
    
}

llvm::Value* AssignStmt::CodeGen(CodeGenContext &context){
    
}

llvm::Value* ForStmt::CodeGen(CodeGenContext &context){
    
}

llvm::Value* FuncCallStmt::CodeGen(CodeGenContext &context){
    
}

llvm::Value* RepeatStmt::CodeGen(CodeGenContext &context){
    
}

llvm::Value* WhileStmt::CodeGen(CodeGenContext &context){
    
}

llvm::Value* ElseStmt::CodeGen(CodeGenContext &context){
    
}

llvm::Value* IfStmt::CodeGen(CodeGenContext &context){
    
}

llvm::Value* BreakStmt::CodeGen(CodeGenContext &context){
    
}

llvm::Value* VarDeclList::CodeGen(CodeGenContext &context){
    vector<VarDecl*> list = this->getList();
    for(int i=0;i<list.size();i++){
        list[i]->CodeGen(context);
    }
    return NULL;
}

llvm::Value* VarDecl::CodeGen(CodeGenContext &context){
    auto list=this->getIDListNode()->getList();
    MyType* ty= this->getTypeNode();
    if(ty->getClass()=="simpletype"){
        cout<<((SimpleType*)ty)->getSimpleTypeName()<<" ";
    }
    else{
        cout<<((ArrayType*)ty)->getTypeName()<<" ";
    }
    for(int i=0;i<list.size();i++){
        cout<<list[i];
    }
}

llvm::Value* IDList::CodeGen(CodeGenContext &context){
    
}

llvm::Value* MyType::CodeGen(CodeGenContext &context){
    
}

llvm::Value* SimpleType::CodeGen(CodeGenContext &context){
    
}

llvm::Value* ArrayType::CodeGen(CodeGenContext &context){
    
}

llvm::Value* ParaList::CodeGen(CodeGenContext &context){
    
}






