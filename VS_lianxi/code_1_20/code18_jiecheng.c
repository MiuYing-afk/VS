#include<stdio.h>
double fact(int n);

void main()
{
    int n;
    printf("请输入一个整数：");
    scanf("%d",&n);
    printf("%d!=%.1f\n",n,fact(n));
}

double fact(int n)
{
    double result;
    if(n==1||n==0)
        result=1;
    else
        result=n*fact(n-1);
    return result;
}