#include <iostream>
#include <omp.h>    // compile with -fopenmp (for gcc,clang)
#include <chrono>
#include <cmath>
#include <vector>
#include "timer.hpp"

int fx(float x)
{
    return int(std::sqrt(x)) % 100;
}

int main()
{
  Timer t("histogram");
  //compute the histogram
  int rest[100]{};
  float sum{0};
  float N = 2e8;
  #pragma omp parallel
  {
    int a[100]{};
    int tmp{0};
    #pragma omp for private(tmp)
    for (long long int x=1; x<(long long int)N+1; ++x)
    {
        tmp = fx(x);
        //std::cout << x << '\n';
        #pragma omp atomic
        rest[tmp] += 1;
    }
  }
  for (int j=0; j<100; ++j)
  {
    std::cout << (j+1) << ": " << rest[j] << '\n';
    sum += rest[j];
  }
    std::cout << sum << '\n';

}
