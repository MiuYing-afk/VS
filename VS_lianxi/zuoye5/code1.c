/*
1. 小于x的Fibonacci数列
【问题描述】

从键盘输入一个大于1的正整数x，打印所有小于x的Fibonacci数列项，x不会大于第41个Fibonacci数列项。

【说明】

Fibonacci数列的第1项、第2项为1，数列从第3项开始，每一项都等于前两项的和

【输入】

一个大于1的正整数x（x不会大于第41个Fibonacci数列项）

【输出】

所有小于x的Fibonacci数列项，用空格分隔

【样例输入】


20
【样例输出】


1 1 2 3 5 8 13
*/

#include<stdio.h>

int main()
{
    int x,a1=1,a2=1,t;
    scanf("%d",&x);
    printf("1 1 ");
    for(;a1+a2<x;){
        t=a1+a2;
        printf("%d ",t);
        a1=a2,a2=t;
    }

    return 0;
}