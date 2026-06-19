/*
5. 二叉树的最大深度
给定一个二叉树 root ，返回其最大深度。

二叉树的 最大深度 是指从根节点到最远叶子节点的最长路径上的节点数。

 

示例 1：（-1表示空节点）



 

输入：
7（输入节点数量） 3 9 20 -1 -1 15 7
输出：
3
示例 2：

输入：
3（输入节点数量） 1 -1 2
输出：
2
 

提示：

树中节点的数量在 [0, 104] 区间内。

-1表示空节点

-100 <= Node.val <= 100

Auxiliary Code

#include <stdio.h>
#include <stdlib.h>
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

int maxDepth(BiNode *root) {
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

    BiTree tree = createBiTree(elements, n);

    printf("%d", maxDepth(tree));

    freeBiTree(tree);
    return 0;
}
*/

#include "stdio.h"
#include "string.h"
#include "stdlib.h"

typedef struct Node{
    int data;
    struct Node *lchild;
    struct Node *rchild;
}BTNode,*BTTree;

void BuildTree(BTTree *root,int *elements,int size);
int Depth(BTTree root);

int main()
{
    BTTree root;
    int num;
    scanf("%d",&num);
    int *elements=(int*)malloc(num*sizeof(int));
    for(int i=0;i<num;i++){
        scanf("%d",&elements[i]);
    }
    BuildTree(&root,elements,num);
    printf("%d",Depth(root));

    free(elements);

    return 0;
}

void BuildTree(BTTree *root,int *elements,int size){
    if(size==0||elements[0]==-1){
        (*root)=NULL;
        return;
    }

    (*root)=(BTTree)malloc(sizeof(BTNode));
    (*root)->data=elements[0];
    (*root)->lchild=(*root)->rchild=NULL;

    BTTree queue[404];
    int rear=0,front=0;
    queue[rear++]=(*root);

    int i=1;
    while(i<size){
        BTTree current=queue[front++];
        for(int j=0;j<2&&i<size;j++){
            if(elements[i]!=-1){
                BTTree new=(BTTree)malloc(sizeof(BTNode));
                new->data=elements[i];
                new->lchild=new->rchild=NULL;
                if(j){
                    current->rchild=new;
                }else{
                    current->lchild=new;
                }
                queue[rear++]=new;
            }
            i++;
        }
    }
}

int Depth(BTTree root){
    if(root==NULL)return 0;
    int dep1=Depth(root->lchild);
    int dep2=Depth(root->rchild);
    int dep=(dep1>dep2)?dep1:dep2;
    return dep+1;
}