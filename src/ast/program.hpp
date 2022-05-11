#pragma once
#include "base.hpp"
#include "value_type.hpp"
#include "stmt.hpp"
#include <iostream>
#include <string>
#include <memory>
using namespace std;
//定义
class Routine;
class DeclPart;
class VarPart;
class FuncPart;
class FuncDecl;
class FuncBody;
class ExecPart;


//全局根节点
class Program: public BaseNode{
private:
    Routine *routine;
public:
    Program(Routine *routine):BaseNode("program"){
        this-> routine = routine;
    }
    Routine* getRoutineNode(){
        return this->routine;
    } 
};

//子程序,目前只有一个，留给嵌套定义做扩展
class Routine: public BaseNode{
private:
    DeclPart *declpart;
    ExecPart *execpart;
public:
    Routine(DeclPart* d, ExecPart* e):BaseNode("routine"){
        this->declpart = d;
        this->execpart = e;
    }
    DeclPart* getDeclPartNode(){
        return this->declpart;
    }
    ExecPart* getExecPartNode(){
        return this->execpart;
    }
};


//定义段
class DeclPart: public BaseNode{
private:
    VarPart *varpart;
public:
    DeclPart(VarPart* v):BaseNode("declpart"){
        this->varpart=v;
    }
    VarPart *getVarPartNode(){
        return this->varpart;
    }
};

//全局变量定义
class VarPart: public BaseNode{
private:
    VarDeclList* vdlist;
public:
    VarPart(VarDeclList *v):BaseNode("varpart"){
        this->vdlist = v;
    }
    VarDeclList* getVarDeclListNode(){
        return this->vdlist;
    }
};

//函数定义段
class FuncPart: public BaseNode{
private:
    FuncDecl* fd;
    FuncBody* fb;
public:
    FuncPart(FuncDecl* d, FuncBody* b):BaseNode("funcpart"){
        this->fd = d;
        this->fb = b;
    }
    FuncDecl* getFuncDeclNode(){
        return this->fd;
    }
    FuncBody* getFuncBodyNode(){
        return this->fb;
    }
};

class FuncDecl: public BaseNode{
private:
    string funcname;
    Type* rty;
    ParaList* pl;
public: 
    FuncDecl(string n, Type* t,ParaList* p):BaseNode("funcdecl"){
        this->funcname=n;
        this->rty = t;
        this->pl=p;
    }
    string getFuncName(){
        return this->funcname;
    }
    Type* getRetType(){
        return this->rty;
    }
    ParaList* getParaList(){
        return this->pl;
    }
};

class FuncBody: public BaseNode{
private:
    DeclPart* dp;
    ExecPart* ex;
    Stmt*  st;
public:
    FuncBody(DeclPart* p, ExecPart* e, Stmt* s):BaseNode("funcbody"){
        this->dp = p;
        this->ex = e;
        this->st = s;
    }
    DeclPart* getDeclPartNode(){
        return this->dp;
    }
    ExecPart* getExecPartNode(){
        return this->ex;
    }
    Stmt* getReturnStmtNode(){
        return this->st;
    }
};

class ExecPart : public BaseNode{
private:
    StmtList* sl;
public:
    ExecPart(StmtList* s):BaseNode("execpart"){
        this->sl = s;
    }
    StmtList* getStmtListNode(){
        return this->sl;
    }
};

