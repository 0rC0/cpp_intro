#include <iostream>
#include <cmath>


// Out-of-bounds:
// 1. Write a program that reads a string from the user input and then a
// number
// 2. print the i-th character of the string to the user (where i is the number
// supplied by the user)
// 3. What happens when the number is larger than the string is big?
// 4. Did you use operator[] or .at() to access the string? Try both and
// compare the behaviour!

int main()
{
  std::string s{"foo"};
  int i{};

  std::cout << "Insert a string" << '\n';
  std::cin >> s;
  std::cout << "Insert a number" << '\n';
  std::cin >> i;
  std::cout << "The " << i << "-th character is: " << s.at(i) << '\n';

}
