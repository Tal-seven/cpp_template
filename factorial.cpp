#include<iostream>

template<size_t n> struct fact;

template<>
struct fact<0>{
const static auto value=1;
};

template<size_t n>
struct fact{
const static auto value = n*fact<n-1>::value;
};

int main()
{
	std::cout<<fact<4>::value<<std::endl;
}
