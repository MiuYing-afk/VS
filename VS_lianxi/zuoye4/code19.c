/*
19. 求前n个自然数的和
【问题描述】
读入一个自然数n，求0+1+2+...+n之和。
【要求】
用循环来完成计算。
【输入形式】
自然数n
【输出形式】
前n个自然数的和
【样例输入】
10
【样例输出】
55
*/

#include<stdio.h>

int main()
{
    int n,sum=0;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        sum+=i;
    }
    printf("%d",sum);

    return 0;
}