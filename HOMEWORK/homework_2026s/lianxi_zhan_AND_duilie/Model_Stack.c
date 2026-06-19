/*顺序栈*/

#include <stdio.h>
#define MAXSIZE 100

// 栈结构定义
typedef struct {
    int data[MAXSIZE];
    int top;  // 栈顶指针，-1表示空栈
} SqStack;

// 初始化栈
void InitStack(SqStack *s) {
    s->top = -1;
}

// 判断栈空
int StackEmpty(SqStack *s) {
    return s->top == -1;
}

// 入栈
int Push(SqStack *s, int x) {
    if (s->top == MAXSIZE-1) return 0; // 栈满
    s->data[++s->top] = x;
    return 1;
}

// 出栈
int Pop(SqStack *s, int *x) {
    if (StackEmpty(s)) return 0; // 栈空
    *x = s->data[s->top--];
    return 1;
}
