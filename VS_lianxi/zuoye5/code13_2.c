#include<stdio.h>

int main() {
    int n, t;
    int min, max;
    
    // 读取数据个数
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("0");
        return 0;
    }
    
    // 读取第一个数并初始化最大最小值
    if (scanf("%d", &t) != 1) {
        printf("0");
        return 0;
    }
    min = max = t;
    
    // 处理剩余的数字
    for(int i = 1; i < n; i++) {
        if(scanf("%d", &t) != 1) {
            printf("0");
            return 0;
        }
        if(t > max) {
            max = t;
        } else if(t < min) {
            min = t;
        }
    }
    
    // 输出结果
    printf("%d", max - min);
    
    return 0;
}
