#include <iostream>
#include <iomanip>
#include <chrono>
#include <cmath>


double f(double x)
{
   return 4 / (1 + x * x);
}

double calcIntegral(unsigned long n)
{
   double h = 1 / static_cast<double>(n);

   double sum = 0;
   for (size_t i = 0; i < n; i++)
   {
      double x = (i + 0.5) * h;
      sum += f(x);
   }

   return sum / n;
}


int main()
{
<<<<<<< HEAD
   const double PI = 3.141592653589793;

=======
>>>>>>> a9673d92f0dff39434f04bbc253f5b9203265480
   unsigned long stepCount = 5000000;

   typedef std::chrono::steady_clock::time_point Time;

   std::cout << "Computing... ";
   Time start = std::chrono::steady_clock::now();
   double result = calcIntegral(stepCount);
   Time stop = std::chrono::steady_clock::now();
   std::cout << "OK" << std::endl;

   std::cout << "Result: " << std::setprecision(7) << std::fixed << result << std::endl;
   std::cout << "Time: " << std::chrono::duration_cast<std::chrono::milliseconds>(stop - start).count()
             << " ms" << std::endl;

   return 0;
}