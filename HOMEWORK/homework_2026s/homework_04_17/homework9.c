/*
9. 中序线索二叉树的后序遍历
【问题描述】

  请设计一个算法实现中序线索二叉树的后序遍历。

【输入形式】

  按根左子树右子树的顺序输入各结点的值，空结点用 # 表示。

【输出形式】

  输出中序线索二叉树的后序遍历序列。
【样例输入】

  image.pngimage.png

AB#D##CF###
【样例输出】

DBFCA
【样例说明】

 样例输入中给出了二叉树以及对应的中序线索二叉树结构，供考生参考。

 请将下列代码粘贴至作答区域，并实现 IPostPreNode 和 ThpostIoOrder 函数。

 提示：可基于 查找结点的后序前驱结点 实现 中序线索二叉树的后序遍历。

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
 
BiThrTree IPostPreNode(BiThrTree head, BiThrTree p)
{
    /* 在中序线索二叉树上寻找结点 p 的后序的前驱结点, head 为线索树的头结点 * /
    // 请在此处书写代码...
}
 
void ThpostIoOrder(BiThrTree head)
{
    /* 在中序线索二叉树上进行后序遍历* /
    // 请在此处书写代码...
}

int main()
{
    BiThrTree head, T;
    //按根左子树右子树的顺序输入
    crt_tree(&T);
    //二叉树中序线索化
    InOrderThr(&head, T);
    //基于中序线索二叉树的后序遍历结果
    ThpostIoOrder(head);
    return 0;
}

*/

#include "stdio.h"
#include "string.h"
#include "stdlib.h"

typedef struct BTNode{
    char data;
    int ltag,rtag;
    struct BTNode *lchild;
    struct BTNode *rchild;
}BTNode,*BTTree;

void CreatTree(BTTree *T);
int InOrderThr(BTTree *head,BTTree T);
void InThreading(BTTree T,BTTree *pre);
void Print(BTTree T);
BTTree InpostNode(BTTree T);

int main()
{
    BTTree head,T;
    CreatTree(&T);
    InOrderThr(&head,T);
    Print(T);

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

int InOrderThr(BTTree *head,BTTree T){
    if(!(*head=(BTTree)malloc(sizeof(BTNode))))return 0;
    (*head)->ltag=0;
    (*head)->rtag=1;
    (*head)->rchild=(*head);
    if(!T){
        (*head)->lchild=(*head);
    }else{
        (*head)->lchild=T;
        BTTree pre=(*head);
        InThreading(T,&pre);
        pre->rchild=(*head);
        pre->rtag=1;
        (*head)->rchild=pre;
        (*head)->rtag=1;
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

BTTree InpostNode(BTTree T){
    BTTree post=T->rchild;
    if(T->ltag==0){
        while(post->ltag==0)post=post->lchild;
    }
    return post;
}

void Print(BTTree T){
    if(T==NULL)return;
    if(T->ltag==0)Print(T->lchild);
    if(T->rtag==0)Print(T->rchild);
    printf("%c",T->data);
}