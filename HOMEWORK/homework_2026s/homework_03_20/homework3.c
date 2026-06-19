/*
3. 将顺序表B合并到顺序表A中并保持A有序
【问题描述】

给定两个顺序表 A 和 B，其中 A 的长度大于等于 B 的长度，将 B 合并到 A 中并保持 A 有序（假设 A 和 B 中的元素均已按升序排列）。

【输入形式】

分别输入两个有序顺序表。在输入时首先第一行输入顺序表长度，第二行输入有序顺序表的元素值，分别输入顺序表A和B。
【输出形式】

输出合并后的有序顺序表A
【样例输入】

5

1 3 5 7 9

3

2 4 6

【样例输出】

1 2 3 4 5 6 7 9



Auxiliary Code

#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 100 // 定义顺序表的最大长度
// 定义顺序表结构体
typedef struct {
    int data[MAXSIZE];
    int length;
} SqList;

// 初始化顺序表
void InitList(SqList *L) {
    L->length = 0;
}

// 创建顺序表
void CreateList(SqList *L, int n) {

    for (int i = 0; i < n; i++) {
        scanf("%d", &L->data[i]);
        L->length++;
    }
}


// 合并两个有序顺序表 A 和 B 到 A 中
void mergeSeqLists(SqList* A, SqList* B) {
    //Code Here...
}

// 输出顺序表
void PrintList(SqList L) {

    for (int i = 0; i < L.length; i++) {
        printf("%d ", L.data[i]);
    }
}

int main() {
    SqList A,B;
    InitList(&A);
    InitList(&B);
    int n1;
    scanf("%d", &n1);
    CreateList(&A, n1);
    int n2;
    scanf("%d", &n2);
    CreateList(&B, n2);
    mergeSeqLists(&A,&B);
    PrintList(A); 
    return 0;
}

*/

#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 100 // 定义顺序表的最大长度
// 定义顺序表结构体
typedef struct {
    int data[MAXSIZE];
    int length;
} SqList;

// 初始化顺序表
void InitList(SqList *L) {
    L->length = 0;
}

// 创建顺序表
void CreateList(SqList *L, int n) {

    for (int i = 0; i < n; i++) {
        scanf("%d", &L->data[i]);
        L->length++;
    }
}


// 合并两个有序顺序表 A 和 B 到 A 中
void mergeSeqLists(SqList* A, SqList* B) {
    //Code Here...
    int i=A->length-1,j=B->length-1,
        k=A->length+B->length-1;
    while(i>=0 && j>=0){
        if(A->data[i]>B->data[j]){
            A->data[k--] = A->data[i--];
        }else{
            A->data[k--] = B->data[j--];
        }
    }
    while(j>=0){
        A->data[k--] = B->data[j--];
    }
    A->length += B->length;
}

// 输出顺序表
void PrintList(SqList L) {

    for (int i = 0; i < L.length; i++) {
        printf("%d ", L.data[i]);
    }
}

int main() {
    SqList A,B;
    InitList(&A);
    InitList(&B);
    int n1;
    scanf("%d", &n1);
    CreateList(&A, n1);
    int n2;
    scanf("%d", &n2);
    CreateList(&B, n2);
    mergeSeqLists(&A,&B);
    PrintList(A); 
    return 0;
}
