#include "kernel.h"

#include <cuda_runtime.h>
#include <device_launch_parameters.h>
#include <cmath>


__global__ void searchGPU(float *data, const float x, int *result)
{
   int idx = blockIdx.x * blockDim.x + threadIdx.x;

   if (data[idx] == x)
   {
      result[0] = static_cast<int>(data[idx]);
      result[1] = idx;
   }
}

void linearSearchGPU(float *data, const float x, int *result, const size_t n)
{
   int threads = 512;
   int blocks = n / threads;
//   dim3 threads(n, n);
//   dim3 blocks(1, 1);
//
//   if (n*n > 512){
//      threads.x = 512;
//      threads.y = 512;
//      blocks.x = ceil(double(n)/double(threads.x));
//      blocks.y = ceil(double(n)/double(threads.y));
//   }

   searchGPU<<< blocks, threads>>>(data, x, result);
}