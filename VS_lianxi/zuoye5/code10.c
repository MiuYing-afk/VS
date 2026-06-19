/*
9. 求三角形
【问题描述】

模仿例题，打印出不同方向的正方形，然后打印三角形矩阵。中间有个空行。

【输入】

输入矩阵的规模，不超过 
9
9。

【输出】

输出矩形和正方形

【样例输入】

4
【样例输出】

01020304
05060708
09101112
13141516

      01
    0203
  040506
07080910

*/

#include<stdio.h>

int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n*n;i++)
    {
        if(i%n==0)
        {
            printf("%02d\n",i);
        }else{
            printf("%02d",i);
        }
    }
    printf("\n");
    int cnt=1;
    for(int i=1;cnt<=n;cnt++)
    {
        for(int j=1;j<=n-cnt;j++)
        {
            printf("  ");
        }
        for(int k=1;k<=cnt;k++)
        {
            printf("%02d",i++);
        }
        printf("\n");
    }

    return 0;
}