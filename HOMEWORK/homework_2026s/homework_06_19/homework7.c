/*
7. 堆排序
给定一个整数数组 elements，请实现堆排序算法。堆排序是一种基于比较的排序算法，利用堆这种数据结构，首先将待排序的数组构建成一个最大堆，然后通过不断地将最大元素放到数组的末尾，实现排序。输入格式：第一行输入一个整数 n，表示数组的长度（1 ≤ n ≤ 100）。第二行输入 n 个整数，表示数组中的值，元素之间用空格分隔（0 ≤ elements[i] ≤ 100）输出格式：输出排序后的数组 elements，元素之间用空格分隔。

示例 1：

输入：
5
3 5 1 10 2
输出：
1 2 3 5 10
示例 2：

输入：
6
6 4 5 2 3 1
输出：
1 2 3 4 5 6
示例 3：

输入：
5
10 9 8 7 6
输出：
6 7 8 9 10
示例 4：

输入：
1
1
输出：
1
示例 5：

输入：
5
5 3 8 4 2
输出：
2 3 4 5 8
提示
数组的长度在范围 [1, 100] 内。

数组中的元素范围在 [0, 100] 内。

输入的数值之间用空格分隔，输出时也请遵循相同的格式。



 

Auxiliary Code

#include <stdio.h>

// 交换两个元素的辅助函数
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// 堆化函数
void heapify(int* elements, int n, int i) {
 // Code here...
}

// 堆排序函数
void heapSort(int* elements, int n) {
 // Code here...
}

int main() {
    int n;
    scanf("%d", &n); // 读取数组长度
    int elements[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &elements[i]); // 读取每个元素的值
    }

    heapSort(elements, n);

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

// 交换两个元素的辅助函数
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// 堆化函数：构建以i为根的大顶堆，n为堆的有效长度
void heapify(int* elements, int n, int i) {
    int largest = i;       // 根节点下标
    int left = 2 * i + 1;  // 左孩子
    int right = 2 * i + 2; // 右孩子

    // 左孩子更大
    if (left < n && elements[left] > elements[largest])
        largest = left;
    // 右孩子更大
    if (right < n && elements[right] > elements[largest])
        largest = right;

    // 最大值不是根节点，交换并递归堆化受影响的子树
    if (largest != i) {
        swap(&elements[i], &elements[largest]);
        heapify(elements, n, largest);
    }
}

// 堆排序函数
void heapSort(int* elements, int n) {
    // 1. 构建大顶堆：从最后一个非叶子节点倒着堆化
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(elements, n, i);

    // 2. 逐步取出堆顶最大值放到数组末尾，缩小堆范围再堆化
    for (int i = n - 1; i > 0; i--) {
        swap(&elements[0], &elements[i]);
        heapify(elements, i, 0);
    }
}

int main() {
    int n;
    scanf("%d", &n); // 读取数组长度
    int elements[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &elements[i]); // 读取每个元素的值
    }

    heapSort(elements, n);

    for (int i = 0; i < n; i++) {
        printf("%d", elements[i]); // 输出排序后的数组
        if (i < n - 1) {
            printf(" "); // 在元素之间添加空格
        }
    }
    printf("\n"); // 输出换行

    return 0;
}