cmake_minimum_required(VERSION 3.19)
project(Traversal_of_binary_tree)

set(CMAKE_CXX_STANDARD 14)
include_directories(src)
include_directories(include)
add_executable(Traversal_of_binary_tree main.cpp src/Tree.cpp include/Tree.h src/Make_Tree.cpp src/BST.cpp include/BST.h)