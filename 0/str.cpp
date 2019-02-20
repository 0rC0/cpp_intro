#include <string>
// declare an empty string:
std::string dd;
// can be {} initialised:
std::string df{"FOOBAR"};
// access elements also via []
std::cout << df[0];
// prints 'F'
std::cout << df.size(); // prints 6
std::string is similar to
std::vector<char>

df.push_back('a');
std::cout << df.size(); // prints 7
std::cout << df;
// prints "FOOBARa"
