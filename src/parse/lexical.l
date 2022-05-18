%{
#include <string>
#include <iostream>
#include <stdio.h>
#include "y.tab.hpp"
using namespace std;
void yyerror(char* s);
%}
%option noyywrap

digit [0-9]
int -?[0-9]{digit}*
float -?(0|int)[.]{digit}+
letter [a-zA-Z]
string \"[^"]*\"
char \'[.]\'
id ({letter}|_)+({letter}|_|{digit})*

%%
"integer" {return TYPE_INT;}
"short" {return TYPE_INT_8;}
"smallint" {return TYPE_INT_16;}
"longint" {return TYPE_INT_32;}
"int64" {return TYPE_INT_64;}
"byte" {return TYPE_BYTE;}
"word" {return TYPE_WORD;}

"real" {return TYPE_FLOAT_8;}
"single" {return TYPE_FLOAT_16;}
"double" {return TYPE_FLOAT_32;}

"boolean" {return TYPE_BOOL;}
"char" {return TYPE_CHAR;}
"string" {return TYPE_STRING;}

"not" {return NOT;}
"+" {return ADD;}
"-" {return SUB;}
"*" {return MUL;}
"/" {return DIV;}
"mod" {return MOD;}
"div" {return IDIV;}
"=" {return EQ;}
">" {return GRE;}
"<" {return LES;}
">=" {return GREQ;}
"<=" {return LESQ;}
"<>" {return NE;}
"or" {return OR;}
"and" {return AND;}
":=" {return ASSIGN;}
".." {return ARANGE;}
"[" {return LBR;}
"]" {return RBR;}
"(" {return LPR;}
")" {return RPR;}
"." {return PERIOD;}
"," {return COM;}
":" {return COL;}
";" {return SEMI;}
"^" {return CARET;}
"true" {return TRUE;}
"false" {return false;}

"array" {return ARRAY;}
"begin" {return BEGN;}
"break" {return BREAK;}
"case" {return CASE;}
"const" {return CONST;}
"to" {return TO;}
"do" {return DO;}
"else" {return ELSE;}
"end" {return END;}
"for" {return FOR;}
"function" {return FUNC;}
"if" {return IF;}
"of" {return OF;}
"procedure" {return PROC;}
"program" {return PROG;}
"repeat" {return REPEAT;}
"read" {return READ;}
"readln" {return READLN;}
"then" {return THEN;}
"until" {return UNTIL;}
"var" {return VAR;}
"while" {return WHILE;}
"write" {return WRITE;}
"Writeln" {return WRITELN;}

{int} {
    yylval.type_int = atoi(yytext);
    return INT;
}

{float} {
    yylval.type_float = atof(yytext);
    return FLOAT;
}

{string} {
    yylval.type_string = strdup(yytext);
    return STRING;
}

{char} {
    yylval.type_char = yytext[0];
    return CHAR;
}

{id} {
    yylval.id = strdup(yytext);
    return ID;
}

. {printf("wrong syntax!");}

%%
void yyerror(char *s) {
  printf("%s\n", s);
}

