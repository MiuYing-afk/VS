/*
27. 因子个数
【问题描述】
对于任意给定的一个正整数，计算其不同因数的个数。

【输入】

正整数N（1<=N<231）。

【输出】

N的因子个数。

【样例输入】

6
【样例输出】

4
【样例说明】
1、2、3、6都是6的因数。因此，输出4。
*/

#include<stdio.h>
#include<math.h>

int main()
{
    int n,cnt=0,i=1;
    scanf("%d",&n);
    for(;i<sqrt(n);i++)
    {
        if(n%i==0)cnt+=2;
    }
    if(i*i==n)cnt++;
    printf("%d",cnt);

    return 0;
}