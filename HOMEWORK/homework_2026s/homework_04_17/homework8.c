/*
8. 中序线索二叉树查找中序前驱和中序后继结点
【问题描述】

  请设计一个算法在中序线索二叉树上查找任意结点的中序前驱结点和中序后继结点。

【输入形式】

  第一行按根左子树右子树的顺序输入各结点的值，第二行输入待查找结点对应的值。

【输出形式】

  输出结点的中序前驱和中序后继结点对应的值，head结点的值用0表示。
【样例输入1】

  image.pngimage.png

AB#D##CF###
B
【样例输出1】

0 D

【样例输入2】

AB#D##CF###
C
【样例输出2】

F 0

【样例输入3】

AB#D##CF###
D
【样例输出3】

B A
【样例说明】

  样例输入1中给出二叉树以及中序线索化后的二叉树，供考生参考。

  请将下列代码粘贴至作答区域，并将函数 InPreNode 和 InPostNode 补充完整。

#include<stdio.h>
#include<stdlib.h>
 
// 在线索二叉树中，结点的结构定义
typedef char elemtype;
typedef struct BiThrNode
{
    int ltag;
    struct BiThrNode *lchild;
    elemtype data;
    int rtag;
    struct BiThrNode *rchild;
}BiThrNodeType, *BiThrTree;
 
void crt_tree(BiThrTree *bt)
{
    char ch;
    scanf("%c", &ch);
    if (ch == '#') *bt = NULL;
    else
    {
        *bt = (BiThrTree)malloc(sizeof(BiThrNodeType));
        (*bt)->data = ch;
        crt_tree(&(*bt)->lchild);
        crt_tree(&(*bt)->rchild);
    }
}
 
void InThreading(BiThrTree p, BiThrTree *pre)
{
    /* 中序遍历进行中序线索化 * /
    if (p)
    {
        InThreading(p->lchild, pre); /*左子树线索化* /
        if (!p->lchild) /*前驱线索* /
        {
            p->ltag = 1;
            p->lchild = *pre;
        }
        else
            p->ltag = 0;
        if (!(*pre)->rchild) /*后继线索* /
        {
            (*pre)->rtag = 1;
            (*pre)->rchild = p;
        }
        else
            (*pre)->rtag = 0;
        *pre = p;
        InThreading(p->rchild, pre); /*右子树线索化* /
    }
}
 
int InOrderThr(BiThrTree *head, BiThrTree T)
{
    /* 中序遍历二叉树 T，并将其中序线索化，*head 指向头结点 * / 
    /* 申请头结点的空间 * /
    if (!(*head = (BiThrTree)malloc(sizeof(BiThrNodeType)))) return 0;
    (*head)->ltag = 0; (*head)->rtag = 1; /* 建立头结点（虚拟）* /
    (*head)->rchild = *head; /*右指针回指* /
    BiThrTree pre;
    if (!T) (*head)->lchild = *head; /*若二叉树为空，则左指针回指* /
    else
    {
        (*head)->lchild = T;
        pre = *head;
        InThreading(T, &pre); /*中序遍历进行中序线索化* /
        pre->rchild = *head; /*最后一个结点线索化* /
        pre->rtag = 1;
        (*head)->rchild = pre;
    }
    return 1;
}

//查找中序前驱结点
BiThrTree InPreNode(BiThrTree p){
    //请在此处书写代码...
}

//查找中序后继结点
BiThrTree InPostNode(BiThrTree p)
{
    //请在此处书写代码...
}

BiThrTree Search(BiThrTree head,elemtype x){
    /*在以head为头结点的中序线索二叉树中查找值为x的结点* /
    BiThrTree p=head->lchild;
    while(p->ltag==0 && p!=head) p = p->lchild;
    while(p!=head && p->data!=x) p = InPostNode(p);
    if(p==head){
        printf("Not Found the data!\n");
        return (0);
    }else{
        return (p);
    }
}

int main()
{
    BiThrTree head, T;
    //按根左子树右子树的顺序输入
    crt_tree(&T);
    //中序线索化
    InOrderThr(&head, T);
    
    // 输入要查找的节点值
    elemtype target;
    scanf(" %c", &target);
    BiThrTree targetNode = Search(head, target);
    // 找到中序前驱和中序后继节点
    BiThrTree preNode = InPreNode(targetNode);
    BiThrTree postNode = InPostNode(targetNode);

    // 打印结果
    if (preNode != head) {
        printf("%c ", preNode->data);
    } else {
        printf("0 ");
    }
    if (postNode != head) {
        printf("%c\n", postNode->data);
    } else {
        printf("0\n");
    }
    return 0;
}
【评分标准】
*/

#include "stdio.h"
#include "stdlib.h"
#include "string.h"

typedef struct BTNode{
    char data;
    int ltag,rtag;
    struct BTNode *lchild;
    struct BTNode *rchild;
}BTNode,*BTTree;

void CreatTree(BTTree *T);
int InorderThr(BTTree *head,BTTree T);
void InThreading(BTTree T,BTTree *pre);
BTTree SearchNode(BTTree head,char target);
BTTree InPostNode(BTTree p);
BTTree InPreNode(BTTree p);

int main()
{
    BTTree head,T;
    CreatTree(&T);
    InorderThr(&head,T);

    char target;
    scanf(" %c",&target);
    BTTree TargetNode=SearchNode(head,target);
    BTTree PreNode=InPreNode(TargetNode);
    BTTree PostNode=InPostNode(TargetNode);

    if(PreNode!=head)printf("%c ",PreNode->data);
    else printf("0 ");
    if(PostNode!=head)printf("%c",PostNode->data);
    else printf("0");

    return 0;
}

void CreatTree(BTTree *T){
    char ch;
    scanf("%c",&ch);
    if(ch=='#')*T=NULL;
    else{
        (*T)=(BTTree)malloc(sizeof(BTNode));
        (*T)->data=ch;
        CreatTree(&(*T)->lchild);
        CreatTree(&(*T)->rchild);
    }
}

int InorderThr(BTTree *head,BTTree T){
    if(!(*head=(BTTree)malloc(sizeof(BTNode))))return 0;
    (*head)->ltag=(*head)->rtag=0;
    (*head)->rchild=(*head);
    if(!T){
        (*head)->lchild=(*head);
    }else{
        (*head)->lchild=T;
        BTTree pre=(*head);
        InThreading(T,&pre);
        pre->rchild=(*head);
        pre->rtag=1;
        (*head)->rtag=1;
        (*head)->rchild=pre;
    }
    return 1;
}

void InThreading(BTTree T,BTTree *pre){
    if(T){
        InThreading(T->lchild,pre);
        if(!T->lchild){
            T->lchild=(*pre);
            T->ltag=1;
        }else T->ltag=0;
        if(!(*pre)->rchild){
            (*pre)->rchild=T;
            (*pre)->rtag=1;
        }else (*pre)->rtag=0;
        (*pre)=T;
        InThreading(T->rchild,pre);
    }
}

BTTree SearchNode(BTTree head,char target){
    BTTree p=head->lchild;
    while(p->ltag==0 && p!=head) p = p->lchild;
    while(p!=head && p->data!=target) p = InPostNode(p);
    if(p==head){
        printf("Not Found the data!\n");
        return (0);
    }else{
        return (p);
    }
}

BTTree InPostNode(BTTree p){
    BTTree post=p->rchild;
    if(p->rtag==0){
        while(post->ltag==0)post=post->lchild;
    }
    return post;
}

BTTree InPreNode(BTTree p){
    BTTree pre=p->lchild;
    if(p->ltag==0){
        while(pre->ltag==0)pre=pre->lchild;
    }
    return pre;
}