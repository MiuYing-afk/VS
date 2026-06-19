/*
37. 进制转换
【问题描述】

模拟将任意给定的正整数n转换成对应的二进制数的过程：对于输入的任意正整数n，输出若干行“shang:* yu:*”的形式，表示其转换过程。

【输入】

正整数n（1<=n<=5000）。

【输出】

其转为二进制的过程(具体见样例)。

【样例输入】

13
【样例输出】

shang:6 yu:1
shang:3 yu:0
shang:1 yu:1
shang:0 yu:1

*/

#include"stdio.h"

int main()
{
    int n,shang,yu;
    scanf("%d",&n);
    while(n!=0)
    {
        yu=n%2;
        shang=n/2;
        printf("shang:%d yu:%d\n",shang,yu);
        n/=2;
    }

    return 0;
}