/*
7. 算术表达式转化为后缀表达式
【问题描述】

编写一个程序，将用户输入的中缀算术表达式（包括加、减、乘、除运算符以及括号）转换为后缀表达式（逆波兰表示法）。

【输入形式】

输入包含一行，表示一个算术表达式，以#结尾。

【输出形式】

输出转换得到的后缀表达式，以#结尾。

【样例输入1】

3 + 4 * 2 / ( 1 - 5 ) #
【样例输出1】

3 4 2 * 1 5 - / + #

【样例输入2】

10 / 2 + ( 3 * 4 - 2 ) * 2 #
【样例输出2】

10 2 / 3 4 * 2 - 2 * + #
【样例说明】

1、表达式中的数字为0-9范围，运算符包括+-/*，被除数不为0

2、请将辅助代码粘贴至作答区域，并实现 Transformation 函数，可根据需要自行添加其它辅助函数。
【辅助代码】

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

// 定义栈结构
typedef struct {
    char items[MAX_SIZE];
    int top;
} LinkStack;

// 初始化栈
void init_Stack(LinkStack *s) {
    s->top = -1;
}

// 判断栈是否为空
int is_empty(LinkStack *s) {
    return s->top == -1;
}

// 入栈操作
void push(LinkStack *s, char item) {
    if (s->top < MAX_SIZE - 1) {
        s->items[++s->top] = item;
    }
}

// 出栈操作
char pop(LinkStack *s) {
    if (!is_empty(s)) {
        return s->items[s->top--];
    }
    return '\0'; // 栈空时返回'\0'
}

// 获取栈顶元素
char gettop(LinkStack *s) {
    if (!is_empty(s)) {
        return s->items[s->top];
    }
    return '\0'; // 栈空时返回'\0'
}

// 将中缀表达式转换为后缀表达式
void Transformation(char a[], char suff[])
{
    // 请在此处书写代码...  
}

int main() {
    char expression[MAX_SIZE], suffix[MAX_SIZE], formattedSuffix[MAX_SIZE*2];

    //输入一个中缀算术表达式（仅包含数字和+,-,*,/,(,)）并以#结束);
    scanf("%[^\n]", expression);

    Transformation(expression, suffix);
    
    // 在各元素间添加空格
    int j = 0;
    for (int i = 0; suffix[i] != '\0'; i++) {
        if (i > 0) formattedSuffix[j++] = ' '; // 先加空格，除了第一个字符之前
        formattedSuffix[j++] = suffix[i];
    }
    formattedSuffix[j] = '\0'; // 确保字符串以null结尾

    printf("%s\n", formattedSuffix);

    return 0;
}
*/

#include "stdio.h"
#include "stdlib.h"
#include "string.h"

#define MAXSIZE 100

typedef struct Fu{
    char items[MAXSIZE];
    int top;
}LinkStack;

void InitStack(LinkStack *S);
void Push(LinkStack *S,char e);
char Pop(LinkStack *S);
char Gettop(LinkStack *S);
int IsEmpty(LinkStack S);
int Num(char e);
void Transformation(char *str1,char *str2);

int main()
{
    char string_1[MAXSIZE];
    char string_2[MAXSIZE];
    char string_3[MAXSIZE*2];
    scanf("%[^\n]",string_1);
    Transformation(string_1,string_2);

    int j = 0;
    for (int i = 0; string_2[i] != '\0'; i++) {
        if (i > 0) string_3[j++] = ' '; // 先加空格，除了第一个字符之前
        string_3[j++] = string_2[i];
    }
    string_3[j] = '\0'; // 确保字符串以null结尾

    printf("%s #\n", string_3);

    return 0;
}

void InitStack(LinkStack *S){
    (*S).top=-1;
}

void Push(LinkStack *S,char e){
    if(S->top<MAXSIZE-1){
        S->items[++S->top]=e;
    }
}

char Pop(LinkStack *S){
    if(!IsEmpty(*S)){
        return S->items[S->top--];
    }
    return '\0';
}

char Gettop(LinkStack *S){
    if(!IsEmpty(*S)){
        return S->items[S->top];
    }
    return '\0';
}

int IsEmpty(LinkStack S){
    return S.top==-1;
}

int Num(char e){
    if(e=='#')return 0;
    else if(e=='(')return 1;
    else if(e=='+'||e=='-')return 2;
    else if(e=='*'||e=='/')return 3;
}

void Transformation(char *str1,char *str2){
    int i=0,k=0;
    LinkStack S;
    char ch;
    InitStack(&S);
    Push(&S,'#');
    while(*(str1+i)!='#'){
        if(str1[i] == ' '){
            i++;
            continue;
        }
        if('0'<=*(str1+i)&&*(str1+i)<='9'){
            *(str2+k++)=*(str1+i++);
        }else{
            switch(*(str1+i)){
                case '(':Push(&S,*(str1+i));break;
                case ')':ch=Pop(&S);
                        while(ch!='('){
                            *(str2+k++)=ch;
                            ch=Pop(&S);
                        }
                        break;
                default:ch=Gettop(&S);
                        while(Num(ch)>=Num(*(str1+i))){
                            *(str2+k++)=ch;
                            ch=Pop(&S);
                            ch=Gettop(&S);
                        }
                        Push(&S,*(str1+i));
                        break;
            }
            i++;
        }    
    }
    while(Gettop(&S) != '#'){
        str2[k++] = Pop(&S);
    }
    str2[k] = '\0';
}
