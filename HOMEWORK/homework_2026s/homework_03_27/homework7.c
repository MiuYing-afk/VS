/*
7. 合并两个有序单链表
【问题描述】

已知两个链表head1 和head2 各自有序，请把它们合并成一个链表依然有序。(保留所有结点，即便大小相同）。

【输入形式】

输入两个有序单链表，并以-1表示链表结束。
【输出形式】

输出合并后的有序链表
【样例输入】

1 3 5 7 9 -1

2 3 6 8 9 -1
【样例输出】

1 2 3  3 5 6 7 8 9 9


Auxiliary Code

#include <stdio.h>
#include <stdlib.h>

// 单链表节点结构体
typedef struct ListNode {
    int val;
    struct ListNode* next;
} ListNode;

// 创建单链表（根据用户输入）
ListNode* createList() {
    ListNode* head = NULL;
    ListNode* tail = NULL;

    int value;
    scanf("%d", &value);

    while (value!= -1) {
        ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
        newNode->val = value;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
        scanf("%d", &value);
    }

    return head;
}

// 合并两个有序链表
ListNode* mergeTwoLists(ListNode* head1, ListNode* head2) {
    //Code Here...
}

void printlist(ListNode* mergedList){
    ListNode* current = mergedList;
    while (current!= NULL) {
        printf("%d ", current->val);
        current = current->next;
    }
}

int main() {
    // 创建第一个有序链表
    ListNode* head1 = createList();

    // 创建第二个有序链表
    ListNode* head2 = createList();

    // 合并两个有序链表
    ListNode* mergedList = mergeTwoLists(head1, head2);

    printlist(mergedList);
    
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
void MergeTwoLists(LinkList *L1,LinkList *L2);
void PrintList(LinkList L);

void main()
{
    LinkList head1,head2;
    CreateList(&head1);
    CreateList(&head2);
    MergeTwoLists(&head1,&head2);
    PrintList(head1);
}

void CreateList(LinkList* L){
    (*L)=(LinkList)malloc(sizeof(LNode));
    (*L)->next=NULL;
    LinkList p=(*L);
    while(1){
        int temp;
        scanf("%d",&temp);
        if(temp==-1)break;
        LinkList q=(LinkList)malloc(sizeof(LNode));
        q->val=temp;
        q->next=p->next;
        p->next=q;
        p=q;
    }
}

// void MergeTwoLists(LinkList *L1,LinkList *L2){
//     LinkList q1,p1,q2,p2;
//     p1=(*L1);
//     q1=(*L1)->next;
//     p2=(*L2)->next;
//     q2=p2;
//     while(q1&&q2){
//         if(q2->val<=q1->val){
//             p1->next=q2;
//             q2->next=q1;
//             p2=p2->next;
//             p1=q2;
//             q2=p2;
//         }else{
//             p1=q1;
//             q1=q1->next;
//         }
//     }
//     if(q2)q1->next=q2;
// }

void MergeTwoLists(LinkList *L1, LinkList *L2) {
    // p1 指向 L1 的当前比较节点
    // p2 指向 L2 的当前比较节点
    // pre 指向 L1 中待插入位置的前驱节点（核心！）
    LinkList p1 = (*L1)->next;
    LinkList p2 = (*L2)->next;
    LinkList pre = *L1;  // 从 L1 头结点开始

    // 两个链表都没走完时，逐个比较并入
    while (p1 != NULL && p2 != NULL) {
        if (p2->val <= p1->val) {
            // 把 p2 插入到 pre 和 p1 之间
            LinkList temp = p2->next;  // 先保存 p2 的下一个
            pre->next = p2;            // 前驱接上 p2
            p2->next = p1;             // p2 接上 p1
            pre = p2;                  // pre 后移
            p2 = temp;                 // p2 继续走
        } else {
            // L1 节点更小，直接后移
            pre = p1;
            p1 = p1->next;
        }
    }

    // 如果 L2 还有剩余节点，全部接到 L1 尾部
    if (p2 != NULL) {
        pre->next = p2;
    }

    // 释放 L2 头结点，L2 置空（真正只剩 L1）
    free(*L2);
    *L2 = NULL;
}

void PrintList(LinkList L){
    LinkList p=L->next;
    while(p){
        printf("%d ",p->val);
        p=p->next;
    }
}
