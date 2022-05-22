# 编译原理 Project-实验报告

### **组员信息：**

 **张振宇 3190104896**

 **颜天明 3190105027**

 **高婧 3180104228**

### 一、工程概述

 我们实现的语言是类似 Pascal 语言格式的 MiniPascal 语言，可以说是 Pascal 语言的子集，在一些地方做出了改变。

 我们支持的功能有：

- 基本数据类型：integer，char，bool，real
- 数组：支持所有基本数据类型
- 全局变量与局部变量的声明与使用
- 函数的声明与调用
- 基本语句：if-else, while, repeat, for, break 等
- 注释
- 赋值语句和运算语句隐含类型转换
- 编译错误提示

 我们开发的环境为：Ubuntu -18.04，flex，bison，LLVM-6.0，Clang-6.0

 开发全程采用 Github 进行版本控制及协作。



 采用的技术路线为：利用 lex 进行词法分析生成 Token 序列，利用 yacc 进行语法分析并构建语法树。

 即下图中的上面一条路线。

<img src="img/1.jpg" width="50%" />

 生成语法树之后，利用 LLVM 框架，遍历语法树生成 IR 代码。

 生成 IR 代码之后，直接利用 Clang 编译器将 IR 代码编译为机器码，生成可执行文件

<img src="img/2.jpg" width="50%" />

### 二、词法分析

##### 2.1. 工具介绍

在这次的实验当中，我们使用 flex 来完成词法分析过程。flex（快速词法分析产生器，fast lexical analyzer generator）是一种词法分析程序。它是 lex 的开放源代码版本，以 BSD 许可证发布。通常与 GNU bison 一同运作，但是它本身不不是 GNU 计划的一部分。
词法分析是将字符序列列转换为标记(token)序列列的过程。在词法分析阶段，编译器器读入源程序字符串流，将字符流转换为标记序列，同时将所需要的信息存储，然后将结果交给语法分析器。这是编译程序的第一个阶段且是必要阶段；词法分析的核心任务是扫描、识别单词且对识别出的单词给出定性、定长的处理。处理完成后，词法分析程序会生成将之前的程序文本转变为一系列 token，传给之后的语法分析程序。示意图如下：
<img src="img/122.png" width="40%" />
标准 lex 文件由三部分组成，分别是定义区、规则区和⽤用户子过程区。在定义区，⽤用户可以编写 C 语⾔言中的声明语句，导入需要的头文件或声明变量。在规则区，用户需要编写以正则表达式和对应的动作的形式的代码。在用户子过程区，用户可以定义函数。

##### 2.2 实现过程

##### 2.2.1 立即数

```c++
digit [0-9]
letter [a-zA-Z]
string \"[^"]*\"
char \'.\'
id ({letter}|_)+({letter}|_|{digit})*
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
```

对于 integer 类型，我们检测一连串的数字；对于 char 类型，我们检测''包裹的任何一个单个字符和\开始的转义字符，对于 string 类型，我们检测""包裹的一连串的字符，对于 identify 类型，我们检测字母和下划线开头的一连串字符。

##### 2.2.2 保留字

```c++
"integer" {return TYPE_INT; printf("integer");}
"real" {return TYPE_FLOAT_8;}
"char" {return TYPE_CHAR;}
"string" {return TYPE_STRING;}
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
"then" {return THEN;}
"until" {return UNTIL;}
"var" {return VAR;}
"while" {return WHILE;}
```

我们实现了部分 pascal 关键字的检测

##### 2.2.3 运算符

```c++
"not" {return NOT;}
"+" {return ADD;}
[-] {return SUB;}
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
"." {return DOT;}
"," {return COM;}
":" {return COL;}
";" {return SEMI;}
"^" {return CARET;}
"\n" {}
```

我们实现了 pascal 中运算符的检测。

### 三、语法分析

#### 3.1 工具介绍

yacc(Yet Another Compiler Compiler)，是一个经典的生成语法分析器的工具。yacc 生成的编译器主要是用 C 语言写成的语法解析器（Parser），需要与词法解析器 Lex 一起使用，再把两部份产生出来的 C 程序一并编译。
yacc 的输入是巴科斯范式（BNF）表达的语法规则以及语法规约的处理代码，Yacc 输出的是基于表驱动的编译器，包含输入的语法规约的处理代码部分。yacc 是开发编译器的一个有用的工具,采用 LALR(1)语法分析方法。
与 Lex 相似，Yacc 的输⼊入文件由以%%分割的三部分组成，分别是声明区、规则区和程序区。三部分的功能与 Lex 相似，不同的是规则区的正则表达式替换为 CFG，在声明区要提前声明好使用到的终结符以及非终结符的类型。
在实验中，我们使用 bison 来进行 yacc 文件的编译。

#### 3.2 实现过程

##### 3.2.1 引入 ast 结点

```c++
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
```

在这里我们引入了 ast 文件中定义的各个结点结构，用作后面的非终结符类型定义。

##### 3.2.2 token 定义

```c++
// 数据类型定义
%token TYPE_INT TYPE_INT_8 TYPE_INT_16 TYPE TYPE_INT_32 TYPE_INT_64 TYPE_BYTE TYPE_WORD TYPE_FLOAT_8 TYPE_FLOAT_16 TYPE_FLOAT_32 TYPE_BOOL TYPE_CHAR TYPE_STRING
// 符号
%token NOT ADD SUB MUL DIV MOD IDIV EQ GRE LES GREQ LESQ NE OR AND ASSIGN ARANGE LBR RBR LPR RPR DOT COM COL SEMI CARET
// 其他保留字
%token ARRAY BEGN BREAK CASE CONST TO DO ELSE END FOR FUNC IF OF PROC PROG REPEAT THEN UNTIL VAR WHILE
```

##### 3.2.3 非终结符定义

```c++
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
```

我们使用之前引入的 ast 结点来定义这些非终结符。

##### 3.2.4 分析过程

```c++
program:
    program program_node
    |
    ;

program_node:
    prog_head decl_part exec_part DOT {
        ast_root = new Program($1, $2, $3);
    }
;
```

我们将程序分为头部，定义部分，执行部分三个部分，每次新分析一个语句，我们都会建立一个对应的新结点，并将其需要的子节点赋值进去。

```c++
decl_part:
    VAR var_list func_list {
        $$ = new DeclPart($2, $3);
    }
    |
    { $$ = new DeclPart(); }
;
exec_part:
    BEGN stmt_list END {
        $$ = new ExecPart($2);
    }
;
```

定义部分分为变量定义和函数定义，执行分为为一系列单独的可执行语句构成。

```c++
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
```

变量定义部分由一系列变量定义语句构成，一个单独的变量定义语句包括一组 identidy 开头，符号:紧随其后，加上变量类型（）可以是数组），后面可以加上初始化的部分。

```c++
simple_type:
    TYPE_INT
{ $$ = new SimpleType("integer"); }
    | TYPE_FLOAT_8
{ $$ = new SimpleType("real"); }
    | TYPE_FLOAT_32
{ $$ = new SimpleType("real"); }
    | TYPE_CHAR
{ $$ = new SimpleType("char"); }
    | TYPE_STRING
{ $$ = new SimpleType("string"); }
;
```

我们实现了以上五个数据类型的检测

```c++
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
func_body:
    var_list exec_part {
        $$ = new FuncBody($1, $2);
    }
;
```

函数部分由一系列的函数构成，和 pascal 程序类似，每一个函数包含一个函数头，变量定义部分和函数体执行部分。函数头包含了函数参数和返回类型。

```c++
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
```

执行部分语句体由一系列可单独执行的语句构成，这些语句分成了赋值语句，循环语句，条件语句等等。

```c++
assign_node:
    ID ASSIGN expr_node SEMI
{ IDExpr* id = new IDExpr("var", (string)$1);
  $$ = new AssignStmt(id, $3); }
    | array_expr ASSIGN expr_node SEMI
{ $$ = new AssignStmt($1, $3); }
;
```

包:=的语句我们认为是赋值语句,赋值语句的左边可以是单个变量或者一个数组的某个元素，右边是一系列 expresssion 的组合

```c++
id_expr:
    ID
{ $$ = new IDExpr("var", (string)$1); }
    | INT
{ $$ = new IDExpr("Imm", (int)$1); }
    | CHAR
{ $$ = new IDExpr("Imm", (char)$1); }
    | FLOAT
{ $$ = new IDExpr("Imm", (double)$1); }
    | STRING
{ $$ = new IDExpr("Imm", (string)$1); }
;
```

expression 的终点是 identify 或者立即数

```c++
expr_node:
    expr_node GRE first_bin_expr
{ $$ = new BinExpr("GT", $1, $3); }
    | expr_node LES first_bin_expr
{ $$ = new BinExpr("LT", $1, $3); }
    | expr_node EQ first_bin_expr
{ $$ = new BinExpr("EQUAL", $1, $3); }
    | expr_node GREQ first_bin_expr
{ $$ = new BinExpr("GE", $1, $3); }
    | expr_node LESQ first_bin_expr
{ $$ = new BinExpr("LE", $1, $3); }
    | expr_node NE first_bin_expr
{ $$ = new BinExpr("NE", $1, $3); }
    | first_bin_expr
{ $$ = $1; }
;

first_bin_expr:
    first_bin_expr ADD second_bin_expr
{ $$ = new BinExpr("PLUS", $1, $3); }
    | first_bin_expr SUB second_bin_expr
{ $$ = new BinExpr("MINUS", $1, $3); }
    | first_bin_expr OR second_bin_expr
{ $$ = new BinExpr("OR", $1, $3); }
    | second_bin_expr
{ $$ = $1; }
;

second_bin_expr:
    second_bin_expr MUL third_bin_expr
{ $$ = new BinExpr("MUL", $1, $3); }
    | second_bin_expr DIV third_bin_expr
{ $$ = new BinExpr("DIV", $1, $3); }
    | second_bin_expr IDIV third_bin_expr
{ $$ = new BinExpr("DIV", $1, $3); }
    | second_bin_expr AND third_bin_expr
{ $$ = new BinExpr("AND", $1, $3); }
    | second_bin_expr MOD third_bin_expr
{ $$ = new BinExpr("MOD", $1, $3); }
    | third_bin_expr
{ $$ = $1; }
;

third_bin_expr:
    NOT third_bin_expr
{ $$ = new UnaryExpr("NOT", $2); }
    | SUB third_bin_expr
{ $$ = new UnaryExpr("SUB", $2); }
    | ID LPR expr_list RPR
{ $$ = new FunCallExpr((string)$1, $3); }
    | array_expr
{ $$ = $1; }
    | LPR expr_node RPR
{ $$ = $2; }
    | id_expr
{ $$ = $1; }
```

按照运算符的优先级，我们逐步解析 expression 的集合体，并且考虑括号数组函数调用等因素。

```c++
array_expr:
    ID LBR expr_node RBR {
        $$ = new ArrayExpr((string)$1, $3);
    }
;
```

数组比较特殊，我们单独分析，为一个数组名和一个括号内的 expression 集合体

```c++
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
```

循环语句包括 for 循环和 while 循环，二者的分析差不多，都是一个条件语句加上 statement 集合体

```c++
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
```

条件语句包括一个 if 开头的判断和 else，if 语句包含一个条件判断 expression 和一系列可执行语句集合体，else 语句可以没有。

### 四、语法树结构设计

利用面向对象的思想，我们将 AST 的每个节点定义成类和对象。利用多态和继承，我们将语法树的每一个节点抽象为基类 BaseNode，基类中存储着每个节点共有的属性：classname，line-number，并定义了通用的方法及生成中间代码所用的 CodeGen 函数。

```c++
class BaseNode{
private:
    int line_num=-1;
    string classname = "base";
public:
    BaseNode(string name){ this->classname = name; }
    string getClass() const { return this->classname; }
    virtual llvm::Value *CodeGen(CodeGenContext &context) = 0;
};
```

利用基类 BaseNode，我们将其余类对其进行继承，大致分为以下几类：

- 划分程序区域类型
- 表达式类型
- 语句类型
- 类型、变量、函数等与定义相关的类型

**划分区域：**

划分区域的节点的主要作用是将各区域的语句综合起来，有序的连在区域节点之下。通过这种设计，我们可以将程序清晰的分为几个区域，及更加细分为子区域，最终到达叶子节点。

采用这种设计的好处是：

- 每种区域都有特定的类，指针也根据具体情况而特化，这样能使语法树的语义更加清楚。
- 利用多态的机制，为每个节点增加一个 CodeGen 的虚函数，这样通过定义每种类的 CodeGen 方法，我们并不需要完全知道孩子是什么类型的派生类，只需要调用他们的 CodeGen 方法即可。
- 这种设计在定义语法树时需要很多代码，但是在使用时带来了极大的方便，因为我们在向下时已经清楚的知道了这种节点的孩子个数，如何使用。

类定义示例如下图所示：

```c++
class DeclPart : public BaseNode
{
private:
    VarDeclList *varlist;
    FuncDeclList *funclist;

public:
    DeclPart():BaseNode("declpart"){}
    DeclPart(VarDeclList *v, FuncDeclList *f) : BaseNode("declpart"), varlist(v), funclist(f) {}
    VarDeclList *getVarListNode() { return this->varlist; }
    FuncDeclList *getFuncPartNode() { return this->funclist; }
    virtual llvm::Value *CodeGen(CodeGenContext &context);
};
```

区域的划分大致如下：

<img src="img/3.jpg" width="50%" />

Program 分为定义部分和执行部分，定义部分分为一组变量定义和一组函数定义。执行部分就是要执行的语句列表。

**表达式类型：**

表达式类型的节点都继承于基类 Expr，共分为：

- IDExpr：存储立即数、变量名的表达式
- BinExpr：二元计算型的表达式
- UnaryExpr：一元计算型的表达式
- FuncallExpr：调用函数返回结果的表达式
- ArrayExpr：指定下标的数组的表达式

**语句类型：**

语句类型的节点都继承于基类 Stmt，共分为：

- AssignStmt：赋值语句，左面是变量，右面是值
- ForStmt：循环类型的语句
- FunCallStmt：调用函数的语句（无用返回值）
- RepeatStmt：循环类型的语句
- WhileStmt：循环类型的语句
- IfStmt：条件控制类型的语句
- ElseStmt：和 If 配套使用
- BreakStmt：跳出循环的语句

**定义相关类型：**

定义相关的类型主要有：

MyType：类型的基类，派生类有：

- SimpleType：基本数据类型
- ArrayType：数组类型

OneFuncDecl：一个函数的定义

- FuncHead：函数头，包含函数名，返回类型，参数表
- FuncBody：变量定义、语句列表

VarDecl：一组变量定义

- 存有 MyType 类型的 type
- IDList，变量名表



### 五、语法树可视化

语法树的可视化帮助我们更好地理解在 parse 过程中建立语法树的过程，也方便我们对语法编写的正确性进行验证。

##### 1、实现方法

可视化部分的实现目标是传入已经建好的语法树的节点可视化出该节点下的语法树的所有组成节点，可以从树的每一层看出对应的语法。本项目中对于语法树中的节点都是继承了`BaseNode`这个基类的子类，语法树中节点的连接关系通过各种类内成员变量，即某个节点类的指针来表示。由于本项目中的类都是自定义的，不方便将使用现有的可视化库将传入的语法树节点指针直接可视化；因此，本项目中设计了`Dict`类将语法树存储为字典类型，并且可以按照`JSON`格式进行输出，方便后续的可视化。

###### `Dict`类

```c++
class Dict
{
private:
    string key;     // 存储节点的classname
    string valType; // 值类型：只能为str/dict，取值与下面一个对应
    string strValue;
    vector<Dict *> dictValue;

    void addOneDictValue(Dict *dict);

    void genFrom_Program(Program *node);   // ProgHead + DeclPart + ExecPart
    void genFrom_ProgHead(ProgHead *node); // name
    void genFrom_DeclPart(DeclPart *node); // VarDeclList + FuncDeclList

    void genFrom_VarDeclList(VarDeclList *node); // VarDecl ...
    void genFrom_VarDecl(VarDecl *node);         // Type + IDlist
    void genFrom_SimpleType(SimpleType *node);   // leaf
    void genFrom_ArrayType(ArrayType *node);     // leaf
    void genFrom_IDList(IDList *node);           // leaf

    void genFrom_FuncDeclList(FuncDeclList *node); // OneFuncDecl ...
    void genFrom_OneFuncDecl(OneFuncDecl *node);   // FuncHead + FuncBody
    void genFrom_FuncHead(FuncHead *node);         // Type + Paralist
    void genFrom_ParaList(ParaList *node);         // VarDecl ...

    void genFrom_FuncBody(FuncBody *node); // DeclPart + ExecPart
    void genFrom_ExecPart(ExecPart *node); // StmtList

    void genFrom_StmtList(StmtList *node);         // Stmt ...
    void genFrom_AssignStmt(AssignStmt *node);     // id(Expr) + rexpr(Expr)
    void genFrom_ForStmt(ForStmt *node);           // var + startexpr + endexpr + stmtl
    void genFrom_FuncCallStmt(FuncCallStmt *node); // funcname + el(ExprList)
    void genFrom_RepeatStmt(RepeatStmt *node);     // cond(Expr) + sl(StmtList)
    void genFrom_WhileStmt(WhileStmt *node);       // con(Expr) + sl(StmtList)
    void genFrom_ElseStmt(ElseStmt *node);         // list(StmtList)
    void genFrom_IfStmt(IfStmt *node);             // con(Expr) + sl(StmtList) + els(ElseStmt)
    void genFrom_BreakStmt(BreakStmt *node);

    void genFrom_ExprList(ExprList *node);       // Expr ...
    Dict *genFrom_Expr(Expr *node);              // judge the Expr type
    void genFrom_BinExpr(BinExpr *node);         // op + lhs + rhs
    void genFrom_UnaryExpr(UnaryExpr *node);     // op (NOT) + ex
    void genFrom_FunCallExpr(FunCallExpr *node); // funcname + ExprList
    void genFrom_ArrayExpr(ArrayExpr *node);     // arrayname + Expr...(index_list)
    void genFrom_IDExpr(IDExpr *node);           // leaf

public:
    Dict(string key, string value) : valType("str"), key(key), strValue(value) {}
    Dict(string key, Dict *value) : valType("dict"), key(key), strValue("") { dictValue.push_back(value); }
    Dict(pair<MyType *, string> node);
    Dict(BaseNode *node);

    void writeJSONFile(string filepath);
    string getJSONString();
};
```

如上代码所示，`Dict`类中字典的键是各个节点的类名，对应的值可以有两种类型，一种是代表语法树已经到达了叶节点的字符串类型，另一种是表示非叶节点的字典列表类型。字符串类型将存储叶节点的值，例如变量名、变量类型、数字、字符等。字典列表类型，可以存储不定数量的字典，通过`vector`进行存储。将语法树转为字典，主要是通过在`Dict`类的构造函数中对当前节点的类型进行判断，然后对不同节点的定义进行适配分析，用 DFS 的方式遍历传入的语法树，将所有节点的信息加入到字典中。再通过该类的`public`函数中的`void writeJSONFile(string filepath);`将转换后的字典写入到指定的 JSON 文件中，方便后续解析。

##### 2、graphviz 可视化

本项目的课时化代码使用了 graphviz 库，该库可以通过调用已经封装好的函数进行树型图的可视化，只需要调用画节点和连接线的函数，再将绘制图像以图片的形式输出到指定的路径下，便可以达到输出语法树的功能。graphviz 库不需要人为设置具体的绘制细节（图片大小、图中各种元素的位置等），库中的`Digraph`类会根据要绘制的语法树的形状安排各个节点的位置，调整合适的图片大小，使用起来十分方便。具体实现中，使用了 python 代码对输出到指定 JSON 文件的语法树字典进行读取，Python 可以解读 JSON 文件，之间转化为 Python 的基本类型之一——字典。再使用 DFS 对字典进行遍历，用直线将各级父子节点连接，在叶节点后绘制代表具体的叶节点值的一个节点。

可视化部分具体的使用伪代码如下所示：

```c++
// ast_root为要传入的语法树的节点指针
Dict *astDict = new Dict(ast_root); // 将语法树转为字典类型
astDict->writeJSONFile("test.json"); // 将字典写入到指定路径下的JSON文件中
```

存入 JSON 文件后，再通过运行 visualize.py 中的 Python 代码来绘制语法树：

```shell
python visulilze.py
```

##### 3、可视化结果

下图为一个简单的可视化样例：

<img src="img/test.png" style="zoom:50%;" />

对需要测试的三个 pascal 文件进行解析并生成相应的语法树后，使用上述的可视化方法进行可视化，生成的语法树结果可以直接查看附带的图片文件。



### 六、中间代码生成

##### 6.1、基本框架与语法树遍历方法：

在中间代码的生成中，我们主要使用的框架是 LLVM 框架，使用的版本是 6.0 （ubuntu apt 安装）

如上文所述，每个节点都有属于自己的虚函数方法。这样的话就可以采用一种“自驱动”的遍历方式。父节点调用子节点的 Codegen 方法，子节点的 CodeGen 方法也会进一步调用子节点的方法，如此以来就很自然的实现了语法树遍历，不用特别考虑遍历的顺序就可以实现正确顺序的遍历。

例如在赋值语句的 CodenGen 方法中：

```c++
llvm::Value* AssignStmt::CodeGen(CodeGenContext &context){
    cout<<"Generate AssignStmt..."<<endl;

    context.genpointer=true;
    auto lhs = this->getLeftExprNode()->CodeGen(context);

    context.genpointer=false;
    auto rhs = this->getRightExprNode()->CodeGen(context);

    ......

    return rhs;
}
```

这个节点可以直接调用左子节点和右子节点的 Codegen 方法，从而实现“需求驱动”的递归遍历。

##### 6.2、CodeGenContext 类设计

LLVM 的基本逻辑是，一个 Module 代表一个文件，一个 BasicBlock 代表一个代码块，所以生成代码实际上就是指定 module 之后，不断新建和向每个 BasicBlock 插入语句的过程。我们需要一个 Context 类来保存现在的文件信息和所在的块，以及历史块和很多的上下文信息。

```C++
class CodeGenContext{
private:
    std::vector<CodeGenBlock *> blocks;
    //主函数
    std::map<std::string,pair<int,int>> arrayrecord;
public:

    bool isGlobal=true;
    bool genpointer=false;
    bool breakif=false;
    llvm::Module *module;
    llvm::IRBuilder<> builder;
    llvm::Function *mainFunction;
    llvm::LLVMContext globalcontext;
    llvm::Function *curfunction;

    //system function
    llvm::Function *printf_func;
    llvm::Function *scanf_func;
    ...
}
```

context 类中存储的变量有：isGlobal-当前是否在全局变量区。genpointer-当前是否在产生指针。breakif-当前 if 是否为 break 的 if 等信息。其中比较重要的属性为：module 代表当前文件，curfunction 代表当前所在函数，builder 是 llvm 的一个工具类，可以指定插入的 Block 进行代码插入。

另外 context 中还定义了两个系统函数：输入和输出。

每个节点的 CodeGen 方法都需要讲 context 作为参数来获取上下文信息。

###### 下面将会展示每类节点的 CodeGen 方法的实现，在主函数中，只需要调用根节点的 Codegen 方法即可遍历整棵树。

##### 6.3、区域划分节点

区域划分节点的实现基本上为：按照顺序调用子节点的 CodeGen 方法。

##### 6.4、定义相关类型

分为函数定义和变量定义：

###### 函数定义的方法为：

- 根据返回类型和参数表创建函数类型
- 根据函数类型创建函数
- 保存上下文并将上下文切换到函数中
- 生成参数的局部变量
- 生成代表返回值的局部变量
- 生成函数体
- 返回返回值
- 恢复上下文
- api 示例如下：

```c++
auto rettype = getLLVMtype(this->getFuncDeclNode()->getRetType(),context);
auto func_type = llvm::FunctionType::get(rettype,llvm::makeArrayRef(para_types),false);
auto function = llvm::Function::Create(func_type,llvm::Function::ExternalLinkage,
        		this->getFuncDeclNode()->getFuncName(),context.module);
```

###### 变量定义的方法为：

- 获取变量的 Type （array 或 simple）
- 检测全局或局部
- 调用 llvm 的 api 进行声明
- api 示例如下：

```c++
       llvm::Value * ret;
       for(auto i=list.begin(); i!=list.end(); i++){
            ret = new llvm::GlobalVariable(
          		*context.module,ty,false,
                llvm::GlobalVariable::ExternalLinkage,constant,*i
            );
            cout<<"create global: "<<*i<<endl;
       }
       return ret;
```

###### 在变量定义的时候，根据数组和基本类型调用不同的 api

##### 6.5、语句相关类型

###### 赋值语句：

- 调用左子节点，获取变量指针
- 调用右子节点，获取值
- 判断是否需要隐式类型转换
- 利用 llvm api 进行赋值

```c++
		context.builder.CreateStore(rhs,lhs);
```

###### 函数调用语句：

- 判断是系统函数还是用户函数
- 系统函数要将参数处理为特定格式
- 用户函数直接调用函数调用的表达式的方法来实现

```c++
llvm::Value* FuncCallStmt::CodeGen(CodeGenContext &context){
    cout<<"Generating FuncCallStmt..."<<endl;
    if(this->getFuncName()=="write"||this->getFuncName()=="writeln"|| this->getFuncName()=="write10d"){
        return SysCall(this,context);
    }
    else if(this->getFuncName()=="read"||this->getFuncName()=="readln"){
        return SysCall(this,context);
    }
    else{
        // user's function
        auto Funcall = new FunCallExpr(this->getFuncName(),this->getParaExprListNode());
        return Funcall->CodeGen(context);
    }
    return NULL;
}
```

###### 循环控制语句，以 For 语句为例：

- 将语句分为四块，分别的 entry 初始化，body 语句体，end 循环及结束判断，next 下一个块
- entry 中要将循环变量赋初值并做初步判断，创建跳向 body 的语句
- body 插入 for 内部的语句
- end 将循环变量增加并且增加条件判断和跳转语句
- 在 body 中要将 body 块放入栈中并记录 break 语句应该跳到的位置，即 next 块
- 结束后将栈顶的块跳出，替换为 next 块，next 块将继承栈顶块的 break 位置

###### 其余循环控制和 for 大同小异，比 for 更加简单，不再展示，但是要注意 body 块一定会入栈并且记录 break 的位置。

###### 条件控制语句：

- 将语句分为三个代码块，blocktrue 判断条件为 true 时的语句块,blockfalse 判断条件为 false 时的语句块,next 下一个语句块。
- 创建一个条件跳转来控制跳转到 blocktrue 或者 blockfalse
- 生成两个 block 中的语句，两个块最后跳转到 next

条件控制中一个关键点是 if 之后的跳转有可能经过 break 的更改，如果连续插入两条跳转，生成的 IR 会出错，所以当有 break 的时候只能用 break 跳转代替原来的跳转。

##### 6.6、表达式相关类型

###### 二元运算表达式：

- 调用左右节点获取左右的值
- 判断是否需要隐式类型转换
- 根据 op 值进行不同运算
- api 调用示例如下：

```c++
        if(op == "PLUS")
            return context.builder.CreateFAdd(L,R,"add");
        else if(op=="MINUS")
            return context.builder.CreateFSub(L,R,"sub");
        else if(op=="MUL")
            return context.builder.CreateFMul(L,R,"mul");
```

###### 单目运算表达式：

- 获取唯一的子节点值
- 根据 op 值进行运算
- api 调用如下：

```c++
	if(op == "NOT")
        return context.builder.CreateNot(this->getExprNode()->CodeGen(context));
```

###### 函数调用表达式：

- 利用 module 的 api 获得函数指针
- 获取参数的值
- 利用 CreateCall 的 api 调用函数

```c++
llvm::Value* FunCallExpr::CodeGen(CodeGenContext &context){
    ......
    auto callee = context.module->getFunction(this->getFuncName());
    vector<llvm::Value*> args;
    for(auto it : this->getExprListNode()->getExprList()){
        args.push_back(it->CodeGen(context));
    }
    return context.builder.CreateCall(callee,args);
}
```

函数调用语句利用函数调用表达式实现函数调用的时候，无需返回值，但是函数调用表达式一定会返回返回值。

###### 数组取值表达式:

- 首先获得 index 节点的生成值
- 利用 CreateInBoundsGEP 的 api 取指针
- 判断当前是否在取指针，从而返回值或指针

```c++
    if(context.genpointer)
        return context.builder.CreateInBoundsGEP(arrptr,{zero,trueindex});
    else
        return context.builder.CreateLoad(context.builder.CreateInBoundsGEP(arrptr,						{zero,trueindex}));
```

###### 立即数或变量类型的表达式：

- IDExpr 是语法树中叶子类型的节点，能够利用本身存储的信息返回 llvm::Value 类型的值。

- IDExpr 中存储了 type 属性，区分立即数和变量名

- 根据属性及 api 返回值或指针

### 七、编译器测试

##### 1、机器码生成

将生成的 IR 输出到.ll 类型的文件中，利用 clang xx.ll -o result 指令生成 result 可执行文件

##### 2、测试样例

###### 快速排序：

```pascal
program quicksort;
var
    n,k:integer;
    a:array[1..10002] of integer;
    i,j,m,t:integer;
function qsort(l,r:integer):integer;
begin
    i:=l;
    j:=r;
    m:=a[(l+r) div 2];
    repeat
        while (a[i]<m) do i:=i+1;
        while (a[j]>m) do j:=j-1;
        if( not(i>j)) then
        begin
        t:=a[i];
        a[i]:=a[j];
        a[j]:=t;
        i:=i+1;
        j:=j-1;
        end;
    until i>j;
    if (l<j) then qsort(l,j);
    if (i<r) then qsort(i,r);
end;
begin
    read(n);
    for k:=1 to n do
        read(a[k]);
    qsort(1,n);
    for k:=1 to n do begin
        writeln(a[k]);
    end;
end.
```

###### 测试结果：

<img src="img/4.jpg" width="50%" />

###### 矩阵乘法：

```pascal
program matrixMul;
var
    a, b, result : array [0 .. 1000] of integer;
    rowA, rowB, columnA, columnB: integer;
    i, j, k, idx1, idx2, idx3 : integer;
begin
    read(rowA, columnA);
    for i := 0 to rowA - 1 do
    begin
        for j := 0 to columnA - 1 do
        begin
            idx1 := i * columnA + j;
            read(a[idx1]);
        end;
    end;

    read(rowB, columnB);
    for i := 0 to rowB - 1 do
    begin
        for j := 0 to columnB - 1 do
        begin
            idx1 := i * columnB + j;
            read(b[idx1]);
        end;
    end;

    if (columnA = rowB) then
    begin
        for i := 0 to rowA - 1 do
        begin
            for j := 0 to columnB - 1 do
            begin
                idx1 := i * columnB + j;
                result[idx1] := 0;
                for k := 0 to rowB - 1 do
                begin
                    idx2 := i * columnA + k;
                    idx3 := k * columnB + j;
                    result[idx1] := result[idx1] + (a[idx2] * b[idx3]);
                end;
            end;
        end;

        for i := 0 to rowA - 1 do
        begin
            for j := 0 to columnB - 1 do
            begin
                idx1 := i * columnB + j;
                write10d(result[idx1]);
            end;
            writeln("");
        end;
    end;

    else
    begin
        writeln("Incompatible Dimensions");
    end;
end.
```

###### 测试结果：

<img src="img/5.jpg" width="50%" />

###### 课程表：

代码复杂不再展示

###### 测试结果：

<img src="img/6.jpg" width="50%" />

### 八、心得与体会

本次实验中，我们花费了半个星期的时间来设计语法树结构，设计阶段花费的时间也让我们后续的工作进行的更加容易。语法树结构设计完毕后，我们三个人就可以分别去做三部分工作。

在中间代码的生成中，一个最大的难点就是 LLVM api 的使用，英文文档晦涩难懂，难以阅读，我们找到了很多关于 IR 生成的博客，和一个 gnu.org 提供的 toy complier 样例，从而学会了 IR 生成的基本流程和方法。在具体的 api 调用中，多使用 vscode 的转到定义方法查看 llvm 的源代码，源代码中的注释和变量名比文档中写的清楚很多。

高婧：本次项目实现了从用 flex 和 bison 对代码进行词法分析和语法分析，再转化为使用自定义类的语法树，然后用 llvm 生成中间代码。整个实验的过程与上课的理论相契合，在课上对于比较抽象的语法树，我没有马上理解。在本次项目中我实现了语法树的可视化部分，再项目开发过程中对课堂上所讲述的语法树的分析、建立过程有了更深的理解。语法树根据定义的语法规则一步步自顶而下地从根节点到叶节点建立语法树的过程可以在可视化时清楚地了解。为了便于可视化，使用了 graphviz 库的 python 库，使得可视化部分的代码编写难度降低，代码结构更加清晰。本项目的开发让我对于编译器的工作目的和词法、语法分析的方式都有了更好的理解，对课堂的内容也进行了加深巩固，而且和组员的项目合作过程也很融洽，整体上收获很大。
