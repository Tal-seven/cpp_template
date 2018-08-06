#include <iostream>


template<typename T>
constexpr bool isarray=false;

template<typename Tp[]>
constexpr bool isarray<Tp[]>=true;


int main()
{
std::array<int,5> v;
std::cout<<"Is array: "<<isarray<int[]><<std::endl;
}
