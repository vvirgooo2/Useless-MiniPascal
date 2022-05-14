#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "../gen/CodeGen.hpp"
using namespace std;

class BaseNode;
class CodeGenContext;
class Expr;
class ExprList;
class BinExpr;
class UnaryExpr;
class FuncCallExpr;
class ArrayExpr;
class IDExpr;
class DeclPart;
class FuncDeclList;
class OneFuncDecl;
class FuncHead;
class FuncBody;
class ExecPart;
class Stmt;
class StmtList;
class AssignStmt;
class ForStmt;
class FuncCallStmt;
class RepeatStmt;
class WhileStmt;
class ElseStmt;
class IfStmt;
class BreakStmt;
class VarDeclList;
class VarDecl;
class MyType;
class SimpleType;
class ArrayType;
class IDList;
class ParaList;

class BaseNode
{
private:
    // ClassName
    string classname = "base";

public:
    BaseNode(string name)
    {
        this->classname = name;
    }
    string getClass() const
    {
        return this->classname;
    }
    virtual llvm::Value *CodeGen(CodeGenContext &context) = 0;
};

//广义表达式
class Expr : public BaseNode
{
public:
    Expr(string t) : BaseNode(t) {}
};

class ExprList : public BaseNode
{
private:
    vector<Expr *> exlist;

public:
    ExprList() : BaseNode("exprlist") {}
    ExprList(Expr *e) : BaseNode("exprlist") { exlist.push_back(e); }
    void pushExprNode(Expr *e) { this->exlist.push_back(e); }
    vector<Expr *> getExprList() { return this->exlist; }
    virtual llvm::Value *CodeGen(CodeGenContext &context);
};

class BinExpr : public Expr
{
    /* GE, GT, LE, LT, EQUAL, UNEQUAL,
                PLUS, MINUS, OR, MUL, REALDIV,
                DIV, MOD, AND*/
private:
    string op;
    Expr *lhs;
    Expr *rhs;

public:
    BinExpr(string op, Expr *l, Expr *r) : Expr("binexpr"), op(op), lhs(l), rhs(r) {}
    string getOp() { return this->op; }
    Expr *getLeftExprNode() { return this->lhs; }
    Expr *getRightExprNode() { return this->rhs; }
    virtual llvm::Value *CodeGen(CodeGenContext &context);
};

class UnaryExpr : public Expr
{
private:
    string op; // NOT
    Expr *ex;

public:
    UnaryExpr(string op, Expr *e) : Expr("unaryexpr"), op(op), ex(e) {}
    string getOp() { return this->op; }
    Expr *getExprNode() { return this->ex; }
    virtual llvm::Value *CodeGen(CodeGenContext &context);
};

class FunCallExpr : public Expr
{
private:
    string funcname;
    ExprList *el;

public:
    FunCallExpr(string n, ExprList *l) : Expr("funcallexpr"), funcname(n), el(l) {}
    string getFuncName() { return this->funcname; }
    ExprList *getExprListNode() { return this->el; }
    virtual llvm::Value *CodeGen(CodeGenContext &context);
};

class ArrayExpr : public Expr
{
private:
    string arrayname;
    vector<Expr *> index_list;

public:
    ArrayExpr(string a, Expr *e) : Expr("arrayexpr"), arrayname(a) { index_list.push_back(e); }
    ArrayExpr(string a) : Expr("arratexpr"), arrayname(a) {}
    string getArrayName() { return this->arrayname; }
    void pushIndexDim(Expr *e) { index_list.push_back(e); }
    vector<Expr *> getIndexExprList() { return this->index_list; }
    virtual llvm::Value *CodeGen(CodeGenContext &context);
};

class IDExpr : public Expr
{
private:
    string type; // var - 变量名 Imm-立即数
    string varname;
    string immtype; // integer, float, string
    int i;
    float f;
    string str;
    bool boolval;

public:
    IDExpr(string t, int i) : Expr("idexpr"), type(t), immtype("integer"), i(i) {}
    IDExpr(string t, float f) : Expr("idexpr"), type(t), immtype("string"), f(f) {}
    IDExpr(string t, string str) : Expr("idexpr"), type(t)
    {
        if (t == "var")
            this->varname = str;
        else if (t == "Imm")
        {
            this->str = str;
            this->immtype = "string";
        }
    }
    string getType() { return this->type; }
    string getImmType() { return this->immtype; }
    string getVarName() { return this->varname; }
    int getIntValue() { return this->i; }
    float getFloatValue() { return this->f; }
    string getStringValue() { return this->str; }
    bool getBooleanValue() { return this->boolval; }
    virtual llvm::Value *CodeGen(CodeGenContext &context);
};

class Program : public BaseNode
{
private:
    DeclPart *declpart;
    ExecPart *execpart;

public:
    string Program_name;
    Program(DeclPart *d, ExecPart *e) : BaseNode("program"), declpart(d), execpart(e) {}
    DeclPart *getDeclPartNode() { return this->declpart; }
    ExecPart *getExecPartNode() { return this->execpart; }
    virtual llvm::Value *CodeGen(CodeGenContext &context);
};

class DeclPart : public BaseNode
{
private:
    VarDeclList *varpart;
    FuncDeclList *funclist;

public:
    DeclPart(VarDeclList *v, FuncDeclList *f) : BaseNode("declpart"), varpart(v), funclist(f) {}
    VarDeclList *getVarListNode() { return this->varpart; }
    FuncDeclList *getFuncPartNode() { return this->funclist; }
    virtual llvm::Value *CodeGen(CodeGenContext &context);
};

class FuncDeclList : public BaseNode
{
private:
    vector<OneFuncDecl *> funclist;

public:
    FuncDeclList() : BaseNode("funcdecllist") {}
    FuncDeclList(OneFuncDecl *of) : BaseNode("funcdecllist") { funclist.push_back(of); }
    void pushOneFuncDecl(OneFuncDecl *f) { this->funclist.push_back(f); }
    vector<OneFuncDecl *> getFuncList() { return this->funclist; }
    virtual llvm::Value *CodeGen(CodeGenContext &context);
};

//函数定义段
class OneFuncDecl : public BaseNode
{
private:
    FuncHead *fd;
    FuncBody *fb;

public:
    OneFuncDecl(FuncHead *d, FuncBody *b) : BaseNode("onefuncdecl"), fd(d), fb(b) {}
    FuncHead *getFuncDeclNode() { return this->fd; }
    FuncBody *getFuncBodyNode() { return this->fb; }
    virtual llvm::Value *CodeGen(CodeGenContext &context);
};

class FuncHead : public BaseNode
{
private:
    string funcname;
    MyType *rty;
    ParaList *pl;

public:
    FuncHead(string n, MyType *t, ParaList *p) : BaseNode("funchead"), funcname(n), rty(t), pl(p) {}
    string getFuncName() { return this->funcname; }
    MyType *getRetType() { return this->rty; }
    ParaList *getParaList() { return this->pl; }
    virtual llvm::Value *CodeGen(CodeGenContext &context);
};

class FuncBody : public BaseNode
{
private:
    DeclPart *dp;
    ExecPart *ex;
    Expr *ret;

public:
    FuncBody(DeclPart *p, ExecPart *e, Expr *s) : BaseNode("funcbody"), dp(p), ex(e), ret(s) {}
    DeclPart *getDeclPartNode() { return this->dp; }
    ExecPart *getExecPartNode() { return this->ex; }
    Expr *getReturnExprNode() { return this->ret; }
    virtual llvm::Value *CodeGen(CodeGenContext &context);
};

class ExecPart : public BaseNode
{
private:
    StmtList *sl;

public:
    ExecPart(StmtList *s) : BaseNode("execpart"), sl(s) {}
    StmtList *getStmtListNode() { return this->sl; }
    virtual llvm::Value *CodeGen(CodeGenContext &context);
};
class Stmt : public BaseNode
{
public:
    Stmt(string t) : BaseNode(t) {}
};

class StmtList : public BaseNode
{
private:
    vector<Stmt *> list;

public:
    StmtList() : BaseNode("stmtlist") {}
    StmtList(Stmt *st) : BaseNode("stmtlist") { list.push_back(st); }
    void pushStmt(Stmt *st) { list.push_back(st); }
    vector<Stmt *> getStmtList() { return list; }
    virtual llvm::Value *CodeGen(CodeGenContext &context);
};

// id可以是arrayexpr 和 IDExpr
class AssignStmt : public Stmt
{
private:
    Expr *id;
    Expr *rexpr;

public:
    AssignStmt(Expr *l, Expr *r) : Stmt("assignstmt"), id(l), rexpr(r) {}
    Expr *getLeftExprNode() { return this->id; }
    Expr *getRightExprNode() { return this->rexpr; }
    virtual llvm::Value *CodeGen(CodeGenContext &context);
};

class ForStmt : public Stmt
{
private:
    string var;
    Expr *startexpr;
    Expr *endexpr;
    StmtList *stmtl;

public:
    ForStmt(string id, Expr *s, Expr *e, StmtList *l) : Stmt("forstmt"), var(id), startexpr(s), endexpr(e), stmtl(l) {}
    string getLoopvarNode() { return this->var; }
    Expr *getStartExprNode() { return this->startexpr; }
    Expr *getEndExprNode() { return this->endexpr; }
    StmtList *getLoopStmtNode() { return this->stmtl; }
    virtual llvm::Value *CodeGen(CodeGenContext &context);
};

class FuncCallStmt : public Stmt
{
private:
    string funcname;
    ExprList *el;

public:
    FuncCallStmt(string name, ExprList *l) : Stmt("funccallstmt"), funcname(name), el(l) {}
    string getFuncName() { return this->funcname; }
    ExprList *getParaExprListNode() { return this->el; }
    virtual llvm::Value *CodeGen(CodeGenContext &context);
};

class RepeatStmt : public Stmt
{
private:
    Expr *cond;
    StmtList *sl;

public:
    RepeatStmt(Expr *e, StmtList *s) : Stmt("repeatstmt"), cond(e), sl(s) {}
    Expr *getConditionExprNode() { return this->cond; }
    StmtList *getLoopStmtNode() { return this->sl; }
    virtual llvm::Value *CodeGen(CodeGenContext &context);
};

class WhileStmt : public Stmt
{
private:
    Expr *con;
    StmtList *sl;

public:
    WhileStmt(Expr *e, StmtList *s) : Stmt("whilestmt"), con(e), sl(s) {}
    Expr *getConditionExprNode() { return this->con; }
    StmtList *getStmtListNode() { return this->sl; }
    virtual llvm::Value *CodeGen(CodeGenContext &context);
};

class ElseStmt : public Stmt
{
private:
    StmtList *list;

public:
    ElseStmt(StmtList *l) : Stmt("elsestmt"), list(l) {}
    StmtList *getStmtListNode() { return this->list; }
    virtual llvm::Value *CodeGen(CodeGenContext &context);
};

class IfStmt : public Stmt
{
private:
    Expr *con;
    StmtList *list;
    ElseStmt *els;

public:
    IfStmt(Expr *e, StmtList *l, ElseStmt *el) : Stmt("ifstmt"), con(e), list(l), els(el) {}
    Expr *getConditionNode() { return this->con; }
    StmtList *getStmtListNode() { return this->list; }
    ElseStmt *getElseStmtNode() { return this->els; }
    virtual llvm::Value *CodeGen(CodeGenContext &context);
};

class BreakStmt : public Stmt
{
public:
    BreakStmt() : Stmt("breakstmt") {}
    virtual llvm::Value *CodeGen(CodeGenContext &context);
};

class VarDeclList : public BaseNode
{
private:
    vector<VarDecl *> list;

public:
    VarDeclList() : BaseNode("vardecllist") {}
    void PushVarDecl(VarDecl *v) { list.push_back(v); }
    vector<VarDecl *> &getList() { return this->list; }
    llvm::Value *CodeGen(CodeGenContext &context);
};

//每一个decl
class VarDecl : public BaseNode
{
private:
    MyType *type;
    IDList *list;
    int init_int;       // TODO
    float init_float;   // TODO
    string init_string; // TODO
    bool init_boolean;  // TODO

public:
    // IDExpr *initial; // TODO
    // VarDecl(MyType *t, IDList *l) : BaseNode("vardecl"), type(t), list(l)
    // {
    //     // 分开初始化类型
    //     if (t->getClass() == "simpletype")
    //     {
    //         SimpleType *curtype = (SimpleType *)t;
    //         if (curtype->getSimpleTypeName() == "integer" || curtype->getSimpleTypeName() == "longint")
    //             this->init_int = 0;
    //         else if (curtype->getSimpleTypeName() == "float")
    //             this->init_float = 0.0;
    //         else if (curtype->getSimpleTypeName() == "string")
    //             this->init_string = "";
    //         else if (curtype->getSimpleTypeName() == "boolean")
    //             this->init_boolean = "false";
    //     }
    //     else
    //     {
    //         ArrayType *curtype = (ArrayType *)t;
    //         if (curtype->getTyName() == "integer" || curtype->getTyName() == "longint")
    //             this->init_int = 0;
    //         else if (curtype->getTyName() == "float")
    //             this->init_float = 0.0;
    //         else if (curtype->getTyName() == "string")
    //             this->init_string = "";
    //         else if (curtype->getTyName() == "boolean")
    //             this->init_boolean = "false";
    //     }
    // }
    // 分离构造函数
    VarDecl(MyType *t, IDList *l, int init) : BaseNode("vardecl"), type(t), list(l), init_int(init) {}
    VarDecl(MyType *t, IDList *l, float init) : BaseNode("vardecl"), type(t), list(l), init_float(init) {}
    VarDecl(MyType *t, IDList *l, string init) : BaseNode("vardecl"), type(t), list(l), init_string(init) {}
    VarDecl(MyType *t, IDList *l, bool init) : BaseNode("vardecl"), type(t), list(l), init_boolean(init) {}
    MyType *getTypeNode() { return this->type; }
    IDList *getIDListNode() { return this->list; }
    int getInitInt() { return this->init_int; }
    float getInitFloat() { return this->init_float; }
    string getInitString() { return this->init_string; }
    bool getInitBoolean() { return this->init_boolean; }
    llvm::Value *CodeGen(CodeGenContext &context);
};

// idlist 变量名的列表
class IDList : public BaseNode
{
private:
    vector<string> list;

public:
    IDList() : BaseNode("idlist") {}
    IDList(string id) : BaseNode("idlist") { list.push_back(id); }
    void PushId(string id) { (this->list).push_back(id); }
    vector<string> &getList() { return this->list; }
    llvm::Value *CodeGen(CodeGenContext &context);
};

class MyType : public BaseNode
{
public:
    MyType(string t) : BaseNode(t) {}
    llvm::Value *CodeGen(CodeGenContext &context);
};

class SimpleType : public MyType
{
private:
    string tyname; // string, integer, float, boolean 等存完整名字即可
public:
    SimpleType(string tn) : MyType("simpletype"), tyname(tn) {}
    string getSimpleTypeName() { return this->tyname; }
    llvm::Value *CodeGen(CodeGenContext &context);
};

class ArrayType : public MyType
{
private:
    string tyname;
    int dim;
    vector<pair<int, int>> index_arrange; // start end，对应维度
public:
    ArrayType(string n) : MyType("arraytype"), dim(0), tyname(n) {}
    int getDim() { return this->dim; }
    string getTypeName() { return tyname; }
    vector<pair<int, int>> getIndexArrange() { return this->index_arrange; }
    void pushNewDim(int s, int e)
    {
        index_arrange.push_back(make_pair(s, e));
        dim++;
    }
    string getTyName() { return this->tyname; }
    llvm::Value *CodeGen(CodeGenContext &context);
};

//参数表
class ParaList : public BaseNode
{
private:
    vector<pair<MyType *, string>> pa;

public:
    ParaList() : BaseNode("paralist") {}
    void pushNewPara(MyType *t, string i) { pa.push_back(pair<MyType *, string>(t, i)); }
    vector<pair<MyType *, string>> getParaList() { return this->pa; }
    llvm::Value *CodeGen(CodeGenContext &context);
};
