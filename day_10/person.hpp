#include <string>
#include <iostream>

template <typename Derived>
struct MyBase
{
  Derived const & toDerived() const
  {
    return static_cast<Derived const&>(*this);
  }
  bool operator==(const Derived& rhs)
  {
    return toDerived().data() == rhs.data();
  }
  bool operator!=(const Derived& rhs)
  {
    return !(operator==(rhs));
  }
};


struct Person : MyBase<Person>
{
public:
  std::string name{};
  std::string surname{};
  std::string dob{};


  Person()= default;
  Person(Person const & ) = default;
  Person(Person &&) = default;
  Person & operator=(Person const &) = default;
  Person & operator=(Person &&) = default;
  ~Person() = default;


  std::string get_name(){return name;}
  std::string get_surname(){return surname;}
  std::string get_day_of_birth(){return dob;}
  void get_data(){
    std::cout << get_name() << " " << get_surname() << " " << get_day_of_birth() << '\n';
  }
};
