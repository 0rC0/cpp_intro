#include <omp.h>    // compile with -fopenmp (for gcc,clang)
#include <chrono>

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
