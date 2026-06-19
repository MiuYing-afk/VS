/*
1. 向单链表第i个位置插入元素k
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
    ListNode* head = (ListNode*)malloc(sizeof(ListNode));
    head->next =NULL;
    ListNode* temp=head;
    for(int t;t!=-1;)
    {
        scanf("%d",&t);
        if(t==-1){break;}
        ListNode* new=(ListNode*)malloc(sizeof(ListNode));
        new->val=t;
        new->next=NULL;
        temp->next=new;
        temp=new;
    }
    return head;
}

// 在单链表的第i个位置插入元素
ListNode* insert(ListNode* head, int i, int val) {
    //Code Here...
    ListNode* temp=head;
    for(int t=0;t<i-1&&temp!=NULL;t++)
    {
        temp=temp->next;
    }
    if(temp==NULL)
    {
        return head;
    }
    ListNode* new=(ListNode*)malloc(sizeof(ListNode));
    new->val=val;
    new->next=temp->next;
    temp->next=new;
    return head;
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