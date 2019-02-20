#include <iostream>
#include <string>
#include <math.h>

// Tasks for the computer lab II
// Floating point types:
// 1. Adapt the code from the "Simple I/O" page
// 2. For a single user-given double , have your program print the number
// rounded down, rounded up and it's square root; what is the behaviour
// for negative numbers?
// 3. Find out how to change the precision of the output stream so more/less
// digits are printed.
// 4. Find out how to change the output format to always show 1e-10 instead
// of 0.1 .

int main() {
  std::string s{"foo"};
  std::cout << "Welcome to the " << s << " program!\n";
  std::cout << "Enter a floating point number followed by [RETURN]\n";
  double d1{};
  std::cin >> d1;
  std::cout << "Rounded up: " << ceil(d1) << '\n';
  std::cout << "Rounded down:" << floor(d1) << '\n';
  std::cout << "Square root: " <<  sqrt(d1) << '\n';
}
