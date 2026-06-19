/*
18. 找最小值
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
n 个整数中最小值是什么。

【输入】

第一行输入一个正整数 
n
n，表示数字个数。

第二行输入 
n
n 个非负整数，表示 
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

1 ≤ n≤100 且 
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

输出一个非负整数，表示这 
n
n 个非负整数中的最小值。

【样例输入】

8
1 9 2 6 0 8 1 7
【样例输出】

0
*/

#include<stdio.h>

int main()
{
    int n,min=100000;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        int temp;
        scanf("%d",&temp);
        if(temp<min)min=temp;
    }
    printf("%d",min);

    return 0;
}