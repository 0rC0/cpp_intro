#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include "person.hpp"
// Tasks for the computer lab II a
// Use an STL container of your choice to store a collection of person elements, storing the
// Name, Surname, Birthday.
// Use STL algorithms to perform the following queries and manipulations:
// sort by name
// sort by surname
// switch name and surname of all persons
// remove all persons born after 1985
// count the number of persons with a certain surname
// split into two containers, one containing all persons older / younger than you!

void print_v(std::vector<Person>  v) {
  for (auto i = 0; i < v.size(); ++i)
  {
    v[i].get_data();
  }
}

int main()
{
  Person p1; p1.name = "A", p1.surname="B"; p1.dob="1981";
  Person p2; p2.name = "C", p2.surname="D"; p2.dob="1986";
  std::vector<Person> v{p1, p2};
  print_v(v);
  std::cout << "sorting by name" << std::endl;
  std::
  return 0;
}
