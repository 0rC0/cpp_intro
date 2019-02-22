#include <iostream>
#include <vector>
#include <algorithm>

// mplement a function with the following signature:
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
std::vector<size_t> filter(std::vector<size_t> const & input, TLambda const & l) {

    return std::for_each(input.begin(), input.end(), &l);
}

int main() {
  auto even = [] (auto const & elem) { return elem % 2 == 0; };
  auto odd = [] (auto const & elem) { return elem %2 != 0; };
  auto not_zero = [] (auto const & elem) { return elem != 0; };

  std::vector<size_t> v{0, 2, 3, 4, 5};

  filter(v,even);
  filter(v,odd);
  filter(v, not_zero);
}
