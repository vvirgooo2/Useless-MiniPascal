#pragma once
#include "base.hpp"
#include "value_type.hpp"
#include "stmt.hpp"
#include "expr.hpp"
#include <iostream>
#include <string>
#include <memory>
using namespace std;
//定义
class DeclPart;
class FuncDeclList;
class OneFuncDecl;
class FuncHead;
class FuncBody;
class ExecPart;

class Program: public BaseNode{
private:
    DeclPart *declpart;
    ExecPart *execpart;
public:
    string Program_name;
    Program(DeclPart* d, ExecPart* e):BaseNode("program"),declpart(d),execpart(e){ }
    DeclPart* getDeclPartNode(){ return this->declpart; }
    ExecPart* getExecPartNode(){ return this->execpart; }
};

class DeclPart: public BaseNode{
private:
    VarDeclList *varpart;
    FuncDeclList* funclist;
public:
    DeclPart(VarDeclList* v,FuncDeclList* f):BaseNode("declpart"),varpart(v),funclist(f){ }
    VarDeclList *getVarPartNode(){ return this->varpart; }
    FuncDeclList* getFuncPartNode(){ return this->funclist; }
};

class FuncDeclList:public BaseNode{
private:
    vector<OneFuncDecl*> funclist;
public:
    FuncDeclList():BaseNode("funcdecllist"){ }
    FuncDeclList(OneFuncDecl* of):BaseNode("funcdecllist"){ funclist.push_back(of); }
    void pushOneFuncDecl(OneFuncDecl* f){ this->funclist.push_back(f); }
    vector<OneFuncDecl*> getFuncList(){ return this->funclist; }
};

//函数定义段
class OneFuncDecl: public BaseNode{
private:
    FuncHead* fd;
    FuncBody* fb;
public:
    OneFuncDecl(FuncHead* d, FuncBody* b):BaseNode("onefuncdecl"),fd(d),fb(b){ }
    FuncHead* getFuncDeclNode(){ return this->fd; }
    FuncBody* getFuncBodyNode(){ return this->fb; }
};

class FuncHead: public BaseNode{
private:
    string funcname;
    Type* rty;
    ParaList* pl;
public: 
    FuncHead(string n, Type* t,ParaList* p):BaseNode("funchead"),funcname(n),rty(t),pl(p){ }
    string getFuncName(){ return this->funcname; }
    Type* getRetType(){ return this->rty; }
    ParaList* getParaList(){ return this->pl; }
};

class FuncBody: public BaseNode{
private:
    DeclPart* dp;
    ExecPart* ex;
    Expr*  ret;
public:
    FuncBody(DeclPart* p, ExecPart* e, Expr* s):BaseNode("funcbody"),dp(p),ex(e),ret(s){ }
    DeclPart* getDeclPartNode(){ return this->dp; }
    ExecPart* getExecPartNode(){ return this->ex; }
    Expr* getReturnExprNode(){ return this->ret; }
};

class ExecPart : public BaseNode{
private:
    StmtList* sl;
public:
    ExecPart(StmtList* s):BaseNode("execpart"),sl(s){ }
    StmtList* getStmtListNode(){ return this->sl; }
};

