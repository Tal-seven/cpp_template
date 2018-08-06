#include <iostream>
#include <boost/type_index.hpp>
#include <tuple>

using boost::typeindex::type_id_with_cvr;

int main()
{
std::tuple<int,long,short> t1;
std::tuple<> t2;
std::tuple<char,double,float> t3;
std::tuple<void*,char*> t4;

auto res=tuple_cat(t1,t2,t3,t4);

std::cout<<"The concatenated tuple type is "<<type_id_with_cvr<decltype(res)>().pretty_name() <<"\n";
}
