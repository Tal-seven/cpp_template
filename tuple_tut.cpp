#include <iostream>
#include <string>

template<typename... Args> class tuple;

template<> class tuple<> {/* Base Case*/};


template<typename Tvalue,typename... Args>
class tuple<Tvalue,Args...>:public tuple<Args...>
{
	public:
	Tvalue value;
};

template<size_t idx,typename tupleType> struct tupleElement;

template<typename Tvalue,typename... Args>
struct tupleElement<0,tuple<Tvalue,Args...>>
{
  using type=Tvalue;
  using tupleType=tuple<Tvalue,Args...>;
};

template<size_t idx,typename Tvalue,typename... Args>
struct tupleElement<idx,tuple<Tvalue,Args...> >:public tupleElement<idx-1,tuple<Args...>> {};

template<size_t idx,typename... Args>
typename tupleElement<idx,tuple<Args...>>::type& get(tuple<Args...>& tup)
{
  using tupleType_t=typename tupleElement<idx,tuple<Args...>>::tupleType;
  return static_cast<tupleType_t&>(tup).value;
}


int main()
{
 tuple<int,std::string,double> utp;
 get<0>(utp)=5;
 get<1>(utp)="JURASSIC";
 get<2>(utp)=3.14;
 std::cout<<get<0>(utp)<<"\n";
 std::cout<<get<1>(utp)<<"\n";
 std::cout<<get<2>(utp)<<"\n";
}
