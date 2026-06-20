/*
3. 希尔排序
给定一个整数数组 elements，请实现希尔排序算法。希尔排序是一种基于插入排序的排序算法，首先将整个数组按照一定的间隔分成若干个子序列，对这些子序列进行插入排序，然后逐步减少间隔，最后对整个数组进行插入排序，使得最终得到一个有序的数组。输入格式：第一行输入一个整数 n，表示数组的长度（1 ≤ n ≤ 100）。第二行输入 n 个整数，表示数组中的值，元素之间用空格分隔（0 ≤ elements[i] ≤ 100）。输出格式：输出 n 个整数，表示排序后的数组，元素之间用空格分隔。

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

// 希尔排序函数
void shellSort(int* elements, int size) {
   // Code here...
}

int main() {
    int n;
    scanf("%d", &n); // 读取数组长度
    int elements[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &elements[i]); // 读取每个元素的值
    }

    shellSort(elements, n); // 调用希尔排序函数

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

// 希尔排序函数
void shellSort(int* elements, int size) {
    // 初始间隔设为长度一半，不断折半缩小间隔
    for (int gap = size / 2; gap > 0; gap /= 2) {
        // 分组插入排序
        for (int i = gap; i < size; i++) {
            int temp = elements[i];
            int j;
            // 向前同间隔比较，大于temp则后移
            for (j = i; j >= gap && elements[j - gap] > temp; j -= gap) {
                elements[j] = elements[j - gap];
            }
            elements[j] = temp;
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

    shellSort(elements, n); // 调用希尔排序函数

    for (int i = 0; i < n; i++) {
        printf("%d", elements[i]); // 输出排序后的数组
        if (i < n - 1) {
            printf(" "); // 输出元素之间用空格分隔
        }
    }
    printf("\n"); // 换行

    return 0;
}