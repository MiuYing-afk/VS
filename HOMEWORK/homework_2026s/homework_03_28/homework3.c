/*
3. 顺序队列判空题
题目描述
请实现一个顺序队列（基于数组实现）的基本操作，支持以下操作：

入队操作（操作码 1）：将一个整数加入队尾。

出队操作（操作码 2）：将队头的整数出队并输出，如果队列为空则输出 -1。

判空操作（操作码 3）：判断队列是否为空，若为空输出 1，否则输出 0。

初始时队列为空。

输入格式
第一行输入一个整数 m，表示操作的总数（1 ≤ m ≤ 100）。

接下来 m 行，每行输入一个操作：

操作码为 1 时，后面紧跟一个整数 x 表示入队的数值；

操作码为 2 时表示出队操作；

操作码为 3 时表示判空操作。

输出格式
对于每个出队操作（操作码 2），输出出队的整数（若队列为空输出 -1）；
对于每个判空操作（操作码 3），输出 1（队列为空）或 0（队列不为空）。

测试样例
样例 1
输入：

5
3
1 100
3
2
3
输出：

1
0
100
1
样例 2
输入：

4
1 10
1 20
3
2
输出：

0
10







 

Auxiliary Code

#include <stdio.h>
#define MAX_SIZE 100

typedef struct {
    int data[MAX_SIZE];
    int front;
    int rear;
} SeqQueue;

// 初始化队列
void initQueue(SeqQueue *q) {
    q->front = 0;
    q->rear = 0;
}

// 入队操作（将 x 插入队尾）
void enqueue(SeqQueue *q, int x) {
    // code here...
}

// 出队操作（移除队头元素），若队列为空则返回 -1
int dequeue(SeqQueue *q) {
    // code here...
}

// 判空操作，若队列为空返回 1，否则返回 0
int isEmpty(SeqQueue *q) {
    // code here...
}

int main() {
    int m;
    scanf("%d", &m);
    SeqQueue q;
    initQueue(&q);
    int op, x;
    for (int i = 0; i < m; i++) {
        scanf("%d", &op);
        if(op == 1) {
            scanf("%d", &x);
            enqueue(&q, x);
        } else if(op == 2) {
            printf("%d\n", dequeue(&q));
        } else if(op == 3) {
            printf("%d\n", isEmpty(&q));
        }
    }
    return 0;
}
*/

#include "stdio.h"
#define MAXSIZE 100

typedef int SqElemType;

typedef struct{
    SqElemType data[MAXSIZE];
    int rear;
    int front;
    int queuesize;
}SqQueue;

void InitQueue(SqQueue *S);
void EnQueue(SqQueue *S);
void DeQueue(SqQueue *S);
int  isEmpty(SqQueue *S);

int main()
{
    SqQueue q;
    int operationCount;
    scanf("%d",&operationCount);
    InitQueue(&q);
    for(int i=0;i<operationCount;i++){
        int op;
        scanf("%d",&op);
        if(op==1)EnQueue(&q);
        else if(op==2)DeQueue(&q);
        else if(op==3)printf("%d\n",isEmpty(&q));
    }

    return 0;
}

void InitQueue(SqQueue *S){
    S->front=S->rear=0;
    S->queuesize=MAXSIZE;
}

void EnQueue(SqQueue *S){
    int e;
    scanf("%d",&e);
    S->data[S->rear++]=e;
}

void DeQueue(SqQueue *S){
    if(isEmpty(S))printf("-1\n");
    else printf("%d\n",S->data[S->front++]);
}

int  isEmpty(SqQueue *S){
    if(S->front==S->rear)return 1;
    else return 0;
}
