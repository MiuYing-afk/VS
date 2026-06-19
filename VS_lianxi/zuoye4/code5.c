/*
5. 完数
【问题描述】

一个正整数如果恰好等于除了它本身以外的所有因子之和，这个数就称为"完数"。例如，6的因子为1、2、3，而6=1+2+3，因此6是"完数"。

编程输出1000以内的所有完数。

【输入】

无
【输出】

1000以内的所有完数，用空格分隔

【样例输入】

无
【样例输出】

6 28 496 
*/

#include<stdio.h>
#include<math.h>

int main()
{
    int num=2,i=1;
    for(;num<1000;num++)
    {
        int sum=0;
        for(i=1;i<=sqrt(num);i++)
        {
            if(num%i==0)
            {
                sum+=i;
                sum+=num/i;
            }
        }
        if(2*num==sum)
            { printf("%d ",num); }
    }
    return 0;
}