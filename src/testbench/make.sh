g++ `llvm-config --libs core native --cxxflags --ldflags` -fexceptions  ../ast/AST_node.h ../gen/AST_node.cpp ../gen/CodeGen.hpp ../gen/CodeGen.cpp -o a.out
./a.out

