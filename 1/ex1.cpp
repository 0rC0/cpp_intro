#include <iostream>
#include <string>

// Tasks for the computer lab I
// Write a program that repeatedly asks the user to input a person's
// name and postal code.
// Immediately after an entry is submitted the program should respond
// with {NAME} lives in Berlin or {NAME} lives outside of Berlin depending on
// the postal code entered1
// After that it should ask the user something like Enter another person?
// [y/n] ;
// if y is entered it should repeat the last step;
// if n is entered it should print the percentage of entered people that
// lives in Berlin and the name of the person with the smallest postal
// code; and then quit.
// 1 You can assume that Zehlendorf and Westend are outside of Berlin

ushort tot_p = 0;
ushort num_ber = 0;
int16_t p_min;
std::string name_p_min{};

void berlin(std::string const & n, uint16_t const & p) {
  if ( (p>=10115) && (p<=14199)) {
    std::cout << n << " lives in Berlin \n";
    num_ber++;
  }
  else {
    std::cout << n << " lives outside Berlin \n";
  }
}

void print_perc() {
  double perc = num_ber*100/tot_p;
  std::cout << perc << "% living in Berlin\n";
}

void min_p_name(std::string const & n, uint16_t const & p) {
  if (p < p_min) {
    p_min = p;
    name_p_min = n;
  }
}

int main() {
  std::string n{};
  uint16_t p;
  std::string another{};
  do {
    std::cout << "Enter a person's name and postal code \n";
    std::cin >> n >> p;
    berlin(n, p);
    min_p_name(n, p);
    std::cout << "Enter another person?";
    std::cin >> another;
  }while(another != "n");
  print_perc();

}
