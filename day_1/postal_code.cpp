#include <iostream>
#include <array>

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



bool check_berlin_code(short const plz)
{
  return (plz >= 1055) && (plz <= 14199);
}

std::string berlin_string(short const plz, std::array<short, 2> & berliner)
{
  if (check_berlin_code(plz))
  {
    berliner[0]++;
    return " lives in Berlin \n";
  }
  else
  {
    berliner[1]++;
    return " lives outside Berlin \n";
  }
}

void update_min(short & min, short n)
{
  if (n < min)
  {
    min = n;
  }
}



int main()
{
  std::string name;
  short plz{};
  char another{};
  std::array<short, 2> berliner{0, 0};
  short min_plz{0};

  while (true)
  {
    std::cout << "Insert a name and a postal code " << '\n';
    std::cin >> name >> plz;
    std::string berlin_str = berlin_string(plz, berliner);
    update_min(min_plz, plz);
    std::cout << name << berlin_str;
    std::cout << "Enter another person? \n n to exit, y or any key to continue \n";
    std::cin >> another;
    if (another == 'n')
    {
      double berliner_perc = (berliner[0]/(berliner[0] + berliner[1])) * 100;
      std::cout << berliner_perc << " % live in Berlin \n";
      std::cout << "Min PLZ: " << min_plz << '\n';
      break;
    }

  }
}
