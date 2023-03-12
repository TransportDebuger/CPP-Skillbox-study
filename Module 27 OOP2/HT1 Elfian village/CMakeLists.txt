cmake_minimum_required(VERSION 3.22)
project(mod27_1)

set(CMAKE_CXX_STANDARD 14)
include_directories(include)
include_directories(src)
add_executable(mod27_1 main.cpp include/forest.h src/forest.cpp)
