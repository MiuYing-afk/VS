/*
4. 冒泡排序
给定一个整数数组 elements，请实现冒泡排序算法。冒泡排序是一种简单的排序算法，通过重复遍历待排序的数组，比较相邻的元素并交换它们的位置，直到整个数组有序。输入格式：第一行输入一个整数 n，表示数组的长度（1 ≤ n ≤ 100）。第二行输入 n 个整数，表示数组中的值，元素之间用空格分隔（0 ≤ elements[i] ≤ 100）。输出格式：输出 n 个整数，表示排序后的数组，元素之间用空格分隔。

示例 1：

输入：
6
5 2 9 1 5 6
输出：
1 2 5 5 6 9
示例 2：

输入：
8
3 1 4 1 5 9 2 6
输出：
1 1 2 3 4 5 6 9
示例 3：

输入：
6
10 7 8 9 1 5
输出：
1 5 7 8 9 10
示例 4：

输入：
5
12 11 13 5 6
输出：
5 6 11 12 13


示例 5：

输入：
4
4 3 2 1
输出：
1 2 3 4
提示：

数组的长度在范围 [1, 100] 内。

数组中的元素范围在 [0, 100] 内。

 

Auxiliary Code

#include <stdio.h>

// 冒泡排序函数
void bubbleSort(int* elements, int size) {
    // Code here...
}

int main() {
    int n;
    scanf("%d", &n); // 读取数组长度
    int elements[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &elements[i]); // 读取每个元素的值
    }

    bubbleSort(elements, n); // 调用冒泡排序函数

    for (int i = 0; i < n; i++) {
        printf("%d", elements[i]); // 输出排序后的数组
        if (i < n - 1) {
            printf(" "); // 输出元素之间用空格分隔
        }
    }
    printf("\n"); // 换行

    return 0;
}
*/

#include <stdio.h>

// 冒泡排序函数
void bubbleSort(int* elements, int size) {
    // 外层控制轮数
    for (int i = 0; i < size - 1; i++) {
        // 内层相邻比较，每轮末尾i个已有序不用比较
        for (int j = 0; j < size - 1 - i; j++) {
            if (elements[j] > elements[j + 1]) {
                // 交换
                int temp = elements[j];
                elements[j] = elements[j + 1];
                elements[j + 1] = temp;
            }
        }
    }
}

int main() {
    int n;
    scanf("%d", &n); // 读取数组长度
    int elements[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &elements[i]); // 读取每个元素的值
    }

    bubbleSort(elements, n); // 调用冒泡排序函数

    for (int i = 0; i < n; i++) {
        printf("%d", elements[i]); // 输出排序后的数组
        if (i < n - 1) {
            printf(" "); // 输出元素之间用空格分隔
        }
    }
    printf("\n"); // 换行

    return 0;
}