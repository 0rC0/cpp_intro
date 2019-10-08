#include <iostream>

// Tasks for the computer lab II b
// #include <iostream>
// template <typename T>
// void print(T const i)
// {
// std::cout << "Integer!\n";
// }
// void print(float const i)
// {
// std::cout << "Floating point!\n";
// }
// int main()
// {
// print(3.3);
// }
//
// What does the program
// print?

// error: unused parameter ‘i’

// Why?

//
// How can you "fix" it?

// 


template <typename T>
void print(T const & i)
{
  std::cout << "Integer!\n";
}

void print(float const & i)
{
  std::cout << "Floating point!\n";
}

int main()
{
  float i = 3.3;
  print(i);
}
