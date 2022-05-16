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
#include "../ast/AST_node.h"
using namespace std;
class Program;
class BaseNode;
class CodeGenBlock;
class CodeGenContext;
//一个局部环境
class CodeGenBlock{
public:
    //一个IR单元
    llvm::BasicBlock* block;
    //变量池
    std::map<std::string,llvm::Value*> locals;
    llvm::BasicBlock* Breakto=NULL;
};

class CodeGenContext{
private:
    std::vector<CodeGenBlock *> blocks;
    //主函数
    std::map<std::string,pair<int,int>> arrayrecord;
public:
    
    bool isGlobal=true;
    bool genpointer=false;
    llvm::Module *module;
    llvm::IRBuilder<> builder;
    llvm::Function *mainFunction;
    llvm::LLVMContext globalcontext;
    llvm::Function *curfunction;

    //system function
    llvm::Function *printf_func;
    llvm::Function *getchar_func;

    CodeGenContext():builder(globalcontext){
        this->module = new llvm::Module("main",globalcontext);
        this->printf_func = regisprintf();
    }
    void generate(BaseNode* root);
    llvm::GenericValue runCode();
    std::map<std::string,llvm::Value*>& locals(){
        return blocks.back()->locals;
    }
    llvm::BasicBlock* currentBlock(){
        return blocks.back()->block;
    }
    CodeGenBlock* getTopBlock(){
        return blocks.back();
    }
    void pushCodeGenBlock(CodeGenBlock* block){
        blocks.push_back(block);
    }
    void pushBlock(llvm::BasicBlock *block,llvm::BasicBlock* breakto = NULL){
        blocks.push_back(new CodeGenBlock());
        blocks.back()->block = block;
        blocks.back()->Breakto = breakto;
    }
    void popBLock(){
        CodeGenBlock *top=blocks.back();
        blocks.pop_back();
        delete top;
    }
    llvm::Value* getValue(string name){
        llvm::Function *c = this->curfunction;
        if ((c->getValueSymbolTable()->lookup(name)) == NULL){
            if (module->getGlobalVariable(name) == NULL){
                throw std::runtime_error("Undeclared variable: "+name+" in module");
                return NULL;
            }
            return module->getGlobalVariable(name);
        }
        return c->getValueSymbolTable()->lookup(name);
    }
    llvm::Function *regisprintf();
    void setArrayRecord(string name, int s, int e){
        this->arrayrecord[name]=make_pair(s,e);
    }
    pair<int,int> getArrayRecord(string name){
        if(arrayrecord.find(name)!=arrayrecord.end()){
            return arrayrecord[name];
        }
        else throw std::runtime_error("ArrayRecord not found: "+name);
    }
};

