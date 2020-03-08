#include <iostream>

struct Base {/*..*/};
struct Derived : Base {/*..*/};

void f() {throw 10.0;}

//void f2() {throw Base();}
void f2() {throw Derived();}


void g()
{
  try
  {
    //f();
    f2();
  }
  catch(unsigned i){
    std::cout << "unsigned int\n";
  }
  catch(int i){
    std::cout << "int\n";
  }
  catch(Base const &b){
    std::cout << "Base\n";
  }
  catch(Derived const & d){
    std::cout << "Derived\n";
  }
  catch(...){
    std::cout << "general\n";
  }
}

int main()
{
  g();
  return 0;
}
