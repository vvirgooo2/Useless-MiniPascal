/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

#ifndef YY_YY_PARSE_YACC_HPP_INCLUDED
# define YY_YY_PARSE_YACC_HPP_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    TYPE_INT = 258,
    TYPE_INT_8 = 259,
    TYPE_INT_16 = 260,
    TYPE = 261,
    TYPE_INT_32 = 262,
    TYPE_INT_64 = 263,
    TYPE_BYTE = 264,
    TYPE_WORD = 265,
    TYPE_FLOAT_8 = 266,
    TYPE_FLOAT_16 = 267,
    TYPE_FLOAT_32 = 268,
    TYPE_BOOL = 269,
    TYPE_CHAR = 270,
    TYPE_STRING = 271,
    NOT = 272,
    ADD = 273,
    SUB = 274,
    MUL = 275,
    DIV = 276,
    MOD = 277,
    IDIV = 278,
    EQ = 279,
    GRE = 280,
    LES = 281,
    GREQ = 282,
    LESQ = 283,
    NE = 284,
    OR = 285,
    AND = 286,
    ASSIGN = 287,
    ARANGE = 288,
    LBR = 289,
    RBR = 290,
    LPR = 291,
    RPR = 292,
    DOT = 293,
    COM = 294,
    COL = 295,
    SEMI = 296,
    CARET = 297,
    ARRAY = 298,
    BEGN = 299,
    BREAK = 300,
    CASE = 301,
    CONST = 302,
    TO = 303,
    DO = 304,
    ELSE = 305,
    END = 306,
    FOR = 307,
    FUNC = 308,
    IF = 309,
    OF = 310,
    PROC = 311,
    PROG = 312,
    REPEAT = 313,
    THEN = 314,
    UNTIL = 315,
    VAR = 316,
    WHILE = 317,
    INT = 318,
    FLOAT = 319,
    CHAR = 320,
    STRING = 321,
    ID = 322
  };
#endif
/* Tokens.  */
#define TYPE_INT 258
#define TYPE_INT_8 259
#define TYPE_INT_16 260
#define TYPE 261
#define TYPE_INT_32 262
#define TYPE_INT_64 263
#define TYPE_BYTE 264
#define TYPE_WORD 265
#define TYPE_FLOAT_8 266
#define TYPE_FLOAT_16 267
#define TYPE_FLOAT_32 268
#define TYPE_BOOL 269
#define TYPE_CHAR 270
#define TYPE_STRING 271
#define NOT 272
#define ADD 273
#define SUB 274
#define MUL 275
#define DIV 276
#define MOD 277
#define IDIV 278
#define EQ 279
#define GRE 280
#define LES 281
#define GREQ 282
#define LESQ 283
#define NE 284
#define OR 285
#define AND 286
#define ASSIGN 287
#define ARANGE 288
#define LBR 289
#define RBR 290
#define LPR 291
#define RPR 292
#define DOT 293
#define COM 294
#define COL 295
#define SEMI 296
#define CARET 297
#define ARRAY 298
#define BEGN 299
#define BREAK 300
#define CASE 301
#define CONST 302
#define TO 303
#define DO 304
#define ELSE 305
#define END 306
#define FOR 307
#define FUNC 308
#define IF 309
#define OF 310
#define PROC 311
#define PROG 312
#define REPEAT 313
#define THEN 314
#define UNTIL 315
#define VAR 316
#define WHILE 317
#define INT 318
#define FLOAT 319
#define CHAR 320
#define STRING 321
#define ID 322

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 14 "./parse/grammar.y" /* yacc.c:1909  */

    int location;
    int type_int;
    float type_float;
    char type_char;
    char* type_string;
    char* id;
    ExprList* expr_list;
    Expr* expr_node;
    IDExpr* id_expr;
    Program* program_node;
    DeclPart* decl_part;
    FuncDeclList* func_list;
    OneFuncDecl* func_node;
    FuncHead* func_head;
    FuncBody* func_body;
    ExecPart* exec_part;
    Stmt* stmt_node;
    StmtList* stmt_list;
    AssignStmt* assign_node;
    ForStmt* for_node;
    FuncCallStmt* call_node;
    RepeatStmt* repeat_node;
    WhileStmt* while_node;
    IfStmt* if_node;
    ElseStmt* else_node;
    BreakStmt* break_node;
    VarDeclList* var_list;
    VarDecl* var_node;
    MyType* type_node;
    SimpleType* simple_type;
    IDList* id_list;
    ArrayType* array_type;
    ParaList* para_node;
    ProgHead* prog_head;
    BinExpr* bin_expr;
    UnaryExpr* un_expr;
    FunCallExpr* funcall_expr;
    ArrayExpr* array_expr;

#line 229 "./parse/yacc.hpp" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif

/* Location type.  */
#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE YYLTYPE;
struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
};
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif


extern YYSTYPE yylval;
extern YYLTYPE yylloc;
int yyparse (void);

#endif /* !YY_YY_PARSE_YACC_HPP_INCLUDED  */
