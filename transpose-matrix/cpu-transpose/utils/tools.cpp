#include "tools.h"

#ifdef _WIN32

    #include <intrin.h>
    #include <iomanip>

#else

    #include <fstream>
    #include <sstream>
    #include <iomanip>

#endif

void fillMatrix(float *matrix, const size_t row, const size_t column)
{
    std::srand(std::time((0)));

    const float X = 100.f;

    for (size_t i = 0; i < row; i++)
    {
        for (size_t j = 0; j < column; j++)
        {
            matrix[i * column + j] = static_cast<float>(std::rand()) / (static_cast<float> (RAND_MAX / X));
        }
    }
}

void printMatrix(float *matrix, const size_t row, const size_t column)
{
    for (size_t i = 0; i < row; i++)
    {
        for (size_t j = 0; j < column; j++)
        {
            std::cout << std::fixed << std::setprecision(4) << std::setw(10) << matrix[i * column + j];
        }
        std::cout << std::endl;
    }
}

void getCPUInfo()
{

#ifdef _WIN32

   // Get extended ids.
   int CPUInfo[4] = {-1};
   __cpuid(CPUInfo, 0x80000000);
   unsigned int nExIds = CPUInfo[0];

   // Get the information associated with each extended ID.
   char CPUBrandString[0x40] = { 0 };
   for(unsigned int i = 0x80000000; i <= nExIds; i++)
   {
       __cpuid(CPUInfo, i);

       // Interpret CPU brand string and cache information.
       if  (i == 0x80000002)
       {
           memcpy( CPUBrandString, CPUInfo, sizeof(CPUInfo));
       }
       else if(i == 0x80000003)
       {
           memcpy( CPUBrandString + 16, CPUInfo, sizeof(CPUInfo));
       }
       else if(i == 0x80000004)
       {
           memcpy(CPUBrandString + 32, CPUInfo, sizeof(CPUInfo));
       }
   }
   std::cout << "CPU: " << CPUBrandString << std::endl;

#else

   std::string line;
   std::ifstream finfo("/proc/cpuinfo");

   while(getline(finfo,line))
   {
       std::stringstream str(line);
       std::string itype;
       std::string info;

       if (getline(str, itype, ':') && getline(str, info) && itype.substr(0, 10) == "model name")
       {
          std::cout << "CPU: " << info << std::endl;
          break;
       }
   }

#endif

}