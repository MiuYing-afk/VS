/*
5. 中序线索二叉树中查找值为x的结点
【问题描述】

  请设计一个算法在中序线索二叉树上查找值为x的结点

【输入形式】

  第一行按根左子树右子树的顺序输入各结点的值，第二行输入待查找结点对应的值。

【输出形式】

  输出该结点对应的中序后继结点对应的值，head结点的值用0表示。
【样例输入1】

  image.pngimage.png

AB#D##CF###
B
【样例输出1】

D

【样例输入2】

AB#D##CF###
C
【样例输出2】

0

【样例输入3】

AB#D##CF###
D
【样例输出3】

A
【样例说明】

  样例输入1中给出二叉树以及中序线索化后的二叉树，供考生参考。

  请将下列代码粘贴至作答区域，并将函数 Search 补充完整。

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

BiThrTree Search(BiThrTree head,elemtype x){
    //请在此处填写代码...
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
    
    // 找到中序后继结点
    BiThrTree postNode = InPostNode(targetNode);

    // 打印结果
    if (postNode != head) {
        printf("%c\n", postNode->data);
    } else {
        printf("0\n");
    }
    return 0;
}
*/

#include "stdio.h"
#include "stdlib.h"

typedef struct BTNode{
    char data;
    struct BTNode *lchild;
    struct BTNode *rchild;
    int ltag,rtag;
}BTNode,*BTTree;

void CreateTree(BTTree *T);
void InitRoot(BTTree *root);
void InThreading(BTTree p, BTTree *pre);
void InOrderThr(BTTree *head, BTTree T);

int main()
{
    BTTree root,T;
    CreateTree(&T);
    if(T==NULL)root->lchild=root;
    else root->lchild=T;

    return 0;
}

void CreateTree(BTTree *T){
    char data;
    scanf("%c",&data);
    if(data=='#')*T=NULL;
    else{
        (*T)=(BTTree)malloc(sizeof(BTNode));
        (*T)->data=data;
        CreateTree(&(*T)->lchild);
        CreateTree(&(*T)->rchild);
    }
}

void InitRoot(BTTree *root){
    (*root)=(BTTree)malloc(sizeof(BTNode));
    (*root)->rchild=(*root);
    (*root)->lchild=NULL;
    (*root)->ltag=0;
    (*root)->rtag=1;
}


void InThreading(BTTree p, BTTree *pre){
    
}

void InOrderThr(BTTree *head, BTTree T){
    if(*head){
        
    }
}
