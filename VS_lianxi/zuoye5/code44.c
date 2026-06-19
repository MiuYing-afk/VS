/*
53. 编程输出1000以内的所有完数
【问题描述】

一个正整数如果恰好等于它的因子之和，这个数就称为"完数"。例如，6的因子为1、2、3，而6=1+2+3，因此6是"完数"。

编程输出1000以内的所有完数。

【输入形式】



【输出形式】

每行输出一个数

【样例输入】

无

【样例输出】

6
28
……
*/

#include <stdio.h>

int main() {
    // 遍历1000以内的所有正整数（从2开始，1没有真因子，不可能是完数）
    for (int num = 2; num < 1000; num++) {
        int factor_sum = 0; // 存储当前数的真因子之和
        // 寻找真因子：只需遍历到num的平方根，减少循环次数（优化）
        for (int i = 1; i * i <= num; i++) {
            if (num % i == 0) {
                // i是num的真因子，累加到和中
                if (i != num) {
                    factor_sum += i;
                }
                // 对应的另一个因子num/i，需判断是否为真因子且避免重复（i=1和i=num时的特殊情况）
                int other = num / i;
                if (other != i && other != num) {
                    factor_sum += other;
                }
            }
        }
        // 判断是否是完数，若是则输出
        if (factor_sum == num) {
            printf("%d\n", num);
        }
    }
    return 0;
}