/*
13. 小于x的Fibonacci数列
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
    int x;
    scanf("%d",&x);
    int arr1[42]={0};
    arr1[1]=1,arr1[0]=1;
    printf("1 ");
    for(int i=2;i<42;i++)
    {
        arr1[i]=arr1[i-1]+arr1[i-2];
        printf("%d ",arr1[i-1]);
        if(arr1[i]>=x)break;
    }

    return 0;
}