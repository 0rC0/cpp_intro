#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>

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

int main()
{
std::string s{"foo"};
std::cout << "Welcome to the " << s << " program!\n";
std::cout << "Enter two floating point numbers followed by [RETURN]\n";
double d1{};
double d2{};
std::cin >> d1 >> d2;
double sum = d1 + d2;
std::cout << "The sum is: " << sum << '\n'
<< "rounded down " << std::ceil(sum) << '\n'
<< "rounded up " <<std::floor(sum) << '\n'
<< "square root " << std::sqrt(sum) << '\n'
<< "scientific notation" << std::scientific << sum << '\n'
<< "proof if it is always scientific " << sum << '\n'
<< "set precision to 10 " << std::setprecision(10) << sum << '\n';
}
