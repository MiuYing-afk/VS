/*
2. 归并排序与逆序对计数
给定一个整数数组 arr，请实现归并排序算法，并在排序的同时计算数组中的逆序对数量。逆序对是指一对索引 (i, j)，使得 i < j 且 arr[i] > arr[j]。输入格式：第一行输入一个整数 n，表示数组的长度（1 ≤ n ≤ 100）。第二行输入 n 个整数，表示数组中的值，元素之间用空格分隔（0 ≤ arr[i] ≤ 100）。输出格式：第一行输出排序后的数组 arr，元素之间用空格分隔。第二行输出逆序对的数量。

示例 1：

输入：
4
7 5 6 4
输出：
4 5 6 7
5
示例 2：

输入：
5
1 3 2 3 1
输出：
1 1 2 3 3
4
示例 3：

输入：
1
1
输出：
1
0
提示
数组的长度在范围 [1, 100] 内。

数组中的元素范围在 [0, 100] 内。

输入的数值之间用空格分隔，输出时也请遵循相同的格式。

Auxiliary Code

#include <stdio.h>

// 归并排序并计算逆序对数目
int mergeSortAndCount(int* arr, int left, int right) {
  // Code here...
}

int main() {
    int n;
    scanf("%d", &n); // 输入数组大小
    int arr[n]; // 数组命名为 arr
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]); // 输入数组元素
    }

    int inversions = mergeSortAndCount(arr, 0, n - 1); // 归并排序并计算逆序对数目

    for (int i = 0; i < n; i++) {
        printf("%d", arr[i]); // 输出排序后的数组
        if (i < n - 1) {
            printf(" "); // 在元素之间添加空格
        }
    }
    printf("\n%d\n", inversions); // 输出逆序对数量

    return 0;
}



*/

#include <stdio.h>
#include <stdlib.h>

// 合并区间并返回当前区间产生的逆序对数量
int merge(int* arr, int left, int mid, int right) {
    int cnt = 0;
    int len1 = mid - left + 1;
    int len2 = right - mid;
    int* L = (int*)malloc(sizeof(int) * len1);
    int* R = (int*)malloc(sizeof(int) * len2);

    for (int i = 0; i < len1; i++)
        L[i] = arr[left + i];
    for (int i = 0; i < len2; i++)
        R[i] = arr[mid + 1 + i];

    int i = 0, j = 0, k = left;
    while (i < len1 && j < len2) {
        if (L[i] <= R[j]) {
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
            // L[i]到末尾全部大于R[j]，产生 len1 - i 个逆序对
            cnt += len1 - i;
        }
    }
    while (i < len1) arr[k++] = L[i++];
    while (j < len2) arr[k++] = R[j++];

    free(L);
    free(R);
    return cnt;
}

// 归并排序并统计总逆序对
int mergeSortAndCount(int* arr, int left, int right) {
    int total = 0;
    if (left < right) {
        int mid = (left + right) / 2;
        total += mergeSortAndCount(arr, left, mid);
        total += mergeSortAndCount(arr, mid + 1, right);
        total += merge(arr, left, mid, right);
    }
    return total;
}

int main() {
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int inversions = mergeSortAndCount(arr, 0, n - 1);

    for (int i = 0; i < n; i++) {
        printf("%d", arr[i]);
        if (i < n - 1)
            printf(" ");
    }
    printf("\n%d\n", inversions);

    return 0;
}