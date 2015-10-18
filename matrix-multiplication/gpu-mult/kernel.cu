#include "kernel.h"

#include <cuda_runtime.h>
#include <device_launch_parameters.h>

#include <cmath>

#define TILE_SIZE 16


// ЗАКОММЕНТИРОВАЛ в ./crt/gost_runtime.h 243 строчку, заработало

__global__ void multMatrixGPU(const float *matrixA, const size_t rowA, const size_t columnA,
                           const float *matrixB, const size_t rowB, const size_t columnB, float *matrixC)
{
   __shared__ float ds_A[TILE_SIZE][TILE_SIZE];
   __shared__ float ds_B[TILE_SIZE][TILE_SIZE];

   int tx = threadIdx.x;
   int ty = threadIdx.y;

   int row = blockIdx.y * blockDim.y + ty;
   int col = blockIdx.x * blockDim.x + tx;

   float cValue = 0.0;

   for (int t = 0; t < (columnA - 1) / TILE_SIZE + 1; t++)
   {
      if (t * TILE_SIZE + tx < columnA && row < rowA)
      {
         ds_A[ty][tx] = matrixA[row * columnA + t * TILE_SIZE + tx];
      } else {
         ds_A[ty][tx] = 0.0;
      }

      if (t * TILE_SIZE + ty < rowB && col < columnB)
      {
         ds_B[ty][tx] = matrixB[(t * TILE_SIZE + ty) * columnB + col];
      } else {
         ds_B[ty][tx] = 0.0;
      }

      __syncthreads();

      for (int i = 0; i < TILE_SIZE; i++) {
         cValue += ds_A[ty][i] * ds_B[i][tx];
      }

      __syncthreads();
   }

   if (row < rowA && col < columnB) {
      matrixC[row * columnB + col] = cValue;
   }
}

void multMatrix(const float *matrixA, const size_t rowA, const size_t columnA,
                const float *matrixB, const size_t rowB, const size_t columnB, float *matrixC)
{
   dim3 threadsPerBlock(TILE_SIZE, TILE_SIZE, 1);
   dim3 blocksPerGrid((columnB - 1) / TILE_SIZE + 1, (rowA -1) / TILE_SIZE + 1, 1);

//   int numBlock;
//   int blockSize = 16;
//
//   cudaOccupancyMaxActiveBlocksPerMultiprocessor(&numBlock, multMatrixGPU, blockSize, 0);
//
//   int gridSize = (N * N + blockSize - 1) / blockSize;

   //std::cout << "BlockPerGrid: " << blocksPerGrid.x << "x" << blocksPerGrid.y << "\n";
   //std::cout << "ThreadsPerBlock: " << threadsPerBlock.y << "x" << threadsPerBlock.y << "\n\n";

   multMatrixGPU<<<blocksPerGrid, threadsPerBlock>>>(matrixA, rowA, columnB,
                                                     matrixB, rowB, columnB, matrixC);
   //multMatrix <<<gridSize, blockSize >>>(a, b, c, N);
}