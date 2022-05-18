#include "dict.hpp"
Dict::Dict(pair<MyType *, string> node)
{
    // for Para node
    this->key = "ParaPair";
    this->valType = "dict";
    MyType *type = node.first;
    Dict *TypeDict;
    if (type->getClass() == "simpletype")
    {
        SimpleType *simpleType = (SimpleType *)type;
        TypeDict = new Dict(simpleType);
    }
    else
    {
        ArrayType *arrayType = (ArrayType *)type;
        TypeDict = new Dict(arrayType);
    }
    Dict *VarDict = new Dict("VarName", node.second);
    addOneDictValue(TypeDict);
    addOneDictValue(VarDict);
}

Dict::Dict(BaseNode *root)
{
    string nodeType = root->getClass();

    if (nodeType == "exprlist")
    {
        ExprList *node = (ExprList *)root;
        genFrom_ExprList(node);
    }
    else if (nodeType == "binexpr")
    {
        BinExpr *node = (BinExpr *)root;
        genFrom_BinExpr(node);
    }
    else if (nodeType == "unaryexpr")
    {
        UnaryExpr *node = (UnaryExpr *)root;
        genFrom_UnaryExpr(node);
    }
    else if (nodeType == "funcallexpr")
    {
        FunCallExpr *node = (FunCallExpr *)root;
        genFrom_FunCallExpr(node);
    }
    else if (nodeType == "arrayexpr")
    {
        ArrayExpr *node = (ArrayExpr *)root;
        genFrom_ArrayExpr(node);
    }
    else if (nodeType == "idexpr")
    {
        IDExpr *node = (IDExpr *)root;
        genFrom_IDExpr(node);
    }
    else if (nodeType == "program")
    {
        Program *node = (Program *)root;
        genFrom_Program(node);
    }
    else if (nodeType == "proghead")
    {
        ProgHead *node = (ProgHead *)root;
        genFrom_ProgHead(node);
    }
    else if (nodeType == "declpart")
    {
        DeclPart *node = (DeclPart *)root;
        genFrom_DeclPart(node);
    }
    else if (nodeType == "vardecllist")
    {
        VarDeclList *node = (VarDeclList *)root;
        genFrom_VarDeclList(node);
    }
    else if (nodeType == "vardecl")
    {
        VarDecl *node = (VarDecl *)root;
        genFrom_VarDecl(node);
    }
    else if (nodeType == "simpletype")
    {
        SimpleType *node = (SimpleType *)root;
        genFrom_SimpleType(node);
    }
    else if (nodeType == "arraytype")
    {
        ArrayType *node = (ArrayType *)root;
        genFrom_ArrayType(node);
    }
    else if (nodeType == "idlist")
    {
        IDList *node = (IDList *)root;
        genFrom_IDList(node);
    }
    else if (nodeType == "funcdecllist")
    {
        FuncDeclList *node = (FuncDeclList *)root;
        genFrom_FuncDeclList(node);
    }
    else if (nodeType == "onefuncdecl")
    {
        OneFuncDecl *node = (OneFuncDecl *)root;
        genFrom_OneFuncDecl(node);
    }
    else if (nodeType == "funchead")
    {
        FuncHead *node = (FuncHead *)root;
        genFrom_FuncHead(node);
    }
    else if (nodeType == "paralist")
    {
        ParaList *node = (ParaList *)root;
        genFrom_ParaList(node);
    }
    else if (nodeType == "funcbody")
    {
        FuncBody *node = (FuncBody *)root;
        genFrom_FuncBody(node);
    }
    else if (nodeType == "execpart")
    {
        ExecPart *node = (ExecPart *)root;
        genFrom_ExecPart(node);
    }
    else if (nodeType == "stmtlist")
    {
        StmtList *node = (StmtList *)root;
        genFrom_StmtList(node);
    }
    else if (nodeType == "assignstmt")
    {
        AssignStmt *node = (AssignStmt *)root;
        genFrom_AssignStmt(node);
    }
    else if (nodeType == "forstmt")
    {
        ForStmt *node = (ForStmt *)root;
        genFrom_ForStmt(node);
    }
    else if (nodeType == "funccallstmt")
    {
        FuncCallStmt *node = (FuncCallStmt *)root;
        genFrom_FuncCallStmt(node);
    }
    else if (nodeType == "repeatstmt")
    {
        RepeatStmt *node = (RepeatStmt *)root;
        genFrom_RepeatStmt(node);
    }
    else if (nodeType == "whilestmt")
    {
        WhileStmt *node = (WhileStmt *)root;
        genFrom_WhileStmt(node);
    }
    else if (nodeType == "elsestmt")
    {
        ElseStmt *node = (ElseStmt *)root;
        if(node->getStmtListNode() != NULL)
            genFrom_ElseStmt(node);
    }
    else if (nodeType == "ifstmt")
    {
        IfStmt *node = (IfStmt *)root;
        genFrom_IfStmt(node);
    }
    else if (nodeType == "breakstmt")
    {
        BreakStmt *node = (BreakStmt *)root;
        genFrom_BreakStmt(node);
    }
}

string Dict::getJSONString()
{
    if (valType == "str")
    {
        return "{ \"" + key + "\" : \"" + this->strValue + "\" }";
    }
    else
    {
        string dictStr = "{ \"" + key + "\" : [";
        for (int i = 0; i < dictValue.size(); i++)
        {
            if (i != 0)
                dictStr += ", ";
            dictStr += dictValue[i]->getJSONString();
        }

        return dictStr + "] }";
    }
}

void Dict::writeJSONFile(string filepath)
{
    ofstream jsonFile;
    jsonFile.open(filepath, ios_base::out | ios_base::trunc);
    jsonFile << this->getJSONString();
    jsonFile.close();
}

void Dict::addOneDictValue(Dict *value)
{
    this->dictValue.push_back(value);
}

void Dict::genFrom_Program(Program *node)
{ // ProgHead + DeclPart + ExecPart
    this->key = "Program";
    this->valType = "dict";
    Dict *ProgHeadDict = new Dict(node->getProgHeadNode());
    Dict *DeclPartDict = new Dict(node->getDeclPartNode());
    Dict *ExecPartDict = new Dict(node->getExecPartNode());
    addOneDictValue(ProgHeadDict);
    addOneDictValue(DeclPartDict);
    addOneDictValue(ExecPartDict);
}

void Dict::genFrom_ProgHead(ProgHead *node)
{ // leaf
    this->key = "ProgHead";
    this->valType = "str";
    this->strValue = node->getProgName();
}

void Dict::genFrom_DeclPart(DeclPart *node)
{ // VarDeclList + FuncDeclList
    this->key = "DeclPart";
    this->valType = "dict";
    Dict *VarDeclListDict = new Dict(node->getVarListNode());
    Dict *FuncDeclListDict = new Dict(node->getFuncPartNode());
    addOneDictValue(VarDeclListDict);
    addOneDictValue(FuncDeclListDict);
}

void Dict::genFrom_VarDeclList(VarDeclList *node)
{ // VarDecl ...
    this->key = "VarDeclList";
    this->valType = "dict";
    vector<VarDecl *> list = node->getList();
    for (int i = 0; i < list.size(); i++)
    {
        Dict *VarDeclDict = new Dict(list[i]);
        addOneDictValue(VarDeclDict);
    }
}

void Dict::genFrom_VarDecl(VarDecl *node)
{ // MyType + IDlist
    this->key = "VarDecl";
    this->valType = "dict";
    string typeName;
    MyType *type = node->getTypeNode();
    Dict *TypeDict;
    if (type->getClass() == "simpletype")
    {
        SimpleType *simpleType = (SimpleType *)type;
        TypeDict = new Dict(simpleType);
        SimpleType *curtype = (SimpleType *)type;
        typeName = curtype->getSimpleTypeName(); // 获取基本类型
    }
    else
    {
        ArrayType *arrayType = (ArrayType *)type;
        TypeDict = new Dict(arrayType);
        ArrayType *curtype = (ArrayType *)type;
        typeName = curtype->getTypeName(); // 获取基本类型
    }
    Dict *IDlistDict = new Dict(node->getIDListNode());

    addOneDictValue(TypeDict);
    addOneDictValue(IDlistDict);
}

void Dict::genFrom_SimpleType(SimpleType *node)
{ // leaf
    this->key = "SimpleType";
    this->valType = "str";
    this->strValue = node->getSimpleTypeName();
}

void Dict::genFrom_ArrayType(ArrayType *node)
{ // leaf
    this->key = "ArrayType";
    this->valType = "str";
    int start = node->getIndexArrage().first;
    int end = node->getIndexArrage().first;
    string str = "array[" + to_string(start) + ".." + to_string(end) + "] of" + node->getTypeName();
    this->strValue = str;
}

void Dict::genFrom_IDList(IDList *node)
{ // leaf
    this->key = "IDList";
    this->valType = "str";
    vector<string> idList = node->getList();
    string str;
    for (int i = 0; i < idList.size(); i++)
    {
        if (i != 0)
            str += ",";
        str += idList[i];
    }
    this->strValue = str;
}

void Dict::genFrom_FuncDeclList(FuncDeclList *node)
{ // OneFuncDecl ...
    this->key = "FuncDeclList";
    this->valType = "dict";
    vector<OneFuncDecl *> funclist = node->getFuncList();
    for (int i = 0; i < funclist.size(); i++)
    {
        Dict *OneFuncDeclDict = new Dict(funclist[i]);
        addOneDictValue(OneFuncDeclDict);
    }
}

void Dict::genFrom_OneFuncDecl(OneFuncDecl *node)
{ // FuncHead + FuncBody
    this->key = "OneFuncDecl";
    this->valType = "dict";
    Dict *FuncHeadDict = new Dict(node->getFuncDeclNode());
    Dict *FuncBodyDict = new Dict(node->getFuncBodyNode());
    addOneDictValue(FuncHeadDict);
    addOneDictValue(FuncBodyDict);
}

void Dict::genFrom_FuncHead(FuncHead *node)
{ // MyType + Paralist
    this->key = "FuncHead";
    this->valType = "dict";
    MyType *type = node->getRetType();
    Dict *varDict = new Dict("FuncName", node->getFuncName());
    Dict *ParaListDict = new Dict(node->getParaList());
    Dict *TypeDict;
    if (type->getClass() == "simpletype")
    {
        SimpleType *simpleType = (SimpleType *)type;
        TypeDict = new Dict(simpleType);
    }
    else
    {
        ArrayType *arrayType = (ArrayType *)type;
        TypeDict = new Dict(arrayType);
    }
    addOneDictValue(varDict);
    addOneDictValue(TypeDict);
    addOneDictValue(ParaListDict);
}

void Dict::genFrom_ParaList(ParaList *node)
{ // VarDecl ...
    this->key = "ParaList";
    this->valType = "dict";

    vector<VarDecl *> paraList = node->getParaList();
    for (int i = 0; i < paraList.size(); i++)
    {
        Dict *ParaDict = new Dict(paraList[i]);
        addOneDictValue(ParaDict);
    }
}

void Dict::genFrom_FuncBody(FuncBody *node)
{ // DeclPart + ExecPart
    this->key = "FuncBody";
    this->valType = "dict";

    Dict *DeclPartDict = new Dict(node->getDeclPartNode());
    Dict *ExecPartDict = new Dict(node->getExecPartNode());
    addOneDictValue(DeclPartDict);
    addOneDictValue(ExecPartDict);
}

void Dict::genFrom_ExecPart(ExecPart *node)
{ // StmtList
    this->key = "ExecPart";
    this->valType = "dict";

    Dict *StmtListDict = new Dict(node->getStmtListNode());
    addOneDictValue(StmtListDict);
}

void Dict::genFrom_StmtList(StmtList *node)
{ // Stmt ...
    this->key = "StmtList";
    this->valType = "dict";
    vector<Stmt *> list = node->getStmtList();
    for (int i = 0; i < list.size(); i++)
    {
        Dict *StmtDict;
        string stmtType = list[i]->getClass();
        if (stmtType == "assignstmt")
        {
            AssignStmt *stmt = (AssignStmt *)list[i];
            StmtDict = new Dict(stmt);
        }
        else if (stmtType == "forstmt")
        {
            ForStmt *stmt = (ForStmt *)list[i];
            StmtDict = new Dict(stmt);
        }
        else if (stmtType == "funccallstmt")
        {
            FuncCallStmt *stmt = (FuncCallStmt *)list[i];
            StmtDict = new Dict(stmt);
        }
        else if (stmtType == "repeatstmt")
        {
            RepeatStmt *stmt = (RepeatStmt *)list[i];
            StmtDict = new Dict(stmt);
        }
        else if (stmtType == "whilestmt")
        {
            WhileStmt *stmt = (WhileStmt *)list[i];
            StmtDict = new Dict(stmt);
        }
        else if (stmtType == "elsestmt")
        {
            ElseStmt *stmt = (ElseStmt *)list[i];
            StmtDict = new Dict(stmt);
        }
        else if (stmtType == "ifstmt")
        {
            IfStmt *stmt = (IfStmt *)list[i];
            StmtDict = new Dict(stmt);
        }
        else if (stmtType == "breakstmt")
        {
            BreakStmt *stmt = (BreakStmt *)list[i];
            StmtDict = new Dict(stmt);
        }
        addOneDictValue(StmtDict);
    }
}

void Dict::genFrom_AssignStmt(AssignStmt *node)
{ // id(Expr) + rexpr(Expr)
    this->key = "AssignStmt";
    this->valType = "dict";
    Dict *idDict = this->genFrom_Expr(node->getLeftExprNode());
    Dict *rexprDict = this->genFrom_Expr(node->getRightExprNode());
    addOneDictValue(idDict);
    addOneDictValue(rexprDict);
}

void Dict::genFrom_ForStmt(ForStmt *node)
{ // var + startexpr + endexpr + stmtl
    this->key = "ForStmt";
    this->valType = "dict";
    Dict *varDict = new Dict("LoopVar", node->getLoopvarNode());
    Dict *startexprDict = this->genFrom_Expr(node->getStartExprNode());
    Dict *endexprDict = this->genFrom_Expr(node->getEndExprNode());
    Dict *stmtlDict = new Dict(node->getLoopStmtNode());
    addOneDictValue(varDict);
    addOneDictValue(startexprDict);
    addOneDictValue(endexprDict);
    addOneDictValue(stmtlDict);
}

void Dict::genFrom_FuncCallStmt(FuncCallStmt *node)
{ // funcname + el(ExprList)
    this->key = "FuncCallStmt";
    this->valType = "dict";
    Dict *varDict = new Dict("FuncName", node->getFuncName());
    Dict *elDict = new Dict(node->getParaExprListNode());
    addOneDictValue(varDict);
    addOneDictValue(elDict);
}

void Dict::genFrom_RepeatStmt(RepeatStmt *node)
{ // cond(Expr) + sl(StmtList)
    this->key = "RepeatStmt";
    this->valType = "dict";
    Dict *condDict = this->genFrom_Expr(node->getConditionExprNode());
    Dict *slDict = new Dict(node->getLoopStmtNode());
    addOneDictValue(condDict);
    addOneDictValue(slDict);
}

void Dict::genFrom_WhileStmt(WhileStmt *node)
{ // con(Expr) + sl(StmtList)
    this->key = "WhileStmt";
    this->valType = "dict";
    Dict *condDict = this->genFrom_Expr(node->getConditionExprNode());
    Dict *slDict = new Dict(node->getStmtListNode());
    addOneDictValue(condDict);
    addOneDictValue(slDict);
}

void Dict::genFrom_ElseStmt(ElseStmt *node)
{ // list(StmtList)
    this->key = "WhileStmt";
    this->valType = "dict";
    Dict *slDict = new Dict(node->getStmtListNode());
    addOneDictValue(slDict);
}

void Dict::genFrom_IfStmt(IfStmt *node)
{ // con(Expr) + sl(StmtList) + els(ElseStmt)
    this->key = "WhileStmt";
    this->valType = "dict";
    Dict *condDict = this->genFrom_Expr(node->getConditionNode());
    Dict *slDict = new Dict(node->getStmtListNode());
    Dict *elsDict = new Dict(node->getElseStmtNode());
    addOneDictValue(condDict);
    addOneDictValue(slDict);
    addOneDictValue(elsDict);
}

void Dict::genFrom_BreakStmt(BreakStmt *node)
{
    this->key = this->strValue = "BreakStmt";
    this->valType = "str";
}

void Dict::genFrom_ExprList(ExprList *node)
{ // Expr ...
    this->key = "ExprList";
    this->valType = "dict";
    vector<Expr *> exlist = node->getExprList();
    for (int i = 0; i < exlist.size(); i++)
    {
        Dict *exprDict = this->genFrom_Expr(exlist[i]);
        addOneDictValue(exprDict);
    }
}

Dict *Dict::genFrom_Expr(Expr *node)
{ // judge the Expr type
    Dict *ExprDict;
    string ExprType = node->getClass();
    if (ExprType == "binexpr")
    {
        BinExpr *expr = (BinExpr *)node;
        ExprDict = new Dict(expr);
    }
    else if (ExprType == "unaryexpr")
    {
        UnaryExpr *expr = (UnaryExpr *)node;
        ExprDict = new Dict(expr);
    }
    else if (ExprType == "funcallexpr")
    {
        FunCallExpr *expr = (FunCallExpr *)node;
        ExprDict = new Dict(expr);
    }
    else if (ExprType == "arrayexpr")
    {
        ArrayExpr *expr = (ArrayExpr *)node;
        ExprDict = new Dict(expr);
    }
    else if (ExprType == "idexpr")
    {
        IDExpr *expr = (IDExpr *)node;
        ExprDict = new Dict(expr);
    }
    return ExprDict;
}

void Dict::genFrom_BinExpr(BinExpr *node)
{ // op + lhs + rhs
    this->key = "BinExpr";
    this->valType = "dict";
    Dict *opDict = new Dict("op", node->getOp());
    Dict *lhsDict = this->genFrom_Expr(node->getLeftExprNode());
    Dict *rhsDict = this->genFrom_Expr(node->getRightExprNode());
    addOneDictValue(lhsDict);
    addOneDictValue(opDict);
    addOneDictValue(rhsDict);
}

void Dict::genFrom_UnaryExpr(UnaryExpr *node)
{ // op (NOT) + ex
    this->key = "UnaryExpr";
    this->valType = "dict";
    Dict *opDict = new Dict("op", node->getOp());
    Dict *exprDict = this->genFrom_Expr(node->getExprNode());
    addOneDictValue(opDict);
    addOneDictValue(exprDict);
}

void Dict::genFrom_FunCallExpr(FunCallExpr *node)
{ // funcname + ExprList
    this->key = "FunCallExpr";
    this->valType = "dict";
    Dict *funcNameDict = new Dict("FuncName", node->getFuncName());
    Dict *exprListDict = new Dict(node->getExprListNode());
    addOneDictValue(funcNameDict);
    addOneDictValue(exprListDict);
}

void Dict::genFrom_ArrayExpr(ArrayExpr *node)
{ // arrayname + Expr...(index_list)
    this->key = "ArrayExpr";
    this->valType = "dict";
    Dict *arrayNameDict = new Dict("ArrayName", node->getArrayName());
    addOneDictValue(arrayNameDict);
    Expr * index = node->getIndexExprNode();
    Dict *exprDict = this->genFrom_Expr(index);
    addOneDictValue(exprDict);
}

void Dict::genFrom_IDExpr(IDExpr *node)
{ // leaf
    this->key = "IDExpr";
    this->valType = "dict";
    if (node->getType() == "var")
    {
        Dict *varNameDict = new Dict("VarName", node->getVarName());
        addOneDictValue(varNameDict);
    }
    else
    {
        string ImmType = node->getImmType();
        Dict *immDict;
        if (ImmType == "integer")
        {
            immDict = new Dict("IntValue", to_string(node->getIntValue()));
        }
        else if (ImmType == "longint")
        {
            immDict = new Dict("LongIntValue", to_string(node->getLongIntValue()));
        }
        else if (ImmType == "float")
        {
            immDict = new Dict("FloatValue", to_string(node->getFloatValue()));
        }
        else if (ImmType == "string")
        {
            immDict = new Dict("StringValue", node->getStringValue());
        }
        else if (ImmType == "boolean")
        {
            immDict = new Dict("BooleanValue", to_string(node->getBooleanValue()));
        }
        addOneDictValue(immDict);
    }
}