/*
1. 循环队列操作
【问题描述】

在顺序队列中，当队尾指针指向数组的最后一个元素时，空间“溢出”，不能继续进队操作，但是此前有若干元素出队，

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
    (*q).front=(*q).rear=0;
    (*q).queueSize=MAXLEN;
}

// 入队操作
int enqueue(SqQueue *q, QElemType e) {
    //Code here...
    (*q).data[(*q).rear]=e;
    (*q).rear++;
}

// 出队操作
int dequeue(SqQueue *q, QElemType *e) {
    //Code here...
    if((*q).front==(*q).rear)return -1;
    *e=(*q).data[(*q).front];
    (*q).front++;
}

// 遍历队列
void traverseQueue(SqQueue *q) {
    //Code here...
    int t=(*q).front;
    while(t!=(*q).rear){
        printf("%d ",(*q).data[t++]);
    }
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