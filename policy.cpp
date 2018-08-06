#include <iostream>
#include <type_traits>

template <typename T>
struct NewCreator{
static void Create()
{
std::cout<<"New Creator Called"<<"\n";
if(std::is_integral<T>::value)
std::cout<<"with type int\n";
}
};

template<typename T>
struct MallocCreator{
static void Create(){
std::cout<<"Malloc creator called\n";
}
};


template<class CreatorPolicy>
class Policy:public CreatorPolicy
{

};

int main()
{
Policy<NewCreator<int>> instance;
instance.Create();
}
