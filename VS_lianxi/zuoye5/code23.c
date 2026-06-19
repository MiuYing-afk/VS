/*
23. 计算余数
【问题描述】
计算两个双精度浮点数a和b相除的余数，a和b都是正数。
这里余数（r）的定义是：a = k * b + r，其中 k是整数， 0 <= r < b。

【输入】

一行两个空格隔开的数a和b。

【输出】

输出a除以b的余数(答案保留两位小数)。

【样例输入】

1.5 1.7
【样例输出】

1.50
*/

// #include<stdio.h>
// #include<math.h>

// int main()
// {
//     double a,b;
//     scanf("%lf%lf",&a,&b);
//     double yv=b;
//     while(1)
//     {
//         if(fabs(a-yv)>1e-6)
//         {yv-=a;}
//         else break;
//     }
//     printf("%.2f",yv);

//     return 0;
// }

#include <stdio.h>
#include <math.h>

int main() {
    double a, b;
    scanf("%lf %lf", &a, &b);
    
    // 核心逻辑：k是a/b向下取整的整数，r = a - k*b
    double k = floor(a / b);  // floor函数：向下取整（如0.882→0，3.9→3）
    double r = a - k * b;
    
    // 保留两位小数输出（自动补0，如1.5→1.50）
    printf("%.2f\n", r);
    return 0;
}