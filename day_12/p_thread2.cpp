#include <iostream>
#include <cmath>
#include <omp.h>    // compile with -fopenmp (for gcc,clang)
#include <thread>
#include <vector>
#include <mutex>
#include <future>
#include "timer.hpp"
/*
We use OpenMP to numerically compute the definite integral of
4/(1+x*x) dx
in the interval [0, 1], which happens to be PI.
If everything works well, our solution should be darn close.
Well...

*/
const double PI = 3.141592653589793238463; // target solution
const uint cores = omp_get_num_procs();
std::mutex mtx;

double pi_worker(int ibegin, int iend, double const step)
{
  double tmp = 0;
  double x{0};
  for (int i=ibegin; i<iend; ++i)
  {
    x = (i - 0.5)*step;
    tmp += 4.0 / (1.0 + x*x);
  }
  return tmp*step;
}


int main()
{
  Timer th("Compute PI");
  double sums[cores];
  double pi_num = 0;
  double const N = 1e8;
  double const step = 1.0/(double)N;
  // do the computation
  std::future<double> t[cores];
  for (uint i=0; i < cores; ++i)
  {
    float n = (float)(N/cores);
    int ibegin = (n*i);
    int iend = (n*(i+1))-1;
    auto a = std::async(std::launch::async, pi_worker, ibegin, iend, step);
    t[i] = std::move(a);
  }
  for (uint i=0; i < cores; ++i)
  {
    sums[i] = t[i].get();
  }
  for (uint j=0; j<cores; ++j)
  {
    pi_num += sums[j];
  }
  double diff = std::fabs(PI - pi_num);
  std::cout << "Numerical PI is this much off: " << std::to_string(diff) << " -- " << (diff < 1e-6 ? "looks good " : "that seems wrong :/") << "\n";
  return 0;
}
