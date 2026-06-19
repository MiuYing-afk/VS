/*
4. 双端队列
【问题描述】

编写一个程序，实现一个双端队列（Deque），该队列支持在两端进行插入和删除操作。
用户可以通过输入命令来操作队列，程序会根据输入的命令执行相应的操作并输出结果。

【输入形式】


程序支持以下操作：

insert_front x：在队列前端插入元素x。

insert_rear x：在队列后端插入元素x。

delete_front：从队列前端删除元素。

delete_rear：从队列后端删除元素。

print：打印队列中的所有元素。

exit：退出程序。



【输出形式】

对于print操作，输出双端队列中的所有元素。

【样例输入1】

insert_front 10
insert_rear 20
insert_front 5
print
delete_front
print
delete_rear
print
delete_rear
print
exit
【样例输出1】

5 10 20
10 20
10
队列已空

【样例输入2】

insert_front 1
insert_rear 2
insert_front 3
print
delete_rear
print
insert_front 4
insert_rear 5
print
exit
【样例输出2】

3 1 2
3 1
4 3 1 5

【样例说明】

队列中的元素为整数，范围为0-99。

当队列满时，insert操作应提示“队列已满”。

当队列为空时，delete和print操作应提示“队列已空”。

请将辅助代码粘贴至作答区域，并实现双端队列的 insert、delete和print函数，
可根据需要自行添加其它辅助函数。


【辅助代码】

#include <stdio.h>
#include <stdlib.h>

#define MAXNUM 100

typedef int DElemType;

typedef struct {
    DElemType data[MAXNUM];
    int front; // 队列前端指针
    int rear;  // 队列后端指针
} Deque;

// 初始化双端队列
void InitDeque(Deque *D) {
    D->front = -1; // 队列前端指针
    D->rear = -1;  // 队列后端指针
}

// 判断队列是否为空
int IsEmpty(Deque *D) {
    return (D->front == -1 && D->rear == -1);
}

// 判断队列是否满
int IsFull(Deque *D) {
    return (D->rear + 1) % MAXNUM == D->front;
}

// 在队列前端插入元素
int InsertFront(Deque *D, DElemType x) {
    //code here...
}

// 在队列后端插入元素
int InsertRear(Deque *D, DElemType x) {
    //code here...
}

// 从队列前端删除元素
int DeleteFront(Deque *D, DElemType *x) {
    //code here...
}

// 从队列后端删除元素
int DeleteRear(Deque *D, DElemType *x) {
    //code here...
}

// 打印队列内容
void PrintDeque(Deque *D) {
    //code here...
}

int main() {
    Deque D;
    InitDeque(&D);
    char command[20];

    while (1) {

        if (strcmp(command, "exit") == 0) {
            break;
        }
        //code here...
    }

    return 0;
}





*/

/*  此代码依旧有疑惑    */
/*
    初始化为什么设为0
    插入和删除的逻辑不太清晰
    打印的逻辑不太清晰
*/

#include "stdio.h"
#include "stdlib.h"
#include "string.h"

#define MAXSIZE 100

typedef struct Deque{
    int data[MAXSIZE];
    int size;
    int front;
    int rear;
}Deque,*LinkQue;

void InitDeque(LinkQue Q);
int isEmpty(LinkQue Q);
int isFull(LinkQue Q);
void InsertFront(LinkQue Q);
void InsertRear(LinkQue Q);
void DeleteFront(LinkQue Q);
void DeleteRear(LinkQue Q);
void PrintQue(LinkQue Q);

int main()
{
    Deque head;
    LinkQue H=&head;
    InitDeque(H);
    char choice[13];
    while(1){
        scanf("%s",&choice);
        if(strcmp(choice,"exit")==0){
            break;
        }
        else if(strcmp(choice,"insert_front")==0){
            InsertFront(H);
        }
        else if(strcmp(choice,"insert_rear")==0){
            InsertRear(H);
        }
        else if(strcmp(choice,"delete_front")==0){
            DeleteFront(H);
        }
        else if(strcmp(choice,"delete_rear")==0){
            DeleteRear(H);
        }
        else if(strcmp(choice,"print")==0){
            PrintQue(H);
        }
         else{
            printf("无效的命令\n");
        }
    }
    return 0;
}

void InitDeque(LinkQue Q){
    Q->front=0;
    Q->rear=0;
    Q->size=0;
}

int isEmpty(LinkQue Q){
    return Q->size==0;
}

int isFull(LinkQue Q){
    return Q->size==MAXSIZE;
}

void InsertFront(LinkQue Q){
    int e;
    scanf("%d",&e);
    if(isFull(Q)){
        printf("队列已满\n");
        return;
    }
    Q->rear=(Q->rear-1+MAXSIZE)%MAXSIZE;
    Q->data[Q->rear]=e;
    Q->size++;
}

void InsertRear(LinkQue Q){
    int e;
    scanf("%d",&e);
    if(isFull(Q)){
        printf("队列已满\n");
        return;
    }
    Q->data[Q->front]=e;
    Q->front=(Q->front+1)%MAXSIZE;
    Q->size++;
}

void DeleteFront(LinkQue Q){
    if(isEmpty(Q)){
        printf("队列已空\n");
        return;
    }
    Q->rear=(Q->rear+1)%MAXSIZE;
    Q->size--;
}

void DeleteRear(LinkQue Q){
    if(isEmpty(Q)){
        printf("队列已空\n");
        return;
    }
    Q->front=(Q->front-1+MAXSIZE)%MAXSIZE;
    Q->size--;
}

void PrintQue(LinkQue Q){
    if(isEmpty(Q)){
        printf("队列已空\n");
        return;
    }
    int i=Q->rear;
    while(i!=Q->front){
        printf("%d ",Q->data[i]);
        i=(i+1)%MAXSIZE;
    }
    printf("\n");
}
