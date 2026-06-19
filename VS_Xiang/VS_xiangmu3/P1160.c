/*
题目描述
一个学校里老师要将班上 N 个同学排成一列，同学被编号为 1∼N，他采取如下的方法：

先将 1 号同学安排进队列，这时队列中只有他一个人；

2∼N 号同学依次入列，编号为 i 的同学入列方式为：老师指定编号为 i 的同学站在编号为 1∼(i−1) 中某位同学（即之前已经入列的同学）的左边或右边；

从队列中去掉 M 个同学，其他同学位置顺序不变。

在所有同学按照上述方法队列排列完毕后，老师想知道从左到右所有同学的编号。

输入格式
第一行一个整数 N，表示了有 N 个同学。

第 2∼N 行，第 i 行包含两个整数 k,p，其中 k 为小于 i 的正整数，p 为 0 或者 1。若 p 为 0，则表示将 i 号同学插入到 k 号同学的左边，p 为 1 则表示插入到右边。

第 N+1 行为一个整数 M，表示去掉的同学数目。

接下来 M 行，每行一个正整数 x，表示将 x 号同学从队列中移去，如果 x 号同学已经不在队列中则忽略这一条指令。

输出格式
一行，包含最多 N 个空格隔开的整数，表示了队列从左到右所有同学的编号。

输入输出样例
输入 #1复制

4
1 0
2 1
1 0
2
3
3
输出 #1复制

2 4 1
说明/提示
【样例解释】

将同学 2 插入至同学 1 左边，此时队列为：

2 1

将同学 3 插入至同学 2 右边，此时队列为：

2 3 1

将同学 4 插入至同学 1 左边，此时队列为：

2 3 4 1

将同学 3 从队列中移出，此时队列为：

2 4 1

同学 3 已经不在队列中，忽略最后一条指令

最终队列：

2 4 1

【数据范围】

对于 20% 的数据，1≤N≤10。

对于 40% 的数据，1≤N≤1000。

对于 100% 的数据，1<M≤N≤10 
5
 。
*/


//改代码只有用数组模拟单链表才不会超时
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

typedef struct Node{
    int num;
    struct Node *next;
}ListNode,*LinkList;

void InitList(LinkList *head);
void InsertNode(LinkList head,int address,int tag,int num);
void DeleteNode(LinkList head,int num);
void PrintList(LinkList head);

int main()
{
    LinkList head;
    int inNum,deNum;
    scanf("%d",&inNum);
    InitList(&head);
    for(int i=2;i<=inNum;i++){
        int address,tag;
        scanf("%d %d",&address,&tag);
        InsertNode(head,address,tag,i);
    }
    scanf("%d",&deNum);
    for(int i=0;i<deNum;i++){
        int num;
        scanf("%d",&num);
        DeleteNode(head,num);
    }
    PrintList(head);

    return 0;
}

void InitList(LinkList *head){
    (*head)=(LinkList)malloc(sizeof(ListNode));
    (*head)->next=NULL;
    LinkList first;
    first=(LinkList)malloc(sizeof(ListNode));
    first->num=1;
    first->next=(*head)->next;
    (*head)->next=first;
}

void InsertNode(LinkList head,int address,int tag,int num){
    LinkList new=(LinkList)malloc(sizeof(ListNode));
    new->num=num;
    LinkList L=head;
    while(L->next->num!=address){
        L=L->next;
        if(L==NULL)return;
    }
    if(tag==0){
        new->next=L->next;
        L->next=new;
    }else{
        L=L->next;
        new->next=L->next;
        L->next=new;
    }
}

void DeleteNode(LinkList head,int num){
    if(head==NULL)return;
    LinkList L=head;
    while(L->next){
        LinkList t=L->next;
        if(t->num==num){
            L->next=t->next;
            if(t!=NULL){
            free(t);
            return;
            }
        }
        L=L->next;
    }
}

void PrintList(LinkList head){
    LinkList L=head->next;
    while(L){
        printf("%d ",L->num);
        L=L->next;
    }
}