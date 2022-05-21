flex -o ./parse/lex.cpp ./parse/lexical.l
bison -y -d -o ./parse/yacc.cpp ./parse/grammar.y
g++ `llvm-config --libs core native --cxxflags --ldflags` -fexceptions ./ast/AST_node.h ./gen/AST_node.cpp ./gen/CodeGen.hpp ./gen/CodeGen.cpp ./astVisualize/dict.cpp ./parse/lex.cpp ./parse/yacc.cpp main.cpp -o parser.out
rm -f result.ll
./parser.out
# clang result.ll -o result
