#include <iostream>

#include <cuda_runtime.h>

#include "kernel.h"

int main()
{
   srand(static_cast<unsigned int>(time(0)));

   const size_t sizeOfArray = 16 * 1024 * 1024;
   const size_t byteSize = sizeOfArray * sizeof(float);

   float *hArray = new float[sizeOfArray];
   int *hResult = new int[2];
   hResult[0] = 0;
   hResult[1] = 0;

   for (size_t i = 0 ; i < sizeOfArray; i++)
      hArray[i] = 0.f;
      hArray[sizeOfArray - 1] = 2.0f;
     // hArray[i] = hArray[i] = static_cast <float> (rand()) / (RAND_MAX / 100.f);


//   for (size_t i = 0; i < sizeOfArray; i++)
//      std::cout << hArray[i] << " ";

   float *dArray = nullptr;
   int *dResult = nullptr;

   cudaMalloc((void**)&dArray, byteSize);
   cudaMalloc((void**)&dResult, 2 * sizeof(float));

   cudaMemcpy(dArray, hArray, byteSize, cudaMemcpyKind::cudaMemcpyHostToDevice);
   cudaMemcpy(dResult, hResult, 2 * sizeof(int), cudaMemcpyKind::cudaMemcpyHostToDevice);

   float x = 2.f;

   cudaEvent_t start, stop;
   cudaEventCreate(&start);
   cudaEventCreate(&stop);

   cudaEventRecord(start, 0);
   linearSearchGPU(dArray, x, dResult, sizeOfArray);
   cudaEventRecord(stop, 0);
   cudaEventSynchronize(stop);

   cudaMemcpy(hResult, dResult, 2 * sizeof(int), cudaMemcpyKind::cudaMemcpyDeviceToHost);

   float ms = 0.f;
   cudaEventElapsedTime(&ms, start, stop);

   std::cout << "Time: " << ms << " ms" << std::endl;
   std::cout << "Element: " << hResult[0] << std::endl;
   std::cout << "Index: " << hResult[1] << std::endl;

   delete[] hArray;
   delete[] hResult;
   cudaFree(dArray);
   cudaFree(dResult);

   return 0;
}