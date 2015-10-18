
#ifdef _WIN32

   #include <intrin.h>

#else

   #include <string>
   #include <iostream>
   #include <fstream>
   #include <sstream>

#endif


// Information about your current CPU like:
// Intel(R) Core(TM)2 Quad CPU Q9300 @ 2.5GHz
// TODO: проверить на разных платформах
void getCPUInfo();



void getCPUInfo()
{
#ifdef _WIN32

   std::cout << "FROM WINDOWS" << "\n";
   // Get extended ids.
   int CPUInfo[4] = {-1};
   __cpuid(CPUInfo, 0x80000000);
   unsigned int nExIds = CPUInfo[0];

   // Get the information associated with each extended ID.
   char CPUBrandString[0x40] = { 0 };
   for(unsigned int i = 0x80000000; i <= nExIds; ++i)
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
       std::cout << "CPU:" << CPUBrandString << std::endl;
   }

#else

   std::cout << "FROM LINUX" << "\n";
   std::string line;
   std::ifstream finfo("/proc/cpuinfo");

   while(getline(finfo, line))
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

   finfo.close();

#endif
}