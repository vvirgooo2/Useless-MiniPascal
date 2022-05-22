

# 编译原理Project-实验报告

### **组员信息：**

​	**张振宇    3190104896**

​	**颜天明    3190105027**

​	**高婧        3180104228**



### 一、工程概述

​	我们实现的语言是类似Pascal语言格式的MiniPascal语言，可以说是Pascal语言的子集，在一些地方做出了改变。

​	我们支持的功能有：

- 基本数据类型：integer，char，bool，real
- 数组：支持所有基本数据类型
- 全局变量与局部变量的声明与使用
- 函数的声明与调用
- 基本语句：if-else, while, repeat, for, break等
- 注释
- 赋值语句和运算语句隐含类型转换
- 编译错误提示

​	我们开发的环境为：Ubuntu -18.04，flex，bison，LLVM-6.0，Clang-6.0

​	开发全程采用Github进行版本控制及协作，目前commit次数达50余次

​	

​	采用的技术路线为：利用lex进行词法分析生成Token序列，利用yacc进行语法分析并构建语法树。

​	即下图中的上面一条路线。

<img src="img/1.jpg" width="50%" />

​	生成语法树之后，利用LLVM框架，遍历语法树生成IR代码。

​	生成IR代码之后，直接利用Clang编译器将IR代码编译为机器码，生成可执行文件

<img src="img/2.jpg" width="50%" />



### 二、词法分析

### 三、语法分析

### 四、语法树结构设计

利用面向对象的思想，我们将AST的每个节点定义成类和对象。利用多态和继承，我们将语法树的每一个节点抽象为基类BaseNode，基类中存储着每个节点共有的属性：classname，line-number，并定义了通用的方法及生成中间代码所用的CodeGen函数。

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

利用基类BaseNode，我们将其余类对其进行继承，大致分为以下几类：

- 划分程序区域类型
- 表达式类型
- 语句类型
- 类型、变量、函数等与定义相关的类型

**划分区域：**

划分区域的节点的主要作用是将各区域的语句综合起来，有序的连在区域节点之下。通过这种设计，我们可以将程序清晰的分为几个区域，及更加细分为子区域，最终到达叶子节点。

采用这种设计的好处是：

- 每种区域都有特定的类，指针也根据具体情况而特化，这样能使语法树的语义更加清楚。
- 利用多态的机制，为每个节点增加一个CodeGen的虚函数，这样通过定义每种类的CodeGen方法，我们并不需要完全知道孩子是什么类型的派生类，只需要调用他们的CodeGen方法即可。
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

Program分为定义部分和执行部分，定义部分分为一组变量定义和一组函数定义。执行部分就是要执行的语句列表。



**表达式类型：**

表达式类型的节点都继承于基类Expr，共分为：

- IDExpr：存储立即数、变量名的表达式
- BinExpr：二元计算型的表达式
- UnaryExpr：一元计算型的表达式
- FuncallExpr：调用函数返回结果的表达式
- ArrayExpr：指定下标的数组的表达式



**语句类型：**

语句类型的节点都继承于基类Stmt，共分为：

- AssignStmt：赋值语句，左面是变量，右面是值
- ForStmt：循环类型的语句
- FunCallStmt：调用函数的语句（无用返回值）
- RepeatStmt：循环类型的语句
- WhileStmt：循环类型的语句
- IfStmt：条件控制类型的语句
- ElseStmt：和If配套使用
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

- 存有MyType类型的type
- IDList，变量名表

​	

### 五、语法树可视化

语法树的可视化帮助我们更好地理解在parse过程中建立语法树的过程，也方便我们对语法编写的正确性进行验证。

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

如上代码所示，`Dict`类中字典的键是各个节点的类名，对应的值可以有两种类型，一种是代表语法树已经到达了叶节点的字符串类型，另一种是表示非叶节点的字典列表类型。字符串类型将存储叶节点的值，例如变量名、变量类型、数字、字符等。字典列表类型，可以存储不定数量的字典，通过`vector`进行存储。将语法树转为字典，主要是通过在`Dict`类的构造函数中对当前节点的类型进行判断，然后对不同节点的定义进行适配分析，用DFS的方式遍历传入的语法树，将所有节点的信息加入到字典中。再通过该类的`public`函数中的`void writeJSONFile(string filepath);`将转换后的字典写入到指定的JSON文件中，方便后续解析。



##### 2、graphviz可视化

本项目的课时化代码使用了graphviz库，该库可以通过调用已经封装好的函数进行树型图的可视化，只需要调用画节点和连接线的函数，再将绘制图像以图片的形式输出到指定的路径下，便可以达到输出语法树的功能。graphviz库不需要人为设置具体的绘制细节（图片大小、图中各种元素的位置等），库中的`Digraph`类会根据要绘制的语法树的形状安排各个节点的位置，调整合适的图片大小，使用起来十分方便。具体实现中，使用了python代码对输出到指定JSON文件的语法树字典进行读取，Python可以解读JSON文件，之间转化为Python的基本类型之一——字典。再使用DFS对字典进行遍历，用直线将各级父子节点连接，在叶节点后绘制代表具体的叶节点值的一个节点。

可视化部分具体的使用伪代码如下所示：

```c++
// ast_root为要传入的语法树的节点指针
Dict *astDict = new Dict(ast_root); // 将语法树转为字典类型
astDict->writeJSONFile("test.json"); // 将字典写入到指定路径下的JSON文件中
```

存入JSON文件后，再通过运行visualize.py中的Python代码来绘制语法树：

```shell
python visulilze.py
```



##### 3、可视化结果

对需要测试的三个pascal文件进行解析并生成相应的语法树后，使用上述的可视化方法进行可视化，生成的语法树结果如下图所示：

###### 快速排序程序语法树可视化

###### 矩阵乘法程序语法树可视化

###### 选课助手程序语法树可视化







### 六、中间代码生成

##### 1、基本框架与语法树遍历方法：

在中间代码的生成中，我们主要使用的框架是LLVM框架，使用的版本是6.0 （ubuntu apt安装）

如上文所述，每个节点都有属于自己的虚函数方法。这样的话就可以采用一种“自驱动”的遍历方式。父节点调用子节点的Codegen方法，子节点的CodeGen方法也会进一步调用子节点的方法，如此以来就很自然的实现了语法树遍历，不用特别考虑遍历的顺序就可以实现正确顺序的遍历。

例如在赋值语句的CodenGen方法中：

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

这个节点可以直接调用

### 七、编译器测试

### 八、心得与体会



高婧：本次项目实现了从用flex和bison对代码进行词法分析和语法分析，再转化为使用自定义类的语法树，然后用llvm生成中间代码。整个实验的过程与上课的理论相契合，在课上对于比较抽象的语法树，我没有马上理解。在本次项目中我实现了语法树的可视化部分，再项目开发过程中对课堂上所讲述的语法树的分析、建立过程有了更深的理解。语法树根据定义的语法规则一步步自顶而下地从根节点到叶节点建立语法树的过程可以在可视化时清楚地了解。为了便于可视化，使用了graphviz库的python库，使得可视化部分的代码编写难度降低，代码结构更加清晰。本项目的开发让我对于编译器的工作目的和词法、语法分析的方式都有了更好的理解，对课堂的内容也进行了加深巩固，而且和组员的项目合作过程也很融洽，整体上收获很大。

