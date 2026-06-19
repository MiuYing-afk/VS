/*
1. 电力系统树
【问题描述】

电力系统是一个庞大且复杂的系统，为了保证安全可靠的运行，世界各国电力系统都采用分层调度控制。全系统的监视控制任务分属于不同层次，下一层调度组织除完成本层次的调度控制任务外，还要接受上一层调度组织的调度命令并向其传送有关的信息。电力系统调度中心分为主调度中心、区域调度中心及地区调度中心，这些调度中心之间的关系可以用树形结构表示。

为了更好地管理电力系统的调度中心，我们采用孩子兄弟表示法来存储和操作这棵树。每个节点存储两个指针：一个指向其第一个孩子节点，另一个指向其下一个兄弟节点。


    以下是一个调度组织示意图，请完成数据的存储、插入、删除、查找、输出功能。提示：需要存储的为字符串类型,可用英文。

生产网：Production Grid，PG

配电网：Distribution Grid，DG

总调度中心：Main Dispatch Center，MDC

分调度中心：Branch Dispatch Center，BDC

区域调度中心：Area Dispatch Center，ADC

§  总部（Entire Power Grid，EPG）

o   输电网总调度中心（PG_MDC）

§  分调度中心A（BDC_A）

·       区域调度中心C （ADC_C）

·       区域调度中心D （ADC_D）

·       区域调度中心D （ADC_E）

§  分调度中心B（BDC_B）

·       区域调度中心E（ADC_F）

·       区域调度中心F（ADC_G）

o   配电网总调度中心（DG_MDC）

§  分调度中心G（BDC_H）

·       区域调度中心H（ADC_I）

·       区域调度中心I（ADC_J）

·       区域调度中心I（ADC_K）

§  分调度中心J（BDC_L）

·       区域调度中心K （ADC_M）

·       区域调度中心L （ADC_N）

操作要求
需要实现以下功能：

创建操作（c）：根据输入的节点序列构建树。

插入操作（i）：在指定的父节点下插入一个子节点。

删除操作（d）：删除指定的节点及其所有子节点。

查找操作（f）：查找指定节点的所有上层节点（从根节点到该节点的路径）。

输出操作（p）：按照层次顺序输出树的结构。

退出操作（q）：退出程序。

注意：每个操作的测试都是独立的，因此每个操作的输入中都包含创建操作。

创建操作
【样例输入】

c
EPG PG_MDC BDC_A ADC_C # ADC_D # ADC_E # # BDC_B ADC_F # ADC_G # # # DG_MDC BDC_H ADC_I # ADC_J # ADC_K # # BDC_L ADC_M # ADC_N # # # # #
p
【样例输出】

EPG
---PG_MDC
------BDC_A
---------ADC_C
---------ADC_D
---------ADC_E
------BDC_B
---------ADC_F
---------ADC_G
---DG_MDC
------BDC_H
---------ADC_I
---------ADC_J
---------ADC_K
------BDC_L
---------ADC_M
---------ADC_N
删除操作
【样例输入】

c
EPG PG_MDC BDC_A ADC_C # ADC_D # ADC_E # # BDC_B ADC_F # ADC_G # # # DG_MDC BDC_H ADC_I # ADC_J # ADC_K # # BDC_L ADC_M # ADC_N # # # # #
d
BDC_H
p
【样例输出】

EPG
---PG_MDC
------BDC_A
---------ADC_C
---------ADC_D
---------ADC_E
------BDC_B
---------ADC_F
---------ADC_G
---DG_MDC
------BDC_L
---------ADC_M
---------ADC_N
插入操作
【样例输入】

c
EPG PG_MDC BDC_A ADC_C # ADC_D # ADC_E # # BDC_B ADC_F # ADC_G # # # DG_MDC BDC_H ADC_I # ADC_J # ADC_K # # BDC_L ADC_M # ADC_N # # # # #
i
BDC_L ADC_O
p
【样例输出】

EPG
---PG_MDC
------BDC_A
---------ADC_C
---------ADC_D
---------ADC_E
------BDC_B
---------ADC_F
---------ADC_G
---DG_MDC
------BDC_H
---------ADC_I
---------ADC_J
---------ADC_K
------BDC_L
---------ADC_M
---------ADC_N
---------ADC_O
查找操作
【样例输入】

c
EPG PG_MDC BDC_A ADC_C # ADC_D # ADC_E # # BDC_B ADC_F # ADC_G # # # DG_MDC BDC_H ADC_I # ADC_J # ADC_K # # BDC_L ADC_M # ADC_N # # # # #
f
ADC_K
【样例输出】

EPG->DG_MDC->BDC_H->ADC_K
退出操作
【样例输入】

q
【样例输出】

程序退出
【样例说明】

上述操作的样例输入中结点序列以孩子兄弟表示法下的先序遍历序列给出，其中空结点用 # 表示，

例如某结点后接连续两个 # 表示 该结点为叶子结点且无右兄弟。


*/

#include "stdio.h"
#include "stdlib.h"
#include "string.h"

typedef struct Node{
	char Name[40];
	struct Node *lchild;
	struct Node *rchild;
}BTNode,*BTTree;

typedef struct SNode{
	BTTree data[60];
	int top;
}SNode,*Stack;

void BuildTree(BTTree *T);
void InsertNode(BTTree root,char *target,int *flag);
void FindNode(BTTree root,BTTree *T,char *target,int *flag);
void DeleteNode(BTTree root);
void PrintTree(BTTree T,int level);

void InitStacK(Stack *S);
int Pop(Stack S);
int Push(Stack S,BTTree T);
void PrintStack(Stack S);
void Print(BTTree root,Stack *S,char *target,int *flag);

int main()
{
	char choice;
	BTTree root;
	
	while(1){
		scanf(" %c",&choice);
		switch(choice){
			case 'i':{
				char tname[40];
				int flag=1;
				scanf(" %s",tname);
				InsertNode(root,tname,&flag);
				break;
			}
			case 'd':{
				char tname[40];
				int flag=1;
				BTTree temp=NULL;
				scanf(" %s",tname);
				FindNode(root,&temp,tname,&flag);
				if(temp!=NULL){
					DeleteNode(temp->lchild);
					free(temp);
				}
				break;
			}
			case 'f':{
				char tname[40];
				int flag=1;
				Stack S;
				InitStacK(&S);
				scanf(" %s",tname);
				Print(root,&S,tname,&flag);
				break;
			}
			case 'c':{
				BuildTree(&root);
				break;
			}
			case 'p':{
				PrintTree(root,0);
				break;
			}
			case 'q':{
				printf("程序退出\n"); 
				exit (0);
			}
			
		}
		
	}
	return 0;
}

void BuildTree(BTTree *T){
	BTTree new=(BTTree)malloc(sizeof(BTNode));
	scanf(" %s",new->Name);
	if(strcmp(new->Name,"#")==0){
		(*T)=NULL;
		free(new);		
		return;
	}
	
	new->lchild=NULL;
	new->rchild=NULL;
	(*T)=new;
	BuildTree(&(*T)->lchild);
	BuildTree(&(*T)->rchild);
}

void InsertNode(BTTree root,char *target,int *flag){
	if(*flag==0)return;
	if(root==NULL)return;
	if(strcmp(root->Name,target)==0){
		BTTree new=(BTTree)malloc(sizeof(BTNode));
		scanf(" %s",new->Name);
		new->lchild=new->rchild=NULL;
		BTTree child=root->lchild;
		while(child->rchild){
			child=child->rchild;
		}
		child->rchild=new;
		(*flag)=0;
	}
	InsertNode(root->lchild,target,flag);
	if(*flag==0)return;
	InsertNode(root->rchild,target,flag);
}

void FindNode(BTTree root,BTTree *T,char *target,int *flag){
	if(*flag==0)return;
	if(root==NULL)return;
	if(root->lchild){
        if(strcmp(root->lchild->Name,target)==0){
            (*T)=root->lchild;
            root->lchild=root->lchild->rchild;
            (*flag)=0;
            return;
        }
    }
	if(root->rchild){
        if(strcmp(root->rchild->Name,target)==0){
            (*T)=root->rchild;
            root->rchild=root->rchild->rchild;
            (*flag)=0;
            return;
        }
    }
	if(*flag==0)return;
	FindNode(root->lchild,T,target,flag);
	if(*flag==0)return;
	FindNode(root->rchild,T,target,flag);
}

void DeleteNode(BTTree root){
	if(root==NULL)return;
	DeleteNode(root->lchild);
	DeleteNode(root->rchild);
	free(root);
}

void PrintTree(BTTree T,int level){
	if(T==NULL)return;
	int i=0;
	for(;i<level;i++){
		printf("---");
	}
	printf("%s\n",T->Name);
	PrintTree(T->lchild,level+1);
	PrintTree(T->rchild,level);
}

void InitStacK(Stack *S){
	(*S)=(Stack)malloc(sizeof(SNode));
	(*S)->top=-1;
}

int Pop(Stack S){
	if(S->top==-1)return 0;
	S->top--;
	return 1;
}

int Push(Stack S,BTTree T){
	if(S->top==59)return 0;
	S->data[++S->top]=T;
	return 1;
}

void PrintStack(Stack S){
    for (int i = 0; i <=S->top; i++) {
        printf("%s",S->data[i]->Name);
		if(i<S->top)printf("->");
    }
	printf("\n");
}

void Print(BTTree root,Stack *S,char *target,int *flag){
	if(*flag==0)return;

	if(root){
		Push(*S,root);
		if(strcmp(root->Name,target)==0){
			PrintStack(*S);
			(*flag)=0;
			return;
		}
		if(*flag==0)return;
		if(root->lchild){
			Print(root->lchild,S,target,flag);
		}
		if(*flag==0)return;
		Pop(*S);
		if(root->rchild){
			Print(root->rchild,S,target,flag);
		}
	}
}
