#include<stdio.h>
#include<stdlib.h>

typedef struct ListNode {
    int val;
    struct ListNode* next;
}ListNode,*Linklist;

ListNode* createList() {
    Linklist L,q,t;
    L = (Linklist)malloc(sizeof(ListNode));
    L->next = NULL;
    t = L;

    int a[1000];
    for (int i = 0; i < 1000; i++) {
        scanf("%d", &a[i]);
        if (a[i] == -1) {
            break;
        }
    }

    for (int i = 0; i < 1000; i++) {
        if (a[i] == -1) {
            break;
        }
        q = (Linklist)malloc(sizeof(ListNode));
        q->val = a[i];

        q->next = t->next;
        t->next = q;
        t=q;
     }

    return L;
}

void printList(ListNode* head) {
    Linklist p = head->next;
    while (p->val != -1) {
        printf("%d ", p->val);
        p = p->next;
    }

}


int main() {
    ListNode* myList = createList();
    printList(myList);
    return 0;
}