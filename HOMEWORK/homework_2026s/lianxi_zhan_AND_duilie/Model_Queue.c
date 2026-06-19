/*循环队列*/

// 队列结构定义
typedef struct {
    int data[MAXSIZE];
    int front, rear;  // 队头、队尾指针
} SqQueue;

// 初始化队列
void InitQueue(SqQueue *q) {
    q->front = q->rear = 0;
}

// 判断队空
int QueueEmpty(SqQueue *q) {
    return q->front == q->rear;
}

// 入队
int EnQueue(SqQueue *q, int x) {
    if ((q->rear+1)%MAXSIZE == q->front) return 0; // 队满
    q->data[q->rear] = x;
    q->rear = (q->rear+1)%MAXSIZE;
    return 1;
}

// 出队
int DeQueue(SqQueue *q, int *x) {
    if (QueueEmpty(q)) return 0; // 队空
    *x = q->data[q->front];
    q->front = (q->front+1)%MAXSIZE;
    return 1;
}