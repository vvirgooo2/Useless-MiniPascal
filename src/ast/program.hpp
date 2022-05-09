#ifndef PROGRAM_HPP_
#define PROGRAM_HPP_

#include "base.hpp"
#include <iostream>
#include <string>

using namespace std;
//防止麻烦，一律public属性

//全局根节点
class Program: public BaseNode{
public:
    BaseNode* declpart,exepart;
    Program(){
        this.id="program";
        declpart = nullptr;
        exepart = nullptr;
    }
}

//定义段
class DeclPart: public BaseNode{
public:
    BaseNode* valpart,funcpart;
    DeclPart(){
        this.id="declpart";
        valpart = nullptr;
        funcpart = nullptr;
    }
}

//全局变量定义
class ValPart: public BaseNode{
public:
    ValPart(){
        this.id="valpart";
    }
}

//函数定义段
class FuncPart: public BaseNode{
public:
    FuncPart(){
        this.id="funcpart";
    }
}

//全局执行段
class ExePart : public BaseNode{
public:
    ExePart(){
        this.id="exepart";
    }
}