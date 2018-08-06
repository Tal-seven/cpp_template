#include <iostream>


template<typename... Ts>
struct List{};

template<int I,typename T>
struct At;

template<int I,typename T,typename... Ts>
struct At<int I,List<T,Ts... > : At<I-1,List<Ts...>>{};

template<typename T,typename... Ts>
struct At<0,List<T,Ts... > >{
using Type=T;
};


int main()
{
using L=List<int,bool,float,int>;
typename At<2,L>::Type f=1.4;
}
