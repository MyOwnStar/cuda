#include <iostream>
#include <chrono>

#include "utils/tools.h"
#include "transpose.h"


int main()
{
    getCPUInfo();

    size_t row = 0;
    size_t column = 0;
    size_t iterations = 0;

    std::cout << "Row: ";
    std::cin >> row;
    std::cout << "Column: ";
    std::cin >> column;
    std::cout << "Itrations: ";
    std::cin >> iterations;

    const size_t matrixSize = row * column;

    // Information
    std::cout << "Matrix size (float): " << row << "x" << column << std::endl;

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
    for (size_t i = 0; i <= iterations; i++)
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
