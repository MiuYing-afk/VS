/*
21. 三角函数
【问题描述】

输入一组勾股数a,b,c（a≠b≠c），用分数格式输出其较小锐角的正弦值。（要求约分。）

【输入】

三个正整数，即勾股数a,b,c（无大小顺序）。1≤ a,b,c ≤10^9 

【输出】

一个分数，即较小锐角的正弦值，要求约分。

【样例输入】

3 5 4
【样例输出】

3/5
*/

#include<stdio.h>

int main()
{
    int a,b,c,sin,min,max,yue;
    int yue_finder(int min,int max);
    scanf("%d%d%d",&a,&b,&c);

    if(a>b&&a>c)max=a;
    else if(b>a&&b>c)max=b;
    else max=c;

    if(a<b&&a<c)min=a;
    else if(b<a&&b<c)min=b;
    else min=c;

    yue=yue_finder(min,max);
    printf("%d/%d",min/yue,max/yue);

    return 0;
}

/*
    10 6  0
    6  4  6
    4  2  4
    2  0  2
*/
int yue_finder(int min,int max)
{
    int temp;
    while (min) {
        temp = min;
        min = max % min;
        max = temp;
    }
    return max;
}