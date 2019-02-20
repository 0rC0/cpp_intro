#include <iostream>

// What does the program
// print?
// 3.3 is an Integer

// Why?
// because of the template function

// How can you "fix" it?
// Possible solutions
// 1- delete template function
// 2- print typeid
// 3- switch case with all the cases

template <typename T>
void print(T const i) {
  std::cout << typeid(i).name() << "!\n";
}

//void print(float const i) {
//  std::cout << "Floating point!\n";
//}

int main() {
  print(3.3);
}
