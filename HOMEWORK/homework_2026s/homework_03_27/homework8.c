/*
8. 删除双向链表中指定值k的所有节点
【问题描述】

删除双向链表中指定值k的所有节点。

【输入形式】

输入双向链表各节点的值，若输入为-1则表示结束输入。
【输出形式】
【样例输入】

1 2 5 2 4 -1

5
【样例输出】

1 2 2 4


Auxiliary Code

#include <stdio.h>
#include <stdlib.h>

// 双向链表节点结构体
typedef struct DListNode {
    int val;
    struct DListNode* prev;
    struct DListNode* next;
} DListNode;

// 创建双向链表（根据用户输入）
DListNode* createDList() {
    DListNode* head = NULL;
    DListNode* tail = NULL;

    int value;
    scanf("%d", &value);

    while (value!= -1) {
        DListNode* newNode = (DListNode*)malloc(sizeof(DListNode));
        newNode->val = value;
        newNode->prev = NULL;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        scanf("%d", &value);
    }

    return head;
}

// 删除双向链表中指定值的所有节点
void deleteNodesByValue(DListNode** head, int target) {
    //Code Here...
}

// 打印双向链表
void printList(DListNode* head) {
    DListNode* curr = head;
    while (curr!= NULL) {
        printf("%d ", curr->val);
        curr = curr->next;
    }
}

int main() {
    // 创建双向链表
    DListNode* myList = createDList();
    // 删除指定值节点（这里假设删除值为5的节点，可根据需要修改）
    int k;
    scanf("%d", &k);
    deleteNodesByValue(&myList, k);

    // 打印删除指定值节点后的双向链表
    printList(myList);

    // 释放链表内存
    DListNode* curr = myList;
    while (curr!= NULL) {
        DListNode* next = curr->next;
        free(curr);
        curr = next;
    }
    return 0;
}

*/

#include "stdio.h"
#include "stdlib.h"

typedef struct DoubleListNode{
    int val;
    struct DoubleListNode* prev;
    struct DoubleListNode* next;
}DLNode,*LinkList;

void CreateDList(LinkList *L);
void DeleteNodesByValue(LinkList* L,int target);
void PrintList(LinkList L);

void main()
{
    LinkList head;
    CreateDList(&head);
    int target;
    scanf("%d",&target);
    DeleteNodesByValue(&head,target);
    PrintList(head);
}

void CreateDList(LinkList *L){
    (*L)=(LinkList)malloc(sizeof(DLNode));
    (*L)->next=NULL;
    (*L)->prev=NULL;
    LinkList p=(*L);
    while(1){
        int temp;
        scanf("%d",&temp);
        if(temp==-1)break;
        LinkList q=(LinkList)malloc(sizeof(DLNode));
        q->val=temp;
        q->next=p->next;
        q->prev=p;
        p->next=q;
        p=q;
    }
}

void DeleteNodesByValue(LinkList* L,int target){
    LinkList p=(*L)->next;
    while(p){
        if(p->val==target){
            p->prev->next=p->next;
            if(p->next)p->next->prev=p->prev;
            LinkList q=p;
            p=p->next;
            free(q);
        }else{
            p=p->next;
        }
    }
}

void PrintList(LinkList L){
    LinkList p=L->next;
    while(p){
        printf("%d ",p->val);
        p=p->next;
    }
}
