#include "stdio.h"
// 提前声明排序函数，更规范
void swap(int *arr, int len);

int main()
{
    int arr[1000] = {0}, sum = 0, n = 0;
    char arr_1[5000] = {0};
    // 读取整行输入
    fgets(arr_1, 5000, stdin);
    
    // 解析多位数：核心修复部分
    int num = 0; // 临时存储正在解析的数字
    for (int i = 0; arr_1[i] != '\0'; i++)
    {
        // 如果是数字，拼接成多位数
        if ('0' <= arr_1[i] && arr_1[i] <= '9')
        {
            num = num * 10 + (arr_1[i] - '0');
        }
        // 如果是空格/换行（分隔符），说明一个数字解析完成
        else if (num != 0)
        {
            arr[n++] = num;
            num = 0; // 重置临时数字，准备解析下一个
        }
    }
    // 处理最后一个数字（行尾无分隔符的情况）
    if (num != 0)
    {
        arr[n++] = num;
    }

    // 冒泡排序（升序）
    swap(arr, n);
    // 取偶数位（0,2,4...）求和：核心逻辑（正确）
    for (int i = 0; i < n; i += 2)
    {
        sum += arr[i];
    }
    printf("%d", sum);
    return 0;
}

// 冒泡排序函数（重命名为bubbleSort，更直观）
void swap(int *arr, int len)
{
    for (int i = 0; i < len - 1; i++)
    {
        for (int j = 0; j < len - i - 1; j++)
        {
            if (*(arr + j) > *(arr + j + 1))
            {
                int temp = *(arr + j);
                *(arr + j) = *(arr + j + 1);
                *(arr + j + 1) = temp;
            }
        }
    }
}