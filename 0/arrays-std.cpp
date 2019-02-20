#include <array>
// declare standard array of size 3:
std::array<double, 3> dd;
// can be {} initialised:
std::array<double, 3> df{3.1, 2.3, 1.1};
// access elements also
std::cout << df[0];
df[1] = 32.0;
df[77] = 32.0;
via []
// prints 3.1
// you can also "assign through" []
// memory access violation, no error, kills kittens
