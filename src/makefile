# LLVM_INCLUDE = -I /usr/include/llvm-6.0 -I /usr/include/llvm-c-6.0
# LLVM_LIBS = -L /usr/lib/llvm-6.0/lib
# ast:
# 	flex -o ./parse/lex.yy.cpp ./parse/lexical.l
# 	bison -d -o ./parse/y.tab.cpp ./src/parser/temp.y
# 	g++ ./lex/lex.yy.cpp ./parse/y.tab.cpp -o a.out

gentest0:
	g++ `llvm-config --libs core native --cxxflags --ldflags` -fexceptions  ast/AST_node.h gen/AST_node.cpp gen/CodeGen.hpp gen/CodeGen.cpp -o ./testbench/a.out
	./testbench/a.out
	clang result.ll -o result
	./result



