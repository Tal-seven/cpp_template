#include<iostream>


template<typename... Ttypes> class Tuple;


template<> class Tuple<> {/*Base Case. No values. Used During parameter unpacking for the last value*/};


template<typename Tvalue,typename... Args>
class Tuple<Tvalue,Args...>: public Tuple<Args...>{
public:
Tvalue value;
//Tvalue& operator <<(Tuple<Tvalue,Args...>);
};


template<size_t idx,typename TupleType> struct TupleElement;

template<typename Tvalue,typename... Args>   
struct TupleElement<0,Tuple<Tvalue,Args...> >{   /*Specialization for the zeroth element*/
using type_t=Tvalue;
using Tupletype_t = Tuple<Tvalue,Args...>;
};

template<size_t idx,typename Tvalue,typename... Args>
struct TupleElement<idx,Tuple<Tvalue,Args...> >:public TupleElement<idx-1,Tuple<Args...> > {};

template<size_t idx,typename... types>
typename TupleElement<idx,Tuple<types...> >::type_t& get(Tuple<types...>& tuple)
{
 using Tupletype_t=typename TupleElement<idx,Tuple<types...> >::Tupletype_t&;
 return static_cast<Tupletype_t>(tuple).value;
}

int main()
{
 Tuple<int,char,std::string> myvalue;

 get<0>(myvalue)=32;
 get<1>(myvalue)='A';
 get<2>(myvalue)=("UTOPIA");


std::cout<<get<2>(myvalue)<<std::endl;
}
