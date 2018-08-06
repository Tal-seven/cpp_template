#include <iostream>

int g=10;

auto make_kitten(int c)
{
    static int a=0;
    return [=](int d){
        static int b=0;
        return (a++) + (b++) +
        (c) + (d);
    };
}

auto constexpr kitten=[=](){return g+1;};
auto cat=[&g=g](){return g+1; } ;

int main()
{
    auto k1=make_kitten(1);
    auto k2=make_kitten(2);
 std::cout<<k1(20)<<" "<<k1(30)<<"\n";
 std::cout<<k2(20)<<" "<<k2(30)<<"\n";
}
