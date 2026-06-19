/*
题目描述
输入长度为 n 的一个正整数序列，要求输出序列中最长连号的长度。

连号指在序列中，从小到大的连续自然数。

输入格式
第一行，一个整数 n。

第二行，n 个整数 a 
i
​
 ，之间用空格隔开。

输出格式
一个数，最长连号的个数。

输入输出样例
输入 #1复制

10
1 5 6 2 3 4 5 6 8 9
输出 #1复制

5

说明/提示
数据规模与约定
对于 100% 的数据，保证 1≤n≤10 
4
 ，1≤a 
i
​
 ≤10 
9
 。
*/

#include<stdio.h>

int main()
{
    int n,cnt=1,max=1,t1=0,t2=0;
    scanf("%d",&n);
    scanf("%d",&t1);
    for(int i=1;i<n;i++){
        scanf("%d",&t2);
        if(t2==t1+1){
            cnt++;
        }else{cnt=1;}
        t1=t2;
        if(max<=cnt)max=cnt;
    }
    printf("%d",max);

    return 0;
}