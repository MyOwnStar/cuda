#include <iostream>

void fillMatrix(float *matrix, const size_t row, const size_t column);

void printMatrix(float *matrix, const size_t row, const size_t column);

// Information about your current CPU like:
// Intel(R) Core(TM)2 Quad CPU Q9300 @ 2.5GHz
// TODO: проверить на разных платформах
void getCPUInfo();