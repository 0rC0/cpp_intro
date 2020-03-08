#include <iostream>
#include <cmath>
#include <omp.h>    // compile with -fopenmp (for gcc,clang)
#include <thread>
#include <vector>
#include <atomic>
#include <future>
#include "timer.hpp"

std::atomic<int> counter(0);
int spinFor(std::chrono::seconds t = std::chrono::seconds(3))
{
auto t_start_(std::chrono::high_resolution_clock::now());
while ((std::chrono::high_resolution_clock::now() - t_start_) < t) {}; // spin
std::cout << "c " << ++counter << " done \n";
return counter;
}

int main()
{
const int N = 40000;
std::vector<std::future<int>> result;
for (int i = 0; i < N; ++i)
{
  auto a = std::async(std::launch::async, []() { return spinFor(); });
result.push_back( std::move(a) );
}

for (int i = 0; i < N; ++i)
{
result[i].get();
}
int k;
std::cin >> k;
return 0;
}
