/*
47. 求最小的 n，使得 Sn>k
【问题描述】

已知：Sn=1+1/2+1/3+…+1/n。显然对于任意一个整数 k，当 n 足够大的时候，Sn>k。

现给出一个整数 k，要求计算出一个最小的 n，使得 Sn>k。

【输入】

一个正整数 k（1≤k≤15）。

【输出】

一个正整数 n，使得 Sn>k的最小正整数。

【样例输入】

1
【样例输出】

2
*/

// #include"stdio.h"
// #include"math.h"

// int main()
// {
//     int k,n=1;
//     float Sn=0.0;
//     scanf("%d",&k);
//     for(;fabs(k-Sn)>1e-6;n++)
//     {
//         Sn += 1.0/n;
//     }
//     printf("%d",n);

//     return 0;
// }

#include "stdio.h"

int main()
{
    int k, n = 0;          // n从0开始，避免冗余递增
    double Sn = 0.0;       // 改用double提高精度
    scanf("%d", &k);
    
    // 循环条件直接判断Sn <= k，符合题目要求
    while (Sn <= k)
    {
        n++;
        Sn += 1.0 / n;     // 累加第n项的倒数
    }
    
    printf("%d", n);
    return 0;
}