/*
6. 单链表逆置
【问题描述】

单链表逆置并打印逆置后的链表。

【输入形式】

输入单链表各节点的值，若输入为-1则表示结束输入。
【输出形式】

输出逆置后的链表。
【样例输入】

1 2 3 -1
【样例输出】

3 2 1


Auxiliary Code

#include <iostream>

// 定义链表节点结构体
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

// 函数用于创建链表，根据用户输入的节点值创建链表
ListNode* createList() {
    ListNode* head = NULL;
    ListNode* tail = NULL;

    int value;
    std::cin >> value;

    while (value!= -1) {
        ListNode* newNode = new ListNode(value);
        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
        std::cin >> value;
    }

    return head;
}

// 函数用于逆转链表
ListNode* reverseList(ListNode* head) {
    //Code Here...
}

// 函数用于打印链表
void printList(ListNode* head) {
    //Code Here...
}

// 测试用例
int main() {
    // 通过输入创建链表
    ListNode* head = createList();

    ListNode* reversedHead = reverseList(head);
    printList(reversedHead);

    return 0;
}

*/