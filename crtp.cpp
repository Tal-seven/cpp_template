#include <iostream>


template<class Derived>
class Base{
public:
void Interface(){
static_cast<Derived*>(this)->Implementation();
}

void Implementation(){std::cout<<"Implementation Base\n";}
};

class Derived1:public Base<Derived1>
{
	public:
	void Implementation(){std::cout<<"Implementation Derived1\n";}
};

class Derived2:public Base<Derived2>
{
	public:
	void Implementation(){std::cout<<"Implementation Derived2\n";}
};

class Derived3:public Base<Derived3> {};
template <typename T>
void execute(T& Base)
{
	Base.Interface();
}

int main()
{
Derived1 d1;
execute(d1);

Derived2 d2;
execute(d2);

Derived3 d3;
execute(d3);
}
