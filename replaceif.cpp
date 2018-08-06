#include <iostream>
#include <type_traits>
#include <list>

using std::list;

template<bool>
struct conditional{
  template<typename A,typename B>
  using f=A;
};

template<>
struct conditional<false>{
template<typename A,typename B>
using f=B;
};



template<typename R,template<typename...> class F> /*template<typename>... class F is a functor in TMP land*/
struct pred{
template<typename T>
using f=typename conditional<F<T>::value>::template f<R,T>;
};

template<typename R,template<typename...> class F,typename... Ts>
using replace_if=list<typename pred<R,F>::template f<Ts>...>;


/*example of a meta functor*/

template<typename T>
using is_void=std::is_same<T,void>;

using result=replace_if<int,is_void,int,char,bool>;


int main()
{
std::cout<<result<<std::endl;
}
