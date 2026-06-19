/*
6. 链栈
【问题描述】

请实现一个链栈（Linked Stack），并完成以下基本操作：

初始化链栈：创建一个空的链栈。

判空：判断链栈是否为空。

进栈：将一个元素压入链栈。

出栈：弹出链栈的栈顶元素。

取栈顶元素：获取链栈的栈顶元素，但不弹出。

求栈长：返回链栈中元素的个数。

遍历链栈：从栈顶到栈底依次输出链栈中的元素。

说明：i --初始化链栈；e --判断链栈是否为空，若为空打印True，否则打印False； p element --将element进栈； o --出栈一个元素并将该元素打印出来；t --取栈顶元素并打印；l --求栈长并打印；f --遍历链栈，依次打印栈中元素，中间用空格隔开。

【输入形式】

第 1 行包含 1 个正整数 n，表示接下来进行 n 次操作。

第2行开始至n+1行，每一行表示一个操作。

【输出形式】

对应n行操作，若该行操作需要输出，则打印结果；否则不需要打印任何内容。

【样例输入】

13

i

e

p 10

p 20

p 30

f

o

o

e

p 40

t

l

f

【样例输出】

True

30 20 10

30

20

False

40

2

40 10

【样例说明】

初始化链栈。

判断链栈是否为空（应为空）。

将元素 10 进栈。

将元素 20 进栈。

将元素 30 进栈。

遍历链栈，输出栈中元素。

出栈一个元素并输出。

出栈一个元素并输出。

判断链栈是否为空（应不为空）。

将元素 40 进栈。

取栈顶元素并输出。

求栈长并输出。

遍历链栈，输出栈中元素。

辅助代码，完成主函数中各种操作的代码：

#include <stdio.h> #include <stdlib.h>

// 定义链栈节点结构 typedef struct Node {    int data;    struct Node* next; } Node;

// 定义链栈结构 typedef struct {    Node* top;    int size; } LinkedStack;



int main() {     

LinkedStack stack;    
initStack(&stack);
int n, element;
char operation;
scanf("%d", &n);

for (int i = 0; i < n; i++) {
    scanf(" %c", &operation);
    switch (operation) {
        case 'i':
            initStack(&stack);
            break;
        case 'e':
            printf("%s\n", isEmpty(&stack) ? "True" : "False");
            break;
        case 'p':
            scanf("%d", &element);
            push(&stack, element);
            break;
        case 'o':
            printf("%d\n", pop(&stack));
            break;
        case 't':
            printf("%d\n", top(&stack));
            break;
        case 'l':
            printf("%d\n", length(&stack));
            break;
        case 'f':
            traverse(&stack);
            break;
        default:
            printf("Invalid operation.\n");
    }
}

return 0;
}

【评分标准】
*/

#include "stdio.h"
#include "stdlib.h"
#include "string.h"

typedef struct snode{
    int data;
    struct snode *next;
}Snode,*LinkStack;

void InitStack(LinkStack *S);
void Push(LinkStack *S);
void Pop(LinkStack *S);
int  IsEmpty(LinkStack S);
void IsEmpty_Print(LinkStack S);
int  Length(LinkStack S);
void GetTop(LinkStack S);
void Print(LinkStack S);

int main()
{
    Snode Head;
    LinkStack head=&Head;
    int counts=0;
    scanf("%d\n",&counts);
    char operation,hang;
    for(int i=0;i<counts;i++){
        // scanf("%c%c",&operation,&hang);
        scanf(" %c",&operation);
        switch(operation){
            case 'i':
                InitStack(&head);
                break;
            case 'e':
                IsEmpty_Print(head);
                break;
            case 'p':
                Push(&head);
                break;
            case 'o':
                Pop(&head);
                break;
            case 't':
                GetTop(head);
                break;
            case 'l':{
                int len=Length(head);
                printf("%d\n",len);
                break;}
            case 'f':
                Print(head);
                break;
            // default:
                // printf("Invalid operation.\n");
                // break;
        }
    }

    return 0;
}

void InitStack(LinkStack *S){
    (*S)=(LinkStack)malloc(sizeof(Snode));
    (*S)->next=NULL;
}

void Push(LinkStack *S){
    int e;
    scanf("%d",&e);
    LinkStack temp=(LinkStack)malloc(sizeof(Snode));
    temp->data=e;
    temp->next=(*S)->next;
    (*S)->next=temp;
}

void Pop(LinkStack *S){
    if(IsEmpty(*S))return;
    LinkStack p=(*S)->next;
    (*S)->next=p->next;
    printf("%d\n",p->data);
    free(p);
}

void  IsEmpty_Print(LinkStack S){
    if(S->next==NULL){
        printf("True\n");
    }else{
        printf("False\n");
    }
}

int IsEmpty(LinkStack S){
    return S->next==NULL;
}

int  Length(LinkStack S){
    int i=0;
    if(IsEmpty(S))return i;
    LinkStack p=S->next;
    while(p){
        i++;
        p=p->next;
    }
    return i;
}

void GetTop(LinkStack S){
    printf("%d\n",S->next->data);
}

void Print(LinkStack S){
    LinkStack p=S->next;
    while(p){
        printf("%d ",p->data);
        p=p->next;
    }
    printf("\n");
}
