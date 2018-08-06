#include <iostream>


class compiletime{
public:

constexpr compiletime(double x,double y):_x(x),_y(y){}
constexpr double getX() const {return _x;}
constexpr double getY() const  {return _y;}
constexpr compiletime middlePoint() noexcept;

private:
double _x=0;
double _y=0;
};

constexpr compiletime compiletime::middlePoint()  noexcept
{
	compiletime temp((_x/2),(_y/2));
	return temp;
}


constexpr unsigned factorial(unsigned n)
{
return n <= 1 ? 1 : (n* factorial(n-1));
}

int main()
{
	constexpr compiletime Orig(5.5,2.14);
	constexpr auto New=Orig.middlePoint();
	constexpr auto variable=factorial(5);
	std::cout<<"Original object is "<<Orig.getX()<<" "<<Orig.getY()<<"\n";
	std::cout<<"New Object is "<<New.getX()<<" "<<New.getY()<<"\n";
	std::cout<<"The constexpr variable is "<<variable<<"\n";
}
