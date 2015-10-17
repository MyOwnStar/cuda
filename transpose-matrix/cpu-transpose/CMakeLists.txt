cmake_minimum_required(VERSION 2.8)
project(cputrans)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp transpose.h transpose.cpp utils/tools.h utils/tools.cpp)
add_executable(cputrans ${SOURCE_FILES})