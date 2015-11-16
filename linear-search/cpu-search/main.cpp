#include <iostream>
#include <iomanip>
#include <chrono>

int main()
{
   srand(static_cast<unsigned int>(time(0)));

   const size_t sizeOfArray = 16 * 1024 * 1024;

   float *array = new float[sizeOfArray];

   for(size_t i = 0; i < sizeOfArray; i++)
      array[i] = 0.0f;
      array[sizeOfArray - 1] = 2.0f;
      //array[i] = static_cast <float> (rand()) / (RAND_MAX / 100.f);


//   for (size_t i = 0; i < sizeOfArray; i++)
//      std::cout << array[i] << " ";

   std::cout << std::endl;

   float x = 2.0f;
   size_t index = 0;

   typedef std::chrono::steady_clock::time_point Time;

   Time start = std::chrono::steady_clock::now();
   for (size_t i = 0; i < sizeOfArray; i++)
   {
      if (array[i] == x)
      {
         x = array[i];
         index = i;
      }
   }
   Time end = std::chrono::steady_clock::now();

   std::cout << "X = " << x << std::endl;
   std::cout << "Index: " << index << std::endl;
   std::cout << "Element: " << x << std::endl;
   std::cout << "Time: " << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count()
             << " ms" << std::endl;


   delete[] array;

   return 0;
}