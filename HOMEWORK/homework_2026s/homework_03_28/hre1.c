/*
1. 循环队列操作
【问题描述】

在顺序队列中，当队尾指针指向数组的最后一个元素时，空间“溢出”，不能继续进队操作，
但是此前有若干元素出队，

一部分空间是“闲置的”，称这种现象为“假溢出”。请编码解决这个问题。
【输入形式】

第一行输入队列元素个数

第二行依次输入要执行入队操作的各个元素值，空格分隔

第三行输入要执行的操作个数

第四行依次输入各个操作码，空格分隔

其中操作码1表示入队，2表示出队，3表示遍历

【输出形式】

输出遍历队列得到的序列（空格分隔）
【样例输入】

5
1 2 3 4 5
4
2 2 1 3
【样例输出】

3 4 5 0
【样例说明】

本题在队列创建完成后默认入队元素为0，因此样例输入中对后续入队操作没有给出入队元素

入队时队满和出队时队空皆返回-1
【辅助代码】

#include <stdio.h>
#define MAXLEN 100
typedef int QElemType;

typedef struct {
    int front;
    int rear;
    int queueSize;
    QElemType data[MAXLEN];
} SqQueue;

// 初始化队列
void initQueue(SqQueue *q) {
    //Code here...
}

// 入队操作
int enqueue(SqQueue *q, QElemType e) {
    //Code here...
}

// 出队操作
int dequeue(SqQueue *q, QElemType *e) {
    //Code here...
}

// 遍历队列
void traverseQueue(SqQueue *q) {
    //Code here...
}

int main() {
    SqQueue q;
    initQueue(&q);
    
    int n, operationCount;
    scanf("%d", &n); // 输入元素个数
    for(int i = 0; i < n; ++i){
        int value;
        scanf("%d", &value);
        enqueue(&q, value);
    }
    
    scanf("%d", &operationCount); // 输入操作个数
    for(int i = 0; i < operationCount; ++i){
        int op;
        scanf("%d", &op);
        if(op == 1){ // 入队
            int value = 0; // 默认值为0
            enqueue(&q, value);
        } else if(op == 2){ // 出队
            int e;
            dequeue(&q, &e);
        } else if(op == 3){ // 遍历
            traverseQueue(&q);
        }
    }

    return 0;
}

*/

#include "stdio.h"
#include "stdlib.h"
#include "string.h"

#define MAXSIZE 100

typedef struct{
    int front;
    int rear;
    int QueueSize;
    int data[MAXSIZE];
}SqQueue,*LinkQueue;

void InitQueue(LinkQueue Q);
int EnQueue(LinkQueue Q,int e);
int DeQueue(LinkQueue Q);
int TraverseQueue(LinkQueue Q);

int main()
{
    SqQueue q;
    InitQueue(&q);
    int num,oprations,t,j=0;
    scanf("%d",&num);
    for(int i=0;i<num;i++){
        scanf("%d",&t);
        EnQueue(&q,t);
    }
    scanf("%d",&oprations);
    for(int i=0;i<oprations;i++){
        int choice;
        scanf("%d",&choice);
        switch(choice){
            case 1:t=0;EnQueue(&q,t);break;
            case 2:DeQueue(&q);break;
            case 3:TraverseQueue(&q);break;
        }
    }
    return 0;
}

void InitQueue(LinkQueue Q){
    Q->rear=Q->front=0;
    Q->QueueSize=MAXSIZE;
}

int EnQueue(LinkQueue Q,int e){
    if(Q->rear+1==Q->QueueSize)return 0;
    Q->data[Q->rear]=e;
    Q->rear=(Q->rear+1)%Q->QueueSize;
    return 1;
}

int DeQueue(LinkQueue Q){
    if(Q->rear==Q->front)return 0;
    Q->front=(Q->front+1)%Q->QueueSize;
    return 1;
}

int TraverseQueue(LinkQueue Q){
    if(Q->rear==Q->front)return 0;
    int t=Q->front;
    while(t<Q->rear){
        printf("%d ",Q->data[t++]);
    }
    printf("\n");
    return 1;
}

