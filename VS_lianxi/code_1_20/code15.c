#include<stdio.h>

void main()
{
    int a=0x1122,b,c;
    printf("a=%#x\n",a);
    b=(a&0xff)<<8;
    c=(a&0xff00)>>8;
    a=b|c;
    printf("对调后：%#x\n",a);
}