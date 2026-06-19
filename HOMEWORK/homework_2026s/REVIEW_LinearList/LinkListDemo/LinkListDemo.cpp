// LinkListDemo.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

/*本程序中的链表为单链表*/
#include "stdio.h"
#include "string.h"
#include "stdlib.h"

enum Is { ERROR, OK };

typedef struct data_1 {
    int data1;
    double data2;
    char data3;
}STD;

typedef struct SqList {
    STD data;
    struct SqList* next;
}SqList, * LinkList;

int InitLinkList(LinkList* L);
int InsertLinkList(LinkList L, int i, STD e);
int DeleteLinkList(LinkList L, int i, STD* e);
int UpdateLinkList(LinkList L, int i, STD e);
int LinkListLength(LinkList L);
LinkList LocationLinkList(LinkList L, char* new);
void DispLinkList(LinkList L);
void CreatLinkList(LinkList* L, int length);
void ClearList(LinkList* L);
int GetElem(LinkList L, int i, STD* e);

void main()
{
    LinkList L;
    InitLinkList(&L);
    int choice;
    printf("Please enter your choice: 1.Insert 2.Delete 3.Update 4.Length 5.Location 6.Display 7.Creat 8.Clear 9.GetElem\n");
    scanf_s("%d", &choice);
    switch (choice) {
    case 1:
    {
        int i;
        STD e;
        InsertLinkList(L, i, e);
        break;
    }
    case 2:
    {
        int i;
        STD e;
        DeleteLinkList(L, i, &e);
        break;
    }
    case 3:
    {
        int i;
        STD e;
        UpdateLinkList(L, i, e);
        break;
    }
    case 4:
    {
        LinkListLength(L);
        break;
    }
    case 5:
    {
        char newstr[20];
        LocationLinkList(L, newstr);
        break;
    }
    case 6:
    {
        DispLinkList(L);
        break;
    }
    case 7:
    {
        int length;
        printf("Please enter the length:");
        scanf("%d", &length);
        CreatLinkList(&L, length);
        break;
    }
    case 8:
    {
        ClearList(&L);
        break;
    }
    case 9:
    {
        int i;
        STD e;
        GetElem(L, i, &e);
        break;
    }
    }
}

/*链表的初始化操作*/
int InitLinkList(LinkList* L) {
    *L = (LinkList)malloc(sizeof(SqList));
    if (*L == NULL)return ERROR;
    (*L)->next = NULL; return OK;
}

/*链表的插入操作*/
int InsertLinkList(LinkList L, int i, STD e) {
    LinkList p = L;
    int j = 0;
    while (p && j < i - 1) {
        p = p->next;
        j++;
    }
    if (!p || j >= i)return ERROR;
    LinkList s = (LinkList)malloc(sizeof(SqList));
    s->data = e;
    s->next = p->next;
    p->next = s;
    return OK;
}

/*链表的删除操作*/
int DeleteLinkList(LinkList L, int i, STD* e) {
    LinkList p = L;
    int j = 0;
    while (p && j < i - 1) {
        p = p->next;
        j++;
    }
    if (!p || !(p->next) || j >= i)return ERROR;
    LinkList q = p->next;
    p->next = q->next;
    *e = q->data;
    free(q);
}

/*链表的更新操作*/
int UpdateLinkList(LinkList L, int i, STD e) {
    LinkList p = L->next;
    int pos;
    if (L->next == NULL || i < 1)return ERROR;
    while (p != NULL && pos < i) {
        p = p->next;
        pos++;
    }
    if (p == NULL || pos > i)return ERROR;
    p->data = e;
    return OK;
}

/*链表的求长度操作*/
int LinkListLength(LinkList L) {
    LinkList p = L->next;
    int len = 0;
    while (p) {
        len++;
        p = p->next;
    }
    return len;
}

/*链表的定位操作*/
LinkList LocationLinkList(LinkList L, char* new) {
    LinkList p = L->next;
    while (p) {
        if (strcmp(&p->data.data3, new) == 0)return p;
        p = p->next;
    }
    return NULL;
}

/*链表的遍历操作*/
void DispLinkList(LinkList L) {
    LinkList p = L->next;
    while (p) {
        printf("%d\n%f\n%c\n", &p->data.data1, &p->data.data2, p->data.data3);
        p = p->next;
    }

}

/*链表的创建操作*/
void CreatLinkList(LinkList* L, int length) {
    (*L)->next = NULL;
    for (int i = length; i > 0; i--) {
        LinkList p = (LinkList)malloc(sizeof(SqList));
        printf("Please enter the data1, data2 and data3:\n");
        scanf_s("%d%f%c", &p->data.data1, &p->data.data2, &p->data.data3);
        p->next = (*L)->next;
        (*L)->next = p;
    }
}

/*链表的删除操作*/
void ClearList(LinkList* L) {
    while ((*L)->next) {
        LinkList p = (*L)->next;
        (*L)->next = p->next;
        free(p);
    }
}

/*链表的查找元素操作*/
int GetElem(LinkList L, int i, STD* e) {
    LinkList p = L->next;
    int j = 1;
    while (p && j < i) { p = p->next; j++; }
    if (!p || j > i)return ERROR;
    *e = p->data; return OK;
}


// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
