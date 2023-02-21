cmake_minimum_required(VERSION 3.22)
project(Mod26_OOP_HT3 VERSION 0.1 DESCRIPTION "Hometask 3 solution")

set(CMAKE_CXX_STANDARD 14)
include_directories(include)
include_directories(src)
add_executable(woperate src/main.cpp include/window.h src/window.cpp)
