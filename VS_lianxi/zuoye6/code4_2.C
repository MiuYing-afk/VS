#include <stdio.h>

int main() {
    int n;
    // 读取输入的行数
    scanf("%d", &n);
    
    // 创建二维数组存储杨辉三角形，最大支持10行
    int yanghui[10][10] = {0};
    
    // 构建杨辉三角形
    for (int i = 0; i < n; i++) {
        // 每行的第一个元素为1
        yanghui[i][0] = 1;
        // 每行的最后一个元素为1
        yanghui[i][i] = 1;
        
        // 计算中间元素的值（从第三行开始）
        for (int j = 1; j < i; j++) {
            yanghui[i][j] = yanghui[i-1][j-1] + yanghui[i-1][j];
        }
    }
    
    // 打印杨辉三角形，每个数字占5个字符位
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            printf("%5d", yanghui[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}
