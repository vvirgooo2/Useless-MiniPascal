#pragma once
#include<string>
#include "base.hpp"
#include "expr.hpp"
#include "value_type.hpp"
using namespace std;
class Stmt;
class StmtList;
class AssignStmt;
class FuncCallStmt;
class RepeatStmt;
class WhileStmt;
class ElseStmt;
class IFStmt;
class BreakStmt;
class RepeatStmt;
class WhileStmt;
class ElseStmt;
class IfStmt;
class BreakStmt;

class Stmt: public BaseNode{
public:
    Stmt(string t):BaseNode(t){}
};  

class StmtList: public BaseNode{
private:
    vector<Stmt*> list;
public:
    StmtList():BaseNode("stmtlist"){ }
    StmtList(Stmt* st):BaseNode("stmtlist"){ list.push_back(st); }
    void pushStmt(Stmt* st){ list.push_back(st); }
    vector<Stmt*> getStmtList(){ return list; }
};

//id可以是arrayexpr 和 IDExpr
class AssignStmt: public Stmt{
private:
    Expr* id;
    Expr* rexpr;
public:
    AssignStmt(Expr* l, Expr* r):Stmt("assignstmt"),id(l),rexpr(r){ }
    Expr* getLeftExprNode(){ return this->id; }
    Expr* getRightExprNode(){ return this->rexpr; }
};

class ForStmt: public Stmt{
private:
    string var;
    Expr* startexpr;
    Expr* endexpr;
    StmtList* stmtl;
public:
    ForStmt(string id, Expr* s, Expr* e, StmtList *l):Stmt("forstmt"),var(id),startexpr(s),endexpr(e),stmtl(l){ }
    string getLoopvarNode(){ return this->var; }
    Expr* getStartExprNode(){ return this->startexpr; }
    Expr* getEndExprNode(){ return this->endexpr; }
    StmtList* getLoopStmtNode(){ return this->stmtl; }
};

class FuncCallStmt: public Stmt{
private:
    string funcname;
    ExprList* el;
public:
    FuncCallStmt(string name, ExprList* l):Stmt("funccallstmt"),funcname(name),el(l){ }
    string getFuncName(){ return this->funcname; }
    ExprList* getParaExprListNode(){ return this->el; }
};

class RepeatStmt:public Stmt{
private:
    Expr* cond;
    StmtList* sl;
public:
    RepeatStmt(Expr* e, StmtList* s):Stmt("repeatstmt"),cond(e),sl(s){ }
    Expr* getConditionExprNode(){ return this->cond; }
    StmtList* getLoopStmtNode(){ return this->sl; }
};

class WhileStmt:public Stmt{
private:
    Expr* con;
    StmtList* sl;
public:
    WhileStmt(Expr* e, StmtList* s):Stmt("whilestmt"),con(e),sl(s){ }
    Expr* getConditionExprNode(){ return this->con; }
    StmtList* getStmtListNode(){ return this->sl; }
};

class ElseStmt: public Stmt{
private:
    StmtList* list;
public:
    ElseStmt(StmtList* l):Stmt("elsestmt"),list(l){ }
    StmtList* getStmtListNode(){ return this->list; }
};

class IfStmt: public Stmt{
private:
    Expr* con;
    StmtList* list;
    ElseStmt* els;
public:
    IfStmt(Expr* e, StmtList* l, ElseStmt* el):Stmt("ifstmt"),con(e),list(l),els(el){ }
    Expr* getConditionNode(){ return this->con; }
    StmtList* getStmtListNode(){ return this->list; }
    ElseStmt* getElseStmtNode(){ return this->els; }
};

class BreakStmt:public Stmt{
public:
    BreakStmt():Stmt("breakstmt"){ }
};





