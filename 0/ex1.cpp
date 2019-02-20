#include <iostream>
#include <limits>
// Tasks for the computer lab I
// Integral types:
// 1. Write a program that prints for the types
// char , short , int , long , long long
// and the respective unsigned versions:
// 1. the size in bits
// 2. the largest possible value
// 3. the smallest possible value
// 2. What happens when you assign a value that is too large/small? Is this
// defined behaviour or random?

unsigned char uc;
unsigned short us;
unsigned int ui;
unsigned long ul;
unsigned long long ull;

char c;
short s;
int i;
long l;
long long ll;

// ToDo
int main() {
  std::cout << sizeof(ui) << ' ' << 2^sizeof(ui) << '\n';

}
