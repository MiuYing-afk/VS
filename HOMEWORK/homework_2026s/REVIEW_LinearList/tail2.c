#include "stdio.h"
#include "stdlib.h"

typedef struct STD{
    int number;
    int old;
    char name[20];
}STD;

typedef struct LNode{
    STD data;
    struct LNode* next;
}LNode,*LinkList;

void InitList(LinkList* L);
void CreateList_1(LinkList *L);
void CreateList_2(LinkList *L,int len);
void DeleteElem(LinkList L,int i,STD *e);
void InsertList(LinkList L,int i,STD e);
void UpdataList(LinkList L,int i,STD e);
void GetElem(LinkList L,int i,STD *e);
void ClearList(LinkList L);
void DestroyList(LinkList *L);
int  ListLength(LinkList L);
void DispList(LinkList L);

int main()
{
    LinkList head;
    InitList(&head);
    char choice;
    int length;
    int loc;
    STD temp;
    while(1){
        printf("请输入你的选择:\n");
        printf("1.创建链表 2.插入元素\n");
        printf("3.删除元素 4.更新元素\n");
        printf("5.获取元素 6.清空链表\n");
        printf("7.销毁链表 8.链表长度\n");
        printf("9.遍历链表 \n");
        while(1){
            scanf("%c",&choice);
            if(choice>='1'&&choice<='9'){
                break;
            }else if(choice=='\n'){
                
            }else{
                printf("输入错误，请重新输入:\n");
            }
        }
        switch(choice){
            case '1':
                int how=0;
                printf("输入你想创建链表的方式:\n");
                printf("1.输入数据创建链表(输入学号为-1时结束)\n");
                printf("2.指定长度创建链表\n");
                scanf("%d",&how);
                switch(how){
                    case 1:
                        CreateList_1(&head);
                        break;
                    case 2:
                        int len;
                        printf("输入链表长度:\n");
                        scanf("%d",&len);
                        CreateList_2(&head,len);
                        break;
                }
                break;
            case '2':
                length=ListLength(head);
                printf("请输入你想要插入的位置(当前链表长度为%d)\n",length);
                scanf("%d",&loc);
                printf("请输入你想要插入的内容:\n");
                printf("学号\n");
                scanf("%d",&temp.number);
                printf("年龄\n");
                scanf("%d",&temp.old);
                printf("姓名\n");
                scanf("%s",temp.name);
                InsertList(head,loc,temp);
                break;
            case '3':
                length=ListLength(head);
                printf("请输入你想要删除的元素的位置(当前链表长度为%d)\n",length);
                scanf("%d",&loc);
                DeleteElem(head,loc,&temp);
                printf("以下是你删除的元素的内容:\n");
                printf("学号:%d\n",temp.number);
                printf("年龄:%d\n",temp.old);
                printf("姓名:%s\n",temp.name);
                break;
            case '4':
                length=ListLength(head);
                printf("请输入你想要更新的位置(当前链表长度为%d)\n",length);
                scanf("%d",&loc);
                printf("请输入你想要更新的内容:\n");
                printf("学号\n");
                scanf("%d",&temp.number);
                printf("年龄\n");
                scanf("%d",&temp.old);
                printf("姓名\n");
                scanf("%s",temp.name);
                UpdataList(head,loc,temp);
                break;
            case '5':
                length=ListLength(head);
                printf("请输入你想要获取的元素的位置(当前链表长度为%d)\n",length);
                scanf("%d",&loc);
                GetElem(head,loc,&temp);
                printf("以下是你获取的元素的内容:\n");
                printf("学号:%d\n",temp.number);
                printf("年龄:%d\n",temp.old);
                printf("姓名:%s\n",temp.name);
                break;
            case '6':
                ClearList(head);
                break;
            case '7':
                DestroyList(&head);
                break;
            case '8':
                printf("链表长度:%d\n",ListLength(head));
                break;
            case '9':
                DispList(head);
                break;
        }
    }
    return 0;
}

void InitList(LinkList* L){
    (*L)=(LinkList)malloc(sizeof(LNode));
    (*L)->next=NULL;
}

void CreateList_1(LinkList *L){
    LinkList p=(*L);
    STD temp;
    while(1){
        printf("输入学生的学号，年龄，姓名:\n");
        scanf("%d%d%s",&temp.number,&temp.old,temp.name);
        if(temp.number==-1)break;
        LinkList q=(LinkList)malloc(sizeof(LNode));
        q->data=temp;
        q->next=p->next;
        p->next=q;
        p=q;
    }
}

void CreateList_2(LinkList *L,int len){
    LinkList p=(*L);
    STD temp;
    for(int i=0;i<len;i++){
        printf("输入学生的学号，年龄，姓名:\n");
        scanf("%d%d%s",&temp.number,&temp.old,temp.name);
        LinkList q=(LinkList)malloc(sizeof(LNode));
        q->data=temp;
        q->next=p->next;
        p->next=q;
        p=q;
    }
}

void DeleteElem(LinkList L,int i,STD *e){
    LinkList p=L;
    for(int j=0;j<i-1;j++)p=p->next;
    LinkList q=p->next;
    p->next=q->next;
    *e=q->data;
    free(q);
}

void InsertList(LinkList L,int i,STD e){
    LinkList p=L;
    int len=ListLength(L);
    if(i<1||i>len+1){
        printf("插入位置不合法\n");
        return;
    }
    for(int j=0;j<i-1;j++)p=p->next;
    LinkList q=(LinkList)malloc(sizeof(LNode));
    q->data=e;
    q->next=p->next;
    p->next=q;
}

void UpdataList(LinkList L,int i,STD e){
    LinkList p=L->next;
    for(int j=0;j<i-1;j++)p=p->next;
    p->data=e;
}

void GetElem(LinkList L,int i,STD *e){
    LinkList p=L->next;
    for(int j=0;j<i-1;j++)p=p->next;
    *e=p->data;
}

void ClearList(LinkList L){
    LinkList p=L->next;
    while(p!=NULL){
        LinkList q=p->next;
        free(p);
        p=q;
    }
    L->next=NULL;
}

void DestroyList(LinkList *L){
    ClearList(*L);
    free(*L);
    *L=NULL;
}

int  ListLength(LinkList L){
    LinkList p=L->next;
    int len=0;
    while(p!=NULL){
        len++;
        p=p->next;
    }
    return len;
}

void DispList(LinkList L){
    LinkList p=L->next;
    while(p){
        printf("学号:%d\n",p->data.number);
        printf("年龄:%d\n",p->data.old);
        printf("姓名:%s\n",p->data.name);
        p=p->next;
    }
}

void InitList(LinkList* L);
void CreateList_1(LinkList *L);
void CreateList_2(LinkList *L,int len);
void DeleteElem(LinkList L,int i,STD *e);
void InsertList(LinkList L,int i,STD e);
void UpdataList(LinkList L,int i,STD e);
void GetElem(LinkList L,int i,STD *e);
void ClearList(LinkList L);
void DestroyList(LinkList *L);
int  ListLength(LinkList L);
void DispList(LinkList L);