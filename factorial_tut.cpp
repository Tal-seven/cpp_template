#include <iostream>

template<size_t n> struct factorial;

template<>
struct factorial<0>
{
const static auto value=1;
};

template<size_t n>
struct factorial
{
 const static auto value = n * factorial<n-1>::value;
};

int main()
{
std::cout<<"Factorial value: "<<factorial<6>::value<<"\n";
}
