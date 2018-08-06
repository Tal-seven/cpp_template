#include <iostream>
#include <type_traits>


class foo{
public:
foo():_rxBuf{0} {}
const uint32_t getSize() {return std::extent<decltype(_rxBuf)>::value;}
protected:
uint8_t _rxBuf[64];
};


int main()
{
foo buf;
std::cout<<buf.getSize()<<"\n";
}
