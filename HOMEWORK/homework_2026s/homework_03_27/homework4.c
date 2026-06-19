/*
4. 删除单链表第i个位置元素
【问题描述】

删除单链表第i个位置元素。

【输入形式】

第一行输入链表元素值，输入-1结束链表输入；

第二行输入删除的位置i。

【输出形式】

输出删除后的链表。
【样例输入】

1 2 3 -1

1
【样例输出】

2 3



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
    // 可从其它题目中粘贴至此处
}

// 删除单链表第i个位置的元素
ListNode* deletelist(ListNode* head, int i) {
    //Code Here...
}

// 打印链表
void printList(ListNode* head) {
    ListNode* cur = head->next;
    while (cur != NULL) {
        printf("%d ", cur->val);
        cur = cur->next;
    }
}

int main() {
    ListNode* myList = createList();
    int deletePos;
    scanf("%d", &deletePos);
    myList = deletelist(myList, deletePos);
    printList(myList);

    return 0;
}

*/

#include "stdio.h"
#include "stdlib.h"

typedef struct ListNode{
    int val;
    struct ListNode* next;
}LNode,*LinkList;

void CreateList(LinkList* L);
void DeleteElem(LinkList L,int loc);
void PrintList(LinkList L);

void main()
{
    LinkList head;
    CreateList(&head);
    int loc;
    scanf("%d",&loc);
    DeleteElem(head,loc);
    PrintList(head);
}

void CreateList(LinkList* L){
    (*L)=(LinkList)malloc(sizeof(LNode));
    (*L)->next=NULL;
    LinkList p=(*L);
    int temp=1;
    while(1){
        scanf("%d",&temp);
        if(temp==-1)break;
        LinkList q=(LinkList)malloc(sizeof(LNode));
        q->val=temp;
        q->next=p->next;
        p->next=q;
        p=q;
    }
}

void DeleteElem(LinkList L,int loc){
    LinkList p=L;
    LinkList q;
    for(int i=0;i<loc-1;i++){
        if(p==NULL)return;
        p=p->next;
    }
    q=p->next;
    p->next=q->next;
    free(q);
}

void PrintList(LinkList L){
    LinkList p=L->next;
    while(p){
        printf("%d ",p->val);
        p=p->next;
    }
}
