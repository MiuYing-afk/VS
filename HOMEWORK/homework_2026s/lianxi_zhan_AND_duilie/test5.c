/*进制转换*/

#include "stdio.h"
#include "stdlib.h"
#include "string.h"

#define MAXSIZE 100

typedef struct{
    int data[30];
    int top;
}Stack,*LinkStack;

long long Trans(long long num1,int n1,int n2);
void InitStack(LinkStack S);
void Push(LinkStack S,int n);
int  Pop(LinkStack S);
int  IsEmpty(LinkStack S);
int  IsFull(LinkStack S);
int Length(long long num);

int main()
{
    long long num1,num2;
    int n1,n2;
    printf("输入原本的数字\n");
    scanf("%lld",&num1);
    printf("输入它的进制(2~10进制)\n");
    scanf("%d",&n1);
    printf("输入你想要转换的进制(2~10进制)\n");
    scanf("%d",&n2);
    num2=Trans(num1,n1,n2);
    printf("转换成%d进制的数为%lld",n2,num2);
    
    return 0;
}

int Length(long long num){
    if(num==0)return 1;
    int t=num,len=0;
    while(t){
        t%=10;
        len++;
    }
    return len;
}

long long Trans(long long num1,int n1,int n2){
    long long times=1,num_in_10=0,temp=num1;
    while(temp){
        num_in_10+=temp%10*times;
        temp/=10;
        times*=n1;
    }
    Stack Temp;
    InitStack(&Temp);
    while(num_in_10){
        int temp2;
        temp2=num_in_10%n2;
        Push(&Temp,temp2);
        num_in_10/=n2;
    }
    num_in_10=0;
    while(!IsEmpty(&Temp)){
        int temp2=Pop(&Temp);
        num_in_10=num_in_10*10+temp2;
    }
    return num_in_10;
}


int  IsEmpty(LinkStack S){
    return S->top==-1;
}

int  IsFull(LinkStack S){
    return S->top==MAXSIZE-1;
}

void InitStack(LinkStack S){
    S->top=-1;
}

void Push(LinkStack S,int n){
    if(IsFull(S))return;
    S->top++;
    S->data[S->top]=n;
}

int  Pop(LinkStack S){
    int t=S->data[S->top--];
    return t;
}
