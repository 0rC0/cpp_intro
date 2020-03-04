#include <iostream>
#include <vector>
#include <memory>
#include "my_vector.hpp"
#include "shape.hpp"


void printArea(ShapeInterface const & s)
{
  std::cout << s.area() << '\n';
}

void print(std::string const & s){std::cout << s;}

int main()
{
  // Square sq{}; sq.width = 4; printArea(sq);
  // Circle ci{}; ci.radius = 4; printArea(ci);
  //std::vector<std::unique_ptr<Shape>> vec{};
  MyVector<std::unique_ptr<ShapeInterface>> v1{};
  std::unique_ptr<Square> s1 = std::make_unique<Square>();
  v1.push_back(s1);
  //v1.push_back();
  //printArea(*vec[0]); // prints `0` because object was default-initialised
  // for (auto i : v1)
  //   std::cout << i << '\n';
}
