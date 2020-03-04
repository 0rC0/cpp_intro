#include <iostream>
#include "my_vector.hpp"


int main()
{
  // size_t s{};
  // std::cin >> s;
  //
  // MyVector<int64_t> arr{s};
  //
  // for (auto & i : arr)
  //   std::cin >> i;
  //
  // for (auto const i: arr)
  //   std::cout << i << '\n';
  MyVector<size_t> v1{7};
  std::cout << "size of v1 before assignment: " << v1.sizes() << '\n';
  MyVector<size_t> v2{9};
  v1 = v2;
  std::cout << "size of v1: " << v1.sizes() << '\n';
  for (auto const i: v1)
      std::cout << i << '\n';
  v1.resize(2);
  std::cout << "size of v1 after resize(2): " << v1.sizes() << '\n';
  for (auto const i: v1)
     std::cout << i << '\n';
  std::cout << "push_back(1)\n";
  v1.push_back(1);
  std::cout << "size of v1 after push_back: " << v1.sizes() << '\n';
  for (auto const i: v1)
     std::cout << i << '\n';
}
