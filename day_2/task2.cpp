#include <iostream>

// Tasks for the computer lab II
// 1. Implement a struct Person with the member variables name and age
// (what are appropriate types?).
// 2. Implement an enum class that represents gender with the three legal
// categories in Germany: FEMALE , MALE and DIVERSE (in case you are not
// happy with those, you may add more ).
// 3. Add a member variable of that type to struct Person .
// 4. Add a member function called print() that prints the fields in some
// descriptive manner.

enum  Gender
{
  F, M, D
};

struct Person
{
  std::string name;
  short age{};
  Gender gender;

  void print()
  {
    std::cout << "Name: " << name << '\n'
              << "Age: " << age << '\n'
              << "Gender: " << gender << '\n';
  }

};

int main()
{
  Person p1{};
  p1.name="A";
  p1.age=1;
  p1.gender=Gender::D;
  p1.print();
}
