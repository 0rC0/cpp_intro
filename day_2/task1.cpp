#include <iostream>
#include <vector>
// Tasks for the computer lab I
// Implement a function with the following signature:
// template <typename TLambda>
// std::vector<size_t> filter(std::vector<size_t> const & input,
// TLambda const & l)
// It should return a vector with those elements of the input for which
// the lambda function evaluates to true .
// Write a main()-function that tests this behaviour with three lambdas:
// 1. a lambda that returns true for even elements.
// 2. a lambda that returns true for odd elements.
// 3. a lambda that returns true for elements that are not zero.

template <typename TLambda>
std::vector<size_t> filter(std::vector<size_t> const & input,
                            TLambda const & l)
{
  std::vector<size_t> vec;
  for (size_t elem : input)
  {
    if (l(elem))
      vec.push_back(elem);
  }
  return vec;
}

template <typename T>
void print_vector(std::vector<T> const & vec)
{
  for (T const & elem : vec)
    std::cout << elem << ' ';
  std::cout << '\n';
}


int main()
{
  auto is_even = [] (auto const & elem) {return elem % 2 == 0;};
  auto is_odd  = [] (auto const & elem) {return elem % 2 != 0;};
  auto not_zero = [] (auto const & elem) {return elem != 0;};

  std::vector<size_t> v{0, 1, 2, 3, 4};
  print_vector(filter(v, is_even));
  print_vector(filter(v, is_odd));
  print_vector(filter(v, not_zero));
}
