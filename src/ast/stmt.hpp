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

class Stmt: public BaseNode{
public:
    Stmt(string t):BaseNode(t){}
};  

class StmtList: public BaseNode{
private:
    vector<Stmt*> list;
public:
    StmtList():BaseNode("stmtlist"){

    }
    void pushStmt(Stmt* st){
        list.push_back(st);
    }
    vector<Stmt*> getStmtList(){
        return list;
    }
};

class AssignStmt: public Stmt{
private:
    string op; /* GE, GT, LE, LT, EQUAL, UNEQUAL,
                PLUS, MINUS, OR, MUL, REALDIV,
                DIV, MOD, AND*/
    Expr* lexpr;
    Expr* rexpr;
public:
    AssignStmt(Expr* l, Expr* r):Stmt("assignstmt"){
        this->lexpr = l;
        this->rexpr = r;
    }
    Expr* getLeftExprNode(){
        return this->lexpr;
    }
    Expr* getRightExprNode(){
        return this->rexpr;
    }
    string getOp(){
        return this->op;
    }
};

class ForStmt: public Stmt{
private:
    ID* var;
    Expr* startexpr;
    Expr* endexpr;
    StmtList* stmtl;
public:
    ForStmt(ID* id, Expr* s, Expr* e, StmtList *l):Stmt("forstmt"){
        this->var = id;
        this->startexpr = s;
        this->endexpr = e;
        this->stmtl = l;
    }
    ID* getLoopvarNode(){
        return this->var;
    }
    Expr* getStartExprNode(){
        return this->startexpr;
    }
    Expr* getEndExprNode(){
        return this->endexpr;
    }
    StmtList* getLoopStmtNode(){
        return this->stmtl;
    }
};

class FuncCallStmt: public Stmt{
private:
    string funcname;
    ExprList* el;
public:
    FuncCallStmt(string name, ExprList* l):Stmt("funccallstmt"){
        this->funcname = name;
        this->el=l;
    }
    string getFuncName(){
        return this->funcname;
    }
    ExprList* getParaExprListNode(){
        return this->el;
    }
};

class RepeatStmt:public Stmt{
private:
    Expr* cond;
    StmtList* sl;
public:
    RepeatStmt(Expr* e, StmtList* s):Stmt("repeatstmt"){
        this->cond = e;
        this->sl=s;
    }
    Expr* getConditionExprNode(){
        return this->cond;
    }
    StmtList* getLoopStmtNode(){
        return this->sl;
    }
};






