#pragma once
#include<string>
#include"base.hpp"

using namespace std;
//广义value
class Value :public  BaseNode{
    Value():BaseNode("value"){
  
    }
};

//变量定义的list
class ValDeclList:public BaseNode{
    public:
    ValDeclList():BaseNode("valdecllist"){

    }
};

//每一个decl
class ValDecl:public BaseNode{
    public:
    ValDecl():BaseNode("valdecl"){

    }
};

//idlist 变量名的列表
class IdList:public BaseNode{
    public:
    IdList():BaseNode("idlist"){

    }
};

//每个变量的node
class Id: public BaseNode{
    public:
    Id():BaseNode("id"){

    }
};