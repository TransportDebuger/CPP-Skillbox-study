cmake_minimum_required(VERSION 3.22)
project(CellPhone VERSION 0.1 DESCRIPTION "Hometask 2 solution")

set(CMAKE_CXX_STANDARD 17)

include_directories(include)
include_directories(src)

add_executable(cellph src/main.cpp include/AddrBook.h src/AddrBook.cpp include/phone.h src/phone.cpp)
