#include <iostream>

template <typename T>
void add(T&& t)
{
puts(__PRETTY_FUNCTION__);
}

int main()
{
//int i;
add(1);
}
