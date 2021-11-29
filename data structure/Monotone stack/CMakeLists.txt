cmake_minimum_required(VERSION 3.19)
project(Monotone_stack)

set(CMAKE_CXX_STANDARD 14)
include_directories(src)
include_directories(include)
add_executable(Monotone_stack main.cpp src/stack_solution.cpp include/stack_solution.h)