/*
1. 用户电价管理（循环单链表）B题
【问题描述】

        电价的设定通常受到多种因素的影响，包括：国家和地区的政策、能源结构、经济发展水平、成本分配以及电力供需关系等。为了促进电力资源的优化分配以及能源的高效合理利用，通常会根据用户的类型设置不同的电费。

        我国某地区通过补贴农业用电来支持农业发展，保障粮食安全，促进农村经济稳定增长。同时，支持制造业和工业生产的政策导向，以减少生产成本，增强企业的竞争力，促进经济发展。假设该地区不同用户类型及电费计价信息如下：

        居民（ID101，Residential，0.50），工业（ID102，Industrial，0.60），商业（ID103，Commercial，0.70），农业（ID104，Agricultural, 0.20），公共事业（ID 105, PublicUtility 0.30）；

        若采用循环单链表对用户计价信息进行管理，每个链表结点代表一种用户类型，包含用户类型编号、用户类型名称、电价。实现以下操作：


             1.    创建：输入上述数据，创建一个带头结点的循环单链表；

             2.    输出：顺序输出所有用户类型电价信息；

             3.    删除：按用户类型名，删除一条电价信息；

             4.    插入：按编号顺序插入一条电价信息；

             5.    查找：根据用户类型，查找并返回该用户类型的电价；

             6.    更新：根据用户类型，更新其电价信息；如果该用户类型不存在，则提示错误。

             7.    排序：按照电价从高到低排序。

        注：i插入操作;d删除操作;f查找操作;u更新操作;s排序操作;q退出程序；所有浮点数输出保留两位小数。


插入操作：

【样例输入】

i
ID101 Residential 0.50
i
ID102 Industrial 0.60
i
ID103 Commercial 0.70
i
ID104 Agricultural 0.20
i
ID105 PublicUtility 0.30

【样例输出】

ID101 Residential 0.50

ID101 Residential 0.50->ID102 Industrial 0.60

ID101 Residential 0.50->ID102 Industrial 0.60->ID103 Commercial 0.70

ID101 Residential 0.50->ID102 Industrial 0.60->ID103 Commercial 0.70->ID104 Agricultural 0.20

ID101 Residential 0.50->ID102 Industrial 0.60->ID103 Commercial 0.70->ID104 Agricultural 0.20->ID105 PublicUtility 0.90

删除操作：

【样例输入】

d
Agricultural

【样例输出】

ID101 Residential 0.50->ID102 Industrial 0.30->ID103 Commercial 0.70->ID105 PublicUtility 0.30

查找操作：

【样例输入】

f
Commercial

【样例输出】

0.70

更新操作：

【样例输入】

u
Industrial 0.55

【样例输出】

ID101 Residential 0.50->ID102 Industrial 0.55->ID103 Commercial 0.70->ID105 PublicUtility 0.30

排序操作：

【样例输入】

s

【样例输出】


ID103 Commercial 0.70->ID102 Industrial 0.55->ID101 Residential 0.50->ID105 PublicUtility 0.30

程序退出操作：

【样例输入】

q

【样例输出】

程序退出




*/

#include "stdio.h"
#include "stdlib.h"
#include "string.h"

typedef struct Node{
	char ID[40];
	char Name[60];
	double price;
	struct Node *next;
}Node,*LinkList;

void InitList(LinkList *L);
void CreatNode(LinkList head);
void DeleteNode(LinkList head,char targetname[60]);
void UpdataNode(LinkList head,char targetname[60],double price1);
void PrintList(LinkList head);
void FindNode(LinkList head,char name1[60]);
void ShunList(LinkList head,int length);
void ClearList(LinkList head);
int IDtrans(char id[40]);
int Length(LinkList head);

int main()
{
	LinkList head;
	InitList(&head);
	char choice;
	while(1){
		scanf(" %c",&choice);
		switch(choice){
			case 'i':
				CreatNode(head);
				PrintList(head);
				break;
			case 'd':
				{
					char name[60];
					scanf(" %s",name);
					DeleteNode(head,name);
					PrintList(head);
					break;
				}
			case 'f':
				{
					char name[60];
					scanf(" %s",name);
					FindNode(head,name);
					break;
				}
			case 'u':
				{
					char name[40];
					double price;
					scanf(" %s %lf",name,&price);
					UpdataNode(head,name,price);
					PrintList(head);
					break;
				}
			case 's':
				{
					int length=Length(head);
					ShunList(head,length);
					PrintList(head);
					break;
				}
			case 'q':
				{
					printf("程序退出\n");
					ClearList(head);
					exit(0);
				}
		}
	}
	
	return 0;
}


void InitList(LinkList *L){
	(*L)=(LinkList)malloc(sizeof(Node));
	(*L)->next=(*L);
}

void CreatNode(LinkList head){
	LinkList last=head;
	LinkList new1=(LinkList)malloc(sizeof(Node));
	scanf(" %s",new1->ID);
	scanf(" %s",new1->Name);
	scanf("%lf",&new1->price);
	int new_id=IDtrans(new1->ID);
	while(last->next!=head){
		int last_id=IDtrans(last->next->ID);
		if(new_id<=last_id)break;
		last=last->next;
	}
	new1->next=last->next;
	last->next=new1;
}

void DeleteNode(LinkList head,char targetname[60]){
	LinkList last=head;
	while(last->next!=head){
		if(strcmp(last->next->Name,targetname)==0){
			LinkList t=last->next;
			last->next=t->next;
			free(t);
			return;
		}
		last=last->next;
	}
}

void UpdataNode(LinkList head,char targetname[60],double price1){
	LinkList last=head->next;
	while(last!=head){
		if(strcmp(last->Name,targetname)==0){
			last->price=price1;
		}
		last=last->next;
	}
}

void PrintList(LinkList head){
	LinkList last=head->next;
	while(last!=head){
		printf("%s %s %.2f",last->ID,last->Name,last->price);
		last=last->next;
		if(last!=head)printf("->");
	}
	printf("\n");
}

void FindNode(LinkList head,char name1[60]){
	LinkList last=head->next;
	while(last!=head){
		if(strcmp(last->Name,name1)==0){
			printf("%.2f\n",last->price);
			return;
		}
		last=last->next;
	}
}

int IDtrans(char id[40]){
	int id_num=0;
	for(int i=2;id[i]!='\0';i++){
		id_num=id_num*10+(id[i]-'0');
	}
	return id_num;
}


void ShunList(LinkList head,int length){
	if(length<=1)return;
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
	LinkList last=head;
	while(last->next!=head){
		LinkList t=last->next;
		last->next=t->next;
		free(t);
	}
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
