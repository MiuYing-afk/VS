#include <stdio.h>
#include <string.h>

int main() {
    // 定义每个数字（0 - 9）的5行点阵显示模式
    const char digits[10][5][4] = {
        {"XXX", "X.X", "X.X", "X.X", "XXX"},    // 0
        {"..X", "..X", "..X", "..X", "..X"},    // 1
        {"XXX", "..X", "XXX", "X..", "XXX"},    // 2
        {"XXX", "..X", "XXX", "..X", "XXX"},    // 3
        {"X.X", "X.X", "XXX", "..X", "..X"},    // 4
        {"XXX", "X..", "XXX", "..X", "XXX"},    // 5
        {"XXX", "X..", "XXX", "X.X", "XXX"},    // 6
        {"XXX", "..X", "..X", "..X", "..X"},    // 7
        {"XXX", "X.X", "XXX", "X.X", "XXX"},    // 8
        {"XXX", "X.X", "XXX", "..X", "XXX"}     // 9
    };

    int n;
    char num_str[101];

    // 输入数字的位数
    scanf("%d", &n);
    // 输入数字序列
    scanf("%s", num_str);

    // 逐行输出5行点阵
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < n; j++) {
            // 获取当前数字（字符转数字）
            int digit = num_str[j] - '0';
            // 输出当前数字对应行的点阵内容
            printf("%s", digits[digit][i]);
            // 数字间的间隔（最后一个数字后无间隔）
            if (j < n - 1) {
                printf("..");
            }
        }
        // 每行结束后换行
        printf("\n");
    }

    return 0;
}