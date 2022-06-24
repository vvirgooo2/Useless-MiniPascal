#pragma once
#include <string>
#include <vector>
#include <stack>
#include <map>
#include "/usr/include/llvm-6.0/llvm/IR/Module.h"
#include <llvm/ADT/STLExtras.h>
#include <llvm/IR/Function.h>
#include <llvm/IR/Type.h>
#include <llvm/IR/DerivedTypes.h>
#include <llvm/IR/LLVMContext.h>
#include <llvm/IR/LegacyPassManager.h>
#include <llvm/IR/PassManager.h>
#include <llvm/IR/CallingConv.h>
#include <llvm/IR/IRBuilder.h>
#include <llvm/IR/Instructions.h>
#include <llvm/IR/CallingConv.h>
#include <llvm/IR/IRPrintingPasses.h>
#include <llvm/ExecutionEngine/GenericValue.h>
#include <llvm/Support/raw_ostream.h>
#include <llvm/IR/BasicBlock.h>
#include <llvm/Bitcode/BitcodeReader.h>
#include <llvm/Bitcode/BitcodeWriter.h>
#include <llvm/IR/BasicBlock.h>
#include <llvm/Support/TargetSelect.h>
#include <llvm/ExecutionEngine/GenericValue.h>
#include <llvm/Support/raw_ostream.h>
#include <llvm/IR/ValueSymbolTable.h>

#include <memory>
#include "../ast/AST_node.h"
using namespace std;
class Program;
class BaseNode;
class CodeGenBlock;
class genContext;
//loop stack 存嵌套循环
class CodeGenBlock{
public:
    //一个IR单元
    llvm::BasicBlock* block;
    llvm::BasicBlock* Breakto=NULL;
    llvm::BasicBlock* Continto=NULL;
};

class genContext{
private:
    std::map<std::string,pair<int,int>> arrayrecord;
    std::map<std::string,llvm::Function*> funcrecord;
public:
    bool isGlobal=true;
    bool genpointer=false;
    bool breakif=false;
    bool continif=false;
    llvm::Module *module;
    llvm::IRBuilder<> builder;
    llvm::Function *mainFunction;
    llvm::LLVMContext globalcontext;
    llvm::Function *curfunction;
    std::vector<llvm::Function*> FuncStack;
    std::vector<CodeGenBlock *> BlockStack;
    //system function
    llvm::Function *printf_func;
    llvm::Function *scanf_func;

    genContext():builder(globalcontext){
        this->module = new llvm::Module("main",globalcontext);
        regis();
    }
    void generate(BaseNode* root);
    void regis();
    CodeGenBlock* getTopBlock(){
        return BlockStack.back();
    }

    void pushCodeGenBlock(CodeGenBlock* block){
        BlockStack.push_back(block);
    }

    void pushBlock(llvm::BasicBlock *block,llvm::BasicBlock* breakto = NULL,llvm::BasicBlock* cont = NULL){
        BlockStack.push_back(new CodeGenBlock());
        BlockStack.back()->block = block;
        BlockStack.back()->Breakto = breakto;
        BlockStack.back()->Continto = cont;
    }

    void popBLock(){
        CodeGenBlock *top=BlockStack.back();
        BlockStack.pop_back();
        delete top;
    }

    llvm::Value* getValue(string name){
        
        //返回值和参数可以存成局部的
        if(curfunction->getValueSymbolTable()->lookup(name)){
            cout<<"get: "<<name<<endl;
            return curfunction->getValueSymbolTable()->lookup(name);
        }

        string path = getpath();
        string fullname;

        while(path!=""){
            fullname = path +name;
            cout<<"get: "<<fullname<<endl;
            if(module->getGlobalVariable(fullname)){
                return module->getGlobalVariable(fullname);
            }
            path = path.substr(0,path.length()-1);
            int pos = path.rfind("/");
            if(pos==-1) break;
            path = path.substr(0,pos+1); 
        }

        throw std::runtime_error("Undeclared Variable: "+name);
    }

    void setArrayRecord(string name, int s, int e){
        this->arrayrecord[name]=make_pair(s,e);
    }

    std::pair<int,int> getArrayRecord(string name){
        string path = getpath();
        string fullname;

        while(path!=""){
            fullname = path +name;
            cout<<"get: "<<fullname<<endl;
            if(arrayrecord.find(fullname)!=arrayrecord.end()){
                return arrayrecord[fullname];
            }
            path = path.substr(0,path.length()-1);
            int pos = path.rfind("/");
            if(pos==-1) break;
            path = path.substr(0,pos+1); 
        }
        throw std::runtime_error("ArrayRecord not found: "+name);
    }

    void ReplaceTopBlock(llvm::BasicBlock *next){
        auto oldtop = getTopBlock();
        auto nextBlock = new CodeGenBlock();
        nextBlock->block = next;
        nextBlock->Breakto=oldtop->Breakto;
        nextBlock->Continto=oldtop->Continto;
        popBLock();
        pushCodeGenBlock(nextBlock);
    }

    string getpath(){
        string path="";
        for(auto i: FuncStack){
            path += i->getName();
            path += "/";
        }
        return path;
    }

    llvm::Function* getFunction(string name){
        
        string path = getpath();
        cout<<"getchild Func: "<<path+name<<endl;
        if(funcrecord.find(path+name)!=funcrecord.end()){
            
            return funcrecord[path+name];
        }
        path = path.substr(0,path.length()-1);
        int pos = path.rfind("/");
        if(pos==-1) throw std::runtime_error("Function not found: "+name);
        path = path.substr(0,pos+1); 
        cout<<"getpara Func: "<<path+name<<endl;
        if(funcrecord.find(path+name)!=funcrecord.end()){
            return funcrecord[path+name];
        }

        throw std::runtime_error("Function not found: "+name);
    }

    void setfuncrecord(string name, llvm::Function* func){
        string path = getpath();
        cout<<"setFunc: "<<path+name<<endl;
        this->funcrecord[path+name]=func;
    }

    
};

