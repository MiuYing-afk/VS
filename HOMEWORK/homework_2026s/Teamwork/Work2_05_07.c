/*
1. 用户电价管理（循环单链表）
【问题描述】

随着智能电网的发展，电力公司需要对不同类型用户的电价信息以及实时用电负荷进行统一管理与分析，从而实现电力资源的优化配置与精细化调度。某地区电网公司建立了一套简化的管理系统，实现以下功能：

用户电价管理（循环单链表）

为了便于管理不同用户类型的电价策略，系统采用带头结点的循环单链表存储用户类型信息。每个结点包含如下数据：

用户类型编号（TypeID，字符串，例： ID101）

用户类型名称（TypeName，如Residential、Industrial、Commercial）

电价（Price，单位：元/度）

系统需要支持以下操作：

1）创建/插入（i）：按用户编号升序插入一条电价信息

2）输出：每次插入或修改后输出当前链表（格式：A->B->C）

3）删除（d）：按用户类型名称删除对应结点（若不存在则输出 Not Found）

4）查找（f）：根据用户类型名称查询电价（若不存在则输出 Not Found）

5）更新（u）：修改某用户类型的电价（若不存在则输出 Not Found）

6）排序（s）：按电价从高到低排序

系统按指令执行操作：

指令	含义
i	插入
d	删除
f	查找
u	更新（循环链表）
s	排序（循环链表）
q	退出
【输入形式】

输入为多组操作指令：

每行输入一个操作符

随后输入对应数据

操作持续进行，直到输入 q 结束

【输出形式】

链表输出格式：

ID101 Residential 0.50->ID102 Industrial 0.60
查找：

成功输出数值

失败输出：Not Found

平均负荷：保留两位小数

退出：

程序退出


【样例输入】

i
ID101 Residential 0.50
i
ID102 Industrial 0.60
i
ID103 Commercial 0.70
s
f
Industrial
u
Industrial 0.65
u
Medical 0.80
d
Residential
d
Residential
q

【样例输出】

ID101 Residential 0.50

ID101 Residential 0.50->ID102 Industrial 0.60

ID101 Residential 0.50->ID102 Industrial 0.60->ID103 Commercial 0.70

ID103 Commercial 0.70->ID102 Industrial 0.60->ID101 Residential 0.50

0.60

ID103 Commercial 0.70->ID102 Industrial 0.65->ID101 Residential 0.50

Not Found

ID102 Industrial 0.65->ID103 Commercial 0.70

Not Found

程序退出

【样例说明】

初始插入按编号排序

排序后按电价降序

【评分标准】

项目	分值
循环单链表结构设计	20%
链表增删查改	30%
链表排序实现	15%
遍历与统计	15%
输入输出规范	20%


*/

#include "stdio.h"
#include "stdlib.h"
#include "string.h"

typedef struct Node{
    char ID[40];
    char Name[60];
    double price;
    struct Node *next;
}ListNode,*LinkList;

void InitList(LinkList *L);
void InsertNode(LinkList head);
void DeleteNode(LinkList head);
void FindNode(LinkList head);
void UpdataNode(LinkList head);
void ShunList(LinkList head);
void Print(LinkList head);
void ClearList(LinkList head);
int IDTrans(char *id);
int Length(LinkList head);

int main()
{
    LinkList head;
    InitList(&head);
    char choice;
    while(1){
        scanf(" %c",&choice);
        switch(choice){
            case 'i':{
                InsertNode(head);
                Print(head);
                break;
            }

            case 'd':{
                DeleteNode(head);
                break;
            }

            case 'f':{
                FindNode(head);
                break;
            }

            case 'u':{
                UpdataNode(head);
                break;
            }

            case 's':{
                ShunList(head);
                Print(head);
                break;
            }
            
            case 'q':{
                ClearList(head);
                printf("程序退出\n");
                exit(0);
                break;
            }

            default:{break;}
        }
    }

    return 0;
}

void InitList(LinkList *L){
    (*L)=(LinkList)malloc(sizeof(ListNode));
    (*L)->next=(*L);
}

void Print(LinkList head){
    LinkList L=head->next;
    if(L==head){
        printf("Not Found\n");
        return;
    }
    while(L!=head){
        printf("%s %s %.2f",L->ID,L->Name,L->price);
        L=L->next;
        if(L!=head)printf("->");
    }
    printf("\n");
}

void InsertNode(LinkList head){
    LinkList L=head;
    LinkList new=(LinkList)malloc(sizeof(ListNode));
    scanf(" %s",new->ID);
    scanf(" %s",new->Name);
    scanf("%lf",&new->price);
    int new_id=IDTrans(new->ID);
    while(L->next!=head){
        int t1=IDTrans(L->next->ID);
        if(new_id<=t1)break;
        L=L->next;
    }
    new->next=L->next;
    L->next=new;
}

void DeleteNode(LinkList head){
    char target[60];
    scanf(" %s",target);
    LinkList last=head;
    while(last->next!=head){
        if(strcmp(last->next->Name,target)==0){
            LinkList t=last->next;
            last->next=t->next;
            free(t);
            Print(head);
            return;
        }
        last=last->next;
    }
    printf("Not Found\n");
}

void FindNode(LinkList head){
    char target[60];
    scanf(" %s",target);
    LinkList last=head;
    while(last->next!=head){
        if(strcmp(last->next->Name,target)==0){
            printf("%.2f\n",last->next->price);
            return;
        }
        last=last->next;
    }
    printf("Not Found\n");
}

void UpdataNode(LinkList head){
    char target[60];
    scanf(" %s",target);
    LinkList last=head;
    while(last->next!=head){
        if(strcmp(last->next->Name,target)==0){
            double new_price;
            scanf("%lf",&new_price);
            last->next->price=new_price;
            Print(head);
            return;
        }
        last=last->next;
    }
    printf("Not Found\n");
}

void ShunList(LinkList head){
    int length=Length(head);
    LinkList p,q;
	for(int i=0;i<length-1;i++){
        p=head->next;
		for(int j=0;j<length-1-i;j++){
            q=p->next;
			if(p->price<q->price){
                char temp_id[40],temp_name[60];
                double temp_price;
                strcpy(temp_id,p->ID);
                strcpy(temp_name,p->Name);
                temp_price=p->price;
                strcpy(p->ID,q->ID);
                strcpy(p->Name,q->Name);
                p->price=q->price;
                strcpy(q->ID,temp_id);
                strcpy(q->Name,temp_name);
                q->price=temp_price;
			}
            p=p->next;
		}
	}
}

void ClearList(LinkList head){
    LinkList last=head->next;
    while(last!=head){
        LinkList t=last;
        last->next=t->next;
        last=last->next;
        free(t);
    }
}

int IDTrans(char *id){
    int tr_id=0;
    for(int i=2;id[i]!='\0';i++){
        tr_id=tr_id*10+(id[i]-'0');
    }
    return tr_id;
}

int Length(LinkList head){
    int len=0;
    LinkList last=head->next;
    while(last!=head){
        len++;
        last=last->next;
    }
    return len;
}