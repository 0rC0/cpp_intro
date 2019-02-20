#include <iostream>
#include <string>

// Tasks for the computer lab III
// Out-of-bounds:
// 1. Write a program that reads a string from the user input and then a
// number
// 2. print the i-th character of the string to the user (where i is the number
// supplied by the user)
// 3. What happens when the number is larger than the string is big?
// 4. Did you use operator[] or .at() to access the string? Try both and
// compare the behaviour!

int main() {
  std::cout << "Insert a string and a number and press ENTER \n";
  std::string s{};
  int n;
  std::cin >> s >> n;
  std::cout << s[n] << s.at(n);
}
