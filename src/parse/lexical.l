%{
#include <string>
#include <string.h>
#include <iostream>
#include <stdio.h>
#include "../ast/AST_node.h"
#include "yacc.hpp"
using namespace std;
void yyerror(char* s);
%}
%option noyywrap
%s STARTCOND

digit [0-9]
letter [a-zA-Z]
string \"[^"]*\"
char \'.\'
id ({letter}|_)+({letter}|_|{digit})*

%%
"integer" { printf("%s\n",yytext);return TYPE_INT; printf("integer");}

"real" { printf("%s\n",yytext);return TYPE_FLOAT_8;}

"char" { printf("%s\n",yytext);return TYPE_CHAR;}

"string" { printf("%s\n",yytext);return TYPE_STRING;}

"not" { printf("%s\n",yytext);return NOT;}
"+" { printf("%s\n",yytext);return ADD;}
[-] { printf("%s\n",yytext);return SUB;}
"*" { printf("%s\n",yytext);return MUL;}
"/" { printf("%s\n",yytext);return DIV;}
"mod" { printf("%s\n",yytext);return MOD;}
"div" { printf("%s\n",yytext);return IDIV;}
"=" { printf("%s\n",yytext);return EQ;}
">" { printf("%s\n",yytext);return GRE;}
"<" { printf("%s\n",yytext);return LES;}
">=" { printf("%s\n",yytext);return GREQ;}
"<=" { printf("%s\n",yytext);return LESQ;}
"<>" { printf("%s\n",yytext);return NE;}
"or" { printf("%s\n",yytext);return OR;}
"and" { printf("%s\n",yytext);return AND;}
":=" { printf("%s\n",yytext);return ASSIGN;}
".." { printf("%s\n",yytext);return ARANGE;}
"[" { printf("%s\n",yytext);return LBR;}
"]" { printf("%s\n",yytext);return RBR;}
"(" { printf("%s\n",yytext);return LPR;}
")" { printf("%s\n",yytext);return RPR;}
"." { printf("%s\n",yytext);return DOT;}
"," { printf("%s\n",yytext);return COM;}
":" { printf("%s\n",yytext);return COL;}
";" { printf("%s\n",yytext);return SEMI;}
"^" { printf("%s\n",yytext);return CARET;}
"\n" {}

"array" { printf("%s\n",yytext);return ARRAY;}
"begin" { printf("%s\n",yytext);return BEGN;}
"break" { printf("%s\n",yytext);return BREAK;}
"case" { printf("%s\n",yytext);return CASE;}
"const" { printf("%s\n",yytext);return CONST;}
"to" { printf("%s\n",yytext);return TO;}
"do" { printf("%s\n",yytext);return DO;}
"else" { printf("%s\n",yytext);return ELSE;}
"end" { printf("%s\n",yytext);return END;}
"for" { printf("%s\n",yytext);return FOR;}
"function" { printf("%s\n",yytext);return FUNC;}
"if" { printf("%s\n",yytext);return IF;}
"of" { printf("%s\n",yytext);return OF;}
"procedure" { printf("%s\n",yytext);return PROC;}
"program" { printf("%s\n",yytext);return PROG;}
"repeat" { printf("%s\n",yytext);return REPEAT;}
"then" { printf("%s\n",yytext);return THEN;}
"until" { printf("%s\n",yytext);return UNTIL;}
"var" { printf("%s\n",yytext);return VAR;}
"while" { printf("%s\n",yytext);return WHILE;}



[0-9]{digit}* {
    yylval.type_int = atoi(yytext);
     
    printf("%s\n",yytext);return INT;
}

-?(0|int)[.]{digit}+ {
    yylval.type_float = atof(yytext);
     
    printf("%s\n",yytext);return FLOAT;
}

{string} {
    char s[30] = {0};
    for(int i=0;i<strlen(yytext)-2;i++){
        s[i] = yytext[i+1];
    }
    yylval.type_string = s;
     
    printf("%s\n",yytext);return STRING;
}
"'\\n'" {
    yylval.type_char = 10;
    return CHAR;
}

"'\\0" {
    yylval.type_char = 0;
    return CHAR;
}
{char} {
    yylval.type_char = yytext[1];
     
    printf("%s\n",yytext);return CHAR;
}

{id} {
    yylval.id = strdup(yytext);
     
    printf("%s\n",yytext);return ID;
}

. { }

%%
void yyerror(char *s) {
  printf("%s\n", s);
}

