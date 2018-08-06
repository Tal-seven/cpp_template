#include<iostream>

template<typename T>
T plus1(T&& b)
{
return b+1;
}


int main()
{
auto y=plus1(5.16);
auto z=plus1<int>(5.16);
std::cout<<"y= "<<y<<"\n";
std::cout<<"z= "<<z<<"\n";
}
