#include <iostream>
#include <stdio.h>
#include <stdarg.h>
#include <stdint.h>
#include <math.h>
#include <string>

struct Slice{
Slice(const uint8_t* array,size_t length):arr{array},n{length} {}
const uint8_t* arr;
size_t n;
size_t iter=0;
const uint8_t* begin(){return arr+iter;}
const uint8_t* end(){return arr+n;}
};

class FilterExact{
public:
bool Data_cb(const char* Cmd,const uint8_t* buf,size_t len);
};


bool FilterExact::Data_cb(const char* cmd,const uint8_t* buf,size_t len)
{
  (void)len;
/* while(iter < (std::extent<decltype(buf)>::value - 1))
{
  for(auto elem: buf)
   {
	//if(int result=strcmp(cmd,reinterpret_cast<const char*>(elem)))
	  //return true;
	std::cout<<"size of elem"<<std::extent<decltype(elem)>::value<<"\n";
   }
 iter++;

}	

   return false;*/
  std::string buffer(reinterpret_cast<const char*>(buf));
  std::cout<<buffer<<std::endl;
  std::string::size_type idx=buffer.find(cmd);
  if(idx!=std::string::npos)
	return true;
  else 
    return false;
}


int main()
{
  const uint8_t buffer[]="I have an in me";
  FilterExact Echo;
  if(Echo.Data_cb("OK",buffer,2))
	std::cout<<"I found the string\n";
//
 std::cout<<std::extent<decltype(buffer)>::value<<"\n";
  return 0;
}
