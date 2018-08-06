#include <iostream>
#include <type_traits>

void test(const char* cmd)
{
 std::cout<<std::extent<decltype(cmd)>::value<<"\n";
}

int main(){
test("OK");
}
