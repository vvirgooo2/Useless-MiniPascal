flex -o ./parse/lex.cpp ./parse/lexical.l
bison -y -d -o ./parse/yacc.cpp ./parse/grammar.y
g++ `llvm-config --libs core native --cxxflags --ldflags` -fexceptions ./ast/AST_node.h ./gen/AST_node.cpp ./gen/CodeGen.hpp ./gen/CodeGen.cpp ./astVisualize/dict.cpp ./parse/lex.cpp ./parse/yacc.cpp main.cpp -o parser.out
rm -f result.ll
./parser.out
<<<<<<< HEAD
# clang result.ll -o result
=======
clang result.ll -o result
>>>>>>> b299ae2cd347548ba097013b244d3e6f60c93210
