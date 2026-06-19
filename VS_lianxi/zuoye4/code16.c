/*
16. 求1！+2！+…+n!
【问题描述】
求1！+2！+…+n!，其中n（1<=n<=10）值由用户输入
【输入】
整数n（1<=n<=10）
【输出】
1！+2！+…+n!的值
【样例输入】
5
【样例输出】
153
*/

#include<stdio.h>

int main()
{
    int n,sum=0,t=1;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        t*=i;
        sum+=t;
    }
    printf("%d",sum);

    return 0;
}