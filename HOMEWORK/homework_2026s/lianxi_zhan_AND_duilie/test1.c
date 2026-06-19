#include "stdio.h"
#include "stdlib.h"
#include "string.h"

#define MAXSIZE 100

typedef struct StackNote{
    int data[MAXSIZE];
    int top;
}SNote,*LinkStack;

void InitStack(LinkStack S);
int IsEmpty(LinkStack S);
int IsFull(LinkStack S);
int Push(LinkStack S,int e);
int Pop(LinkStack S,int *e);
void Print(LinkStack S);

int main()
{

    SNote head;
    InitStack(&head);
    while(1){
        int e;
        scanf("%d",&e);
        if(e==-1)break;
        Push(&head,e);
    }
    Print(&head);

    return 0;
}

void InitStack(LinkStack S){
    S->top=-1;
}

int IsEmpty(LinkStack S){
    return S->top==-1;
}

int IsFull(LinkStack S){
    return S->top==MAXSIZE-1;
}

int Push(LinkStack S,int e){
    if(IsFull(S))return 0;
    S->data[++S->top]=e;
    return 1;
}

int Pop(LinkStack S,int *e){
    if(IsEmpty(S))return 0;
    *e=S->data[S->top--];
    return 1;
}

void Print(LinkStack S){
    if(IsEmpty(S))return;
    for(int i=S->top;i>=0;i--){
        printf("%d ",S->data[i]);
    }
    printf("\n");
}