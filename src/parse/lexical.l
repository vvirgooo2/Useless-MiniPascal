%option noyywrap yylineno caseless
%{
#include <string>
#include <string.h>
#include <iostream>
#include <stdio.h>
#include "../ast/AST_node.h"
#include "yacc.hpp"
#define YY_USER_ACTION yylloc.first_line = yylineno;
using namespace std;
void yyerror(char* s);
%}
%option noyywrap

digit [0-9]
letter [a-zA-Z]
string \"[^"]*\"
char \'.\'
id ({letter}|_)+({letter}|_|{digit})*

%%
"integer" { return TYPE_INT; printf("integer");}
"real" { return TYPE_FLOAT_8;}
"char" { return TYPE_CHAR;}
"string" { return TYPE_STRING;}

"not" { return NOT;}
"+" { return ADD;}
[-] { return SUB;}
"*" { return MUL;}
"/" { return DIV;}
"mod" { return MOD;}
"div" { return IDIV;}
"=" { return EQ;}
">" { return GRE;}
"<" { return LES;}
">=" { return GREQ;}
"<=" { return LESQ;}
"<>" { return NE;}
"or" { return OR;}
"and" { return AND;}
":=" { return ASSIGN;}
".." { return ARANGE;}
"[" { return LBR;}
"]" { return RBR;}
"(" { return LPR;}
")" { return RPR;}
"." { return DOT;}
"," { return COM;}
":" { return COL;}
";" { return SEMI;}
"^" { return CARET;}

"array" { return ARRAY;}
"begin" { return BEGN;}
"break" { return BREAK;}
"case" { return CASE;}
"const" { return CONST;}
"to" { return TO;}
"do" { return DO;}
"else" { return ELSE;}
"end" { return END;}
"for" { return FOR;}
"function" { return FUNC;}
"if" { return IF;}
"of" { return OF;}
"procedure" { return PROC;}
"program" { return PROG;}
"repeat" { return REPEAT;}
"then" { return THEN;}
"until" { return UNTIL;}
"var" { return VAR;}
"while" { return WHILE;}



[0-9]{digit}* {
    yylval.type_int = atoi(yytext);   
    return INT;
}

-?(0|int)[.]{digit}+ {
    yylval.type_float = atof(yytext);
    return FLOAT;
}

{string} {
    char s[30] = {0};
    for(int i=0;i<strlen(yytext)-2;i++){
        s[i] = yytext[i+1];
    }
    yylval.type_string = s;
    return STRING;
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
     
    return CHAR;
}

{id} {
    yylval.id = strdup(yytext);
     
    return ID;
}
" " {}
\n|\r\n {}
. { 
    char s[100] = "wrong syntax";
    yyerror(s); 
  }

%%
void yyerror(char *s) {
  printf("%s at line %d\n", s,yylineno);
}

