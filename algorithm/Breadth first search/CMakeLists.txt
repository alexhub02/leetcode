cmake_minimum_required(VERSION 3.19)
project(Breadth_first_search)

set(CMAKE_CXX_STANDARD 14)
include_directories(src)
add_executable(Breadth_first_search main.cpp src/BFS.cpp src/BFS.h)