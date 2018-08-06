#include <iostream>
#include <functional>

std::function<int(int)> func;


func=[&func] (int n)->int
{
if(n==0)
 return 1;
else
{
return (n * func(n-1));
}
};


int main()
{
std::cout<<"Factorial: "<<func(6)<<"\n";
}
