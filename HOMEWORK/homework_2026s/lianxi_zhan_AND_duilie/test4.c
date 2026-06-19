#include "stdio.h"
#include "stdlib.h"

#define MAXSIZE 100

typedef struct Stack{
    char data[MAXSIZE];
    int top;
}SqStack,*LinkStack;

void InitStack(LinkStack S);
int  IsFull(LinkStack S);
int  IsEmpty(LinkStack S);
void Push(LinkStack S,char e);
char Pop(LinkStack S);
void GetTop(LinkStack S,char *e);

int main()
{
    char string1[30];
    scanf("%s",string1);
    SqStack head;
    InitStack(&head);
    for(int i=0;string1[i]!='\0';i++){
        if(string1[i]=='('||string1[i]=='['||string1[i]=='{'){
            Push(&head,string1[i]);
        }else if(string1[i]==')'||string1[i]==']'||string1[i]=='}'){
            if(IsEmpty(&head)){
                printf("括号不匹配\n");
                return 0;
            }
            char x;
            GetTop(&head,&x);
            if((string1[i]==')'&& x=='(')||
               (string1[i]==']'&& x=='[')||
               (string1[i]=='}'&& x=='{')){
                Pop(&head);
            }else{
                printf("括号不匹配\n");
                return 0;
            }
        }
    }
    if(!IsEmpty(&head)){
        printf("括号不匹配\n");
    }else{
        printf("括号匹配\n");
    }

    return 0;
}

void InitStack(LinkStack S){
    S->top=-1;
}

int  IsFull(LinkStack S){
    return S->top==MAXSIZE-1;
}

int  IsEmpty(LinkStack S){
    return S->top==-1;
}

void Push(LinkStack S,char e)
{
    if(IsFull(S)){
        printf("栈已满，无法入栈\n");
        return;
    }
    S->top++;
    S->data[S->top]=e;
}

char Pop(LinkStack S){
    if(IsEmpty(S)){
        printf("栈为空，无法出栈\n");
        return '\0'; // 表示栈为空
    }
    char ch=S->data[S->top];
    S->top--;
    return ch;
}

void GetTop(LinkStack S,char *e){
    if(IsEmpty(S)){
        (*e)='\0';
        return;
    }
    (*e)=S->data[S->top];
}