%define parse.error verbose
%{
    #include <stdio.h>
    #include <string.h>
    #include "../ast/AST_node.h"
    #include "main.h"
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
}
// 数据类型定义
%token TYPE_INT TYPE_INT_8 TYPE_INT_16 TYPE TYPE_INT_32 TYPE_INT_64 TYPE_BYTE TYPE_WORD TYPE_FLOAT_8 TYPE_FLOAT_16 TYPE_FLOAT_32 TYPE_BOOL TYPE_CHAR TYPE_STRING
// 符号
%token NOT ADD SUB MUL DIV MOD IDIV EQ GRE LES GREQ LESQ NE OR AND ASSIGN ARANGE LBR RBR LPR RPR DOT COM COL SEMI CARET
// 其他保留字
%token ARRAY BEGN BREAK CASE CONST TO DO ELSE END FOR FUNC IF OF PROC PROG REPEAT THEN UNTIL VAR WHILE
// 数据常量
%token<type_int> INT 
%token<type_float> FLOAT 
%token<type_char> CHAR
%token<type_string> STRING ID
// 结点
%type<expr_list> expr_list;
%type<expr_node> expr_node;
%type<id_expr> id_expr;
%type<program_node> program_node;
%type<decl_part> decl_part;
%type<func_list> func_list;
%type<func_node> func_node;
%type<func_head> func_head;
%type<func_body> func_body;
%type<exec_part> exec_part;
%type<stmt_node> stmt_node;
%type<stmt_list> stmt_list;
%type<assign_node> assign_node;
%type<for_node> for_node;
%type<call_node> call_node;
%type<repeat_node> repeat_node;
%type<while_node> while_node;
%type<if_node> if_node;
%type<else_node> else_node;
%type<break_node> break_node;
%type<var_list> var_list;
%type<var_node> var_node;
%type<simple_type> simple_type;
%type<id_list> id_list;
%type<para_node> para_node;
%type<prog_head> prog_head;
%type<expr_node> first_bin_expr;
%type<expr_node> second_bin_expr;
%type<expr_node> third_bin_expr;
%type<array_expr> array_expr;

%%
program:
    program program_node
    | 
    ;

program_node:
    prog_head decl_part exec_part DOT { 
        ast_root = new Program($1, $2, $3); 
    }
;

prog_head:
    PROG ID SEMI { $$ = new ProgHead($2); }
;

decl_part:
    VAR var_list func_list { 
        $$ = new DeclPart($2, $3); 
    }
    |
    { $$ = new DeclPart(); }
;

var_list:
    var_list var_node SEMI
{ $$ = $1;
  $$->pushVarDecl($2); }
    | 
{ $$ = new VarDeclList(); }
;

var_node:
    id_list COL simple_type{
        $$ = new VarDecl($3, $1); 
    }
    | id_list COL ARRAY LBR INT ARANGE INT RBR OF simple_type{
        ArrayType* ary = new ArrayType($5, $7, $10->getSimpleTypeName()); 
        $$ = new VarDecl(ary, $1);
    }
;

simple_type:
    TYPE_INT
{ $$ = new SimpleType("integer"); }
    | TYPE_FLOAT_8
{ $$ = new SimpleType("real"); }
    | TYPE_FLOAT_32
{ $$ = new SimpleType("double"); }
    | TYPE_CHAR
{ $$ = new SimpleType("char"); }
    | TYPE_STRING
{ $$ = new SimpleType("string"); }
;

id_list:
    id_list COM ID
{ $$ = $1;
  $$->pushID((string)$3); }
    | ID
{ $$ = new IDList(); 
  $$->pushID((string)$1); }
;

func_list:
    func_list func_node
{ $$ = $1;
  $$->pushOneFuncDecl($2); }
    | 
{ $$ = new FuncDeclList(); }
;

func_node:
    func_head SEMI func_body SEMI
{ $$ = new OneFuncDecl($1, $3); }
;

func_head:
    FUNC ID LPR para_node RPR COL simple_type { 
        $$ = new FuncHead((string)$2, $7, $4); 
    }
;

para_node:
    para_node COM var_node
{ $$ = $1;
  $$->pushNewPara($3); }
    | var_node
{ $$ = new ParaList($1); }
;

func_body:
    var_list exec_part {
        $$ = new FuncBody($1, $2); 
    }
;

exec_part:
    BEGN stmt_list END { 
        $$ = new ExecPart($2);
    }
;

stmt_list:
    stmt_list stmt_node { 
        $$ = $1;
        $$->pushStmt($2); 
    }
    | stmt_node
{ $$ = new StmtList($1); }
;

stmt_node:
    assign_node
{ $$ = $1; }
    | for_node
{ $$ = $1; }
    | call_node
{ $$ = $1; }
    | repeat_node
{ $$ = $1; }
    | break_node
{ $$ = $1; }
    | while_node
{ $$ = $1; }
    | if_node
{ $$ = $1; }
;

assign_node:
    ID ASSIGN expr_node SEMI
{ IDExpr* id = new IDExpr("var", (string)$1); 
  $$ = new AssignStmt(id, $3); }
    | array_expr ASSIGN expr_node SEMI
{ $$ = new AssignStmt($1, $3); }
;

expr_list:
    expr_list COM expr_node
{ $$ = $1;
  $$->pushExprNode($3); }
    | expr_node
{ $$ = new ExprList($1); }
;

id_expr:
    ID
{ $$ = new IDExpr("var", (string)$1); }
    | INT
{ $$ = new IDExpr("int", $1); }
    | CHAR
{ $$ = new IDExpr("char", $1); }
    | FLOAT
{ $$ = new IDExpr("float", $1); }
    | STRING
{ $$ = new IDExpr("string", $1); }
;

expr_node:
    expr_node GRE first_bin_expr
{ $$ = new BinExpr("GRE", $1, $3); }
    | expr_node LES first_bin_expr
{ $$ = new BinExpr("LES", $1, $3); }
    | expr_node EQ first_bin_expr
{ $$ = new BinExpr("EQ", $1, $3); }
    | expr_node GREQ first_bin_expr
{ $$ = new BinExpr("GREQ", $1, $3); }
    | expr_node LESQ first_bin_expr
{ $$ = new BinExpr("LESQ", $1, $3); }
    | expr_node NE first_bin_expr
{ $$ = new BinExpr("NE", $1, $3); }
    | first_bin_expr
{ $$ = $1; }
;

first_bin_expr:
    first_bin_expr ADD second_bin_expr
{ $$ = new BinExpr("add", $1, $3); }
    | first_bin_expr SUB second_bin_expr
{ $$ = new BinExpr("sub", $1, $3); }
    | first_bin_expr OR second_bin_expr
{ $$ = new BinExpr("or", $1, $3); }
    | second_bin_expr
{ $$ = $1; }
;

second_bin_expr:
    second_bin_expr MUL third_bin_expr
{ $$ = new BinExpr("mul", $1, $3); }
    | second_bin_expr DIV third_bin_expr
{ $$ = new BinExpr("div", $1, $3); }
    | second_bin_expr IDIV third_bin_expr
{ $$ = new BinExpr("idiv", $1, $3); }
    | second_bin_expr AND third_bin_expr
{ $$ = new BinExpr("and", $1, $3); }
    | second_bin_expr MOD third_bin_expr
{ $$ = new BinExpr("mod", $1, $3); }
    | third_bin_expr
{ $$ = $1; }
;

third_bin_expr:
    NOT third_bin_expr
{ $$ = new UnaryExpr("not", $2); }
    | SUB third_bin_expr
{ $$ = new UnaryExpr("sub", $2); }
    | ID LPR expr_list RPR
{ $$ = new FunCallExpr((string)$1, $3); }
    | array_expr
{ $$ = $1; }
    | LPR expr_node RPR
{ $$ = $2; }
    | id_expr
{ $$ = $1; }
;

array_expr:
    ID LBR expr_node RBR {
        $$ = new ArrayExpr((string)$1, $3);
    }
;

for_node:
    FOR ID ASSIGN expr_node TO expr_node DO exec_part SEMI {
        $$ = new ForStmt((string)$2, $4, $6, $8->sl); 
    }
    | FOR ID ASSIGN expr_node TO expr_node DO stmt_node {
        StmtList* sl = new StmtList($8);
        $$ = new ForStmt((string)$2, $4, $6, sl);
    }
;

while_node:
    WHILE expr_node DO exec_part SEMI{
        $$ = new WhileStmt($2, $4->sl); 
    }
    | WHILE expr_node DO stmt_node {
        StmtList* sl = new StmtList($4);
        $$ = new WhileStmt($2, sl);
    }
;

if_node:
    IF LPR expr_node RPR THEN exec_part SEMI else_node
{ $$ = new IfStmt($3, $6->sl, $8); }
    | IF LPR expr_node RPR THEN stmt_node else_node
{ StmtList* sl = new StmtList();
  sl->pushStmt($6);
  $$ = new IfStmt($3, sl, $7); }
;

else_node:
    ELSE exec_part SEMI
{ $$ = new ElseStmt($2->sl); }
    | 
{ $$ = new ElseStmt(); }
;

break_node:
    BREAK SEMI
{ $$ = new BreakStmt(); }
;

call_node:
    ID LPR expr_list RPR SEMI
{ $$ = new FuncCallStmt((string)$1, $3); }
;

repeat_node:
    REPEAT stmt_list UNTIL expr_node SEMI{ 
        $$ = new RepeatStmt($4, $2); 
    }
;

%%
void yyerror (char const *s) {
   printf ("%s\n", s);
   
 }