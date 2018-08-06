#include <iostream>

template<class Derived>
class Base{
public:
float profit(){return 42 * (static_cast<Derived*>(this)->output)/(static_cast<Derived*>(this)->input);}
};

class Derived1: public Base<Derived1>
{
public:
Derived1(float x,float y):output(x),input(y){}
float output,input;
};

int main()
{
  Derived1 foo(12.0,3.56);
  std::cout<<"Ther profit is :"<<foo.profit()<<"\n";
  return 0;
}
