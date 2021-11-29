cmake_minimum_required(VERSION 3.19)
project(Recursive_operation)

set(CMAKE_CXX_STANDARD 14)
include_directories(src)
include_directories(include)
add_executable(Recursive_operation main.cpp src/Tree.cpp include/Tree.h src/Make_Tree.cpp include/Recur.h src/Recur.cpp src/Tree.h include/Tree.cpp src/Recur.h include/Recur.cpp)