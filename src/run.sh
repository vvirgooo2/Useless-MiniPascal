rm -f result.ll result
./parser.out
clang result.ll -o result
./result