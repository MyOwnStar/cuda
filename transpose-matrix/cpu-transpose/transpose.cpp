#include <iostream>

void transpose(float *inputMatrix, float *outputMatrix, const size_t row, const size_t column)
{
    for (size_t i = 0; i < row; i++)
    {
        for (size_t j = 0; j < column; j++)
        {
            outputMatrix[j * row + i] = inputMatrix[i * column + j];
        }
    }
}
