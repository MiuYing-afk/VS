/*
6. 创建带头结点的中序线索二叉树
【问题描述】

  请设计一个算法创建一个带头结点的中序线索二叉树。

【输入形式】

  按根左子树右子树的顺序输入各结点的值，空结点用 # 表示。

【输出形式】

  输出各结点对应的线索标志值。
【样例输入】

  image.png

AB#D##CF###
【样例输出】

image.png

10 11 00 11 01
【样例说明】

 请将下列代码粘贴至作答区域，并实现 InOrderThr 函数。

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
    //请在此处书写代码，可自行添加其它辅助函数...
}

BiThrTree InPostNode(BiThrTree p)
{
    /*在中序线索二叉树上寻找结点 p 的中序后继结点 *
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
    /* 在中序线索二叉树上进行中序遍历，输出每个结点对应的线索标志值 *
    BiThrTree p = head->lchild;

    // 如果头结点的左孩子是头结点本身，则说明树为空
    if (p == head) return;

    // 找到第一个节点
    while (p->ltag == 0) {
        p = p->lchild;
    }

    // 开始中序遍历
    while (p != head) {
        printf("%d%d ", p->ltag, p->rtag); // 输出当前节点的 ltag 和 rtag
        p = InPostNode(p); // 找到下一个中序后继节点
    }
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
#include "stdlib.h"
#include "string.h"

typedef struct BTNode{
    int lflag,rflag;
    char data;
    struct BTNode *lchild;
    struct BTNode *rchild;
}BTNode,*BTTree;
int address=0;

void CreatBTTree(BTTree *T,char *levelorder,int ad);
BTTree Inithead();
BTTree CreatNode(char data);
void ClueBTTree(BTTree *T,BTTree *pre);
void PrintBTTree(BTTree head);

int main()
{
    BTTree head=Inithead();
    char levelorder[105];
    scanf("%s",levelorder);
    BTTree T;
    CreatBTTree(&T,levelorder,0);
    if(T){
        head->lchild=T;
        ClueBTTree(&T,&head);
    }else{
        head->lchild=head;
    }
    PrintBTTree(head);
    return 0;
}

BTTree Inithead(){
    BTTree head=(BTTree)malloc(sizeof(BTNode));
    head->lchild=head->rchild=NULL;
    head->lflag=0;
    head->rflag=1;
    return head;
}

void CreatBTTree(BTTree *T,char *levelorder,int ad){
    if(levelorder[address]=='\0')return;
    if(levelorder[address]=='#'){
        *T=NULL;
        return;
    }
    *T=CreatNode(levelorder[address]);
    CreatBTTree(&(*T)->lchild,levelorder,++address);
    CreatBTTree(&(*T)->rchild,levelorder,++address);
}

BTTree CreatNode(char data){
    if(data=='#')return NULL;
    BTTree new=(BTTree)malloc(sizeof(BTNode));
    new->data=data;
    new->lchild=new->rchild=NULL;
    new->lflag=new->rflag=0;
    return new;
}

void ClueBTTree(BTTree *T,BTTree *pre){
    if(*T==NULL)return;
    ClueBTTree(&(*T)->lchild,pre);
    if((*T)->lchild==NULL){
        (*T)->lflag=1;
        (*T)->lchild=(*pre);
    }
    if((*pre)!=NULL&&(*pre)->rchild==NULL){
        (*pre)->rflag=1;
        (*pre)->rchild=(*T);
    }
    *pre=*T;
    ClueBTTree(&(*T)->rchild,pre);
}

void PrintBTTree(BTTree head){
    if(head->lchild==head)return;
    BTTree T=head->lchild;
    while(T->lflag==0){
        T=T->lchild;
    }
    while(T!=head){
        printf("%d%d ",T->lflag,T->rflag);
        if(T->rflag==1)T=T->rchild;
        else{
            BTTree p=T->rchild;
            while(p->lflag==0)p=p->lchild;
            T=p;
        }
    }
}
