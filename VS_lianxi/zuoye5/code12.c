/*
11. 最长连号
【问题描述】

输入长度为 
n
n 的一个正整数序列，要求输出序列中最长连号的长度。

连号指在序列中，从小到大的连续自然数。

【输入形式】

第一行，一个整数 
n
n。

第二行，
n
n 个整数 
a
i
a 
i
 ，之间用空格隔开。

1≤n≤10 
4
 ，
1
≤
a
i
≤
1
0
9
1≤a 
i
 ≤10 
9
 。

【输出形式】

一个数，最长连号的个数。



【样例输入】

10
1 5 6 2 3 4 5 6 8 9
【样例输出】

5
【样例说明】

最长的连号是“2 3 4 5 6”，数字个数为5
*/

#include<stdio.h>

int main()
{
    int n,t=1,cnt=1,str[1000]={0};
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&str[i]);
    }
    for(int i=0;str[i]!=0;i++)
    {
        if(str[i+1]==str[i]+1)
        {
            t++;
            if(t>cnt)cnt=t;
        }else{
            t=1;
        }
    }
    printf("%d",cnt);

    return 0;
}