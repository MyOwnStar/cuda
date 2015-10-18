#include "tools.h"

#include <iomanip>
#include <chrono>

#include <cuda_runtime.h>


void fillMatrix(float *matrix, const size_t row, const size_t column)
{
   srand(std::chrono::high_resolution_clock::now().time_since_epoch().count());

   for (size_t i = 0; i < row; i++)
   {
      const float X = 100.f;
      for (size_t j = 0; j < column; j++)
      {
         matrix[i * column + j] = static_cast<float>(rand()) / (static_cast<float> (RAND_MAX / X));
      }
   }
}

void printMatrix(float *matrix, const size_t row, const size_t column)
{
   for (size_t i = 0; i < row; i++)
   {
      for (size_t j = 0; j < column; j++)
      {
         std::cout << std::fixed << std::setprecision(4) << std::setw(15) << matrix[i * column + j];
      }
      std::cout << std::endl;
   }
}

void getGPUInfo()
{
   cudaDeviceProp prop;

   int deviceCount = 0;
   cudaGetDeviceCount(&deviceCount);

   for(int i = 0; i < deviceCount; i++)
   {
      cudaGetDeviceProperties(&prop, i);

      std::cout << "GPU: " << prop.name << std::endl;
      std::cout << "Compute capability : " << prop.major << "." << prop.minor << std::endl;
   }
}