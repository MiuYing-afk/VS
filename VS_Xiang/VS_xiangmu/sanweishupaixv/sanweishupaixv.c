/*
题目描述
给出三个整数 a,b,c(0≤a,b,c≤100)，要求把这三位整数从小到大排序。

输入格式
输入三个整数 a,b,c，以空格隔开。

输出格式
输出一行，三个整数，表示从小到大排序后的结果。

输入输出样例
输入 #1复制

1 14 5
输出 #1复制

1 5 14
输入 #2复制

2 2 2
输出 #2复制

2 2 2
*/

#include<stdio.h>

int main()
{
    int a,b,c;
    scanf("%d %d %d",&a,&b,&c);
    int i=0;

    if(b<a){
        i=a;a=b;b=i;
    }

    if(c<b){
        i=b;b=c;c=i;
    }

    if(b<a){
        i=a;a=b;b=i;
    }

    printf("%d %d %d",a,b,c);

    return 0;
}