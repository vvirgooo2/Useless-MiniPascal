#pragma once

#include<iostream>
#include<string>
#include<algorithm>
#include<vector>

using namespace std;
class BaseNode;
 
class BaseNode{    
private:
    //ClassName
    string classname="base";
public: 
    BaseNode(string name){
        this->classname = name;
    }
    string getClass() const{
        return this->classname;
    }
};
