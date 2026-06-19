#include <stdio.h>

int main() {
    long long n;
    scanf("%lld", &n);
    // 寻找第一个质因数
    for (long long i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            // 另一个质因数是 n / i，比较两者大小并输出较大的
            long long other = n / i;
            printf("%lld\n", i > other ? i : other);
            return 0;
        }
    }
    // 若循环中未找到（实际题目中n是两个不同质数的积，所以这里理论上不会执行）
    printf(" ");
    return 0;
}