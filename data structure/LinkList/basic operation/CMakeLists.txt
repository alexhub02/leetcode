cmake_minimum_required(VERSION 3.19)
project(basic_operation)

set(CMAKE_CXX_STANDARD 14)
include_directories(src)
include_directories(include)
add_executable(basic_operation main.cpp src/LinkList.cpp include/LinkList.h src/test_func.cpp include/test_func.h)