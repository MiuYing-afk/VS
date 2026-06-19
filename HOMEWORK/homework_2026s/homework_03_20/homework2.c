/*
2. 修改顺序表中指定位置的元素
【问题描述】

修改顺序表中指定位置的元素，并输出修改后的顺序表。若修改失败则终止本次修改，返回原顺序表。

【输入形式】

第一行输入线性表长度；

第二行输入线性表元素值;

第三行输入修改位置和元素值。

【输出形式】

输出修改后的顺序表。
【样例输入1】

4

1 2 3 4

3 6
【样例输出1】

1 2 6 4

【样例输入2】

1

1

1 3
【样例输出2】

3



注：1、输入的线性表长度需大于0，若输入长度不合理则返回-1；




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
// 修改顺序表中指定位置的元素
void ModifyElem(SqList *L, int pos, int newVal) {
    //Code Here...
}
// 输出顺序表
void PrintList(SqList L) {
    for (int i = 0; i < L.length; i++) {
        printf("%d ", L.data[i]);
    }
}

int main() {
    SqList L;
    InitList(&L);
    int n;
    scanf("%d", &n);
    if(n<1){
        printf("-1");
        return 0;
    }
    CreateList(&L, n);
    int pos,num;
    scanf("%d %d",&pos, &num);
    ModifyElem(&L,pos,num);
    PrintList(L); 
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
// 修改顺序表中指定位置的元素
void ModifyElem(SqList *L, int pos, int newVal) {
    //Code Here...
    if(pos<1 || pos>L->length){
        return;
    }
    L->data[pos-1] = newVal;
}
// 输出顺序表
void PrintList(SqList L) {
    for (int i = 0; i < L.length; i++) {
        printf("%d ", L.data[i]);
    }
}

int main() {
    SqList L;
    InitList(&L);
    int n;
    scanf("%d", &n);
    if(n<1){
        printf("-1");
        return 0;
    }
    CreateList(&L, n);
    int pos,num;
    scanf("%d %d",&pos, &num);
    ModifyElem(&L,pos,num);
    PrintList(L); 
    return 0;
}
