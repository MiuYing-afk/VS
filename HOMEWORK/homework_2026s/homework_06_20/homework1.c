/*
1. 判断小根堆
给定一个整数数组 elements，请设计一个算法判断该数组是否构成一个小根堆。小根堆是完全二叉树的一种实现，满足每个节点的值都小于等于其子节点的值。输入格式：第一行输入一个整数 n，表示数组的长度（1 ≤ n ≤ 100）。第二行输入 n 个整数，表示数组中的值，元素之间用空格分隔（0 ≤ elements[i] ≤ 100）。输出格式：输出一个布尔值 true 或 false，表示数组是否构成小根堆。

示例 1：

输入：
6
1 3 2 7 6 4
输出：
true
示例 2：

输入：
6
10 15 20 30 40 50
输出：
true
示例 3：

输入：
1
1
输出：
true
提示
数组的长度在范围 [1, 100] 内。

数组中的元素范围在 [0, 100] 内。

输入的数值之间用空格分隔，输出时也请遵循相同的格式。



 

Auxiliary Code

#include <stdio.h>
#include <stdbool.h>

// 判断数组是否构成小根堆的函数
bool isMinHeap(int* elements, int n) {
     // Code here...
}

int main() {
    int n;
    scanf("%d", &n); // 读取数组长度
    int elements[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &elements[i]); // 读取每个元素的值
    }

    if (isMinHeap(elements, n)) {
        printf("true\n"); // 输出 true
    } else {
        printf("false\n"); // 输出 false
    }

    return 0;
}
*/

#include <stdio.h>
#include <stdbool.h>

// 判断数组是否构成小根堆的函数
bool isMinHeap(int* elements, int n) {
    // 只需要遍历所有非叶子节点
    int lastNonLeaf = n / 2 - 1;
    for (int i = 0; i <= lastNonLeaf; i++) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        // 左孩子存在，父节点大于左孩子则不满足小根堆
        if (elements[i] > elements[left]) {
            return false;
        }
        // 右孩子存在，父节点大于右孩子则不满足小根堆
        if (right < n && elements[i] > elements[right]) {
            return false;
        }
    }
    return true;
}

int main() {
    int n;
    scanf("%d", &n); // 读取数组长度
    int elements[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &elements[i]); // 读取每个元素的值
    }

    if (isMinHeap(elements, n)) {
        printf("true\n"); // 输出 true
    } else {
        printf("false\n"); // 输出 false
    }

    return 0;
}