/*
32. 等腰三角形
【问题描述】

输入一个正整数n，输出高为n的由*组成的等腰三角形。

【输入】

一个正整数n（1<=n<=20）。

【输出】

高为n的由*组成的等腰三角形。

【样例输入】

3
【样例输出】

  *
 ***
*****
*/

#include"stdio.h"

int main()
{
    int n,i = 1 ,fu = 1;
    scanf("%d",&n);
    for( ; n > 0 ; fu += 2)
    {
        int kong = n-- -1 ,fuu = fu;
        while(kong-- >= 0)printf(" ");
        while(fuu-- != 0)printf("*");
        printf("\n");
    }

    return 0;
}