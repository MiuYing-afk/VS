#include<stdio.h>

int main() {
    int n;
    // 使用 long long 类型，可以存储更大的整数
    long long S = 0;
    long long factorial = 1;  // 保存当前阶乘值
    
    scanf("%d", &n);
    
    // 优化：利用阶乘的递推关系，避免重复计算
    for(int i = 1; i <= n; i++) {
        factorial *= i;      // 计算 i! = (i-1)! * i
        S += factorial;      // 累加到总和
    }
    
    printf("%lld\n", S);
    
    return 0;
}
//会超时