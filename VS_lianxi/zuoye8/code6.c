#include<stdio.h>
int main()
{  int a[11]={10,20,30,40,50,60,70,80,90,100}, *p=a, n;
   scanf("%d", &n);
   for(p=a+9;p>=a; p--)
   {    if(*p>n)
            *(p+1)=*p;
        else
        {   
            *(p+1)=n;
            if(*p<0)a[0]=n;
            break;
        }
        if(p==a)
            break;
    }
    for(p=a; p<=a+10; p++)
        printf("%d ", *p);
    
} 