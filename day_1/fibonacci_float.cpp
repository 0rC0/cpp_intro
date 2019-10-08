#include <iostream>

// Tasks for the computer lab III
// Write a function that takes two initial numbers n1 and n2 and a counter
// c and returns the c-th "fibonacci" number based on the two initial
// numbers
// It should accept any numeric type for the initial numbers!
// Write a program that asks the user for two floating point variables and
// then returns the 42nd "fibonacci number" for these floats

template <typename T>
T fibonacci(T n1, T n2, size_t const c)
{
  T sum{0};
  for (size_t i = 0; i < c; ++i)
  {
    sum = n1 + n2;
    std::cout << sum << '\n';
    n1 = n2;
    n2 = sum;
  }
  return sum;
}

int main()
{
  float n1 = 1.2345;
  float n2 = 2.3456;
  size_t c = 10;

  std::cout << fibonacci(n1, n2, c) << '\n';

}
