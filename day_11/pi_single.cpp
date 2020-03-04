#include <iostream>
#include <omp.h>    // compile with -fopenmp (for gcc,clang)
#include <chrono>
#include <cmath>
/*
We use OpenMP to numerically compute the definite integral of
4/(1+x*x) dx
in the interval [0, 1], which happens to be PI.
If everything works well, our solution should be darn close.
Well...

*/
const double PI = 3.141592653589793238463; // target solution

/**
A timer class -- which starts measuring when constructed and tells the elapsed time when destructed.
Give it a name when constructing (so it can tell the user what was being timed).
Call stop() if you want it to stop at a specific point.
*/
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


double getPI(int num_steps)
{
  Timer t("Compute PI");

  double x, pi, sum = 0.0;

  double step = 1.0 / (double)num_steps;
  for (int i = 0; i < num_steps; ++i)
  {
    x = (i - 0.5)*step;
    sum += 4.0 / (1.0 + x*x);
  }
  pi = step * sum; // normalize once
  return pi;
}

int main()
{
  double N = 1e8;

  // do the computation
  double pi_num = getPI(N);
  double diff = std::fabs(PI - pi_num);
  std::cout << "Numerical PI is this much off: " << std::to_string(diff) << " -- " << (diff < 1e-6 ? "looks good " : "that seems wrong :/") << "\n";
  return 0;
}