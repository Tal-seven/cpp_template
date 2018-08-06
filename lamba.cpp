#include <iostream>
#include <functional>

/*This is a helper function which helps the compiler deduce the second template type of meow.*/
template<typename T>
struct Identity{
using type=T;
};

/*compiler deduces the :: qualified type by deducing val and using Identity::type to match the lambda call to the template parameter*/
template<typename T> 
void meow(T val,typename Identity<std::function<void (T)>>::type func)
{
func(val);
}

int main()
{
//std::function<void (int)> f=[](int x){std::cout<<x<<std::endl;};
//meow(1329,f);
meow(1329,[](int x){std::cout<<x<<std::endl; });
return 0;
}
