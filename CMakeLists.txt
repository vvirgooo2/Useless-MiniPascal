cmake_minimum_required(VERSION 3.0.0)
add_compile_options(-std=c++11)

project(Te VERSION 0.1.0)

INCLUDE_DIRECTORIES(
 "/usr/include/llvm-6.0"
)
include(CTest)
enable_testing()

add_executable(parese )

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
