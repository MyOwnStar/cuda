#include <iostream>
#include <chrono>

#include "utils/tools.h"
#include "transpose.h"

#define ITERATIONS 20

int main()
{
    const size_t row = 2048;
    const size_t column = 2048;
    const size_t matrixSize = row * column;

    getCPUInfo();

    // Information
    std::cout << "Matrix size (float): " << row << "x" << column << std::endl;
    std::cout << "Iterations: " << ITERATIONS << std::endl;

    std::cout << "Allocating RAM... ";
    float *inputMatrix = new float[matrixSize];
    float *outputMatrix = new float[matrixSize];
    std::cout << "OK!" << std::endl;

    std::cout << "Filling matrix... ";
    fillMatrix(inputMatrix, row, column);
    std::cout << "OK!" << std::endl;

    //printMatrix(inputMatrix, row, column);

    typedef std::chrono::steady_clock::time_point Time;

    std::cout << "Computing... ";
    Time start = std::chrono::steady_clock::now();
    for (size_t i = 0; i < ITERATIONS; i++)
        transpose(inputMatrix, outputMatrix, row, column);
    Time stop = std::chrono::steady_clock::now();
    std::cout << "OK!" << std::endl << std::endl;

    std::cout << "Time: " << std::chrono::duration_cast<std::chrono::milliseconds>(stop - start).count()
              << " ms" << std::endl;

//    std::cout << "\n";
//    printMatrix(outputMatrix, column, row);


    delete[] inputMatrix;
    delete[] outputMatrix;

    return 0;
}
