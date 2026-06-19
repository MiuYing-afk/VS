/*
题目描述
计算 1+2+3+⋯+(n−1)+n 的值，其中正整数 n 不大于 100。由于你没有高斯聪明，所以你不被允许使用等差数列求和公式直接求出答案。

输入格式
输入一个正整数 n。

输出格式
输出一个正整数，表示最后求和的答案。

输入输出样例
输入 #1复制

100
输出 #1复制

5050
说明/提示
数据保证，1≤n≤100。
*/

// #include<stdio.h>

// int main()
// {
//     int n;
//     scanf("%d",&n);
//     int guo;
//     guo=n*(n+1)/2;
//     printf("%d",guo);

//     return 0;
// }

#include<stdio.h>

int main()
{
    int n;
    scanf("%d",&n);
    int guo=0;

    for(n=n;n>0;n--){
        guo+=n;
    }
    printf("%d",guo);

    return 0;
}
