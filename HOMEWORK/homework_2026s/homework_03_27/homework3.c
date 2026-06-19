/*
3. 向单链表第i个位置插入元素k
【问题描述】

向单链表第i个位置插入元素k。

【输入形式】

第一行输入链表元素值，输入-1结束链表输入；

第二行输入插入的位置i；

第三行输入插入元素k。
【输出形式】

输出插入后的链表。
【样例输入】

20 30 40 -1

1

15

【样例输出】

15 20 30 40

【作答说明】

单链表的创建函数可从上一道题目中粘贴过来。

Auxiliary Code

#include <stdio.h>
#include <stdlib.h>

// 定义单链表节点结构体
typedef struct ListNode {
    int val;
    struct ListNode *next;
} ListNode;

// 创建带头结点的链表，通过输入-1表示结束输入
ListNode* createList() {
    // Code here...
}

// 在单链表的第i个位置插入元素
ListNode* insert(ListNode* head, int i, int val) {
    //Code Here...
}

// 输出单链表元素
void printList(ListNode* head) {
    ListNode* cur = head->next;
    while (cur != NULL) {
        printf("%d ", cur->val);
        cur = cur->next;
    }
}

int main() {
    ListNode* myList = createList();
    int insertPos;
    int insertValue;
    scanf("%d", &insertPos);
    scanf("%d", &insertValue);
    myList = insert(myList, insertPos, insertValue);
    printList(myList);

    return 0;
}
*/

#include "stdio.h"
#include "stdlib.h"

typedef struct List{
    int val;
    struct List *next;
}LNode,*LinkList;

void New(LinkList* L);
void CreateList(LinkList* L);
void InsertElem(LinkList L,int loc,int e);
void PrintList(LinkList L);

void main()
{
    LinkList head;
    CreateList(&head);
    int i,e;
    scanf("%d%d",&i,&e);
    InsertElem(head,i,e);
    PrintList(head);
}

void New(LinkList* L){
    (*L)=(LinkList)malloc(sizeof(LNode));
}
void CreateList(LinkList* L)
{
    New(L);
    (*L)->next=NULL;
    LinkList p=(*L);
    int temp;
    while(1){
        scanf("%d",&temp);
        if(temp==-1)break;
        LinkList q;New(&q);
        q->val=temp;
        q->next=p->next;
        p->next=q;
        p=q;
    }
}

void InsertElem(LinkList L,int loc,int e){
    LinkList p=L;
    for(int i=0;i<loc-1;i++){p=p->next;}
    LinkList q;New(&q);
    q->val=e;
    q->next=p->next;
    p->next=q;
}

void PrintList(LinkList L){
    LinkList p=L->next;
    while(p){
        printf("%d ",p->val);
        p=p->next;
    }
}
