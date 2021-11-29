cmake_minimum_required(VERSION 3.19)
project(Dual_pointer)

set(CMAKE_CXX_STANDARD 11)
include_directories(src)
include_directories(include)
add_executable(Dual_pointer main.cpp include/Speed_pointer.h src/Speed_pointer.cpp include/Basic_double_pointer.h src/Basic_double_pointer.cpp)