/*
2. 将数表示为两个素数之和
【问题描述】

输入一个大于等于6的偶数，将它表示为两个素数之和。

要求：用自定义函数int prime(int n)来判断n是否为素数。

【输入形式】

 一个偶数

【输出形式】

所有的组合，要求第一个素数从小到大的顺序

【样例输入】

10
【样例输出】

10=3+7

10=5+5
*/

#include<stdio.h>
#include<math.h>

int main()
{
    int n;
    int prime(int n);
    scanf("%d",&n);
    for(int i=2;i<=n/2;i++)
    {
        if(prime(i)==1&&prime(n-i)==1)
        {
            printf("%d=%d+%d\n",n,i,n-i);
        }
    }

    return 0;
}

int prime(int n)
{
    for(int i=2;i<=sqrt(n);i++)
    {
        if(n%i==0)
        {
            return 0;
        }
    }
    return 1;
}