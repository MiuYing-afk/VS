/*
题目描述
用高精度计算出 S=1!+2!+3!+⋯+n!（n≤50）。

其中 ! 表示阶乘，定义为 n!=n×(n−1)×(n−2)×⋯×1。例如，5!=5×4×3×2×1=120。

输入格式
一个正整数 n。

输出格式
一个正整数 S，表示计算结果。

输入输出样例
输入 #1复制

3
输出 #1复制

9
说明/提示
【数据范围】

对于 100% 的数据，1≤n≤50。
*/

// #include"stdio.h"

// int main()
// {
//     int n;
//     long long S=0;
//     long long Factorial(int n);
//     scanf("%d",&n);
//     for(int i=1;i<=n;i++)
//     {
//         S+=Factorial(i);
//     }
//     printf("%lld",S);

//     return 0;
// }

// long long Factorial(int n)
// {
//     if(n==1)return 1;
//     if(n>=2)return n*Factorial(n-1);
// }

#include <stdio.h>
#include <string.h>

// 定义数组存储大整数，50! 约有65位，数组长度设100足够
#define MAX_LEN 100

// 计算单个数的阶乘（高精度），结果存入res数组，返回有效位数
int factorial(int n, int res[]) {
    // 初始化：1! = 1
    memset(res, 0, sizeof(int) * MAX_LEN);
    res[0] = 1;
    int len = 1; // 当前有效位数

    for (int i = 2; i <= n; i++) {
        int carry = 0; // 进位
        // 逐位相乘
        for (int j = 0; j < len; j++) {
            int temp = res[j] * i + carry;
            res[j] = temp % 10; // 保留当前位
            carry = temp / 10;  // 更新进位
        }
        // 处理剩余进位
        while (carry > 0) {
            res[len] = carry % 10;
            carry /= 10;
            len++;
        }
    }
    return len;
}

// 高精度加法：将fact_res加到sum_res中，返回sum_res的有效位数
int add(int sum_res[], int fact_res[], int fact_len) {
    int carry = 0;
    int sum_len = 0;
    // 先找到sum_res当前的有效位数
    while (sum_res[sum_len] != 0 || sum_len < fact_len) {
        sum_len++;
    }

    // 逐位相加
    for (int i = 0; i < sum_len || i < fact_len || carry > 0; i++) {
        int temp = sum_res[i] + (i < fact_len ? fact_res[i] : 0) + carry;
        sum_res[i] = temp % 10;
        carry = temp / 10;
    }

    // 重新计算sum_res的有效位数
    sum_len = 0;
    for (int i = MAX_LEN - 1; i >= 0; i--) {
        if (sum_res[i] != 0) {
            sum_len = i + 1;
            break;
        }
    }
    return sum_len;
}

int main() {
    int n;
    scanf("%d", &n);

    int sum_res[MAX_LEN] = {0}; // 存储最终和（高精度）
    int fact_res[MAX_LEN];      // 存储单个阶乘结果（高精度）
    int sum_len = 0;            // 最终和的有效位数

    for (int i = 1; i <= n; i++) {
        // 计算i!
        int fact_len = factorial(i, fact_res);
        // 将i!加到总和中
        sum_len = add(sum_res, fact_res, fact_len);
    }

    // 输出结果（从高位到低位）
    if (sum_len == 0) { // 特殊情况：n=0时和为0（题目中n≥1，可省略）
        printf("0");
    } else {
        for (int i = sum_len - 1; i >= 0; i--) {
            printf("%d", sum_res[i]);
        }
    }
    printf("\n");

    return 0;
}