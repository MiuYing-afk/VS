/*
题目描述
给出 n 和 n 个整数 a 
i
​
 ，求这 n 个整数中的极差是什么。极差的意思是一组数中的最大值减去最小值的差。

输入格式
第一行输入一个正整数 n，表示整数个数。

第二行输入 n 个整数 a 
1
​
 ,a 
2
​
 …a 
n
​
 ，以空格隔开。

输出格式
输出一个整数，表示这 n 个整数的极差。

输入输出样例
输入 #1复制

6
4 1 5 1 4 1
输出 #1复制

4
说明/提示
数据保证，1≤n≤100，0≤a 
i
​
 ≤1000。
*/

#include<stdio.h>

int main()
{
    int n,a,max=0,min=100;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&a);
        if(a>=max)max=a;
        if(a<=min)min=a;
    }
    printf("%d",max-min);

    return 0;
}