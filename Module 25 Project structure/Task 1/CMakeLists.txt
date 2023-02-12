cmake_minimum_required(VERSION 3.22)
project("Operation simulator" VERSION 0.1)

set(CMAKE_CXX_STANDARD 14)
include_directories(include)
include_directories(src)

add_executable(mod25_2 src/main.cpp include/node.h src/node.cpp include/operation.h src/operation.cpp)
