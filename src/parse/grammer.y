%{
    #include <stdio.h>
    #include <string.h>
    #include <stdio.h>
    #include "../ast/AST_node.h"
%}

%union{
    int type_int;
    float type_float;
    char type_char;
    string type_string;
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
    IDList* id_list;
    ArrayType* array_type;
    ParaList* para_node;
    ProgHead* prog_head;
    ParaDecl* para_decl;
    BinExpr* bin_expr;
    UnaryExpr* un_expr;
    FunCallExpr* funcall_expr;
    ArrayExpr* array_expr;
    string op;
}
// 数据类型定义
%token TYPE_INT TYPE_INT_8 TYPE_INT_16 TYPE TYPE_INT_32 TYPE_INT_64 TYPE_BYTE TYPE_WORD TYPE_FLOAT_8 TYPE_FLOAT_16 TYPE_FLOAT_32 TYPE_BOOL TYPE_CHAR TYPE_STRING
// 符号
%token NOT ADD SUB MUL DIV MOD IDIV EQ GRE LES GREQ LESQ NE OR AND ASSIGN ARANGE LBR RBR LPR RPR PERIOD COM COL SEMI CARET DOT TRUE FALSE
// 其他保留字
%token ARRAY BEGIN BREAK CASE CONST TO DO ELSE END FILE FOR FUNC IF OF PROC PROG REPEAT READ READLN THEN UNTIL VAR WHILE WRITE WRITELN
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
%type<type_node> type_node;
%type<id_list> id_list;
%type<array_type> array_type;
%type<para_node> para_node;
%type<prog_head> prog_head;
%type<bin_expr> first_bin_expr;
%type<bin_expr> second_bin_expr;
%type<bin_expr> third_bin_expr;
%type<array_expr> array_expr;

%%
program:
    program program_node
    | 
    ;

program_node:
    prog_head decl_part exec_part DOT { 
        $$ = new program_node($1, $2, $3); 
    }
;

prog_head:
    PROG ID SEMI { $$ = new prog_head($2); }
;

decl_part:
    VAR var_list func_list { 
        $$ = new decl_part($2, $3); 
    }
;

var_list:
    var_list var_node SEMI
{ $$ = $1;
  $$->pushVarDecl($2); }
    | 
{ $$ = new var_list(); }
;

var_node:
    id_list COL type_node
{ $$ = new var_node($3, $1); }
    | id_list COL ARRAY array_type OF type_node
{ $4->SetType($6);
  $$ = new var_node($4, $1); }
  ;

array_type:
    array_type LBR INT ARANGE INT RBR
{ $$ = $1; 
  $$->pushNewDim($3, $5); }
    | 
{ $$ = new array_type(); }
;

type_node:
    TYPE_INT
{ $$ = new type_node("integer"); }
    | TYPE_FLOAT_8
{ $$ = new type_node("real"); }
    | TYPE_FLOAT_32
{ $$ = new type_node("double"); }
    | TYPE_CHAR
{ $$ = new type_node("char"); }
    | TYPE_STRING
{ $$ = new type_node("string"); }
;

id_list:
    id_list COM ID
{ $$ = $1;
  $$->pushID($3); }
    | ID
{ $$ = new id_list; 
  $$->PushID($1); };

func_list:
    func_list func_node
{ $$ = $1->pushOneFuncDecl($2); }
    | 
{ $$ = new func_list(); }
;

func_node:
    func_node SEMI func_body SEMI
{ $$ = new func_node($1, $3); }
;

func_head:
    FUNC ID LPR para_node RPR COL type_node SEMI
{ $$ = new func_head($2, $7, $4); }
;

para_node:
    para_node COM var_node
{ $$ = $1->pushPara($3); }
;

func_body:
    decl_part exec_part
{ $$ = new func_body($1, $2); }
;

exec_part:
    BEGIN stmt_list END { 
        //$$ = new exec_part($2);
    }
;

stmt_list:
    stmt_list stmt_node
{ $$ = $1
  $$->pushStmt($2); }
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
    | else_node
{ $$ = $1; }
;

assign_node:
    ID ASSIGN expr_node
{ id_expr* id = new id_expr("var", $1); 
  $$ = new assign_node(id, $3); }
    | array_expr ASSIGN expr_node
{ $$ = new assign_node($1, $3); }
;

expr_list:
    expr_list COM expr_node
{ $$ = $1;
  $$->pushExprNode($3); }
    | expr_node
{ $$ = new expr_list($1); }
;

id_expr:
    ID
{ $$ = new id_expr("var", $1); }
    | INT
{ $$ = new id_expr("int", $1); }
    | CHAR
{ $$ = new id_expr("char", $1); }
    | FLOAT
{ $$ = new id_expr("float", $1); }
    | STRING
{ $$ = new id_expr("string", $1); }
;

expr_node:
    expr_node GRE first_bin_expr
{ $$ = new bin_expr("GRE", $1, $3); }
    | expr_node LES first_bin_expr
{ $$ = new bin_expr("LES", $1, $3); }
    | expr_node EQ first_bin_expr
{ $$ = new bin_expr("EQ", $1, $3); }
    | expr_node GREQ first_bin_expr
{ $$ = new bin_expr("GREQ", $1, $3); }
    | expr_node LESQ first_bin_expr
{ $$ = new bin_expr("LESQ", $1, $3); }
    | expr_node NE first_bin_expr
{ $$ = new bin_expr("NE", $1, $3); }
    | first_bin_expr
{ $$ = $1; }
;

first_bin_expr:
    first_bin_expr ADD second_bin_expr
{ $$ = new bin_expr("add", $1, $3); }
    | first_bin_expr SUB second_bin_expr
{ $$ = new bin_expr("sub", $1, $3); }
    | first_bin_expr OR second_bin_expr
{ $$ = new bin_expr("or", $1, $3); }
    | second_bin_expr
{ $$ = $1; }
;

second_bin_expr:
    second_bin_expr MUL third_bin_expr
{ $$ = new bin_expr("mul", $1, $3); }
    | second_bin_expr DIV third_bin_expr
{ $$ = new bin_expr("div", $1, $3); }
    | second_bin_expr IDIV third_bin_expr
{ $$ = new bin_expr("idiv", $1, $3); }
    | second_bin_expr AND third_bin_expr
{ $$ = new bin_expr("and", $1, $3); }
    | second_bin_expr MOD third_bin_expr
{ $$ = new bin_expr("mod", $1, $3); }
    | third_bin_expr
{ $$ = $1; }
;

third_bin_expr:
    NOT third_bin_expr
{ $$ = new un_expr("not", $2); }
    | SUB third_bin_expr
{ $$ = new un_expr("sub", $2); }
    | ID LPR expr_list RPR
{ $$ = new call_node($1, $3); }
    | ID array_expr
{ $$ = $2;
  $$->SetName($1); }
    | LPR expr_node RPR
{ $$ = $2; }
    | id_expr
{ $$ = $1; }
;

array_expr:
    array_expr LBR expr_node RBR
{ $$ = $1; 
  $$->pushIndexDim($3); }
    | 
{ $$ = new array_expr(); }
;

for_node:
    FOR ID ASSIGN expr_node TO expr_node DO exec_part SEMI
{ $$ = new for_node($2, $4, $6, $8->sl); }
;

while_node:
    WHILE expr_node DO exec_part SEMI
{ $$ = new while_node($2, $4->sl); }
;

if_node:
    IF LPR expr_node RPR THEN exec_part else_node
{ $$ = new if_node($3, $6->sl, $7); }
    | IF LPR expr_node RPR THEN stmt_node else_node
{ stmt_list*sl = new stmt_list();
  sl.pushStmt($6);
  $$ = new if_node($3, sl, $7); }
;

else_node:
    ELSE exec_part
{ $$ = new else_node($2->sl); }
    | 
{ $$ = new else_node(); }
;

break_node:
    BREAK
{ $$ = new break_node(); }
;

call_node:
    ID LPR expr_list RPR
{ $$ = new call_node($1, $3); }
;

repeat_node:
    REPEAT stmt_list UNTIL expr_node SEMI
{ $$ = new repeat_node($4, $2); }
;
