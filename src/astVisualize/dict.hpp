#include <iostream>
#include <fstream>
#include "../ast/AST_node.h"
using namespace std;

class Dict
{
private:
    string key;     // classname
    string valType; // 值类型：只能为str/dict，取值与下面一个对应
    string strValue;
    vector<Dict *> dictValue;

    void addOneDictValue(Dict *dict);

    void genFrom_Program(Program *node);   // ProgHead + DeclPart + ExecPart
    void genFrom_ProgHead(ProgHead *node); // name
    void genFrom_DeclPart(DeclPart *node); // VarDeclList + FuncDeclList

    void genFrom_VarDeclList(VarDeclList *node); // VarDecl ...
    void genFrom_VarDecl(VarDecl *node);         // Type + IDlist
    void genFrom_SimpleType(SimpleType *node);   // leaf
    void genFrom_ArrayType(ArrayType *node);     // leaf
    void genFrom_IDList(IDList *node);           // leaf

    void genFrom_FuncDeclList(FuncDeclList *node); // OneFuncDecl ...
    void genFrom_OneFuncDecl(OneFuncDecl *node);   // FuncHead + FuncBody
    void genFrom_FuncHead(FuncHead *node);         // Type + Paralist
    void genFrom_ParaList(ParaList *node);         // VarDecl ...

    void genFrom_FuncBody(FuncBody *node); // DeclPart + ExecPart
    void genFrom_ExecPart(ExecPart *node); // StmtList

    void genFrom_StmtList(StmtList *node);         // Stmt ...
    void genFrom_AssignStmt(AssignStmt *node);     // id(Expr) + rexpr(Expr)
    void genFrom_ForStmt(ForStmt *node);           // var + startexpr + endexpr + stmtl
    void genFrom_FuncCallStmt(FuncCallStmt *node); // funcname + el(ExprList)
    void genFrom_RepeatStmt(RepeatStmt *node);     // cond(Expr) + sl(StmtList)
    void genFrom_WhileStmt(WhileStmt *node);       // con(Expr) + sl(StmtList)
    void genFrom_ElseStmt(ElseStmt *node);         // list(StmtList)
    void genFrom_IfStmt(IfStmt *node);             // con(Expr) + sl(StmtList) + els(ElseStmt)
    void genFrom_BreakStmt(BreakStmt *node);

    void genFrom_ExprList(ExprList *node);       // Expr ...
    Dict *genFrom_Expr(Expr *node);              // judge the Expr type
    void genFrom_BinExpr(BinExpr *node);         // op + lhs + rhs
    void genFrom_UnaryExpr(UnaryExpr *node);     // op (NOT) + ex
    void genFrom_FunCallExpr(FunCallExpr *node); // funcname + ExprList
    void genFrom_ArrayExpr(ArrayExpr *node);     // arrayname + Expr...(index_list)
    void genFrom_IDExpr(IDExpr *node);           // leaf

public:
    Dict(string key, string value) : valType("str"), key(key), strValue(value) {}
    Dict(string key, Dict *value) : valType("dict"), key(key), strValue("") { dictValue.push_back(value); }
    Dict(pair<MyType *, string> node);
    Dict(BaseNode *node);

    void writeJSONFile(string filepath);
    string getJSONString();
};
