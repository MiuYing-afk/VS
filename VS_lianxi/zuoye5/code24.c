/*
24. 数字识别
【问题描述】

输入一个不多于四位的正整数，求出它是几位数，并分别打印出各位上的数字。

【输入】

一个不多于四位的正整数x（1<=x<=9999）。

【输出】

第一行输出x的位数num，接下来num行从高位到低位输出x的每一位上的数字。

【样例输入】

123
【样例输出】

3
1
2
3
*/

#include<stdio.h>

int main()
{
    int n,Long_i,reverse_i;
    int Long(int n),reverse(int n);
    scanf("%d",&n);
    Long_i=Long(n);
    reverse_i=reverse(n);
    printf("%d\n",Long_i);
    for(;Long_i>0;Long_i--)
    {
        printf("%d\n",reverse_i%10);
        reverse_i/=10;
    }

    return 0;
}

int Long(int n)
{
    int Long=0;
    for(;n>0;Long++,n/=10);
    return Long;
}

int reverse(int n)
{
    int reverse=0;
    for(;n>0;n/=10)
    {
        reverse=reverse*10+n%10;
    }
    return reverse;
}