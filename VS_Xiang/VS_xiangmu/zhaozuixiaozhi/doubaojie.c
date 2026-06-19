#include<stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    int a[n];  // 数组大小应为n（若编译器支持VLA），或用#define定义足够大的常量
    int i;
    int min;

    // 先读取第一个元素初始化min
    scanf("%d", &a[0]);
    min = a[0];

    // 读取剩余n-1个元素并比较
    for (i = 1; i < n; i++) {
        scanf("%d", &a[i]);
        if (a[i] < min) {
            min = a[i];
        }
    }

    printf("%d", min);
    return 0;
}