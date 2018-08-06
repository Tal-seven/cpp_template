#include <iostream>


template<typename T>
struct Starcounter
{
static const int value=0;
};

template<typename U>
struct Starcounter<U*>
{
static const int value = 1 + Starcounter<U>::value;
};

int main()
{
std::cout<<Starcounter<int>::value<<std::endl;
std::cout<<Starcounter<int****>::value<<std::endl;
}

