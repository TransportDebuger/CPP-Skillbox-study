cmake_minimum_required(VERSION 3.22)
project("Company simulator")

set(CMAKE_CXX_STANDARD 17)
include_directories(include)
include_directories(src)
add_executable(cmpsmln src/main.cpp include/person.h src/person.cpp include/company.h src/company.cpp include/task.h src/task.cpp)
