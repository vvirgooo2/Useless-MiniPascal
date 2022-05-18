%define parse.error verbose
%{
    #include <stdio.h>
    #include <string.h>
    #include <stdio.h>
    #include "../ast/AST_node.h"
    extern int yylex();
    extern FILE* yyin;
    void yyerror(const char* s);
%}

%union{
    int type_int;
    float type_float;
    char type_char;
    char* type_string;
    char* id;
}
// 数据类型定义
%token TYPE_INT TYPE_INT_8 TYPE_INT_16 TYPE TYPE_INT_32 TYPE_INT_64 TYPE_BYTE TYPE_WORD TYPE_FLOAT_8 TYPE_FLOAT_16 TYPE_FLOAT_32 TYPE_BOOL TYPE_CHAR TYPE_STRING
// 符号
%token NOT ADD SUB MUL DIV MOD IDIV EQ GRE LES GREQ LESQ NE OR AND ASSIGN ARANGE LBR RBR LPR RPR PERIOD COM COL SEMI CARET DOT TRUE FALSE SPACE NEWLINE
// 其他保留字
%token ARRAY BEGN BREAK CASE CONST TO DO ELSE END FOR FUNC IF OF PROC PROG REPEAT READ READLN THEN UNTIL VAR WHILE WRITE WRITELN
// 数据常量
%token<type_int> INT 
%token<type_float> FLOAT 
%token<type_char> CHAR
%token<type_string> STRING ID

%%
program :
    | PROG {
        printf("end of file");
    }
    | 
;

%%
void yyerror (char const *s) {
   printf ("%s\n", s);
 }