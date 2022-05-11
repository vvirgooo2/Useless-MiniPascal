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
class ID;
class IDList;
class ParaList;

//变量定义的list
class VarDeclList:public BaseNode{
private:
    vector<VarDecl*> list;
public:
    VarDeclList():BaseNode("vardecllist"){
        
    }
    void PushVarDecl(VarDecl* v){
        list.push_back(v);
    }
    vector<VarDecl*>& getList(){
        return this->list;
    }
};

//每一个decl
class VarDecl:public BaseNode{
private:
    Type* type;
    IDList* list;

public:
    IDExpr* initial;
    VarDecl(Type* t, IDList* l):BaseNode("vardecl"){
        this->type = t;
        this->list= l ;
    }
    Type* getTypeNode(){
        return this->type;
    }
    IDList* getIDListNode(){
        return this->list;
    }
};

//idlist 变量名的列表
class IDList:public BaseNode{
private:
    vector<ID*> list;

public:
    IDList():BaseNode("idlist"){

    }
    void PushId(ID* id){
        (this->list).push_back(id);
    }
    vector<ID*> getList(){
        return this->list;
    }
};

//每个变量名的node
class ID: public BaseNode{
private:
    string name;
public:
    ID(string varname):BaseNode("id"){
        this->name=varname;
    }
    string getName(){
        return this->name;
    }
};


class Type : public BaseNode{
public:
    Type(string t):BaseNode(t){
        
    }
};

class SimpleType: public Type{
private:
    string tyname;
    //string, integer, float, boolean 等存完整名字即可
public:
    SimpleType(string tn):Type("simpletype"){
        this->tyname = tn;
    }
    string getSimpleTypeName(){
        return this->tyname;
    }
};

class ArrayType: public Type{
private:
    string tyname;
    int dim;
    vector<pair<int,int>> index_arrange; //start end，对应维度
public:
    ArrayType(string n):Type("arraytype"),dim(0){

    }
    void pushNewDim(int s, int e){
        index_arrange.push_back(make_pair(s,e));
        dim++;
    }
    int getDim(){
        return this->dim;
    }
    vector<pair<int,int>> getIndexArrange(){
        return this->index_arrange;
    }
};

//参数表
class ParaList: public BaseNode{
private:
    vector<pair<Type*, ID*>> pa;
public:
    ParaList():BaseNode("paralist"){
        
    }
    void pushNewPara(Type* t, ID* i){
        pa.push_back(pair<Type*,ID*>(t,i));
    }
    vector<pair<Type*, ID*>> getParaList(){
        return this->pa;
    }
};