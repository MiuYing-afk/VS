/*
1. 二叉树的堂兄弟节点
在二叉树中，根节点位于深度 0 处，每个深度为 k 的节点的子节点位于深度 k+1 处。

如果二叉树的两个节点深度相同，但 父节点不同 ，则它们是一对堂兄弟节点。

我们给出了具有唯一值的二叉树的根节点 root ，以及树中两个不同节点的值 x 和 y 。

只有与值 x 和 y 对应的节点是堂兄弟节点时，才返回 true 。否则，返回 false。



示例 1：（-1表示空节点）



输入：
4（输入节点数量） 1 2 3 4
4 3（分别为x和y）
输出：false
示例 2：


输入：
7（输入节点数量） 1 2 3 -1 4 -1 5
5 4（分别为x和y）
输出：true
示例 3：



输入：
5（输入节点数量） 1 2 3 -1 4
2 3（分别为x和y）
输出：
false


提示：

二叉树的节点数介于?2 到?100?之间。

每个节点的值都是唯一的、范围为?1 到?100?的整数。



Auxiliary Code

#include<stdio.h>
#include<stdlib.h>
typedef int ElementType;

typedef struct BiNode {
    ElementType data;
    struct BiNode *left;
    struct BiNode *right;
} BiNode, *BiTree;

BiTree createBiTree(const int *levelOrder, int size) {
    if (size == 0 || levelOrder[0] == -1) {
        return NULL;
    }

    BiTree root = (BiNode *) malloc(sizeof(BiNode));
    root->data = levelOrder[0];
    root->left = NULL;
    root->right = NULL;

    BiNode *queue[size];
    int front = 0, rear = 0;
    queue[rear++] = root;

    int i = 1;
    while (i < size) {
        BiNode *currentNode = queue[front++];
        for (int j = 0; j < 2 && i < size; j++) {
            if (levelOrder[i] != -1) {
                BiNode *child = (BiNode *) malloc(sizeof(BiNode));
                child->data = levelOrder[i];
                child->left = NULL;
                child->right = NULL;
                if (j == 0) {
                    currentNode->left = child;
                } else {
                    currentNode->right = child;
                }
                queue[rear++] = child;
            }
            i++;
        }
    }

    return root;
}

int isCousins(BiTree root, int x, int y) {
  // Code here...
}


void freeBiTree(BiTree root) {
    if (root == NULL) {
        return;
    }
    freeBiTree(root->left);
    freeBiTree(root->right);
    free(root);
}

int main() {
    int n, nn;
    scanf("%d", &n);
    nn = n;
    int elements[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &elements[i]);
        if (elements[i] == -1) {
            nn--;
        }
    }

    int a, b;
    scanf("%d %d", &a, &b);

    BiTree tree = createBiTree(elements, n);

    if (isCousins(tree, a, b)){
        printf("true");
    } else {
        printf("false");
    }
    free(tree);
    return 0;
}
*/

#include "stdio.h"
#include "stdlib.h"

typedef struct BiNode{
    int data;
    int level;
    struct BiNode *lchild;
    struct BiNode *rchild;
}BiNode,*BiTree;

BiTree CreateTree(const int *levelorder,int size);
BiTree Find(BiTree root,int e);
int isCousins(BiTree root, int x, int y) ;
void Free(BiTree root);

int main()
{
    int num,x,y;
    int elements[100];
    scanf("%d",&num);
    for(int i=0;i<num;i++){
        scanf("%d",&elements[i]);
    }
    scanf("%d%d",&x,&y);

    BiTree root=CreateTree(elements,num);

    if (isCousins(root,x,y)){
        printf("true");
    } else {
        printf("false");
    }
    Free(root);

    return 0;
}


BiTree CreateTree(const int *levelorder,int size){
    if(size==0||levelorder[0]==-1)return NULL;
    BiTree root=(BiTree)malloc(sizeof(BiNode));
    root->lchild=root->rchild=NULL;
    root->data=levelorder[0];
    root->level=0;

    BiTree queue[100];
    int rear=0,front=0;
    queue[rear++]=root;

    int i=1;
    while(i<size){
        BiTree current=queue[front++];
        for(int j=0;j<2&&i<size;j++){
            if(levelorder[i]!=-1){
                BiTree child=(BiTree)malloc(sizeof(BiNode));
                child->data=levelorder[i];
                child->lchild=child->rchild=NULL;
                if(j==0){
                    current->lchild=child;
                    current->lchild->level=current->level+1;
                }else{
                    current->rchild=child;
                    current->rchild->level=current->level+1;
                }
                queue[rear++]=child;
            }
            i++;
        }
    }
    return root;
}

/*此函数为豆包解*/
BiTree Find(BiTree root,int e){
    if(root == NULL) return NULL;

    if(root->lchild && root->lchild->data == e)
        return root;
    if(root->rchild && root->rchild->data == e)
        return root;

    BiTree left = Find(root->lchild, e);
    if(left) return left;

    return Find(root->rchild, e);
}

int isCousins(BiTree root, int x, int y) {
    BiTree parent1=root,parent2=root;
    if(root->data==x||root->data==y)return 0;

    parent1=Find(root,x);
    parent2=Find(root,y);
    if(parent1->level==parent2->level&&parent1!=parent2)return 1;
    else return 0;
}

void Free(BiTree root){
    if(root==NULL)return;
    Free(root->lchild);
    Free(root->rchild);
    free(root);
}
