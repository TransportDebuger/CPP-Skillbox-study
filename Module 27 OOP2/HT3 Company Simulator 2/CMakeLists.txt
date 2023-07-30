cmake_minimum_required(VERSION 3.22)
project("Company simulator")

set(CMAKE_CXX_STANDARD 17)
include_directories(inc)
include_directories(src)
add_executable(HT3_Company_Simulator_2 src/main.cpp src/person.cpp inc/person.h inc/company.h src/company.cpp src/routines.cpp inc/routines.h inc/task.h src/task.cpp)
