#pragma once
#include "base.hpp"
#include <iostream>
#include <string>
#include <memory>
using namespace std;
//防止麻烦，一律public属性

//全局根节点
class Program: public BaseNode{
public:
    Routine *routine = NULL;
    Program():BaseNode("program"){
        
    }
};

//子程序段
class Routine: public BaseNode{
    public:
    Routine():BaseNode("routine"){
        
    }
};


//定义段
class DeclPart: public BaseNode{
public:
    // shared_ptr<BaseNode> valpart=make_shared<BaseNode>();
    // shared_ptr<BaseNode> funcpart=make_shared<BaseNode>();
    DeclPart():BaseNode("declpart"){
        
    }
};

//全局变量定义
class ValPart: public BaseNode{
public:
    ValPart():BaseNode("valpart"){

    }
};

//函数定义段
class FuncPart: public BaseNode{
public:
    FuncPart():BaseNode("funcpart"){
        
    }
};

//全局执行段
class ExePart : public BaseNode{
public:
    ExePart():BaseNode("exepart"){
        
    }
};