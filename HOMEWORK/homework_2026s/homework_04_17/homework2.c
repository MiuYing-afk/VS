/*
2. 二叉树的中序遍历
给定一个二叉树的根节点 root ，返回 它的 中序 遍历 。

 

示例 1：（-1表示空节点）



输入：
4（输入节点数量） 1 -1 2 3
输出：
1 3 2
示例 2：

输入：
0（输入节点数量）
输出：
示例 3：

输入：
1（输入节点数量） 1
输出：
1
 

提示：

树中节点数目在范围 [0, 100] 内

-1表示空节点

-100 <= Node.val <= 100

 

进阶: 递归算法很简单，你可以通过迭代算法完成吗？

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

int* inorderTraversal(BiTree root, int* index) {
    // Code here...
    // index为辅助变量，若无需要可忽略
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
    int returnSize;
    for (int i = 0; i < n; i++) {
        scanf("%d", &elements[i]);
        if (elements[i] == -1) {
            nn--;
        }
    }

    BiTree tree = createBiTree(elements, n);

    int* result = inorderTraversal(tree, &returnSize);
    
    for (int i = 0; i < nn; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");

    freeBiTree(tree);
    free(result);
    return 0;
}
*/

#include "stdio.h"
#include "stdlib.h"

typedef struct BiNode{
    int data;
    struct BiNode *lchild;
    struct BiNode *rchild;
} BiNode,*BiTree;

void InitBiTree(BiTree *T,int ele);
void CreBiTree(BiTree *T,const int *levelorder,int size);
void MidPrint(BiTree T);
void Free(BiTree T);

int main()
{
    int num;
    scanf("%d",&num);
    int *elements=(int*)malloc(num*sizeof(int));
    BiTree root;
    for(int i=0;i<num;i++){
        scanf("%d",&elements[i]);
    }
    CreBiTree(&root,elements,num);
    MidPrint(root);
    Free(root);

    return 0;
}

void InitBiTree(BiTree *T,int ele){
    if(!((*T)=(BiTree)malloc(sizeof(BiNode))))exit (0);
    (*T)->data=ele;
    (*T)->lchild=NULL;
    (*T)->rchild=NULL;
}

void CreBiTree(BiTree *T,const int *levelorder,int size){
    if(size==0||levelorder[0]==-1){
        (*T)=NULL;
        return;
    }
    InitBiTree(&(*T),levelorder[0]);

    BiTree queue[100];
    int rear=0,front=0;
    queue[rear++]=(*T);

    int i=1;
    while(i<size){
        BiTree current=queue[front++];
        for(int j=0;j<2&&i<size;j++){
            if(levelorder[i]!=-1){
                BiTree child;
                InitBiTree(&child,levelorder[i]);
                if(j==0){
                    current->lchild=child;
                }else{
                    current->rchild=child;
                }
                queue[rear++]=child;
            }
            i++;
        }
    }

}

void MidPrint(BiTree T){
    if(T){
        MidPrint(T->lchild);
        printf("%d ",T->data);
        MidPrint(T->rchild);
    }
}

void Free(BiTree T){
    if(T==NULL)return;
    Free(T->lchild);
    Free(T->rchild);
    free(T);
}