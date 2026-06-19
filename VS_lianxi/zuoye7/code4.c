#include<stdio.h>
int fun(long n);

int main(  )
{   long in; 
    scanf("%ld",&in);
    if(fun(in))  
           printf("YES\n");
    else
           printf("NO\n");
}

// int fun(long in)
// {
//     long index=in,index2=in;
//     int cnt=0;
//     if(index==0)return 1;
//     for(;index!=0;cnt++)
//     {
//         index/=10;
//     }
//     index=in;
//     for(int i=1;cnt!=0;cnt-=2)
//     {
//         int t;
//         for(int j=1;j!=cnt-1;j++)
//         {
//             index2/=10;
//             if(index2<10)t=index2;
//         }
//         if(index/10!=t)return 0;
//         index-=t*
//     }
// }

int fun(long n) {
    long temp = n;
    long reverse = 0;
    // 反转数字
    while (temp != 0) {
        reverse = reverse * 10 + temp % 10;
        temp = temp / 10;
    }
    // 比较原数字和反转后的数字是否相等
    return n == reverse;
}