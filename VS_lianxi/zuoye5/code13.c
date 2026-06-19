/*
12. 求极差 / 最大跨度值
【问题描述】

给出 
n
n 和 
n
n 个整数 
a
i
a 
i
 ，求这 
n
n 个整数中的极差是什么。极差的意思是一组数中的最大值减去最小值的差。



【输入】

第一行输入一个正整数 
n
n，表示整数个数。

第二行输入 
n
n 个整数 
a
1
,
a
2
…
a
n
a 
1
 ,a 
2
 …a 
n
 ，以空格隔开。

≤n≤100，
0
≤
a
i
≤
1000
0≤a 
i
 ≤1000。



【输出】

输出一个整数，表示这 
n
n 个整数的极差。



【样例输入】

6
4 1 5 1 4 1
【样例输出】

4
*/

#include<stdio.h>

int main()
{
    int n,t,min=1000,max=0;
    scanf("%d",&n);
    if(n==0)printf("0");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&t);
        if(n==1)
        {
            printf("%d",t);
            return 0;
        }
        if(t>max)max=t;
        else if(t<min)min=t;
    }
    if(n!=1&&n!=0)printf("%d",max-min);

    return 0;
}