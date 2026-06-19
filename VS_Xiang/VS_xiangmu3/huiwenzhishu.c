/*
题目描述
因为 151 既是一个质数又是一个回文数（从左到右和从右到左是看一样的），所以 151 是回文质数。

写一个程序来找出范围 [a,b](5≤a<b≤100,000,000)（一亿）间的所有回文质数。

输入格式
第一行输入两个正整数 a 和 b。

输出格式
输出一个回文质数的列表，一行一个。

输入输出样例
输入 #1复制

5 500
输出 #1复制

5
7
11
101
131
151
181
191
313
353
373
383
*/

#include"stdio.h"

int main()
{
    int a,b;
    int isReverse(int n);
    int isPrime(int n);
    scanf("%d%d",&a,&b);
    if(isPrime(a)==0)a++;
    for(int i=a;i<=b;i+=2)
    {
        if(isReverse(i))
        {
            if(isPrime(i))
            {
                printf("%d\n",i);
            }
        }
    }

    return 0;
}

int isReverse(int n)
{
    int temp=n,re=0;
    while(temp>0)
    {
        re=re*10+temp%10;
        temp/=10;
    }
    if(re==n)return 1;
    else return 0;
}

int isPrime(int n)
{
    if(n%2==0)return 0;
    for(int i=3;i*i<=n;i+=2)
    {
        if(n%i==0)return 0;
    }
    return 1;
}