

template<typename... T>
struct typelist {};

namespace detail{

template<typename Ret, typename... Is, typename... Ks
	typename Tuples>
	Ret tuple_cat_(typelist<Is...>,typelist<Ks...>,Tuples tpls)
	{
	  return Ret{std::get<Ks::value>(std::get<Is::value>(tpls))...};
	}

}


template<typename... Tuples>
typelist_cat_t< typelist<as_typelist_t<Tuples>...>>

template<template <typename...> class C, typename List>
struct typelist_apply;

template<template<typename...> class C, typename... List>
struct typelist_apply<C,typelist<List...>>
{
using type=C<List...>;
};


