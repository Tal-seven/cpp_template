#include <type_traits>
#include <iostream>
#include <stdio.h>

template<typename Ty,Ty v>
struct integral_constant{
	static const Ty value=v;
};

template<bool B>
using bool_constant=integral_constant<bool,B>;

using true_type = bool_constant<true>;

using false_type = bool_constant<false>;


template<typename T> struct is_reference			:	false_type	{};
template<typename T> struct is_reference<T&>	: true_type 	{};
template<typename T> struct is_reference<T&&> : true_type 	{};

template<typename T>
constexpr bool is_reference_v = is_reference<T>::value;

template<typename T> struct remove_reference				{using type=T;};
template<typename T> struct remove_reference<T&> 		{using type=T;};
template<typename T>	struct remove_reference<T&&>	{using type=T;};

template<typename T>
using remove_reference_t = typename remove_reference<T>::type;

//static_assert(std::is_same< remove_reference_t<int&> , int>,"" );

template<class ...> using void_t =void;

template<typename T,class Enable> struct ALR_impl	{using type=T;};

template<typename T>
struct ALR_impl<T,void_t<T&>>	{using type=T&;};

template<typename T,class Enable>	struct ARR_impl	{using type=T;};

template<typename T>
struct ARR_impl<T,void_t<T&&>>	{using type=T&&;};

template<typename T>
struct add_lvalue_reference : ALR_impl<T,void> {};

template<typename T>
struct add_rvalue_reference : ARR_impl<T,void> {};

template<typename T>
using add_lvalue_reference_t = typename add_lvalue_reference<T>::type;

template<typename T>
using add_rvalue_reference_t = typename add_rvalue_reference<T>::type;

int main()
{
//	static_assert(std::is_same_v<remove_reference_t<int&&>, int>::value," ");
//	static_assert(std::is_same_v<add_lvalue_reference_t<int>,int&>::value," ");
	std::cout<<std::is_same<remove_reference_t<int&&>, int>::value <<std::endl;
	std::cout<<std::is_same<add_lvalue_reference_t<int>,int&>::value << std::endl;
	std::cout<<std::is_same<add_rvalue_reference_t<int>,int&&>::value << std::endl;
}
