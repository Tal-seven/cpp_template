#include<iostream>


template<size_t N>
struct pow;


template<size_t N>
struct pow{
double operator()(double x)
{
return x*pow<N-1>()(x);
}
};

template<>
struct pow<1>
{
double operator()(double x){return x;}
};

template<>
struct pow<0>
{
double operator()(double x){return 1;}
};

int main()
{
std::cout<<pow<5>()(2)<<std::endl;
}
