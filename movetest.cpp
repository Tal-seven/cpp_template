#include <iostream>
#include <string>
#include <math.h>
#include <stdarg.h>



void move(float speed,float direction)                                                                                                                                                   
{ 
  (void)direction;
  char cmdbuffer[50]={0};       //not using std::string to avoid dynamic allocation overhead.                                                                                                                      
  unsigned char speed_hex;     
  speed_hex=static_cast<unsigned char>(fabs(speed));                                                                                                                                                               
    
  auto format_str=[&](const char* fmt,...){                                                                                                                                                        
        int n=0;               
        size_t size=50;        
        va_list ap;
        while(1){
        va_start(ap,fmt);
        n=vsnprintf(cmdbuffer,size,fmt,ap);
        va_end(ap);
        if(n > -1 && n < static_cast<int>(size))                                                                                                                                                                   
        {
          return true;
        }
        if(n > -1)
        {
          size=n+1;
        }
        else 
        {
          size *=2;
        }

        }
   };
  if(speed<0)
   {
     format_str("!a%.2X",speed_hex);                                                                                                                                                                               
   }
  else
   {
     format_str("!A%.2X",speed_hex);                                                                                                                                                                               
   }
   //auto Cmd=reinterpret_cast<const char*>(cmdbuffer.c_str());
   //
   ////   issueCommand(cmdbuffer);
     std::cout<<cmdbuffer<<"\n";
}
         
int main()
{
move(-23,28);
}
