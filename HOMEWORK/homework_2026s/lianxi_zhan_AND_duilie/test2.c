#include "stdio.h"
#include "stdlib.h"

#define MAXSIZE 100

typedef struct Queue{
    int data[MAXSIZE];
    int rear;
    int front;
    int size;
}SqQue,*LinkQue;

void InitQueue(LinkQue Q);
int  IsEmpty(LinkQue Q);
int  IsFull(LinkQue Q);
void InsertQue(LinkQue Q);
void DeleteQue(LinkQue Q);
void PrintQue(LinkQue Q);

int main()
{
    SqQue head;
    InitQueue(&head);
    while(1){
        printf("1.入队 2.出队 3.打印队列 4.退出\n");
        int choice;
        scanf("%d",&choice);
        switch(choice){
            case 1: InsertQue(&head); break;
            case 2: DeleteQue(&head); break;
            case 3: PrintQue(&head); break;
            case 4: exit(0);
            default: printf("无效输入，请重新选择\n");
        }
    }

    return 0;
}

void InitQueue(LinkQue Q){
    Q->rear=0;
    Q->front=0;
    Q->size=0;
}

int  IsEmpty(LinkQue Q){
    return Q->size==0;
}

int  IsFull(LinkQue Q){
    return Q->size==MAXSIZE;
}

void InsertQue(LinkQue Q){
    int e;
    scanf("%d",&e);
    if(IsFull(Q)||e==-1)return;
    Q->data[Q->rear]=e;
    Q->rear=(Q->rear+1)%MAXSIZE;
    Q->size++;
}

void DeleteQue(LinkQue Q){
    if(IsEmpty(Q))return;
    Q->front=(Q->front+1)%MAXSIZE;
    Q->size--;
}

void PrintQue(LinkQue Q){
    if(IsEmpty(Q))return;
    for(int i=Q->front;i!=Q->rear;i=(i+1)%MAXSIZE){
        printf("%d ",Q->data[i]);
    }
    printf("\n");
}
