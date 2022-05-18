#include "main.h"
#include <stdio.h>
#include <iostream>
#include "../astVisualize/dict.hpp"

Program* ast_root;
extern FILE* yyin;

int main(){
    char filename1[20] = "quicksort.pas";
    char filename2[20] = "matrixMul.pas";
    yyin = fopen(filename2, "r");
    // char s[100];
    // fscanf(yyin, "%s", s);
    // printf("%s\n",s);
    yyparse();
    Dict *astDict = new Dict(ast_root);
    astDict->writeJSONFile("../astVisualize/test.json");
    return 0;
}