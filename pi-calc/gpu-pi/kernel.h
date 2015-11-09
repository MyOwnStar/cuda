#ifndef KERNEL_H
#define KERNEL_H

void calcIntegral(float *array, const float h, const long stepCount, const int treads, const int blocks);

#endif // KERNEL_H