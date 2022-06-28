文档结构：

ast：ast.h 语法树结构定义

astVisualize：dict.cpp visualize.py dict.hpp  语法树可视化模块

gen：AST_node.cpp CodeGen.cpp CodeGen.hpp 代码生成模块

parse：lexical.l grammar.y 词法分析与语法分析





编译脚本：make.sh 运行后默认在本级目录生成parser.out可执行文件

运行脚本：run.sh     默认编译parse文件夹中的test.pas文件，生成result可执行文件并运行

测试：使用./testbench/linnux-amd64-x ./result 指令进行测试

