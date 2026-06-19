/*
3. 中序线索二叉树的中序遍历
【问题描述】

  请设计一个算法实现中序线索二叉树的中序遍历。

【输入形式】

  按根左子树右子树的顺序输入各结点的值，空结点用 # 表示。

【输出形式】

  输出中序线索二叉树的中序遍历序列。
【样例输入】

  image.pngimage.png

AB#D##CF###
【样例输出】

BDAFC
【样例说明】

 样例输入中给出了二叉树以及对应的中序线索二叉树结构，供考生参考。

 请将下列代码粘贴至作答区域，并实现 InPostNode 和 ThIoOrder 函数。

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
 
int InOrderThr(BiThrTree *head, BiThrTree T)
{
    /* 中序遍历二叉树 T，并将其中序线索化，*head 指向头结点 */
    /* 申请头结点的空间 * /
    if (!(*head = (BiThrTree)malloc(sizeof(BiThrNodeType)))) return 0;
    (*head)->ltag = 0; (*head)->rtag = 1; /* 建立头结点（虚拟）* /
    (*head)->rchild = *head; /*右指针回指* /
    BiThrTree pre;
    if (!T) 
        (*head)->lchild = *head; /*若二叉树为空，则左指针回指* /
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
    // 请在此处书写代码...
}

void ThIoOrder(BiThrTree head)
{
    // 请在此处书写代码...
}

int main()
{
    BiThrTree head, T;
    //按根左子树右子树的顺序输入
    crt_tree(&T);
    //二叉树中序线索化
    InOrderThr(&head, T);
    //基于中序线索二叉树的中序遍历结果
    ThIoOrder(head);
    return 0;
}
*/

#include "stdio.h"
#include "string.h"
#include "stdlib.h"

typedef struct BiThrNode{
    char data;
    struct BiThrNode *left;
    struct BiThrNode *right;
    int ltag;
    int rtag;
}BiThrNode,*BiThrTree;

BiThrTree Inithead();
BiThrTree CreateNode(char ele);
void CreatBiTree(BiThrTree *head,char *levelorer);
void ClueBihrTree(BiThrTree root,BiThrTree T);
void InClue(BiThrTree T,BiThrTree *pre);
void PrintTree(BiThrTree root);
BiThrTree InPostNode(BiThrTree p);

int main()
{
    BiThrTree root=Inithead();
    char levelorder[404];
    scanf("%s",levelorder);
    BiThrTree T=NULL;
    CreatBiTree(&T,levelorder);
    if(T){
        root->left=T;
        ClueBihrTree(root,T);
    }else{
        root->left=root;
    }
    PrintTree(root);

    return 0;
}


BiThrTree Inithead(){
    BiThrTree head=(BiThrTree)malloc(sizeof(BiThrNode));
    head->left=NULL;
    head->right=head;
    head->ltag=0;
    head->rtag=1;
    return head;
}

BiThrTree CreateNode(char ele){
    BiThrTree new=(BiThrTree)malloc(sizeof(BiThrNode));
    new->data=ele;
    new->left=new->right=NULL;
    new->ltag=new->rtag=0;
    return new;
}

void CreatBiTree(BiThrTree *head,char *levelorer){
    static int idx=0;
    if(levelorer[idx]=='\0'){
        idx=0;
        *head=NULL;
        return;
    }
    if(levelorer[idx]=='#'){
        *head=NULL;
        idx++;
        return;
    }
    (*head)=CreateNode(levelorer[idx++]);
    CreatBiTree(&(*head)->left,levelorer);
    CreatBiTree(&(*head)->right,levelorer);
}

void ClueBihrTree(BiThrTree root,BiThrTree T){
    BiThrTree pre=root;
    InClue(root,&pre);

    pre->right=root;
    pre->rtag=1;
    root->right=pre;
}


void InClue(BiThrTree T,BiThrTree *pre){
    if(!T)return;

    if(T->ltag==0){
        InClue(T->left,pre);
    }

    if(!T->left){
        T->left=*pre;
        T->ltag=1;
    }
    if(*pre&&!(*pre)->right){
        (*pre)->rtag=1;
        (*pre)->right=T;
    }
    *pre=T;
    if(T->rtag==0){
        InClue(T->right,pre);
    }
    
}

void PrintTree(BiThrTree root){
    if(root->left==root)return;

    BiThrTree p=root->left;
    while(p->ltag==0){
        p=p->left;
    }
    while(p!=root){
        printf("%c",p->data);
        p=InPostNode(p);
    }
}

BiThrTree InPostNode(BiThrTree p){
    if(p->rtag==1){
        return p->right;
    }else{
        BiThrTree q=p->right;
        while(q->ltag==0){
            q=q->left;
        }
        return q;
    }
}