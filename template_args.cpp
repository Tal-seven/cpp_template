#include <iostream>


template<class T> void f(){std::cout<<"Class version called\n";}
template<int I> void f(){std::cout<<"Type version called\n";}

void g(){
f<3>();
}

int main()
{
 g();
};
