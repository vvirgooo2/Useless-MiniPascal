#pragma once
#include<string>
#include"base.hpp"
#include<vector>
#include"expr.hpp"
using namespace std;
class VarDecl;
class Type;
class SimpleType;
class ArrayType;
class IDList;
class ParaList;

//变量定义的list
class VarDeclList:public BaseNode{
private:
    vector<VarDecl*> list;
public:
    VarDeclList():BaseNode("vardecllist"){  }
    void PushVarDecl(VarDecl* v){ list.push_back(v); }
    vector<VarDecl*>& getList(){ return this->list; }
};

//每一个decl
class VarDecl:public BaseNode{
private:
    Type* type;
    IDList* list;
public:
    IDExpr* initial;
    VarDecl(Type* t, IDList* l):BaseNode("vardecl"),type(t),list(l){ }
    Type* getTypeNode(){ return this->type; }
    IDList* getIDListNode(){ return this->list; }
};

//idlist 变量名的列表
class IDList:public BaseNode{
private:
    vector<string> list;
public:
    IDList():BaseNode("idlist"){ }
    IDList(string id):BaseNode("idlist"){ list.push_back(id); }
    void PushId(string id){ (this->list).push_back(id);}
    vector<string> &getList(){ return this->list; }
};

class Type : public BaseNode{
public:
    Type(string t):BaseNode(t){ }
};

class SimpleType: public Type{
private:
    string tyname; //string, integer, float, boolean 等存完整名字即可
public:
    SimpleType(string tn):Type("simpletype"),tyname(tn){}
    string getSimpleTypeName(){ return this->tyname; }
};

class ArrayType: public Type{
private:
    string tyname;
    int dim;
    vector<pair<int,int>> index_arrange; //start end，对应维度
public:
    ArrayType(string n):Type("arraytype"),dim(0){ }
    int getDim(){ return this->dim; }
    vector<pair<int,int>> getIndexArrange(){ return this->index_arrange; }
    void pushNewDim(int s, int e){
        index_arrange.push_back(make_pair(s,e));
        dim++;
    }
};

//参数表
class ParaList: public BaseNode{
private:
    vector<pair<Type*, string>> pa;
public:
    ParaList():BaseNode("paralist"){ }
    void pushNewPara(Type* t, string i){ pa.push_back(pair<Type*,string>(t,i)); }
    vector<pair<Type*, string>> getParaList(){ return this->pa; }
};