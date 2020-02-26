#include <iostream>
#include <vector>
#include <memory>
#include "my_vector.hpp"
#include "shape.hpp"


void printArea(ShapeInterface const & s)
{
  std::cout << s.area() << '\n';
}

int main() 
{
  //Square sq{}; sq.width = 4; printArea(sq);
  //Circle ci{}; ci.radius = 4; printArea(ci);
  //std::vector<std::unique_ptr<Shape>> vec{};
  MyVector<std::unique_ptr<ShapeInterface>> v1{};
  //v1.push_back(std::make_unique<Square>());
  v1.push_back(std::make_unique<Square>());
  //printArea(*vec[0]); // prints `0` because object was default-initialised
}
