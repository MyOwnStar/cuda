cmake_minimum_required(VERSION 2.8)
project(CPUTest)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp cpumult.h cpumult.cpp utils/tools.h
                                                utils/tools.cpp
                                                )

add_executable(CPUTest ${SOURCE_FILES})

