rm -f result result.ll
./parser.out
clang result.ll -o result
./result