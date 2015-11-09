#include <iostream>
#include <iomanip>

#include "kernel.h"

#include <cuda_runtime.h>
#include <cmath>

int main()
{
   const long stepCount = 5000000;
   const float h = 1.f / static_cast<float>(stepCount);

   int threads = 30;
   int blocks = 8;

   float *hArray = new float[threads * blocks];

   float *dArray = nullptr;
   cudaMalloc((void**)&dArray, threads * blocks * sizeof(float));
   cudaMemset(dArray, 0, threads * blocks * sizeof(float));

   cudaEvent_t start, stop;
   cudaEventCreate(&start);
   cudaEventCreate(&stop);

   cudaEventRecord(start, 0);
   calcIntegral(dArray, h, stepCount, threads, blocks);
   cudaEventRecord(stop, 0);

   cudaEventSynchronize(stop);

   cudaMemcpy(hArray, dArray, threads * blocks * sizeof(float), cudaMemcpyKind::cudaMemcpyDeviceToHost);

   float sum = 0;
   for (int i = 0; i < threads * blocks; i++)
   {
      sum += hArray[i];
   }

   sum *= h;

   float ms = 0;
   cudaEventElapsedTime(&ms, start, stop);

   std::cout << "Result: " << std::setprecision(7) << std::fixed << sum << std::endl;
   std::cout << "Time: " << std::setprecision(2) << ms << " ms" << std::endl;

   delete[] hArray;
   cudaFree(dArray);

   return 0;
}
