#include<iostream>
#include<type_traits>

template<int... Ts>
struct Intvector{
using Type=Intvector<Ts...>;
};

template<typename T_vector>
struct Front;

template<int Ifirst,int... Rest>
struct Front<Intvector<Ifirst,Rest...>>
{
 enum {value=Ifirst};
};

template<typename T_vector,int Index>
struct At;

template<int Ifirst,int... Rest,size_t Index>
struct At<Intvector<Ifirst,Rest...>,Index>:At<Intvector<Rest...>,Index-1> {};

template<int Ifirst,int... Rest>
struct At<Intvector<Ifirst,Rest...>,0>
{
 enum {value=Ifirst};
};

template<typename T,T T_val>
struct Value{
constexpr static auto value=T_val;
};

template<int Inew>
using Int=Value<int,Inew>;

template<typename T,T... Tval>
struct Vector{
using Type=Vector<T,Tval...>;
};

template<int... Is>
using IntVector=Vector<int,Is...>;



/*template<typename T_vector,typename  Tval>
struct PushFront;

template<int... Is,int Inew>
struct PushFront<Intvector<Is...>,Inew>:Intvector<Inew,Is...> {};*/

template<typename T_vector,typename T_vnew>
struct PushBack;

template<typename T,T... Tval,T T_vnew>
struct PushBack<Vector<T,Tval...>,Value<int,T_vnew>>:Vector<T,Tval...,T_vnew> {};


int main()
{
using someNumbers=Intvector<5,4,3,2,1,0>;

//static_assert(std::is_same<typename PushFront<typename PushBack<Intvector<1,2>,Value<int,3>::Type,4>::Type,Intvector<4,1,2,3>>::value,"");
}
