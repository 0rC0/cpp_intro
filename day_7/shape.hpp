#include <cmath>

class ShapeInterface
{
public:
  //contructors
  ShapeInterface() = default;
  
  virtual double area() const = 0; // this function is pure virtual
  virtual double perimeter() const = 0; // this function is pure virtual
};

class Square : public ShapeInterface
{
  double width{};
  
public:
  //constructors
  Square() : width{}
  { }
  Square(Square const & ) = default;
  Square(Square &&) = default;
  Square & operator=(Square const &) = default;
  Square & operator=(Square &&) = default;
  ~Square() = default;

  double area() const override
    { return width*width; }

  double perimeter() const override
    { return 4*width; }
};
  
class Circle : public ShapeInterface
{
  
private:
  static constexpr double pi = 3.14;
  double radius{};
  
public:
  //constructors
  Circle() : radius{}
  { } 
  Circle(Circle const & ) = default;
  Circle(Circle &&) = default;
  Circle & operator=(Circle const &) = default;
  Circle & operator=(Circle &&) = default;
  ~Circle() = default;
  

  double area() const override
    { return pi*radius*radius; }
  double perimeter() const override 
    { return 2*pi*radius; }
};