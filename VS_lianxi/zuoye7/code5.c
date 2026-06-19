#include"stdio.h"

long compose(long number);

int main()
{
   long int n ;
   scanf("%ld",&n);
   printf("%ld\n",compose(n));
   return 0;
}

long compose(long number)
{
    long reverse=0,index=number,Return=0;
    for(;index!=0;index/=10)
    {
        reverse=reverse*10+index%10;
    }
    for(;reverse!=0;reverse/=10)
    {
        if((reverse%10)%2==0)
        {
            Return=Return*10+reverse%10;
        }
    }
    return Return;
}