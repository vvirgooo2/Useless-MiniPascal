
#include <iostream>
#include "../astVisualize/dict.hpp"

using namespace std;

int main()
{
    // VarDeclList
    VarDeclList *vdl = new VarDeclList();
    // a,b : integer
    IDList *l = new IDList();
    l->pushID("a");
    l->pushID("b");
    vdl->pushVarDecl(new VarDecl(new SimpleType("integer"), l));
    // c: string
    IDList *l1 = new IDList();
    l1->pushID("c");
    vdl->pushVarDecl(new VarDecl(new SimpleType("integer"), l1));

    // function DeclList
    // Head
    FuncDeclList *funclist = new FuncDeclList();
    ParaList *pal = new ParaList();
    pal->pushNewPara(new VarDecl(new SimpleType("integer"), new IDList("in")));
    FuncHead *fd = new FuncHead("Testout", new SimpleType("integer"), pal);
    // Body
    DeclPart *d1 = new DeclPart(new VarDeclList(), new FuncDeclList());
    StmtList *Stl = new StmtList();
    ExprList *l2 = new ExprList();
    l2->pushExprNode(new IDExpr("var", (string) "in"));
    Stl->pushStmt(new FuncCallStmt("writeln", l2));
    ExecPart *ep = new ExecPart(Stl);
    FuncBody *funcb = new FuncBody(d1, ep, new IDExpr("Imm", 1));
    // OneFuncDecl
    OneFuncDecl *Testout = new OneFuncDecl(fd, funcb);
    funclist->pushOneFuncDecl(Testout);
    // declPart
    DeclPart *declp = new DeclPart(vdl, funclist);

    // ExecPart
    StmtList *stl2 = new StmtList();
    // assign
    AssignStmt *as = new AssignStmt(new IDExpr("var", (string) "c"), new IDExpr("Imm", 1));
    stl2->pushStmt(as);
    // for
    StmtList *forsubst = new StmtList();
    forsubst->pushStmt(new FuncCallStmt("writeln", new ExprList(new IDExpr("var", (string) "a"))));
    ForStmt *fo = new ForStmt("a", new IDExpr("Imm", 1), new IDExpr("Imm", 100), forsubst);
    stl2->pushStmt(fo);
    //
    ExecPart *execp = new ExecPart(stl2);
    Program *root = new Program(new ProgHead("test"), declp, execp);

    // 可视化，将AST转为JSON文件
    Dict *astDict = new Dict(root);
    astDict->writeJSONFile("./test.json");
}

/*
program test;
var
    a,b:integer ;
    c: integer ;

function Testout(in:string):integer
begin
    writeln(in);
end

begin
    c=1;
    for a:=1 to 100 do
        writeln(c);
end.
*/