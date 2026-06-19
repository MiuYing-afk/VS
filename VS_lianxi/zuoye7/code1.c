/*
1. 输出两数间的孪生素数
【问题描述】

输入2个正整数m 和n，输出m到n间的各对孪生素数i和j（m<=i<j<=n）。
如果两个素数之差为2, 称它们是一对孪生素数。要求素数判定用函数完成，函数int prime(int k) 判断k是否为素数。

【样例输入】

1 10

【样例输出】

[3,5]

[5,7]
*/

#include<stdio.h>
#include<math.h>

int main()
{
    int a,b;
    int prime(int k);
    scanf("%d %d",&a,&b);
    for(int i=a;i<=b-2;i++)
    {
        if(i<2)i=2;
        int s1=i;
        if(1==prime(s1)&&prime(s1+2)==1)
        {
            printf("[%d,%d]\n",s1,s1+2);
        }
    }


    return 0;
}

int prime(int k)
{
    for(int i=2;i<=sqrt(k);i++)
    {
        if(k%i==0)
        {
            return 0;
        }
    }
    return 1;
}