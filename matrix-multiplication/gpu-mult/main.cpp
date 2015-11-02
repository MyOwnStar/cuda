#include <iostream>

#include <cuda_runtime.h>

#include "kernel.h"
#include "utils/tools.h"


int main()
{
   getGPUInfo();

   size_t rowA = 0;
   size_t columnA = 0;
   size_t rowB = 0;
   size_t columnB = 0;
   size_t iterations = 0;

   std::cout << "Row (matrix A): ";
   std::cin >> rowA;
   std::cout << "Column (matrix A): ";
   std::cin >> columnA;

   std::cout << "Row (matrix B): ";
   std::cin >> rowB;
   std::cout << "Column (matrix B): ";
   std::cin >> columnB;

   std::cout << "Iterations: ";
   std::cin >> iterations;

   if (columnA != rowB)
   {
      std::cout << "SORRY: ColumnA must be equal RowB" << std::endl;
      std::cout << "TRY AGAIN DUDE" << std::endl;
      exit(true);
   }

   std::cout << std::endl;
   std::cout << "Matrix A (size): " << rowA << "x" << columnA << std::endl;
   std::cout << "Matrix B (size): " << rowB << "x" << columnB << std::endl;
   std::cout << std::endl;

   const size_t matrixSizeA = rowA * columnA;
   const size_t matrixSizeB = rowB * columnB;
   const size_t matrixSizeC = rowA * columnB;

   std::cout << "Allocating RAM (host)... ";
   float *hMatrixA = new float[matrixSizeA];
   float *hMatrixB = new float[matrixSizeB];
   float *hMatrixC = new float[matrixSizeC];
   std::cout << "OK!" << std::endl;

   std::cout << "Filling matrix... ";
   fillMatrix(hMatrixA, rowA, columnA);
   fillMatrix(hMatrixB, rowB, columnB);
   std::cout << "OK!" << std::endl;

   float *dMatrixA = nullptr;
   float *dMatrixB = nullptr;
   float *dMatrixC = nullptr;

   const size_t byteSizeA = matrixSizeA * sizeof(float);
   const size_t byteSizeB = matrixSizeB * sizeof(float);
   const size_t byteSizeC = matrixSizeC * sizeof(float);

   std::cout << "Allocating RAM (device)... ";
   cudaMalloc((void**)&dMatrixA, byteSizeA);
   cudaMalloc((void**)&dMatrixB, byteSizeB);
   cudaMalloc((void**)&dMatrixC, byteSizeC);
   std::cout << "OK!" << std::endl;

   std::cout << "Copying data to device... ";
   cudaMemcpy(dMatrixA, hMatrixA, byteSizeA, cudaMemcpyKind::cudaMemcpyHostToDevice);
   cudaMemcpy(dMatrixB, hMatrixB, byteSizeB, cudaMemcpyKind::cudaMemcpyHostToDevice);
   std::cout << "OK!" << std::endl;

   cudaEvent_t start, stop;
   cudaEventCreate(&start);
   cudaEventCreate(&stop);

   std::cout << "Computing... ";
   cudaEventRecord(start, 0);
   for (size_t i = 0; i <= iterations; i++)
      multMatrix(dMatrixA, rowA, columnA, dMatrixB, rowB, columnB, dMatrixC);
   cudaEventRecord(stop, 0);
   std::cout << "OK!" << std::endl;

   cudaEventSynchronize(stop);

   std::cout << "Copying data to host... ";
   cudaMemcpy(hMatrixC, dMatrixC, byteSizeC, cudaMemcpyKind::cudaMemcpyDeviceToHost);
   std::cout << "OK!" << std::endl;

   float ms = 0;
   cudaEventElapsedTime(&ms, start, stop);
   std::cout << "Time: " << ms << " ms" << std::endl;

//   printMatrix(hMatrixA, rowA, columnA);
//   std::cout << "\n";
//   printMatrix(hMatrixB, rowB, columnB);
//   std::cout << "\n";
//   printMatrix(hMatrixC, rowA, columnB);

   cudaEventDestroy(start);
   cudaEventDestroy(stop);

   delete[] hMatrixA;
   delete[] hMatrixB;
   delete[] hMatrixC;

   cudaFree(dMatrixA);
   cudaFree(dMatrixB);
   cudaFree(dMatrixC);


#ifdef _WIN32

   std::cin.ignore();
   std::cin.get();

#endif

   return 0;
}