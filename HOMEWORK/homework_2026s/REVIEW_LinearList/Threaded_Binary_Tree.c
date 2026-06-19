/*中序线索二叉树演示文稿*/

#include "stdio.h"
#include "stdlib.h"
#include "string.h"

/*数据类型*/
typedef char ElemType;

/*线索二叉树定义*/
typedef struct BTNode{
    ElemType data;
    struct BTNode *lchild;
    struct BTNode *rchild;
    int ltag;
    int rtag;
}BTNode,*BTTree;

/*函数声明*/
void CreateTree(BTTree *head);
void InThreading(BTTree p,BTTree *pre);
int InorderThr(BTTree *head,BTTree T);
BTTree InPreNode(BTTree p);
BTTree InPostNode(BTTree p);

/*主函数*/
int main()
{
    return 0;
}

/*先序遍历生成二叉树*/
void CreateTree(BTTree *head){
    char data;//默认数据类型为字符
    scanf("%c",&data);
    if(data=='\n')return;//输入完毕
    /*输入为空*/
    if(data=='#'){
        (*head)=NULL;
        return;
    }
    /*输入不为空,创建节点*/
    (*head)=(BTTree)malloc(sizeof(BTNode));
    (*head)->data=data;

    CreateTree(&(*head)->lchild);
    CreateTree(&(*head)->rchild);
}

//-----------------------------------------------------------------------------------------
// 1.建立一颗中序线索二叉树

/*基于中序遍历进行中序线索化*/
void InThreading(BTTree p,BTTree *pre){
    if(p)
    {
        InThreading(p->lchild,pre);     /*左子树线索化*/
        if(!p->lchild){                 /*后继线索*/
            p->ltag=1;
            p->lchild=*pre;
        }
        else p->ltag=0;
        if(!(*pre)->rchild){            /*前驱线索*/
            (*pre)->rtag=1;
            (*pre)->rchild=p;
        }
        else (*pre)->rtag=0;
        (*pre)=p;
        InThreading(p->rchild,pre);     /*右子树线索化*/
    }
}

/*创建一个带头结点的中序线索二叉树*/
int InorderThr(BTTree *head,BTTree T){
    /*基于中序遍历二叉树T,并将其中序线索化,*head指向头结点*/
    /*申请头结点的空间*/
    BTTree pre;
    if(!(*head=(BTTree)malloc(sizeof(BTNode))))return 0;
    (*head)->ltag=0;                    /*建立头结点*/
    (*head)->rchild=(*head);            /*右指针回指*/
    if(!T)(*head)->lchild=(*head);      /*若二叉树为空，则左指针回指*/
    else{
        (*head)->lchild=T;
        pre=(*head);
        InThreading(T,&pre);            /*中序遍历进行中序线索化*/
        pre->rchild=(*head);            /*最后一个节点进行线索化*/
        pre->rtag=1;
        (*head)->rtag=1;
        (*head)->rchild=pre;
    }
    return 1;
}

//-----------------------------------------------------------------------------------------
// 2.在中序线索二叉树上查找任意结点的中序前驱节点

/*在中序线索二叉树上寻找结点p的中序前驱节点*/
BTTree InPreNode(BTTree p){
    /*在中序线索二叉树上寻找结点p的中序前驱节点*/
    BTTree pre=p->lchild;
    if(p->ltag==0)                      //有左子树，找左子树最右下方的结点
        while(pre->rtag==0)pre=pre->rchild;
    return pre;
}

//-----------------------------------------------------------------------------------------
// 3.在中序线索二叉树上查找任意结点的中序后继节点

/*在中序线索二叉树上寻找结点p的中序后继节点*/
BTTree InPostNode(BTTree p){
    /*在中序线索二叉树上寻找结点p的中序后继节点*/
    BTTree post=p->rchild;
    if(p->rtag==0)                      //有右子树，找右子树最左下方的结点
        while(post->ltag==0)post=post->lchild;
    return post;
}

//-----------------------------------------------------------------------------------------
// 4.在中序线索二叉树上查找任意结点在先序下的后继节点