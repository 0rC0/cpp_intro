#include <iostream>
#include <vector>
#include <algorithm>

// Tasks for the computer lab III
// 1. Use your type from the previous task!
// 2. Write a main function that repeatedly asks the user to input name, age
// and gender and then saves those as elements of a std::vector<Person> .
// Ask the user after every input if they want to quit adding persons.
// 3. If they quit, sort the vector of persons by age.
// Use std::sort and read up the documentation on it!
// Implement the actual comparison as operator< inside struct Person .
// instead implement a lambda-function that does the comparison
// (and is passed to std::sort ).
// 4. Which solution do you think is better? How difficult would it be to sort
// by name (alphabetically) instead?
// 5. Print the first and last persons from the vector.

enum  Gender
{
  F, M, D
};

struct Person
{
  std::string name;
  short age{};
  Gender gender{Gender::D};

  void print()
  {
    std::cout << "Name: " << name << '\n'
              << "Age: " << age << '\n'
              << "Gender: " << gender << '\n';
  }

  bool operator<(Person const & p)
  {
    return age < p.age;
  }
};

int main()
{
  std::vector<Person> vp;
  while(true)
  {
    Person p_tmp{};
    char q{'n'};
    std::cout << "Input a person's name, age and gender\n";
    std::cin >> p_tmp.name >> p_tmp.age; // >> p_tmp.gender;
    vp.push_back(p_tmp);
    std::cout << "Quit? (y to quit)\n";
    std::cin >> q;
    if (q=='y')
      break;
  }
  std::sort(vp.begin(), vp.end());
  for (Person & p : vp)
    p.print();
}
