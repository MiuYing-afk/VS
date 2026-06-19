/*
29. 数字之和
【问题描述】

对于任意输入的整数，计算其各个数位上的数字之和。

【输入】

一个正整数N（1<=N<231）。

【输出】

N的各个位上的数字之和。

【样例输入】

1234
【样例输出】

10
*/

#include<stdio.h>

int main()
{
    int n,sum=0;
    scanf("%d",&n);
    do{
        sum+=n%10;
        n/=10;
    }while(n!=0);
    printf("%d",sum);
    
    return 0;
}