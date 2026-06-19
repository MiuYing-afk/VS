#include "stdio.h"

long long Fac(int n);

int main()
{
    int n;
    printf("请输入一个整数：");
    scanf("%d",&n);
    printf("该数的阶乘为：%lld\n",Fac(n));

    return 0;
}

long long Fac(int n){
    if(n==0||n==1)return 1;
    else return n*Fac(n-1);
}