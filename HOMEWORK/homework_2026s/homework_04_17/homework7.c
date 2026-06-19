/*
7. 中序线索二叉树插入结点
【问题描述】

  请设计一个算法在中序线索二叉树中插入结点p使其成为结点s的右孩子。

【输入形式】

  第一行按根左子树右子树的顺序输入各结点的值，第二行依次输入结点p、结点s对应的值。

【输出形式】

  输出插入结点p之后中序遍历线索二叉树所得各结点的值以及对应的左右线索标志值。
【样例输入1】

  image.pngimage.png

AB#D##CF###
E C
【样例输出1】

B 1 0
D 1 1
A 0 0
F 1 1
C 0 0
E 1 1

【样例输入2】

AB#D##CF###
E B
【样例输出2】

B 1 0
E 1 0
D 1 1
A 0 0
F 1 1
C 0 0
【样例说明】

  样例输入1中给出二叉树以及中序线索化后的二叉树，供考生参考。

  请将下列代码粘贴至作答区域，并将函数 InsertThrRight 补充完整。

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

BiThrTree InPostNode(BiThrTree p)
{
    /* 在中序线索二叉树上寻找结点 p 的中序后继结点 * /
    BiThrTree post;
    post = p->rchild;
 
    // 如果是线索，直接返回右子树的后继节点
    if (p->rtag == 1)
        return post;
    
    // 否则, 继续寻找右子树的最左边节点
    while (post->ltag == 0) {
        post = post->lchild;
    }
    return post;
}

void ThIoOrder(BiThrTree head)
{
    /* 在中序线索二叉树上进行中序遍历 * /
    BiThrTree p = head->lchild;
    // 如果头结点的左孩子是头结点本身，则说明树为空
    if (p == head) return;
    // 找到第一个节点
    while (p->ltag == 0) {
        p = p->lchild;
    }
    // 开始中序遍历
    while (p != head) {
        printf("%c %d %d\n", p->data, p->ltag, p->rtag);
        p = InPostNode(p); // 找到下一个中序后继节点
    }
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

void InsertThrRight(BiThrTree s,BiThrTree p){
    //请在此处填写代码...
}

int main()
{
    BiThrTree head, T;
    //按根左子树右子树的顺序输入
    crt_tree(&T);
    //中序线索化
    InOrderThr(&head, T);
    
    // 输入结点p的值
    elemtype p_value;
    scanf(" %c", &p_value);
    BiThrTree pNode = Search(head, p_value);
    getchar();
    // 输入结点s的值
    elemtype s_value;
    scanf(" %c", &s_value);
    BiThrTree sNode = Search(head, s_value);
    
    // 插入结点p使其成为结点s的右孩子
    InsertThrRight(sNode, pNode);

    // 中序遍历线索二叉树
    ThIoOrder(BiThrTree head)；
   
    return 0;
}

*/

#include "stdio.h"
#include "string.h"
#include "stdlib.h"

typedef struct BTNode{
    char data;
    int ltag,rtag;
    struct BTNode* lchild;
    struct BTNode* rchild;
}BTNode,*BTTree;

void CreatTree(BTTree *T);
int InorderThr(BTTree *head,BTTree T);
void InThreading(BTTree T,BTTree *pre);
BTTree Search(BTTree head,char pa);
BTTree CreatNode(char ch);
void InsertRNode(BTTree pa_node,BTTree ch_node);
void PrintBTTree(BTTree head);

int main()
{
    BTTree head,T;
    CreatTree(&T);
    InorderThr(&head,T);

    char pa,ch;
    scanf(" %c %c",&ch,&pa);
    BTTree pa_node=Search(head,pa);
    BTTree ch_node=CreatNode(ch);
    InsertRNode(pa_node,ch_node);
    PrintBTTree(head);

    return 0;
}

void CreatTree(BTTree *T){
    char ch;
    scanf("%c",&ch);
    if(ch=='#')*T=NULL;
    else{
        *T=(BTTree)malloc(sizeof(BTNode));
        (*T)->data=ch;
        CreatTree(&(*T)->lchild);
        CreatTree(&(*T)->rchild);
    }
}


int InorderThr(BTTree *head,BTTree T){
    if(!(*head=(BTTree)malloc(sizeof(BTNode))))return 0;
    (*head)->ltag=0;
    (*head)->rtag=0;
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

BTTree Search(BTTree head,char pa){
    BTTree p=head->lchild;
    while(p->ltag==0&&p!=head)p=p->lchild;
    while(p!=head&&p->data!=pa){
        if(p->rtag==1){
            p=p->rchild;
        }else{
            p=p->rchild;
            while(p->ltag==0)p=p->lchild;
        }
    }
    if(p==head){
        printf("Not Found the data!\n");
        return (0);
    }else{
        return p;
    }
}

BTTree CreatNode(char ch){
    BTTree new;
    if(!(new=(BTTree)malloc(sizeof(BTNode))))return NULL;
    new->data=ch;
    new->lchild=new->rchild=NULL;
    new->ltag=new->rtag=1;
    return new;
}

void InsertRNode(BTTree pa_node,BTTree ch_node){
    ch_node->rchild=pa_node->rchild;
    ch_node->rtag=pa_node->rtag;
    ch_node->lchild=pa_node;
    if(pa_node->rchild->ltag==1){
        pa_node->rchild->lchild=ch_node;
    }
    pa_node->rchild=ch_node;
    pa_node->rtag=0;
}

void PrintBTTree(BTTree head){
    BTTree p=head->lchild;
    if(head==NULL||p==head)return;
    while(p->ltag==0)p=p->lchild;
    while(p!=head){
        printf("%c %d %d\n",p->data,p->ltag,p->rtag);
        if(p->rtag==1){
            p=p->rchild;
        }else{
            p=p->rchild;
            while(p->ltag==0)p=p->lchild;
        }
    }
}
