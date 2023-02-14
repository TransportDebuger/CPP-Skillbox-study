cmake_minimum_required(VERSION 3.22)
project(OOP_ht1)

set(CMAKE_CXX_STANDARD 14)

include_directories(include)
include_directories(src)
add_executable(mplayer src/main.cpp include/track.h src/track.cpp include/mplayer.h src/mplayer.cpp)
