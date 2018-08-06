#include<iostream>
#include<sstream>
//#include<string>
#include<vector>

template<typename T>
std::string to_string_impl(const T& param)
{
 std::stringstream ss;
 ss << param;
 return ss.str();
}

std::vector<std::string> to_string()
{
 return {};
}


template<typename P1,typename... Param>
std::vector<std::string> to_string(const P1& param1,const Param&... param)
{
 std::vector<std::string> vec;
 vec.push_back(to_string_impl(param1));
 
 const auto remainder=to_string(param...);
 vec.insert(vec.end(),remainder.begin(),remainder.end());
 return vec; 
}


int main()
{
 const auto vec=to_string("Hello",1,true,"World");
 for(const auto& o: vec)
 std::cout<<o<<"\n";
}


