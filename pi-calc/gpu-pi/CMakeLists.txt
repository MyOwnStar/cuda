cmake_minimum_required(VERSION 2.8)
project(picalc)

find_package(CUDA REQUIRED)

include(FindCUDA)

include_directories(/usr/local/cuda-6.5/include)

set(SOURCE_FILE main.cpp kernel.cu kernel.h)
cuda_add_executable(picalc ${SOURCE_FILE})

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

list(APPEND CUDA_NVCC_FLAGS --compiler-options -fno-strict-aliasing -lineinfo -use_fast_math -Xptxas -dlcm=cg)
list(APPEND CUDA_NVCC_FLAGS -gencode arch=compute_11,code=sm_11)
list(APPEND CUDA_NVCC_FLAGS -gencode arch=compute_21,code=sm_21)