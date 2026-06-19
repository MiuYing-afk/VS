#include <stdio.h>

int main() {
    int a[100];
    int i = 0;
    // 输入数据，直到遇到 0
    while (1) {
        scanf("%d", &a[i]);
        if (a[i] == 0) {
            break;
        }
        i++;
    }
    // 倒序输出，从最后一个有效数字开始
    for (int j = i - 1; j >= 0; j--) {
        printf("%d ", a[j]);
    }
    return 0;
}