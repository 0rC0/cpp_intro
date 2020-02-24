#include "birthday.hpp"

Birthday::Birthday(int const y, int const m, int const d)
{
  set_year(y);
  set_month(m);
  set_day(d);
}

//copy constructor
Birthday::Birthday(Birthday const & bd)
{ set_year(bd.get_year()); set_month(bd.get_month()); set_day(bd.get_day()); }


//copy assignment constructor
void Birthday::operator=(Birthday const & bd)
{ set_year(bd.get_year()); set_month(bd.get_month()); set_day(bd.get_day()); }

// == operator
bool Birthday::operator==(Birthday const & bd2)
{
  Birthday bd1 = *this;
  return (bd1.get_year() == bd2.get_year() &&
          bd1.get_month() == bd2.get_month() &&
          bd1.get_day() == bd2.get_day());
}

// != operator
bool Birthday::operator!=(Birthday const & bd2)
{
  Birthday bd1 = *this;
  return (bd1.get_year() != bd2.get_year() ||
          bd1.get_month() != bd2.get_month() ||
          bd1.get_day() != bd2.get_day());

}


// Invariants
void Birthday::set_month(int const m)
{
  assert(m<=12);
  month=m;
}

void Birthday::set_day(int const d)
{
  if (month == 2 && year % 4 == 0)
    assert(d <= 29);
  else if (month == 2) // similar for the day with 30 days :P
    assert(d <= 28);
  else
    assert(d<=31);
  day=d;
}

void Birthday::set_year(int const y) {assert(y<=3000); year = y;}
