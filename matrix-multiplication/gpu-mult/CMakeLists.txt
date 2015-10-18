CMAKE_MINIMUM_REQUIRED(VERSION 2.8)
PROJECT(GPUTest)

FIND_PACKAGE(CUDA)

INCLUDE(FindCUDA)

INCLUDE_DIRECTORIES(/usr/local/cuda-6.5/include ${CUDA_SOURCES})

FILE(GLOB SOURCES main.cpp kernel.h kernel.cu utils/tools.h utils/tools.cpp)
CUDA_ADD_EXECUTABLE(GPUTest ${SOURCES})

LIST(APPEND CMAKE_CXX_FLAGS "-std=c++11")

LIST(APPEND CUDA_NVCC_FLAGS --compiler-options -fno-strict-aliasing -lineinfo -use_fast_math -Xptxas -dlcm=cg)
LIST(APPEND CUDA_NVCC_FLAGS -gencode arch=compute_11, code=sm_11)
LIST(APPEND CUDA_NVCC_FLAGS -gencode arch=compute_21, code=sm_21)