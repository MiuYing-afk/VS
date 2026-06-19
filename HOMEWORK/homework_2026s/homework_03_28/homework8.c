/*
8. 共用栈
【问题描述】

编写一个程序，实现一个共用栈（Shared Stack），该栈可以同时支持两个栈的操作。
用户可以选择在栈1或栈2中进行添加、删除和打印操作。栈的最大容量为100。

【输入形式】

输入包含多行，第一行为操作指令，后续行为操作的具体内容，直到输入exit结束程序。
操作指令包括：

push1 x：将元素x压入栈1。

push2 x：将元素x压入栈2。

pop1：从栈1弹出元素。

pop2：从栈2弹出元素。

print1：打印栈1的所有元素。

print2：打印栈2的所有元素。

【输出形式】

对于print操作，输出栈中的所有元素。

【样例输入1】

push1 10
push1 20
push2 30
print1
pop1
print1
print2
exit
【样例输出1】

20 10
10
30

【样例输入2】

push2 50
push1 40
pop2
print1
print2
exit
【样例输出2】

40
栈2空
【样例说明】

栈中的元素为整数，范围为0-99。

当栈满时，push操作应提示“栈1满”或“栈2满”。

当栈为空时，pop和print操作应提示“栈1空”或“栈2空”。

请将辅助代码粘贴至作答区域，并实现共用栈的 push、pop和print函数，可根据需要自行添加其它辅助函数。


【辅助代码】

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

// 定义共用栈结构
typedef struct {
    int items[MAX_SIZE];
    int top1; // 栈1的顶部
    int top2; // 栈2的顶部
} SharedStack;

// 初始化共用栈
void initStack(SharedStack *s) {
    s->top1 = -1; // 栈1为空
    s->top2 = MAX_SIZE; // 栈2的底部
}

// 判断栈1是否满
int isFull1(SharedStack *s) {
    return s->top1 + 1 == s->top2;
}

// 判断栈2是否满
int isFull2(SharedStack *s) {
    return s->top2 - 1 == s->top1;
}

// 判断栈1是否空
int isEmpty1(SharedStack *s) {
    return s->top1 == -1;
}

// 判断栈2是否空
int isEmpty2(SharedStack *s) {
    return s->top2 == MAX_SIZE;
}

// 压入栈1
void push1(SharedStack *s, int item) {
    //code here...
}

// 压入栈2
void push2(SharedStack *s, int item) {
    //code here...
}

// 弹出栈1
void pop1(SharedStack *s) {
    //code here...
}

// 弹出栈2
void pop2(SharedStack *s) {
    //code here...
}

// 打印栈1
void print1(SharedStack *s) {
    //code here...
}

// 打印栈2
void print2(SharedStack *s) {
}

int main() {
    SharedStack stack;
    initStack(&stack);
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

#include "stdio.h"
#include "string.h"
#include "stdlib.h"

#define MAXSIZE 100

typedef struct ShStack{
    int data[MAXSIZE];
    int top1;
    int top2;
}ShStack;

void InitShStack(ShStack *S);
void Push1(ShStack *S);
void Pop1(ShStack *S);
int IsEmpty1(ShStack *S);
int IsFull1(ShStack *S);
void Print1(ShStack *S);
void Push2(ShStack *S);
void Pop2(ShStack *S);
int IsEmpty2(ShStack *S);
int IsFull2(ShStack *S);
void Print2(ShStack *S);

int main()
{
    ShStack S;
    InitShStack(&S);
    char command[10];
    while(1){
        int i=1;
        char ch;
        scanf(" %c",&ch);
        command[0]=ch;
        while(ch!=' '&&ch!='\n'){
            scanf("%c",&ch);
            command[i++]=ch;
        }
        command[--i]='\0';
        if(strcmp(command,"exit")==0)break;
        else if(strcmp(command,"pop1")==0)Pop1(&S);
        else if(strcmp(command,"pop2")==0)Pop2(&S);
        else if(strcmp(command,"push1")==0)Push1(&S);
        else if(strcmp(command,"push2")==0)Push2(&S);
        else if(strcmp(command,"print1")==0)Print1(&S);
        else if(strcmp(command,"print2")==0)Print2(&S);
    }

    return 0;
}


void InitShStack(ShStack *S){
    S->top1=-1;
    S->top2=MAXSIZE;
}

void Push1(ShStack *S){
    int t;
    scanf("%d",&t);
    if(!IsFull1(S)){
        S->data[++S->top1]=t;
    }else{
        printf("栈1满\n");
    }
}

void Pop1(ShStack *S){
    if(IsEmpty1(S)){
        printf("栈1空\n");
    }else{
        S->top1--;
    }
}

int IsEmpty1(ShStack *S){
    return S->top1==-1;
}

int IsFull1(ShStack *S){
    return S->top1+1==S->top2;
}

void Print1(ShStack *S){
    if(IsEmpty1(S)){
        printf("栈1空\n");
    }else{
        for(int i=S->top1;i>-1;i--){
            printf("%d ",S->data[i]);
        }
        printf("\n");
    }
}

void Push2(ShStack *S){
    int t;
    scanf("%d",&t);
    if(!IsFull2(S)){
        S->data[--S->top2]=t;
    }else{
        printf("栈2满\n");
    }
}

void Pop2(ShStack *S){
    if(IsEmpty2(S)){
        printf("栈2空\n");
    }else{
        S->top2++;
    }
}

int IsEmpty2(ShStack *S){
    return S->top2==MAXSIZE;
}

int IsFull2(ShStack *S){
    return S->top2-1==S->top1;
}

void Print2(ShStack *S){
    if(IsEmpty2(S)){
        printf("栈2空\n");
    }else{
        for(int i=S->top2;i<MAXSIZE;i++){
            printf("%d ",S->data[i]);
        }
        printf("\n");
    }
}
