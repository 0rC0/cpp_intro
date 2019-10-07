#include <iostream>
#include <typeinfo>
#include <cmath>

// 1. Write a program that prints for the types char , short , int , long , long long
// and the respective unsigned versions:
// 1. the size in bits
// 2. the largest possible value
// 3. the smallest possible value
// 2. What happens when you assign a value that is too large/small? Is this
// defined behaviour or random?

int main()
{
  //char a{};
  //short a{32767};
  //short a_min{-32767};
  //int a = 2147483647;
  //int a_min{-2147483648};
  //long a{9223372036854775807};
  //long a_min = -a -1;
  //long long a{9223372036854775807};
  //long long a_min = -a -1;
  // unsigned char a{};
  unsigned short a{65535};
  unsigned short a_min = 0;
  // unsigned int a{};
  // unsigned long a{};
  // unsigned lung long a{};

  // type at least typically
  // bool 8bit 8bit
  // char 8bit 8bit
  // short 16bit 16bit
  // int 16bit 16bit or 32bit
  // long 32bit 32bit or 64bit
  // long long 64bit 64bit
  // float 32bit 32bit
  // double 64bit 64bit

  //std::cout << 'char: max = ' << (c = '?') << 'min = ' << (c = '?');
  std::cout << typeid(a).name() << "\n" <<
  "max = " << a << "\n" <<
  "adding 1 = " << (a +1) << "\n" << typeid(a +1).name() << '\n' <<
  "min = " << a_min << "\n" << typeid(a_min).name() << "\n" <<
  "subtracting 1 = " << (a_min - 1) << "\n" << typeid(a_min - 1).name() <<"\n";

  // Overflow
  // short: conversion to int
  // int max + 1 = min min -1 = max
  // long long same of int
  // unsigned short: same of short
}
