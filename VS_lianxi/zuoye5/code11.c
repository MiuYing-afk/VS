/*
10. 质因数分解
【问题描述】

已知正整数 
n
n 是两个不同的质数的乘积，试求出两者中较大的那个质数。

【输入】

输入一个正整数 
n
n。

1≤n≤2×10 
9
 

【输出】

输出一个正整数 
p
p，即较大的那个质数。



【样例输入】

21
【样例输出】

7
*/

#include<stdio.h>
#include<math.h>

int main()
{
    int n,t=2;
    scanf("%d",&n);
    if(n==1)
    {
        printf("1");
        return 0;
    }
    for(int i=2;i<=sqrt(n);i++)
    {
        if(n%i==0)
        {
            if(i>t)t=i;
            n/=i;
            i=2;
        }
        if(n==1)break;
    }
    printf("%d",t);

    return 0;
}