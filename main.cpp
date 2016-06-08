#include <stdio.h>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include "include/zlib.h"
 
using namespace std;

void showHex(const char* src)
{
	for(int i=0;i<strlen(src);i++)
	{
		printf("%02x ",(Byte)src[i]);
		if((i+1)%20==0)printf("\n");
	}
	printf("\n");
}
 
int main()
{ 
	cout<<"test zlib!"<<endl;
    char src[] = "hello zlib! This is a test zlib program! Version 1.2.8 fixes a very rare bug in decompression. All users are encouraged to upgrade immediately. Version 1.2.8 also has these improvements.";
   	cout<<"src:"<<endl;
   	showHex(src);
   	
   	//compress
   	Byte compr[1024]={0};
	uLong comprLen = sizeof(compr);
	int err = compress(compr, &comprLen, (const Bytef*)src,strlen(src)+1);
	if (err != Z_OK) {
        cerr << "compess error: " << err << '\n';
        exit(1);
    }    
    cout<<"compress:"<<endl;
   	showHex((char*)compr);
    
    //ucompress
    Byte uncompr[1024]={0};
    uLong uncomprLen = sizeof(uncompr);
    err = uncompress(uncompr, &uncomprLen, compr, comprLen);
    if (err != Z_OK) {
        cerr << "uncompess error: " << err << '\n';
        exit(1);
    }
    cout<<"uncompress:"<<endl;
   	showHex((char*)uncompr);
}
