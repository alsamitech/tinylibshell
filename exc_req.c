#include "include/exc_req.h"

char* get_line(FILE* stream){
    size_t bytes=0;
    unsigned int capacity=64;
    char* buf=(char*)malloc(capacity);
    if(!buf)return 0x0;
    char c;
#ifdef __unix__
    while((c=fgetc(stream))!=EOF&&c!='\n')
#else
    while((c=fgetc(stream))!=EOF&&c!='\n'&&c!='\r')
#endif // __unix__
    {
        bytes++;
        if(bytes+1>=capacity){
            capacity*=2;
            buf=realloc(buf, capacity);
            if(!buf){
                return 0x0;
            }
        }
        buf[bytes-1]=c;
    }
    
    return buf;
}

unsigned char starts_with(char* _in, char* startsw){
  for(unsigned int i=0;_in[i]&&startsw[i];i++){
    if(_in[i]!=startsw[i]) return 1;
  }

  return 0;
}