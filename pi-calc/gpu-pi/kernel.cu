#include "kernel.h"

#include <cuda_runtime.h>
#include <device_launch_parameters.h>


__device__ float f(float x)
{
   return 4.f / (1.f + x * x);
}

__global__ void calcIntegralGPU(float *array, const float h, const long stepCount,
                                                             const int threads,
                                                             const int blocks)
{
   int idx = blockIdx.x * blockDim.x + threadIdx.x;

   for (int i = idx; i < stepCount; i+= threads * blocks)
   {
      float x = (i + 0.5f) * h;
      array[idx] += f(x);
   }
}

void calcIntegral(float *array, const float h, const long stepCount,
                                               const int threads,
                                               const int blocks)
{
   dim3 blocksPerGrid = 30;
   dim3 threadPerBlocks = 8;

   calcIntegralGPU<<< blocksPerGrid, threadPerBlocks >>>(array, h, stepCount, threads, blocks);
}