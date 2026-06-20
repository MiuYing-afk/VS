/*
1. 直接插入排序
给定一个整数数组 elements，请实现直接插入排序算法。直接插入排序是一种简单的排序算法，它的基本思想是将一个待排序的元素插入到已经排好序的部分中，从而得到一个新的、个数增1的有序序列。输入格式：第一行输入一个整数 n，表示数组的长度（n 的范围在 [1, 100]）。第二行输入 n 个整数，元素之间用空格分隔，表示数组中的值（范围在 [0, 100] 内）。输出格式：输出 n 个整数，表示排序后的数组，元素之间用空格分隔。

 

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

// 直接插入排序函数
void insertionSort(int* elements, int size) {
 // Code here...
}

int main() {
    int n;
    scanf("%d", &n); // 读取数组长度
    int elements[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &elements[i]); // 读取每个元素的值
    }

    insertionSort(elements, n); // 调用排序函数

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

#include "stdio.h"
#include "stdlib.h"

void StraightSort(int *)

int main()
{
    int num;
    scanf("%d",&num);
    int *elements=(int*)malloc(sizeof(int)*num);
    for(int i=0;i<num;i++){
        scanf("%d",&elements[i]);
    }

    insertionSort(elements,num);

    for(int i=0;i<num;i++){
        printf("%d",elements[i]);
        if(i<num-1)printf(" ");
    }
    printf("\n");

    return 0;
}

void insertionSort(int *elements,int num){
    for(int i=1;i<num;i++){
        int temp=elements[i];
        int j;
        for(j=i-1;j>=0&&elements[j]>temp;j--){
            elements[j+1]=elements[j];
        }
        elements[j+1]=temp;
    }
}