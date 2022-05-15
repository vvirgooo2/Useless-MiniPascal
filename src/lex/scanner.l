%{
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "../parser.hpp"
void yyerror(char*);
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
/* type */
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

/* op */
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

/* saved words */
"array" {return ARRAY;}
"begin" {return BEGIN;}
"break" {return BREAK;}
"case" {return CASE;}
"const" {return CONST;}
"to" {return TO;}
"do" {return DO;}
"else" {return ELSE;}
"end" {return END;}
"file" {return FILE;}
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

/* value */
{int} {
    yylval.ival = atoi(yytext);
    return INT;
}

{float} {
    yylval.fval = atof(yytext);
    return FLOAT;
}

{string} {
    yylval.sval = strdup(yytext);
    return STRING;
}

{char} {
    yylval.cval = yytext[0];
    return CHAR;
}

{id} {
    yylval.id = strdup(yytext);
    return ID;
}

/* error */
. {yyerror("wrong syntax!")}

%%
/* function */
void yyerror(char *s) {
  printf("%s\n", s);
}
