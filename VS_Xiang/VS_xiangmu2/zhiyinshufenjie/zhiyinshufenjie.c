/*
题目描述
已知正整数 n 是两个不同的质数的乘积，试求出两者中较大的那个质数。

输入格式
输入一个正整数 n。

输出格式
输出一个正整数 p，即较大的那个质数。

输入输出样例
输入 #1复制

21
输出 #1复制

7
说明/提示
1≤n≤2×10 
9
 

NOIP 2012 普及组 第一题
*/

#include<stdio.h>
#include<math.h>

int main()
{
    int n,p,q;
    scanf("%d",&n);
    for(p=2;p<=sqrt(n);p++){
        if(n%p==0){
            q=n/p;
        }
    }
    if(p>=q)printf("%d",p);
    else printf("%d",q);    

    return 0;
}