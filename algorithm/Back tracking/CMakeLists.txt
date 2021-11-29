cmake_minimum_required(VERSION 3.19)
project(Back_tracking)

set(CMAKE_CXX_STANDARD 14)
include_directories(src)
include_directories(include)
add_executable(Back_tracking main.cpp src/test_func.cpp
        include/test_func.h src/Combine.cpp
        include/Combine.h src/Subsets.cpp
        include/Subsets.h src/Partition.cpp
        include/Partition.h src/Permutations.cpp
        include/Permutations.h)