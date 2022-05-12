#pragma once

#include<string>
#include "base.hpp"
using namespace std;
class Expr;
class ExprList;
class BinExpr;
class UnaryExpr;
class FuncCallExpr;
class ArrayExpr;
class IDExpr;

//广义表达式
class Expr : public BaseNode{
public:
    Expr(string t):BaseNode(t){ }
};

class ExprList: public BaseNode{
private:
    vector<Expr*> exlist;
public:
    ExprList():BaseNode("exprlist"){ }
    ExprList(Expr* e):BaseNode("exprlist"){ exlist.push_back(e); }
    void pushExprNode(Expr* e){ this->exlist.push_back(e); }
    vector<Expr*> getExprList(){ return this->exlist; }
};

class BinExpr: public Expr{
    /* GE, GT, LE, LT, EQUAL, UNEQUAL,
                PLUS, MINUS, OR, MUL, REALDIV,
                DIV, MOD, AND*/
private:
    string op;
    Expr* lhs;
    Expr* rhs;
public:
    BinExpr(string op, Expr* l, Expr* r):Expr("binexpr"),op(op),lhs(l),rhs(r){ }
    string getOp(){ return this->op; }
    Expr* getLeftExprNode(){ return this->lhs; }
    Expr* getRightExprNode(){ return this->rhs; }
};

class UnaryExpr: public Expr{
private:
    string op; //NOT
    Expr* ex;
public:
    UnaryExpr(string op, Expr* e):Expr("unaryexpr"),op(op),ex(e){ }
    string getOp(){ return this->op; }
    Expr* getExprNode(){ return this->ex; }
};

class FunCallExpr:public Expr{
private:
    string funcname;
    ExprList* el;
public:
    FunCallExpr(string n, ExprList* l):Expr("funcallexpr"),funcname(n),el(l){ }
    string getFuncName(){ return this->funcname; }
    ExprList* getExprListNode(){ return this->el; }
};

class ArrayExpr:public Expr{
private:
    string arrayname;
    vector<Expr*> index_list;
public:
    ArrayExpr(string a, Expr* e):Expr("arrayexpr"),arrayname(a){ index_list.push_back(e); }
    ArrayExpr(string a): Expr("arratexpr"),arrayname(a){}
    string getArrayName(){ return this->arrayname; }
    void pushIndexDim(Expr* e){ index_list.push_back(e); }
    vector<Expr*> getIndexExprList(){ return this->index_list;}
};

class IDExpr:public Expr{
private:
    string type;    //var - 变量名 Imm-立即数
    string varname;
    string immtype; //integer, float, string
    int i;
    float f;
    string str;
public:
    IDExpr(string t, int i):Expr("idexpr"),type(t),immtype("integer"),i(i){ }
    IDExpr(string t, float f):Expr("idexpr"),type(t),immtype("string"),str(str){ }
    IDExpr(string t, string str):Expr("idexpr"),type(t){
        if(t=="var") this->varname=str;
        else if(t=="Imm"){
            this->str=str;
            this->immtype="string";
        }
    }
    string getType(){ return this->type;}
    string getVarName(){ return this->varname; }
    int getIntValue(){ return this->i; }
    float getFloatValue(){ return this->f; }
    string getStringValue(){ return this->str; }
};

  