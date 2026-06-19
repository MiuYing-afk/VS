#include <stdio.h>
#include <stdlib.h>  // 用于 abs 函数

int main() {
    int n;
    scanf("%d", &n);

    // 用数组分别存储各科成绩和总分
    int chinese[1000], math[1000], english[1000], total[1000];

    // 读取成绩并计算总分
    for (int i = 0; i < n; i++) {
        scanf("%d %d %d", &chinese[i], &math[i], &english[i]);
        total[i] = chinese[i] + math[i] + english[i];  // 计算总分
    }

    int count = 0;

    // 双重循环判断每一对学生是否符合条件
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {  // j 从 i+1 开始，避免重复计算
            // 检查三科分差是否≤5，总分差是否≤10
            if (abs(chinese[i] - chinese[j]) <= 5 &&
                abs(math[i] - math[j]) <= 5 &&
                abs(english[i] - english[j]) <= 5 &&
                abs(total[i] - total[j]) <= 10) {
                count++;
            }
        }
    }

    printf("%d\n", count);
    return 0;
}

//abs函数-->绝对值函数