/*
2. 最大公约数和最小公倍数
【问题描述】

输入两个正整数m和n，求其最大公约数和最小公倍数。  

【输入】

两个正整数m和

n，用空格分隔

【输出】其最大公约数和最小公倍数，用空格分隔

【样例输入】

2 3
【样例输出】

1 6
*/

#include<stdio.h>

int main()
{
    int m,m1,n,n1,t,yue,bei;
    scanf("%d %d",&m,&n);
    m1=m,n1=n;

    if(n>m)
    { t=n1,n1=m1,m1=t; }
    t=m1%n1;
    while(t!=0)
    { m1=n1,n1=t,t=m1%n1; }
    yue=n1;
    bei=n*m/yue;
    printf("%d %d",yue,bei);
}