/*
3. 中序线索二叉树的前序遍历
【问题描述】

  请设计一个算法实现中序线索二叉树的前序遍历。

【输入形式】

  按根左子树右子树的顺序输入各结点的值，空结点用 # 表示。

【输出形式】

  输出中序线索二叉树的前序遍历序列。
【样例输入】

  image.pngimage.png

AB#D##CF###
【样例输出】

ABDCF
【样例说明】

 样例输入中给出了二叉树以及对应的中序线索二叉树结构，供考生参考。

 请将下列代码粘贴至作答区域，并实现 IPrePostNode 与 ThpreIoOrder 函数。

 提示：可基于 查找结点的前序后继结点 实现 中序线索二叉树的前序遍历。

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
    /* 中序遍历二叉树 T，并将其中序线索化，*head 指向头结点 */
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
 

//在中序线索二叉树上寻找结点 p 的前序的后继结点
BiThrTree IPrePostNode(BiThrTree head, BiThrTree p)
{
    //请在此处书写代码...
}
 
  // 在中序线索二叉树上进行前序遍历 
void ThpreIoOrder(BiThrTree head)
{
    //请在此处书写代码... 
}

int main()
{
    BiThrTree head, T;
    //按根左子树右子树的顺序输入
    crt_tree(&T);
    //二叉树中序线索化
    InOrderThr(&head, T);
    //基于中序线索二叉树的前序遍历结果
    ThpreIoOrder(head);
    return 0;
}
*/

#include "stdio.h"
#include "stdlib.h"

typedef struct Node{
    char data;
    struct Node *lchild;
    struct Node *rchild;
    int lfalg;
    int rflag;
}CTNode,*CTree;

void CreateTree(CTree *root);
void InThreading(CTree p,CTree *pre);
int InorderThr(CTree *head,CTree T);
CTree InPrePostNode(CTree head,CTree p);
void ThpreInOrder(CTree head);

int main()
{
    CTree head,T;
    CreateTree(&T);
    InorderThr(&head,T);
    ThpreInOrder(head);

    return 0;
}

void CreateTree(CTree *root){
    char data;
    scanf("%c",&data);
    if(data=='\n')return;
    if(data=='#'){
        (*root)=NULL;
        return;
    }
    (*root)=(CTree)malloc(sizeof(CTNode));
    (*root)->data=data;
    CreateTree(&(*root)->lchild);
    CreateTree(&(*root)->rchild);
}

void InThreading(CTree p,CTree *pre){
    if(p){
        InThreading(p->lchild,pre);
        if(!p->lchild){
            p->lfalg=1;
            p->lchild=(*pre);
        }else{
            p->lfalg=0;
        }
        if(!(*pre)->rchild){
            (*pre)->rchild=p;
            (*pre)->rflag=1;
        }else{
            (*pre)->rflag=0;
        }
        (*pre)=p;
        InThreading(p->rchild,pre);
    }
}

int InorderThr(CTree *head,CTree T){
    if(!(*head=(CTree)malloc(sizeof(CTNode))))return 0;
    (*head)->lfalg=0;(*head)->rflag=1;
    (*head)->rchild=(*head);
    CTree pre;
    if(!T)(*head)->lchild=(*head);
    else{
        (*head)->lchild=T;
        pre=(*head);
        InThreading(T,&pre);
        pre->rchild=(*head);
        pre->rflag=1;
        (*head)->rchild=pre;
    }
    return 1;
}

CTree InPrePostNode(CTree head,CTree p){
    CTree post;
    if(p->lfalg==0)post=p->lchild;
    else{
        post=p;
        while(post->rflag==1&&post->rchild!=head)post=post->rchild;
        post=post->rchild;
    }
    return post;
}

void ThpreInOrder(CTree head){
    CTree p=head->lchild;
    while(p!=head){
        printf("%c",p->data);
        p=InPrePostNode(head,p);
    }
}