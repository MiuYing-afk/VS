/*
5. 快速排序
给定一个整数数组 arr，请实现快速排序算法。快速排序是一种高效的排序算法，采用分而治之的策略，通过一个基准元素将数组分为两部分，使得左侧部分的元素都小于基准元素，右侧部分的元素都大于基准元素，然后递归地对这两部分进行排序。输入格式：第一行输入一个整数 n，表示数组的长度（1 ≤ n ≤ 100）。第二行输入 n 个整数，表示数组中的值，元素之间用空格分隔（0 ≤ arr[i] ≤ 100）。输出格式：输出 n 个整数，表示排序后的数组，元素之间用空格分隔。在输出中，数字之间用一个空格分隔，最后一个数字后面不需要有空格。

 

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

输入的数值之间用空格分隔，输出时也请遵循相同的格式。

 

Auxiliary Code

#include <stdio.h>

// 快速排序函数
void quickSort(int* arr, int low, int high) {
  // Code here...
}

int main() {
    int n;
    scanf("%d", &n); // 读取数组长度
    int elements[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &elements[i]); // 读取每个元素的值
    }

    quickSort(elements, 0, n - 1); // 调用快速排序函数

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

// 交换两个数
void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

// 分区函数，返回基准位置
int partition(int* arr, int low, int high) {
    int pivot = arr[high];  // 选最右侧作为基准
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

// 快速排序函数
void quickSort(int* arr, int low, int high) {
    if (low < high) {
        int mid = partition(arr, low, high);
        quickSort(arr, low, mid - 1);   // 左区间递归
        quickSort(arr, mid + 1, high);  // 右区间递归
    }
}

int main() {
    int n;
    scanf("%d", &n);
    int elements[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &elements[i]);
    }

    quickSort(elements, 0, n - 1);

    for (int i = 0; i < n; i++) {
        printf("%d", elements[i]);
        if (i < n - 1) {
            printf(" ");
        }
    }
    printf("\n");

    return 0;
}