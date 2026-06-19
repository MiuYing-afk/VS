/*
2. 实现一个顺序栈
【问题述描】

请你实现一个顺序栈，并支持以下三种操作：

1. 出栈（pop）：移除栈顶元素，如果栈为空，则输出 "empty"

2. 取栈顶元素（top）：获取当前栈顶元素，如果栈为空，则输出 "empty"

3. 求栈长（size）：返回当前栈的元素个数

【输入形式】

第一行输入一个整数 n (1 ≤ n ≤ 100)，表示接下来的操作次数。

接下来的 n 行，每行输入一个操作，格式如下：

"pop"：执行出栈操作。

"top"：获取当前栈顶元素。

"size"：获取当前栈的元素个数。

"push x"：将整数 x 入栈。

【输出形式】

对 "pop" 操作，如果栈不为空，不输出内容，否则输出 "empty"。

对 "top" 操作，如果栈不为空，输出栈顶元素，否则输出 "empty"。

对 "size" 操作，输出当前栈的元素个数。

【样例输入1】


5
push 1
push 2
top
pop
size


【样例输出1】



2
1



【样例输入2】


6
push 10
push 20
size
pop
top
size


【样例输出2】


2
10
1


【辅助代码】



#include <stdio.h>
#include <string.h>
#define MAXSIZE 100
typedef int SElemType;

//定义顺序栈结构体
typedef struct stack{
    SElemType data[MAXSIZE];   //SElemType是数据元素类型，data是一维数组
    int top;    //表示栈顶的位置
    int stackSize;    //栈的容量
}SqStack;

//初始化栈
void initSqStack(SqStack *S){
    S->top = -1;
    S->stackSize = MAXSIZE;
}

//判断栈是否为空
int EmptySqStack(SqStack *S){
    return S->top == -1;
}

//判断栈是否已满
int FullSqStack(SqStack *S){
    return S->top == S->stackSize - 1;
}

//取栈顶
void GetTopSqStack(SqStack *S){
    //code here...
}

//求顺序栈的长度
void LengthSqStack(SqStack *S){
    //code here...
}

//进栈
void PushSqStack(SqStack *S, int e){
    if(FullSqStack(S)){
        printf("栈已满，无法入栈\n");  //栈满
    }else{
        S->data[++S->top] = e;
    }
}

//出栈
int PopSqStack(SqStack *S){
    //code here...
}

int main(){
    //code here...
    return 0;
}




*/

#include "stdio.h"
#include "stdlib.h"
#include "string.h"

#define MAXSIZE 100 
typedef int SElemType;

typedef struct stack{
    SElemType data[MAXSIZE];
    int top;
    int stacksize;
}SqStack;

void InitSqStack(SqStack* S);
int  EmptySqStack(SqStack *S);
int  FullSqStack(SqStack *S);
void GetTopSqStack(SqStack *S);
void LengthSqStack(SqStack *S);
void PushSqStack(SqStack *S, int e);
int PopSqStack(SqStack *S);

int main()
{
    SqStack S;
    int operationCount;
    InitSqStack(&S);
    scanf("%d",&operationCount);
    char choice[5];
    int e;
    for(int i=0;i<operationCount;i++){
        scanf("%s",choice);
        if(strcmp(choice,"push")==0){
            scanf("%d",&e);
            PushSqStack(&S,e);
        }else if(strcmp(choice,"pop")==0){
            PopSqStack(&S);
        }else if(strcmp(choice,"top")==0){
            GetTopSqStack(&S);
        }else if(strcmp(choice,"size")==0){
            LengthSqStack(&S);
        }
    }
    
    return 0;
}

void InitSqStack(SqStack* S){
    S->top=-1;
    S->stacksize=MAXSIZE;
}

int  EmptySqStack(SqStack *S){
    return S->top==-1;
}

int  FullSqStack(SqStack *S){
    return S->top==S->stacksize-1;
}

void GetTopSqStack(SqStack *S){
    if(EmptySqStack(S)){
        printf("empty\n");
    }else{
    printf("%d\n",S->data[S->top]);
    }
}

void LengthSqStack(SqStack *S){
    printf("%d\n",S->top+1);
}

void PushSqStack(SqStack *S, int e){
    if(FullSqStack(S)){
        printf("栈已满，无法入栈\n");
    }else{
        S->data[++S->top]=e;
    }
}

int PopSqStack(SqStack *S){
    if(EmptySqStack(S)){
        printf("empty\n");
        return -1;
    }else{
        return S->data[S->top--];
    }
}

