/*
题目描述
给出 n 和 n 个整数 a 
i
​
 ，求这 n 个整数中最小值是什么。

输入格式
第一行输入一个正整数 n，表示数字个数。

第二行输入 n 个非负整数，表示 a 
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
输出一个非负整数，表示这 n 个非负整数中的最小值。

输入输出样例
输入 #1复制

5
5 7 4 2 6
输出 #1复制

2
说明/提示
数据保证，n≤100 且 0≤a 
i
​
 ≤1000。
*/

#include<stdio.h>

int main()
{
    int n;
    scanf("%d",&n);
    int k=n-1;
    int a[k];
    int i=0,j=n;
    int min=100;

    for(i=0;j>0;j--){
        scanf("%d",&a[i]);
        i++;
        if(a[i]<min){
            min=a[i];
        }else{
            min=min;
        }
    }

    printf("%d",min);

    return 0;
}