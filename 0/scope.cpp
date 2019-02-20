#include <iostream>

char c = 'C'; //global scope

int main() {
  char d = 'D'; //function body scope

  std::cout << c << ' ' << d << '\n';

  {
    //local scope
    char e = 'E'; // this is only in the local scope
    std::cout << c << ' ' << d << ' ' << e << '\n';
  }
  // there is no e here, the following line gives compile error
  //std::cout << e << '\n';
}
