/*
1. 负荷数据管理（二叉树）
【问题描述】

随着智能电网的发展，电力公司需要对不同类型用户的电价信息以及实时用电负荷进行统一管理与分析，从而实现电力资源的优化配置与精细化调度。某地区电网公司建立了一套简化的管理系统，实现以下功能：

负荷数据管理（二叉树）
为了分析电网负荷情况，系统使用二叉链表（构成 BST）存储用户的实时负荷数据。每个结点包含：

用户编号（UserID，整数）

当前负荷（Load，单位：kW）

构建规则：

按用户编号插入，满足 BST 性质

系统需要支持以下操作：

1）初始化（i）：初始化构造二叉链表存储所有用户的负荷数据（插入后不进行输出，提示“插入成功”）

2）遍历（t）：中序遍历输出（按用户编号升序）

3）查找（f）：按用户编号查找负荷

4）删除（d）：删除指定用户结点为根节点的二叉树

5）统计（a）：计算平均负荷（保留两位小数）

6）最大负荷（m）：输出负荷最大的用户编号及其负荷

系统按指令执行操作：

指令	含义
i	插入
d	删除
f	查找
t	遍历（二叉树）
a	平均负荷（二叉树）
m	最大负荷（二叉树）
q	退出
【输入形式】

输入为多组操作指令：

每行输入一个操作符

随后输入对应数据

操作持续进行，直到输入 q 结束

【输出形式】

查找：

成功输出数值

失败输出：Not Found

二叉树遍历：

1001 50 1002 60 1003 80
平均负荷：保留两位小数

最大负荷：

1003 80
退出：

程序退出
【样例输入】

i

1001 50

i

1003 80

i

1002 60

f

1002

f

9999

t

a

m

d

1002

q

【样例输出】

插入成功

插入成功

插入成功

60

Not Found

1001 50 1002 60 1003 80

63.33

1003 80

1001 50 1003 80

程序退出

【样例说明】

插入形成 BST

中序遍历结果为升序

平均负荷：

(50+80+60)/3 = 63.33
【评分标准】

项目	分值
BST 结构设计	20%
二叉树的增删改查	30%
二叉树的遍历
15%
平均负荷和最大负荷的计算	15%
输入输出规范	20%

*/

#include "stdio.h"
#include "stdlib.h"
#include "string.h"

typedef struct Node{
	int userID;
	int Load;
	struct Node *lchild;
	struct Node *rchild;
}BTNode,*BTTree;

void InsertNode(BTTree *root,int id,int load,int *flag);
void FindNode(BTTree root,int id);
int Delete_Node(BTTree *root, int id);
void DeleteNode(BTTree *root,int id);
void DeleteTree(BTTree root);
void Average(BTTree root,int *sum,int *num);
void MaxLoad(BTTree root,int *id,int *load);
void PrintTree(BTTree root,int *first);

int main()
{
	BTTree root=NULL;
	char choice;
	while(1){
		scanf(" %c",&choice);
		switch(choice){
			case 'i':{
				int id,load,flag=1;
				scanf("%d%d",&id,&load);
				InsertNode(&root,id,load,&flag);
				break;
			}
			case 'd':{
				int id;
				scanf("%d",&id);
				Delete_Node(&root,id);
				break;
			}
			case 'f':{
				int id;
				scanf("%d",&id);
				FindNode(root,id);
				break;
			}
			case 't':{
				int first = 1;
				PrintTree(root, &first);
				printf("\n");
				break;
			}
			case 'a':{
				int sum=0,num=0;
				Average(root,&sum,&num);
				if(num!=0){
					float ave=sum*1.0/num;
					printf("%.2f\n",ave);
				}
				break;
			}
			case 'm':{
				int id=root->userID;
				int load=root->Load;
				MaxLoad(root,&id,&load);
				printf("%d %d\n",id,load);
				break;
			}
			case 'q':{
				DeleteTree(root);
				printf("程序退出");
				exit(0);
				break;
			}
			default:{
			}
		}
	}
	return 0;
}

void InsertNode(BTTree *root,int id,int load,int *flag){
	if(*flag==0)return;
	if(*root==NULL){
		(*root)=(BTTree)malloc(sizeof(BTNode));
		(*root)->userID=id;
		(*root)->Load=load;
		(*root)->lchild=(*root)->rchild=NULL;
		(*flag)=0;
		printf("插入成功\n");
		return;
	}else{
		if(id>(*root)->userID)InsertNode(&(*root)->rchild,id,load,flag);
		else InsertNode(&(*root)->lchild,id,load,flag);
	}
}

void FindNode(BTTree root,int id){
	if(root==NULL){
		printf("Not Found\n");
		return;
	}
	if(root->userID==id){
		printf("%d\n",root->Load);
		return;
	}
	if(id>root->userID)FindNode(root->rchild,id);
	else FindNode(root->lchild,id); 
}

int Delete_Node(BTTree *root, int id){
	BTTree p, q;
	if (*root == NULL)
		return 0;

	if (id < (*root)->userID)
	{
		return Delete_Node(&(*root)->lchild, id);
	}
	else if (id > (*root)->userID)
	{
		return Delete_Node(&(*root)->rchild, id);
	}
	else
	{
		if ((*root)->lchild == NULL)
		{
			p = *root;
			*root = (*root)->rchild;
			free(p);
		}
		else if ((*root)->rchild == NULL)
		{
			p = *root;
			*root = (*root)->lchild;
			free(p);
		}
		else
		{
			p = *root;
			q = (*root)->lchild;
			while (q->rchild != NULL)
			{
				p = q;
				q = q->rchild;
			}
			(*root)->userID = q->userID;
			(*root)->Load = q->Load;

			if (p != *root)
				p->rchild = q->lchild;
			else
				p->lchild = q->lchild;
			free(q);
		}
		return 1;
	}
}

void DeleteNode(BTTree *root,int id){
	BTTree target=*root,last=NULL;
	int tag=-1;
	while(target&&target->userID!=id){
		last=target;
		if(id>target->userID){
			target=target->rchild;
			tag=1;
		}else{
			target=target->lchild;
			tag=0;
		}
	}
	
	if(target==NULL)return;
	if(last==NULL)(*root)=NULL;
	else if(tag==0)last->lchild=NULL;
	else last->rchild=NULL;
	DeleteTree(target);
	
}

void DeleteTree(BTTree root){
	if(root==NULL)return;
	DeleteTree(root->lchild);
	DeleteTree(root->rchild);
	free(root);
}

void Average(BTTree root,int *sum,int *num){
	if(root==NULL)return;
	(*sum)+=root->Load;
	(*num)++;
	Average(root->lchild,sum,num);
	Average(root->rchild,sum,num);
}

void MaxLoad(BTTree root,int *id,int *load){
	if(root==NULL)return;
	if(root->Load>*load){
		(*id)=root->userID;
		(*load)=root->Load;
	}
	MaxLoad(root->lchild,id,load);
	MaxLoad(root->rchild,id,load);
}

void PrintTree(BTTree root,int *first){
    if(root==NULL)return;
    PrintTree(root->lchild,first);
    if(*first)
    {
        printf("%d %d",root->userID,root->Load);
        *first = 0;
    }
    else
    {
        printf(" %d %d",root->userID,root->Load);
    }
    PrintTree(root->rchild,first);
}

