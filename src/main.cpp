#include "main.h"
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <unistd.h>
#include <fcntl.h>
#include "./astVisualize/dict.hpp"
#include "./gen/CodeGen.hpp"
Program* ast_root;
extern FILE* yyin;

int main(int argc,char *argv[]){
    yyin = fopen(argv[1], "r");
    yyparse();
    // Dict *astDict = new Dict(ast_root);
    // astDict->writeJSONFile("./astVisualize/test.json");
    CodeGenContext* context = new CodeGenContext();
    try{
        context->generate(ast_root);
        int fd = open("result.ll", O_CREAT | O_WRONLY, 0644);
        dup2(fd, 1);
        close(fd);
        context->module->print(llvm::outs(),nullptr);
    }
    catch (std::runtime_error &error){
        cout << "[Error] " << error.what() << endl;
    }
    return 0;
}