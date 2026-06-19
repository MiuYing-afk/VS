/*1. 创建带头结点的单链表
【问题描述】

创建带头结点的单链表并打印链表元素。

【输入形式】

输入链表元素值，输入-1结束链表输入；

【输出形式】

输出链表元素。
【样例输入】

20 30 40 -1

【样例输出】

20 30 40



Auxiliary Code

#include <stdio.h>
#include <stdlib.h>

// 定义单链表结点
typedef struct ListNode {
    int val;
    struct ListNode *next;
} ListNode;

// 创建带头结点的单链表，通过输入-1表示结束输入
ListNode* createList() {
    // Code here...
}

// 打印链表
void printList(ListNode* head) {
    // Code here...
}

int main() {
    ListNode* myList = createList();
    printList(myList);

    return 0;
}
*/

#include <stdio.h>
#include <stdlib.h>

// 定义单链表结点
typedef struct ListNode {
    int val;
    struct ListNode *next;
} ListNode,*LinkList;

// 创建带头结点的单链表，通过输入-1表示结束输入
ListNode* createList() {
    // Code here...
    LinkList L,q;
    L=(LinkList)malloc(sizeof(ListNode));
    L->next=NULL;
    q=L;
    int temp;
    do{
        scanf("%d",&temp);
        if(temp==-1)break;
        LinkList p=(LinkList)malloc(sizeof(ListNode));
        p->val=temp;
        p->next=q->next;
        q->next=p;
        q=p;
    }while(temp!=-1);
    return L;
}

// 打印链表
void printList(ListNode* head) {
    // Code here...
    LinkList p=head->next;
    while(p){
        printf("%d ",p->val);
        p=p->next;
    }
}

int main() {
    ListNode* myList = createList();
    printList(myList);

    return 0;
}