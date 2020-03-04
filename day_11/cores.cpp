#include <iostream>
#include <omp.h>    // compile with -fopenmp (for gcc,clang)

// 6 Cores from cat /proc/cpuinfo

int main()
{
  #pragma omp parallel
  {
    std::cout << "Logical cores: " << omp_get_num_threads() << '\n';
    std::cout <<  "Max threads: " << omp_get_max_threads() << '\n';
  }  
}