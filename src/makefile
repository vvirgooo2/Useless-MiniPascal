LLVM_INCLUDE = -I /usr/include/llvm-6.0 -I /usr/include/llvm-c-6.0
LLVM_LIBS = -L /usr/lib/llvm-6.0/lib
# ast:
# 	flex -o ./parse/lex.yy.cpp ./parse/lexical.l
# 	bison -d -o ./parse/y.tab.cpp ./src/parser/temp.y
# 	g++ ./lex/lex.yy.cpp ./parse/y.tab.cpp -o a.out

run:
	flex -o ./parse/lex.cpp ./parse/lexical.l
	bison -y -d -o ./parse/yacc.cpp ./parse/grammar.y
	g++ `llvm-config --libs core native --cxxflags --ldflags` -fexceptions 
	./ast/AST_node.h ./gen/AST_node.cpp ./gen/CodeGen.hpp ./gen/CodeGen.cpp 
	./astVisualize/dict.cpp 
	./parse/lex.cpp ./parse/yacc.cpp ./main.cpp -o a.out


	# g++ -g `llvm-config --libs core native --cxxflags --ldflags` -fexceptions -ll
	# ast/AST_node.h gen/AST_node.cpp gen/CodeGen.hpp gen/CodeGen.cpp astVisualize/dict.cpp parse/yacc.hpp parse/lex.cpp parse/yacc.cpp
	# main.cpp -std=c++11
	#  -o ./testbench/bin/ge.out

clean:
	rm -f lex.cpp yacc.cpp
	rm -f yacc.hpp lex.hpp




