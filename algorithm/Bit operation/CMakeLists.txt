cmake_minimum_required(VERSION 3.19)
project(Bit_operation)

set(CMAKE_CXX_STANDARD 14)
include_directories(src)
include_directories(include)
add_executable(Bit_operation main.cpp src/Bit_cal.cpp include/Bit_cal.h src/Bit_func.cpp)