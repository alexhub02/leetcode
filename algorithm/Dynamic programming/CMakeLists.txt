cmake_minimum_required(VERSION 3.19)
project(Dynamic_programming)

set(CMAKE_CXX_STANDARD 14)
include_directories(src)
include_directories(include)
add_executable(Dynamic_programming main.cpp
        src/Basic_question.cpp include/Basci_question.h
        include/bag.h src/bag.cpp include/one_zero_bag.h
        src/one_zero_bag.cpp include/knapsack.h
        src/knapsack.cpp include/Rob.h src/Rob.cpp
        include/Stock_trading.h src/Stock_trading.cpp)