#include <iostream>
#include <cstdint>

#include "birthday.cpp"

int main()
{
  Birthday b1{};
  Birthday b2{};

  int y{};
  int m{};
  int d{};

  // std::cout << "Default constructor: " << b1.year << ' ' << b1.month << ' ' << b1.day << '\n';

  std::cout << "Birthday 1 (y,m,d):\n";

  std::cin >> y;
  b1.set_year(y);

  std::cin >> m;
  b1.set_month(m);

  std::cin >> d;
  b1.set_day(d);

  std::cout << "Birthday 2 (y,m,d):\n";
  std::cin >> y >> m >> d;
  b2.set_year(y);
  b2.set_month(m);
  b2.set_day(d);

  std::cout << "1st Bday: " << b1.get_year() << ' ' << b1.get_month() << ' ' << b1.get_day() << '\n';
  std::cout << "2st Bday: " << b2.get_year() << ' ' << b2.get_month() << ' ' << b2.get_day() << '\n';

  if (b1 == b2 )
    std::cout << "same bday \n"; 

}
