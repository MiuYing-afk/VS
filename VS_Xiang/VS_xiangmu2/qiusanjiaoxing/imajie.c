#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    
    int num = 1;
    
    // 打印正方形矩阵
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            printf("%02d", num++);
        }
        printf("\n");
    }
    
    printf("\n"); // 空行分隔
    
    // 打印右对齐的三角形矩阵
    num = 1;
    for(int i = 1; i <= n; i++) {
        // 打印前导空格：每行需要2*(n-i)个空格（因为每个数字占2位）
        for(int j = 0; j < n - i; j++) {
            printf("  "); // 两个空格，因为每个数字占两位
        }
        // 打印数字
        for(int j = 0; j < i; j++) {
            printf("%02d", num++);
        }
        printf("\n");
    }
    
    return 0;
}
