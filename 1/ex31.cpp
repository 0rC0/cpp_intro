#include <iostream>

// Write a function that takes two initial numbers n1 and n2 and a counter
// c and returns the c-th "fibonacci" number based on the two initial
// numbers
// It should accept any numeric type for the initial numbers!

template <typename T>
void get_nums() {
  T n1;
  T n2;
  uint32_t c;
  std::cout << "Enter two initial numbers and a counter";
  std::cin >> n1, n2, c;
  std::cout << fib(n1, n2, c);
}

template <typename T>
T fib(T & n1, T & n2, uint32_t const & c) {
  for (uint16_t i=0; i < c; ++i) {
    T tmp = n1 + n2;
    n1 = n2;
    n2 = tmp;
  }
  return n2;
}

int main(){
  get_nums();
}
