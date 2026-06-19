/*
5. 括号匹配
【问题描述】

输入一个包含括号的四则运算表达式，表达式中允许出现以下内容：

'a'~'z'运算数

'+'、'-'、'*'、'/'四种运算符

'()'、'[]'、'{}'三种括号

判断输入的表达式中括号是否匹配。

【输入形式】

输入一个包含括号的表达式字符串
【输出形式】

输出 "括号匹配" 或 "括号不匹配"

【样例输入1】

a+b*(c/{d-e})[f*g]
【样例输出1】

括号匹配

【样例输入2】

a+(b*[c/d))
【样例输出2】

括号不匹配
【样例说明】

1、本题允许小括号套在大括号外面，只需判断括号是否成对匹配即可。

2、请将辅助代码粘贴至作答区域，并实现 matching 函数，可根据需要自行添加其它辅助函数。
【辅助代码】

#include <stdio.h>
#include <stdbool.h>
 
// 栈的最大容量
#define MAX_SIZE 100
 
// 定义栈结构
struct Stack {
    int top;
    char items[MAX_SIZE];
};
 
// 初始化栈
void initialize(struct Stack *stack) {
    stack->top = -1;
}
 
// 检查栈是否为空
bool isEmpty(struct Stack *stack) {
    return stack->top == -1;
}
 
// 检查栈是否已满
bool isFull(struct Stack *stack) {
    return stack->top == MAX_SIZE - 1;
}
 
// 入栈操作
void push(struct Stack *stack, char item) {
    if (isFull(stack)) {
        printf("栈已满，无法入栈\n");
    } else {
        stack->items[++stack->top] = item;
    }
}
 
// 出栈操作
char pop(struct Stack *stack) {
    if (isEmpty(stack)) {
        printf("栈为空，无法出栈\n");
        return '\0'; // 表示栈为空
    } else {
        return stack->items[stack->top--];
    }
}

// 括号匹配算法
bool matching(char expression[]) {
    //请在此处编写代码...
}
 
int main() {
    char expression[MAX_SIZE];
 
    //输入一个包含括号的表达式
    //fgets(expression, MAX_SIZE, stdin);
    scanf("%[^\n]", expression);
 
    if (matching(expression)) {
        printf("括号匹配");
    } else {
        printf("括号不匹配");
    }
 
    return 0;
}

*/


/*
    %s → 读到空格就停
    %[^\n] → 读到换行才停（读一整行）
*/
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