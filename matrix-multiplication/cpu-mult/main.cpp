#include <iostream>
#include <iomanip>
#include <chrono>

#include "cpumult.h"
#include "utils/tools.h"


int main()
{
   getCPUInfo();

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

   if (columnA != rowB)
   {
      std::cout << "SORRY: ColumnA must be equal rowB" << std::endl;
      std::cout << "TRY AGAIN DUDE!" << std::endl;
      exit(true);
   }

   std::cout << "Iterations: ";
   std::cin >> iterations;

   std::cout << "Matrix A (size): " << rowA << "x" << columnA << std::endl;
   std::cout << "Matrix B (size): " << rowB << "x" << columnB << std::endl;

   const size_t matrixSizeA = rowA * columnA;
   const size_t matrixSizeB = rowB * columnB;
   const size_t matrixSizeC = rowA * columnB;

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
   for (size_t i = 0; i <= iterations; i++)
      multMatrix(matrixA, rowA, columnA, matrixB, rowB, columnB, matrixC);
   Time end = std::chrono::steady_clock::now();

   std::cout << "OK" << std::endl << std::endl;

   std::cout << "Time: " << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count()
             << " ms" << std::endl;


   //printMatrix(matrixC, rowA, columnB);


   delete[] matrixA;
   delete[] matrixB;
   delete[] matrixC;


#ifdef _WIN32

   std::cin.ignore();
   std::cin.get();

#endif


   return 0;
}