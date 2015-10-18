#include <iostream>
#include <iomanip>
#include <chrono>

#include "cpumult.h"
#include "utils/tools.h"


int main()
{
   const size_t rowA = 2048;
   const size_t columnA = 1536;
   const size_t matrixSizeA = rowA * columnA;

   const size_t rowB = 1536;
   const size_t columnB = 4096;
   const size_t matrixSizeB = rowB * columnB;

   const size_t matrixSizeC = rowA * columnB;

   std::cout << "Matrix A (size): " << rowA << "x" << columnA << std::endl;
   std::cout << "Matrix B (size): " << rowB << "x" << columnB << std::endl;

   getCPUInfo();

   std::cout << "Allocating RAM... ";
   float *matrixA = new float[matrixSizeA];
   float *matrixB = new float[matrixSizeB];
   float *matrixC = new float[matrixSizeC];
   std::cout << "OK!" << std::endl;

   std::cout << "Filling matrix... ";
   fillMatrix(matrixA, rowA, columnA);
   fillMatrix(matrixB, rowB, columnB);
   std::cout << "OK!" << std::endl;


//   printMatrix(matrixA, rowA, columnA);
//   std::cout << "\n";
//   printMatrix(matrixB, rowB, columnB);


   std::cout << "Computing... ";

   typedef std::chrono::steady_clock::time_point Time;

   Time start = std::chrono::steady_clock::now();
   multMatrix(matrixA, rowA, columnA, matrixB, rowB, columnB, matrixC);
   Time end = std::chrono::steady_clock::now();

   std::cout << "OK" << std::endl << std::endl;

   std::cout << "Time: " << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count()
             << " ms" << std::endl;


   //printMatrix(matrixC, rowA, columnB);


   delete[] matrixA;
   delete[] matrixB;
   delete[] matrixC;


   return 0;
}