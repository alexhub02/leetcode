cmake_minimum_required(VERSION 3.19)
project(Binary_search)

set(CMAKE_CXX_STANDARD 14)
include_directories(src)
include_directories(include)
add_executable(Binary_search main.cpp src/Binary_search.cpp include/Binary_search.h)