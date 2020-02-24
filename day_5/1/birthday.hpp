#pragma once
#include <cassert>
#include <cstdint>

// Tasks for the computer lab I
// Create birthday.hpp that defines class Birthday .
// The class should be able to represent at least dates between 0000-00-00
// (0 A.D.) and 3000-00-00.
// The class should enforce it's invariants (valid dates!) on user provided
// input (e.g. via assert() ), you should handle simple leap years (every
// fourth year), but handling the more complicated rules is not required.
// Define default constructor, copy constructor and copy assignment
// operator yourself, don't use = default . You can omit move constructor
// and move-assignment for now.
// Implement operator== and operator!= . Bonus: also add operator< , operator<=
// ...
// Test your implementation with a small program that reads user-given
// dates and creates objects from them.

class Birthday
{
private:
  int year{};
  int month{};
  int day{};

public:


  Birthday(int const y, int const m, int const d);

  //default constructor
  Birthday() : year{}, month{}, day{}
  { }

  //copy constructor
  Birthday(Birthday const & bd);

  //copy assignment constructor
  void operator=(Birthday const & bd);

  // == operator
  bool operator==(Birthday const & bd2);

  // != operator
  bool operator!=(Birthday const & bd2);

  // Invariants
  void set_month(int const m);
  void set_day(int const d);
  void set_year(int const y);

  int get_day() const {return day;}
  int get_month() const {return month;}
  int get_year() const {return year;}
};
