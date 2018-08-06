#include <iostream>
#include <boost/hana.hpp>


namespace hana=boost::hana;
using namespace hana::literals;

int main()
{
auto tuple=hana::make_tuple(1,2.2f,"hello",3.4,'x');
auto no_floats=hana::remove_if(tuple,[](auto const& t){
return hana::traits::is_floating_point(hana::typeid_(t));
}
);

static_assert(no_floats==hana::make_tuple(1,"hello",'x'));
}
