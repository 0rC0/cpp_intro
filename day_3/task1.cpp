
#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
// Adapt your program from yesterday's task2/3 to use a std::tuple
// instead of struct Person .
// Which things are now easier / better to understand? Which have
// become more difficult / obscure?

enum  Gender
{
  F, M, D
};


std::string gender2str(Gender const & g)
{
  std::string out{"D"};
  switch(g) //Gender is enum, so switch case
  {
    case F:
      out = "F";
      break;
    case M:
      out = "M";
      break;
    default:
      out = "D";
  }
  return out;
}


Gender str2gender(std::string const & s)
{
  Gender g{D};
  if (s == "F")
    g = F;
  else if (s == "M")
    g = M;
  return g;
}


void print_person_tuple(std::tuple<std::string, short, Gender> const & t)
{
  std::cout << std::get<0>(t) << ' '
            << std::get<1>(t) << ' '
            << gender2str(std::get<2>(t)) << '\n';
}

bool sort_by_second(std::tuple<std::string, short, Gender> const & t1,
                    std::tuple<std::string, short, Gender> const & t2)
{
  return (std::get<1>(t1) < std::get<1>(t2));
}


int main()
{
  short age{0};
  std::string name{"unknown"};
  std::string gender_str{"D"};
  Gender gender{D};

  std::vector<std::tuple<std::string, short, Gender>> people;

  while(true)
  {
    char q{'n'};
    std::cout << "Input a person's name, age and gender\n";
    std::cin >> name >> age >> gender_str;

    gender = str2gender(gender_str);

    std::tuple person{name, age, gender};

    people.push_back(person);
    std::cout << "Quit? (y to quit)\n";
    std::cin >> q;
    if (q=='y')
      break;
  }
  std::sort(people.begin(), people.end(), sort_by_second); // or setting age as 1st element :P
  for (std::tuple p : people)
    print_person_tuple(p);
}
