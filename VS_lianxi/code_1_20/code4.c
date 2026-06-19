/*
2. 求最大数
【问题描述】

编写一个程序，输入a、b、c三个值，输出其中最大值。

【输入】

a、b、c三个整数，用空格分隔

【输出】

3个整数中的最大数
【样例输入】

1 5 3
【样例输出】

5
*/

#include<stdio.h>

int main()
{
    int a,max=0;
    for(int i=0;i<3;i++)
    {
    scanf("%d",&a);
    if(a>=max)max=a;
    }
    
    printf("%d",max);

    return 0;
}