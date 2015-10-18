#include "cpumult.h"

// TODO: Потестить
void multMatrix(const float *matrixA, const size_t rowA, const size_t columnA,
                const float *matrixB, const size_t rowB, const size_t columnB, float *matrixC)
{
   for (size_t i = 0; i < rowA; i++)
   {
      for (size_t j = 0; j < columnB; j++)
      {
         matrixC[i * columnB + j] = 0;
         for (size_t k = 0; k < rowB; k++)
         {
            matrixC[i * columnB + j] += matrixA[i * columnA + k] * matrixB[k * columnB + j];
         }
      }
   }
}
