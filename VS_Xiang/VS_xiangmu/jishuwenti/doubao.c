#include <stdio.h>

int main() {
    int n, x;
    // 输入两个整数n和x
    scanf("%d %d", &n, &x);
    int count = 0;
    // 遍历1到n的每个整数
    for (int num = 1; num <= n; num++) {
        int temp = num;
        // 分解当前整数的每一位数字
        while (temp > 0) {
            int digit = temp % 10;
            // 如果当前位数字等于x，计数加1
            if (digit == x) {
                count++;
            }
            temp /= 10;
        }
    }
    // 输出x出现的次数
    printf("%d\n", count);
    return 0;
}