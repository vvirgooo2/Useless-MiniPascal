#include "CodeGen.hpp"
#include <iostream>
#include <fstream>
#include <unistd.h>
#include <fcntl.h>
using namespace std;
void CodeGenContext::regis(){
    vector<llvm::Type *> argtypes;
    argtypes.push_back(llvm::Type::getInt8PtrTy(this->globalcontext));
    llvm::FunctionType *wtype  = llvm::FunctionType::get(llvm::Type::getInt32Ty(globalcontext),argtypes,true);
    llvm::Function *func = llvm::Function::Create(
        wtype,llvm::Function::ExternalLinkage,
        llvm::Twine("printf"),
        this->module
    );
    func->setCallingConv(llvm::CallingConv::C);
    this->printf_func = func;

    llvm::Function* funcd = llvm::Function::Create(
        wtype,llvm::Function::ExternalLinkage,
        llvm::Twine("scanf"),
        this->module
    );
    funcd->setCallingConv(llvm::CallingConv::C);
    this->scanf_func = funcd;
}   

void CodeGenContext::generate(BaseNode* root){
    Program* r = (Program*) root;
    cout<<"Starting Generating..."<<endl;
    vector<llvm::Type*> argTypes;
    //返回int32，无参数,不接不定参数
    llvm::FunctionType *ftype = llvm::FunctionType::get(this->builder.getInt32Ty(),false); 
    this->mainFunction = llvm::Function::Create(ftype,llvm::Function::ExternalLinkage,"main",this->module);
    this->curfunction = mainFunction;
    llvm::BasicBlock* block = llvm::BasicBlock::Create(this->module->getContext(),"entry",mainFunction);
    this->builder.SetInsertPoint(block);
    pushBlock(block);
    cout<<"Global Decl:"<<endl;
    r->getDeclPartNode()->CodeGen(*this);

    this->builder.SetInsertPoint(block); //reset insert point
    cout<<"Global Exec:"<<endl;
    r->getExecPartNode()->CodeGen(*this);
  
    this->builder.CreateRet(this->builder.getInt32(0));
    

}

llvm::GenericValue CodeGenContext::runCode(){
    
}

int main(){
    //VarDeclList
    VarDeclList* vdl = new VarDeclList();
    // a,b : integer
    IDList* l =new IDList();
    l->pushID("a");
    l->pushID("b");
    vdl->pushVarDecl(new VarDecl(new SimpleType("integer"),l));
    //c: string
    IDList* l1=new IDList();
    l1->pushID("c");
    vdl->pushVarDecl(new VarDecl(new ArrayType((string)"integer",1,7),l1));

    //function DeclList
    //Head
    FuncDeclList* funclist=new FuncDeclList();
    ParaList* pal =new ParaList();
    pal->pushNewPara(new VarDecl(new SimpleType("real"),new IDList("in")));
    FuncHead* fd=new FuncHead("Testout",new SimpleType("real"),pal); 
    //Body
    DeclPart* d1 =new DeclPart(new VarDeclList(),new FuncDeclList());
    StmtList* Stl=new StmtList();
    ExprList* l2 = new ExprList();
    l2->pushExprNode(new IDExpr("var",(string)"in"));
    Stl->pushStmt(new FuncCallStmt("writeln",l2));
    ExecPart* ep =new ExecPart(Stl);
    FuncBody* funcb = new FuncBody(d1,ep,new IDExpr("Imm",1));
    //OneFuncDecl
    OneFuncDecl* Testout=new OneFuncDecl(fd,funcb);
    funclist->pushOneFuncDecl(Testout);
    //declPart
    DeclPart* declp = new DeclPart(vdl,funclist);

    //ExecPart
    StmtList* stl2 =new StmtList();
    //assign
    AssignStmt* as = new AssignStmt(new IDExpr("var",(string)"a"),new IDExpr("Imm",190));
    stl2->pushStmt(as);
    //for
    StmtList* forsubst =new StmtList();
    forsubst->pushStmt(new FuncCallStmt("writeln",new ExprList(new IDExpr("Imm",(string)"123"))));
    ForStmt* fo = new ForStmt("a",new IDExpr("Imm",1),new IDExpr("Imm",100),forsubst);
    stl2->pushStmt(fo);
    //
    ExecPart* execp = new ExecPart(stl2);
    Program* root = new Program(new ProgHead("test"),declp,execp);

    CodeGenContext* context = new CodeGenContext();
    try{
        context->generate(root);
        
        int fd = open("result.ll", O_CREAT | O_WRONLY, 0644);
        dup2(fd, 1);
        close(fd);
          
        context->module->print(llvm::outs(),nullptr);
    }
    catch (std::runtime_error &error){
        cout << "[Error] " << error.what() << endl;
    }
}