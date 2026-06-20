/*
8. 归并排序
给定一个整数数组 elements，请实现归并排序算法。归并排序是一种有效的排序算法，采用分治法（Divide and Conquer）策略，将数组分为两半，分别排序，然后将两个已排序的部分合并在一起。输入格式：第一行输入一个整数 n，表示数组的长度（1 ≤ n ≤ 100）。第二行输入 n 个整数，表示数组中的值，元素之间用空格分隔（0 ≤ elements[i] ≤ 100）。输出格式：输出排序后的数组 elements，元素之间用空格分隔。

示例 1：

输入：
7
38 27 43 3 9 82 10
输出：
3 9 10 27 38 43 82
示例 2：

输入：
6
5 2 9 1 5 6
输出：
1 2 5 5 6 9
示例 3：

输入：
1
1
输出：
1
提示
数组的长度在范围 [1, 100] 内。

数组中的元素范围在 [0, 100] 内。

输入的数值之间用空格分隔，输出时也请遵循相同的格式。

Auxiliary Code

#include <stdio.h>

// 归并排序函数
void mergeSort(int* arr, int left, int right) {
 // Code here...
}

int main() {
    int n;
    scanf("%d", &n); // 读取数组长度
    int elements[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &elements[i]); // 读取每个元素的值
    }

    mergeSort(elements, 0, n - 1);

    for (int i = 0; i < n; i++) {
        printf("%d", elements[i]); // 输出排序后的数组
        if (i < n - 1) {
            printf(" "); // 在元素之间添加空格
        }
    }
    printf("\n"); // 输出换行

    return 0;
}
*/

#include <stdio.h>
#include <stdlib.h>

// 合并两个有序区间 [left,mid] 和 [mid+1,right]
void merge(int* arr, int left, int mid, int right) {
    int len1 = mid - left + 1;
    int len2 = right - mid;
    int *L = (int*)malloc(sizeof(int) * len1);
    int *R = (int*)malloc(sizeof(int) * len2);

    // 复制左半段
    for (int i = 0; i < len1; i++)
        L[i] = arr[left + i];
    // 复制右半段
    for (int i = 0; i < len2; i++)
        R[i] = arr[mid + 1 + i];

    int i = 0, j = 0, k = left;
    // 双指针合并
    while (i < len1 && j < len2) {
        if (L[i] <= R[j])
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }
    // 剩余元素直接复制
    while (i < len1) arr[k++] = L[i++];
    while (j < len2) arr[k++] = R[j++];

    free(L);
    free(R);
}

// 归并排序递归函数
void mergeSort(int* arr, int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;
        mergeSort(arr, left, mid);    // 左区间递归
        mergeSort(arr, mid + 1, right);// 右区间递归
        merge(arr, left, mid, right); // 合并有序区间
    }
}

int main() {
    int n;
    scanf("%d", &n);
    int elements[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &elements[i]);
    }

    mergeSort(elements, 0, n - 1);

    for (int i = 0; i < n; i++) {
        printf("%d", elements[i]);
        if (i < n - 1)
            printf(" ");
    }
    printf("\n");

    return 0;
}