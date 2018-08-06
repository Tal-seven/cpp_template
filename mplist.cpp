#include <type_traits>
#include <tuple>

template<typename... Ts>
struct mp_list{};

template<typename T>
using add_pointer=T*;


template<class A, template<class...> class B> struct mp_rename_impl{};

template<template<class...> class A,class... T,template<class...> class B>
struct mp_rename_impl<A<T...>, B>{
using Type=B<T...>;
};

template<class A,template<class...> class B>
using mp_rename=typename mp_rename_impl<A,B>::Type;

template<class L> struct mp_size_impl;

template<template<class...> class L,class... T> struct mp_size_impl<L<T...>>
{
 using type=std::integral_constant<std::size_t,sizeof...(T)>;
};

//template<class L> 
//using mp_size = typename mp_size_impl<L>::type;

//template<template<class...> class L,class... T> 
template<class... L>
using mp_length=std::integral_constant<std::size_t,sizeof...(L)>;

template<class L>
using mp_size=mp_rename<L,mp_length>;

int main()
{
 static_assert(mp_size<std::tuple<int,char,int,bool>>::value == mp_length<int,char,int,bool>::value, "");
 
}
