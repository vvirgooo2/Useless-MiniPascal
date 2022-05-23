rm -f result.ll result
./parser.out ./parse/test.pas
clang result.ll -o result
./result