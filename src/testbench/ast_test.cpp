
#include <iostream>
#include "../ast/AST_node.h"

using namespace std;

int main()
{
    //VarDeclList
    VarDeclList* vdl = new VarDeclList();
    // a,b : integer
    IDList* l =new IDList();
    l->PushId("a");
    l->PushId("b");
    vdl->PushVarDecl(new VarDecl(new SimpleType("integer"),l));
    //c: string
    IDList* l1=new IDList();
    l1->PushId("c");
    vdl->PushVarDecl(new VarDecl(new SimpleType("string"),l1));

    //function DeclList
    //Head
    FuncDeclList* funclist=new FuncDeclList();
    ParaList* pal =new ParaList();
    pal->pushNewPara(new SimpleType("stirng"),"in");
    FuncHead* fd=new FuncHead("Testout",new SimpleType("integer"),pal); 
    //Body
    DeclPart* d1 =new DeclPart(new VarDeclList(),new FuncDeclList());
    StmtList* Stl=new StmtList();
    ExprList* l2 = new ExprList();
    l2->pushExprNode(new IDExpr("var","in"));
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
    AssignStmt* as = new AssignStmt(new IDExpr("var","c"),new IDExpr("Imm","1234"));
    stl2->pushStmt(as);
    //for
    StmtList* forsubst =new StmtList();
    forsubst->pushStmt(new FuncCallStmt("writeln",new ExprList(new IDExpr("var","c"))));
    ForStmt* fo = new ForStmt("a",new IDExpr("Imm",1),new IDExpr("Imm",100),forsubst);
    stl2->pushStmt(fo);
    //
    ExecPart* execp = new ExecPart(stl2);
    Program* root = new Program(declp,execp);

    Stmt* s=root->getExecPartNode()->getStmtListNode()->getStmtList()[1];
    cout<<((ForStmt*)s)->getLoopvarNode()<<endl;
}

/*
program test;
var
    a,b:integer ;
    c: string ;

function Testout(in:string):integer
begin
    writeln(in);
end

begin
    c='1234';
    for a:=1 to 100 do
        writeln(c);
end.
*/