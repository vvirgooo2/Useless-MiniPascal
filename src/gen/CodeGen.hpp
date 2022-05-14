#pragma once
#include <string>
#include <vector>
#include <stack>
#include <map>
#include "/usr/include/llvm-6.0/llvm/IR/Module.h"
#include <llvm/IR/Function.h>
#include <llvm/IR/DerivedTypes.h>
#include <llvm/IR/LLVMContext.h>
#include <llvm/IR/PassManager.h>
#include <llvm/IR/IRBuilder.h>
#include <llvm/IR/Instructions.h>
#include <llvm/IR/CallingConv.h>
#include <llvm/ExecutionEngine/GenericValue.h>
#include <llvm/Support/raw_ostream.h>
#include <llvm/IR/BasicBlock.h>
#include <llvm/IR/BasicBlock.h>
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
};

class CodeGenContext{
private:
    std::vector<CodeGenBlock *> blocks;
    //主函数
    llvm::Function *mainFunction;
    llvm::LLVMContext globalcontext;
public:
    bool isGlobal=true;
    llvm::Module *module;
    llvm::IRBuilder<> builder;
    CodeGenContext():builder(globalcontext){
        this->module = new llvm::Module("main",globalcontext);
    }
    void generate(BaseNode* root);
    llvm::GenericValue runCode();
    std::map<std::string,llvm::Value*>& locals(){
        return blocks.back()->locals;
    }
    llvm::BasicBlock* currentBlock(){
        return blocks.back()->block;
    }
    void pushBlock(llvm::BasicBlock *block){
        blocks.push_back(new CodeGenBlock());
        blocks.back()->block = block;
    }
    void popBLock(){
        CodeGenBlock *top=blocks.back();
        blocks.pop_back();
        delete top;
    }
};