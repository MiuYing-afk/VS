/*
题目描述
判断某年是否是闰年。如果公元 a 年是闰年输出 Y，否则输出 N。

输入格式
输入只有一行，包含一个整数 a(0<a<3000)。

输出格式
一行，如果公元 a 年是闰年输出 Y，否则输出 N。

输入输出样例
输入 #1复制

2006
输出 #1复制

N
*/

#include<stdio.h>

int main()
{
    int a;
    scanf("%d",&a);
    if(a%4==0){
        printf("Y");
    }else{
        printf("N");
    }

    return 0;
}