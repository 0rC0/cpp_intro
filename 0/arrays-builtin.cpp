#include <iostream>

int main() {
  // declare built-in array of size 3:
  double dd[3];
  // can be {} initialised:
  double df[3]{3.1, 2.3, 1.1};
  // access elements also
  std::cout << df[0];
  df[1] = 32.0;
  df[77] = 32.0;
  //via [];
  // prints 3.1
  // you can also "assign through" []
  // memory access violation, no error, kills kittens
  size_t constexpr s = 100;
  double dg[s];
  // only works because s is constexpr

  // to prevent unused variables compile error
  std::cout << dd << '\n' << df << '\n' << dg << '\n';
}
