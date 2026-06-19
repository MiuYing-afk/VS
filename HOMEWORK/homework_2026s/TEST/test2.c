/*
1. 电力系统二叉树
【问题描述】

    电力系统是一个庞大的、所跨地域辽阔的系统，为了保证安全可靠的运行，世界各国电力系统都采用分层调度控制，全系统的监视控制任务分属于不同层次，下一层调度组织除完成本层次的调度控制任务外，还要接受上一层调度组织的调度命令并向其传送有关的信息。《国际电工委员会标准》提出典型分层结构，将电力系统调度中心分为主调度中心、区域调度中心及地区调度中心。这些相当于中国的网调、省调和地调。因此分层控制和调度组织结构是相适应的。尤其是调度控制任务有全网性的亦有局部性的，大量的局部性的调度控制任务可以由下层相应的调度机构来完成，而全网性或跨地区性的调度可以由上层相应调度机构来完成，这样便于协调和平衡，也压缩了信息量的传输和处理，提高了调度效能。

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

§  分调度中心B（BDC_B）

·       区域调度中心E（ADC_E）

·       区域调度中心F（ADC_F）

o   配电网总调度中心（DG_MDC）

§  分调度中心G（BDC_G）

·       区域调度中心H（ADC_H）

·       区域调度中心I（ADC_I）

§  分调度中心J（BDC_J）

·       区域调度中心K （ADC_K）

·       区域调度中心L （ADC_L）

注：i 插入操作；d 删除操作；f 查找操作；c 创建操作；p 输出操作；q 程序退出操作。

创建操作：

【样例输入】

c
EPG PG_MDC BDC_A ADC_C # # ADC_D # # BDC_B ADC_E # # ADC_F # # DG_MDC BDC_G ADC_H # # ADC_I # # BDC_J ADC_K # # ADC_L # #
p
【样例输出】

EPG
---PG_MDC     
------BDC_A   
---------ADC_C
---------ADC_D
------BDC_B   
---------ADC_E
---------ADC_F
---DG_MDC     
------BDC_G   
---------ADC_H
---------ADC_I
------BDC_J
---------ADC_K
---------ADC_L
删除操作：

【样例输入】

c
EPG PG_MDC BDC_A ADC_C # # ADC_D # # BDC_B ADC_E # # ADC_F # # DG_MDC BDC_G ADC_H # # ADC_I # # BDC_J ADC_K # # ADC_L # #
d
ADC_H
p
【样例输出】

EPG
---PG_MDC
------BDC_A
---------ADC_C
---------ADC_D
------BDC_B
---------ADC_E
---------ADC_F
---DG_MDC
------BDC_G
---------ADC_I
------BDC_J
---------ADC_K
---------ADC_L
插入操作：

【样例输入】

c
EPG PG_MDC BDC_A ADC_C # # ADC_D # # BDC_B ADC_E # # ADC_F # # DG_MDC BDC_G ADC_H # # ADC_I # # BDC_J ADC_K # # ADC_L # #
i
BDC_J ADC_M
p
注：插入区域调度中心M（ADC_M）到分调度中心J（BDC_J）之下，若该结点孩子节点已满，则无法插入。

【样例输出】

EPG
---PG_MDC     
------BDC_A   
---------ADC_C
---------ADC_D
------BDC_B   
---------ADC_E
---------ADC_F
---DG_MDC     
------BDC_G   
---------ADC_H
---------ADC_I
------BDC_J
---------ADC_K
---------ADC_L
查找操作：（输出该机构隶属的所有上层机构）

【样例输入】

c
EPG PG_MDC BDC_A ADC_C # # ADC_D # # BDC_B ADC_E # # ADC_F # # DG_MDC BDC_G ADC_H # # ADC_I # # BDC_J ADC_K # # ADC_L # #
f
ADC_H
【样例输出】

EPG->DG_MDC->BDC_G->ADC_H

退出操作：

【样例输入】

q
【样例输出】

程序退出
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
				DeleteNode(temp);
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
		char str[40];
		scanf(" %s",str);
		if(root->lchild==NULL){
			root->lchild=(BTTree)malloc(sizeof(BTNode));
			strcpy(root->lchild->Name,str);
			root->lchild->lchild=root->lchild->rchild=NULL;
			(*flag)=0;
			return;
		}
		if(root->rchild==NULL){
			root->rchild=(BTTree)malloc(sizeof(BTNode));
			strcpy(root->rchild->Name,str);
			root->rchild->lchild=root->rchild->rchild=NULL;
			(*flag)=0;
			return;
		}
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
            root->lchild=NULL;
            (*flag)=0;
            return;
        }
    }
	if(root->rchild){
        if(strcmp(root->rchild->Name,target)==0){
            (*T)=root->rchild;
            root->rchild=NULL;
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
	PrintTree(T->rchild,level+1);
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

	if(root!=NULL){
		Push(*S,root);

		if(!root->lchild&&!root->rchild){
			if(strcmp(root->Name,target)==0){
				PrintStack(*S);
				(*flag)=0;
			}
		}else{
			Print(root->lchild,S,target,flag);
			if(*flag!=0)Print(root->rchild,S,target,flag);
		}

		Pop(*S);
	}
}
