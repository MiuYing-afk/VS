/*
5. 链表逆序输出
【问题描述】

输入一个单链表的头节点，按链表从尾到头的顺序返回每个节点的值。

【输入形式】

输入单链表节点的值，若输入为-1则表示结束输入。
【输出形式】

按链表从尾到头的顺序输出每个节点的值。

【样例输入】

1 2 3 -1
【样例输出】

3 2 1


Auxiliary Code

#include <stdio.h>
#include <stdlib.h>

// 单链表节点结构体
typedef struct ListNode {
    int val;
    struct ListNode* next;
} ListNode;

// 创建带头结点的单链表
ListNode* createList() {
    // 可从其它题目中粘贴至此处
}

// 按从尾到头的顺序输出单链表节点的值
void printListReverse(ListNode* head) {
    //Code Here...
}

int main() {
    // 创建单链表
    ListNode* list = createList();

    // 按从尾到头的顺序输出单链表节点的值
    printListReverse(list);

    // 释放链表内存
    ListNode* current = list;
    while (current!= NULL) {
        ListNode* next = current->next;
        free(current);
        current = next;
    }

    return 0;
}

*/

#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode{
    int val;
    struct ListNode* next;
}LNode,*LinkList;

void CreateList(LinkList* L);
void ReverseList(LinkList* L);
void PrintList(LinkList L);
void ClearList(LinkList* L);

void main()
{
    LinkList head;
    CreateList(&head);
    ReverseList(&head);
    PrintList(head);
    ClearList(&head);
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

void ReverseList(LinkList* L){
    LinkList pre,curr,next;
    pre=NULL;
    curr=(*L)->next;
    while(curr){
        next=curr->next;
        curr->next=pre;
        pre=curr;
        curr=next;
    }
    (*L)->next=pre;
}

void PrintList(LinkList L){
    LinkList p=L->next;
    while(p){
        printf("%d ",p->val);
        p=p->next;
    }
}

void ClearList(LinkList* L){
    while((*L)->next){
        LinkList p=(*L)->next;
        (*L)->next=p->next;
        free(p);
    }
}