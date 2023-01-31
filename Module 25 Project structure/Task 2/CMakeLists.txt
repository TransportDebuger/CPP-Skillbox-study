cmake_minimum_required(VERSION 3.22)
project("Computer simulator" VERSION 1.0)

set(CMAKE_CXX_STANDARD 14)
include_directories(include)
include_directories(src)
add_executable(ssim src/main.cpp include/mod-ram.h src/mod-ram.cpp include/mod-cmp.h src/mod-cmp.cpp include/mod-cli.h src/mod-cli.cpp)
