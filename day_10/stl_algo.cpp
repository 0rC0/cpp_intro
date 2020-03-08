#include <iostream>
#include <algorithm>
#include <vector>

int main()
{
  std::vector<int> v{1,2,3,4,5,6,7,8};
  bool r = std::all_of(v.cbegin(), v.cend(), [](int i) {return i % 2 == 0;});
  std::cout << r << '\n';
  size_t c1 = std::count(v.cbegin(), v.cend(), 5);
  std::cout << c1 << std::endl;
  size_t c2 = std::count(v.cbegin(), v.cend(),[](int i){return i % 2 == 0;});
  std::cout << c2 << std::endl;
}
