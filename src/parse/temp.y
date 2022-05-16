%{
    #include <stdio.h>
    #include <string.h>
    #include "../ast/AST_node.h"
    extern int yylex();
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
    IDList* id_list;
    ArrayType* array_type;
    ParaList* para_node;
    ProgHead* prog_head;
    BinExpr* bin_expr;
    UnaryExpr* un_expr;
    FunCallExpr* funcall_expr;
    ArrayExpr* array_expr;
%}
// 数据类型定义
%token TYPE_INT TYPE_INT_8 TYPE_INT_16 TYPE TYPE_INT_32 TYPE_INT_64 TYPE_BYTE TYPE_WORD TYPE_FLOAT_8 TYPE_FLOAT_16 TYPE_FLOAT_32 TYPE_BOOL TYPE_CHAR TYPE_STRING
// 符号
%token NOT ADD SUB MUL DIV MOD IDIV EQ GRE LES GREQ LESQ NE OR AND ASSIGN ARANGE LBR RBR LPR RPR PERIOD COM COL SEMI CARET DOT TRUE FALSE
// 其他保留字
%token ARRAY BEGN BREAK CASE CONST TO DO ELSE END FOR FUNC IF OF PROC PROG REPEAT READ READLN THEN UNTIL VAR WHILE WRITE WRITELN
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
        ast_root = Program($1, $2, $3); 
    }
;

prog_head:
    PROG ID SEMI { $$ = new ProgHead($2); }
;

decl_part:
    VAR var_list func_list { 
        $$ = new DeclPart($2, $3); 
    }
;

var_list:
    var_list var_node SEMI
{ $$ = $1;
  $$->pushVarDecl($2); }
    | 
{ $$ = new VarList(); }
;

var_node:
    id_list COL type_node
{ $$ = new VarDecl($3, $1); }
    | id_list COL ARRAY array_type OF type_node
{ $4->SetType($6);
  $$ = new VarDecl($4, $1); }
;

array_type:
    array_type LBR INT ARANGE INT RBR
{ $$ = $1; 
  $$->pushNewDim($3, $5); }
    | 
{ $$ = new ArrayType(); }
;

type_node:
    TYPE_INT
{ $$ = new MyType("integer"); }
    | TYPE_FLOAT_8
{ $$ = new MyType("real"); }
    | TYPE_FLOAT_32
{ $$ = new MyType("double"); }
    | TYPE_CHAR
{ $$ = new MyType("char"); }
    | TYPE_STRING
{ $$ = new MyType("string"); }
;

id_list:
    id_list COM ID
{ $$ = $1;
  $$->pushID($3); }
    | ID
{ $$ = new id_list; 
  $$->pushID($1); }
;

func_list:
    func_list func_node
{ $$ = $1->pushOneFuncDecl($2); }
    | 
{ $$ = new FunCDeclList(); }
;

func_node:
    func_head SEMI func_body SEMI
{ $$ = new OneFuncDecl($1, $3); }
;

func_head:
    FUNC ID LPR para_node RPR COL type_node SEMI { 
        $$ = new FuncHead($2, $7, $4); 
    }
;

para_node:
    para_node COM var_node
{ $$ = $1->pushPara($3); }
    | 
{ $$ = para_node(); }
;

func_body:
    VAR {
        //$$ = new FuncBody($1, $2); 
    }
;

exec_part:
    BEGN stmt_node END { 
        $$ = new ExecPart($2);
    }
;

stmt_list:
    stmt_list stmt_node
{ $$ = $1
  $$->pushStmt($2); }
    | 
{ $$ = new StmtList(); }
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
    ID ASSIGN expr_node
{ IDExpr* id = new IDExpr("var", $1); 
  $$ = new AssignStmt(id, $3); }
    | array_expr ASSIGN expr_node
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
{ $$ = new IDExpr("var", $1); }
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
{ $$ = new FunCallExpr($1, $3); }
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
{ $$ = new ArrayExpr(); }
;

for_node:
    FOR ID ASSIGN expr_node TO expr_node DO exec_part SEMI
{ $$ = new ForStmt($2, $4, $6, $8->sl); }
;

while_node:
    WHILE expr_node DO exec_part SEMI
{ $$ = new WhileStmt($2, $4->sl); }
;

if_node:
    IF LPR expr_node RPR THEN exec_part else_node
{ $$ = new IfStmt($3, $6->sl, $7); }
    | IF LPR expr_node RPR THEN stmt_node else_node
{ StmtList* sl = new StmtList();
  sl.pushStmt($6);
  $$ = new IfStmt($3, sl, $7); }
;

else_node:
    ELSE exec_part
{ $$ = new ElseStmt($2->sl); }
    | 
{ $$ = new ElseStmt(); }
;

break_node:
    BREAK
{ $$ = new BreakStmt(); }
;

call_node:
    ID LPR expr_list RPR
{ $$ = new FunCallExpr($1, $3); }
;

repeat_node:
    REPEAT stmt_list UNTIL expr_node SEMI { 
        $$ = new RepeatStmt($4, $2); 
    }
;

%%
int main() {
    /* char[] filename = "quicksort.pas";
    yyin = fopen(filename, "r"); */
    yyparse();
    return 0;
}