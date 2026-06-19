/*
16. 级数求和
【问题描述】

已知：
S
n
=
1
+
1
2
+
1
3
+
…
+
1
n
S 
n
 =1+ 
2
1
 + 
3
1
 +…+ 
n
1
 。显然对于任意一个整数 
k
k，当 
n
n 足够大的时候，
S
n
>
k
S 
n
 >k。

现给出一个整数k，要求计算出一个最小的n，使得Sn>k。

【输入】
一个正整数1≤k≤15。

【输出】

一个正整数 n。

【样例输入】

1
【样例输出】

2
*/

// #include<stdio.h>

// int main()
// {
//     double sum=0;
//     int n=1,k;
//     scanf("%d",&k);
//     for(;(sum-(double)k)<=1e-6;n++)
//     {
//         sum+=1/n;
//     }
//     printf("%d",n);
// }

#include <stdio.h>

int main() {
    int k;
    scanf("%d", &k);
    
    double sum = 0.0;
    int n = 0; // 从0开始计数，避免多输出1
    while (sum <= k) { // 直接判断sum是否≤k（浮点数误差不影响k为整数的场景）
        n++;
        sum += 1.0 / n; // 先自增n，再累加（保证顺序正确）
    }
    printf("%d\n", n);
    return 0;
}