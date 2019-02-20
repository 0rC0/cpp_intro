#include <iostream>
#include <string>
int main()
{
std::string s{"foo"};
std::cout << "Welcome to the " << s << " program!\n";
std::cout << "Enter two floating point numbers followed by [RETURN]\n";
double d1{};
double d2{};
std::cin >> d1 >> d2;
std::cout << "The sum is: " << d1 + d2 << '\n';
}
