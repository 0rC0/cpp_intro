#include <iostream>
#include <omp.h>    // compile with -fopenmp (for gcc,clang)
#include <chrono>
#include <cmath>
#include <vector>

class Timer
{
public:
  Timer(const std::string name = "unknown computation")
    : omp_t_start(omp_get_wtime()),
    t_wall_sec(0)
  {
    std::cout << name.c_str() << " running ...\n";
  }

  void stop()
  {
    t_wall_sec = round((omp_get_wtime() - omp_t_start) * 100) / 100; // 2 digits
  }

  ~Timer()
  {
    if (t_wall_sec == 0) stop();
    std::cout << "Time: " << t_wall_sec << " s (wall)\n\n";
  }

  double omp_t_start; // start time
  double t_wall_sec; // wall time
};

unsigned long long int fx(unsigned long long int x)
{
    return int(std::sqrt(x)) % 100;
}

int main()
{
  Timer t("histogram");
  //compute the histogram
  int a[100]{};
  unsigned long long sum{0};
  unsigned long long int N = 2e5;
  #pragma omp parallel
  //{
    for (unsigned long long int x=0; x<N; ++x)
    {
        unsigned long long int tmp = fx(x);
        //std::cout << x << '\n';
        a[tmp] += 1;
    }
    #pragma omp atomic
    sum += a[j];
    for (int j=0; j<100; ++j)
    {
      std::cout << (j+1) << ": " << a[j] << '\n';
    }
    std::cout << sum << '\n';
//}

}
