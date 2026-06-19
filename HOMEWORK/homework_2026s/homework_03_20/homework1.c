/*
1. 顺序表删除最小元素值
【问题描述】

从顺序表中删除具有最小值的元素并由函数返回删除元素后的顺序表。
（假设顺序表中的数据元素全为正值且最小值唯一）。

【输入形式】

第一行输入线性表长度；

第二行输入线性表元素值。

【输出形式】

输出删除后的顺序表。
【样例输入1】

3

1 2 3
【样例输出1】

2 3

【样例输入2】

1

1
【样例输出2】





注：1、输入的线性表长度需大于0，若输入长度不合理则返回-1；

2、在输入线性表元素时请输入不重复的正数；



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
//删除唯一的最小元素值 
int Delete_Min(SqList *L){
    //Code Here...
}
// 输出顺序表
void PrintList(SqList L) {
    for (int i = 0; i < L.length; i++) {
        printf("%d ", L.data[i]);
    }
}

int main(void) {
    SqList L;
    InitList(&L);
    int n;
    scanf("%d", &n);
    CreateList(&L, n);
    int res=Delete_Min(&L);
    if(res==-1){
        printf("-1");
    }else{
        PrintList(L); 
    }

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
//删除唯一的最小元素值 
int Delete_Min(SqList *L){
    //Code Here...
    if(L->length <= 0) {
        return -1;
    }
    int min;
    min=L->data[0];
    for(int i=1;i<L->length;i++){
        if(L->data[i]<min){
            min=L->data[i];
        }
    }
    for(int i=0;i<L->length;i++){
        if(L->data[i]==min){
            for(int j=i;j<L->length-1;j++){
                L->data[j]=L->data[j+1];
            }
            L->length--;
            break;
        }
    }
    return 0;
}
// 输出顺序表
void PrintList(SqList L) {
    for (int i = 0; i < L.length; i++) {
        printf("%d ", L.data[i]);
    }
}

int main(void) {
    SqList L;
    InitList(&L);
    int n;
    scanf("%d", &n);
    CreateList(&L, n);
    int res=Delete_Min(&L);
    if(res==-1){
        printf("-1");
    }else{
        PrintList(L); 
    }
}