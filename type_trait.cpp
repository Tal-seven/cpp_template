#include <iostream>
#include <boost/shared_ptr.hpp>

//template<typename T>
//using Type=boost::shared_ptr<T>;

template<typename T>
struct is_boost_shared{
bool value=false;
};

template<typename T>
struct is_boost_shared<boost::shared_ptr<T>>
{
bool value=true;
};

int main()
{
int x=42;
constexpr boost::shared_ptr<int> ok(new int(42));
std::cout<<"Is boost shared: "<<is_boost_shared<ok>.value<<"\n";
};
