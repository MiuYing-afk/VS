/*
5. 树的孩子兄弟表示方法
【问题描述】

 给定一棵孩子链表表示法存储的完全树，设计一个算法将其转换为孩子兄弟表示法。
【输入形式】

 第一行输入树的结点总数n；第二行输入层序遍历所得各结点对应的元素值；接着输入n行，每一行包含结点的孩子结点数以及各孩子结点在数组中对应的位置。

  由此构造出孩子链表表示的多叉树作为输入。

【输出形式】

 输出孩子兄弟表示法构造的树的先序遍历序列。
【样例输入】

 image.png

6
a b c d e f
3 1 2 3
2 4 5
0
0
0
0
【样例输出】

image.png

a b e f c d
【样例说明】

 上述样例输入与输出仅供参考。请将下列代码粘贴至作答区域，考生只需实现convertToCS(...)函数

#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 20
#define TElemType char

// 孩子链表结点结构
typedef struct CTNode {
    int child; // 孩子结点在数组中的索引
    struct CTNode *next;
} ChildPtr;

// 孩子链表表示法的结点结构
typedef struct {
    TElemType data; // 结点的数据类型
    ChildPtr *firstchild; // 孩子链表的头指针
} CTBox;

// 孩子链表表示法的树结构
typedef struct {
    CTBox nodes[MAX_SIZE]; // 存储结点的数组
    int n, r; // 结点数量和树根的位置
} CTree;

// 初始化孩子链表表示法的树
CTree initTree(CTree tree, int n, char values[], int children[][MAX_SIZE], int childrenCounts[]) {
    tree.n = n;
    tree.r = 0; // 默认树根结点位于数组nodes[0]处

    for (int i = 0; i < n; i++) {
        tree.nodes[i].data = values[i];
        tree.nodes[i].firstchild = NULL;

        if (childrenCounts[i] > 0) {
            ChildPtr *p = NULL;
            for (int j = 0; j < childrenCounts[i]; j++) {
                // 创建新孩子结点
                ChildPtr *newEle = (ChildPtr*)malloc(sizeof(ChildPtr));
                newEle->child = children[i][j];
                newEle->next = NULL;

                // 如果当前结点没有孩子，设置firstchild
                if (tree.nodes[i].firstchild == NULL) {
                    tree.nodes[i].firstchild = newEle;
                } else {
                    p->next = newEle;
                }
                p = newEle;  // 移动到链表的下一个结点
            }
        }
    }

    return tree;
}

// 将孩子链表表示法的树转换为孩子兄弟表示法的树
CSNode* convertToCS(CTree tree, int index) {
    //Code here...
}

// 打印孩子兄弟表示法的树（前序遍历）
void printCS(CSNode *root, int level) {
    //Code here...
}

int main() {
    CTree tree;
    int n;
    char values[MAX_SIZE];
    int children[MAX_SIZE][MAX_SIZE];
    int childrenCounts[MAX_SIZE];
    char targetNode;

    // 读取结点数量
    scanf("%d", &n);

    // 读取层序遍历树所得各个结点的值
    for (int i = 0; i < n; i++) {
        scanf(" %c", &values[i]);
    }

    // 读取每个结点的孩子结点信息
    for (int i = 0; i < n; i++) {
        scanf("%d", &childrenCounts[i]);
        for (int j = 0; j < childrenCounts[i]; j++) {
            scanf("%d", &children[i][j]);
        }
    }

    // 初始化孩子链表表示法的树
    tree = initTree(tree, n, values, children, childrenCounts);

    // 转换为孩子兄弟表示法的树
    CSNode *csRoot = convertToCS(tree, tree.r);

    // 打印孩子兄弟表示法的树
    printCS(csRoot, 0);

    return 0;
}
*/

#include "stdio.h"
#include "stdlib.h"

typedef struct CSNode{
    char data;
    struct CSNode *firstchild;
    struct CSNode *nextsibling;
}CSNode,*CSTree;

CSTree CreatCSNode(char data);
CSTree BuildCSTree(char *levelorder,int len,CSTree *Nodes);
void PrintCSTree(CSTree root);
int Free(CSTree root);

int main()
{
    CSTree Nodes[105];
    char levelorder[105];
    int len;
    scanf("%d",&len);
    for(int i=0;i<len;i++){
        scanf(" %c",&levelorder[i]);
    }
    for(int i=0;i<len;i++){
        Nodes[i]=CreatCSNode(levelorder[i]);
    }

    CSTree root=BuildCSTree(levelorder,len,Nodes);
    PrintCSTree(root);
    Free(root);

    return 0;
}

CSTree CreatCSNode(char data){
    CSTree new=(CSTree)malloc(sizeof(CSNode));
    new->data=data;
    new->firstchild=new->nextsibling=NULL;
    return new;
}

CSTree BuildCSTree(char *levelorder,int len,CSTree *Nodes){
    if(len==0)return NULL;

    int degree=0;
    for(int i=0;i<len;i++){
        CSTree current=Nodes[i];
        scanf("%d",&degree);
        CSTree child=current->firstchild;
        for(int j=0;j<degree;j++){
            int childIndex;
            scanf("%d",&childIndex);
            if(child==NULL){
                current->firstchild=Nodes[childIndex];
                child=current->firstchild;
            }else{
                child->nextsibling=Nodes[childIndex];
                child=child->nextsibling;
            }
        }
    }
    CSTree root=Nodes[0];
    return root;
}

void PrintCSTree(CSTree root){
    if(root==NULL)return;
    printf("%c ",root->data);
    PrintCSTree(root->firstchild);
    PrintCSTree(root->nextsibling);
}

int Free(CSTree root){
    if(root==NULL)return 0;
    Free(root->firstchild);
    Free(root->nextsibling);
    free(root);
    return 1;
}