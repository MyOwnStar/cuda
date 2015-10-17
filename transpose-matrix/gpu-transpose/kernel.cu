#include "kernel.h"

#include <cuda_runtime.h>
#include <device_launch_parameters.h>

#define BLOCK_SIZE 16

__global__ void transGPU(const float *inMatrix, float *outMatrix, const size_t row, const size_t column)
{
    size_t xIndex = blockIdx.x * blockDim.x + threadIdx.x;
    size_t yIndex = blockIdx.y * blockDim.y + threadIdx.y;

    if ((xIndex < column) && (yIndex < row))
    {
        size_t inIndex = yIndex * column + xIndex;
        size_t outIndex = xIndex * row + yIndex;

        outMatrix[outIndex] = inMatrix[inIndex];
    }
}

void transpose(const float *inputMatrix, float *outputMatrix, const size_t row, const size_t column)
{
    dim3 threadsPerBlock(BLOCK_SIZE, BLOCK_SIZE, 1);
    dim3 blocksPerGrid((column + BLOCK_SIZE - 1) / BLOCK_SIZE, (row + BLOCK_SIZE - 1) / BLOCK_SIZE, 1);

    transGPU<<< blocksPerGrid, threadsPerBlock >>>(inputMatrix, outputMatrix, row, column);
}
