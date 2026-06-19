/*
1. 从前序与中序遍历序列构造二叉树
给定两个整数数组 preorder 和 inorder ，其中 preorder 是二叉树的先序遍历，
 inorder 是同一棵树的中序遍历，请构造二叉树并返回其根节点。

 

示例 1:



输入: 
5（输入节点数量） 3 9 20 15 7
5（输入节点数量） 9 3 15 20 7
输出: 
3 9 20 -1 -1 15 7
说明：
输入第一行为先序遍历，第二行为中序遍历
示例 2:

输入: 
0（输入节点数量）
0（输入节点数量）
输出: 

说明：
输入第一行为先序遍历，第二行为中序遍历
 

提示:

1 <= preorder.length <= 3000

inorder.length == preorder.length

-3000 <= preorder[i], inorder[i] <= 3000

preorder 和 inorder 均 无重复 元素

inorder 均出现在 preorder

preorder 保证 为二叉树的前序遍历序列

inorder 保证 为二叉树的中序遍历序列

Auxiliary Code

#include<stdio.h>
#include<stdlib.h>
typedef int ElementType;

typedef struct BiNode {
    ElementType data;
    struct BiNode *left;
    struct BiNode *right;
} BiNode, *BiTree;

void hierarchicalTraversal(BiTree root) {
    if (!root) return;

    BiNode *queue[100];
    int front = 0, rear = 0;

    queue[rear++] = root;

    while (front < rear) {
        BiNode *current = queue[front++];
        if (current) {
            printf("%d ", current->data);
            queue[rear++] = current->left;
            queue[rear++] = current->right;
        }
        else {
            int flag = 1;
            for (int i = front; i < rear; i++) {
                if (queue[i]) {
                    flag = 0;
                    break;
                }
            }
            if (flag == 1) {
                break;
            }
            printf("-1 ");
        }
    }
}

BiTree buildTree(int* preorder, int preorderSize, int* inorder, int inorderSize) {
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
    int elements1[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &elements1[i]);
        if (elements1[i] == -1) {
            nn--;
        }
    }

    int m, mm;
    scanf("%d", &m);
    mm = m;
    int elements2[m];
    for (int i = 0; i < m; i++) {
        scanf("%d", &elements2[i]);
        if (elements2[i] == -1) {
            mm--;
        }
    }

    BiTree tree = buildTree(elements1, n, elements2, m);

    hierarchicalTraversal(tree);

    freeBiTree(tree);
    return 0;
}
*/

#include "stdio.h"
#include "stdlib.h"
#include "string.h"

typedef struct BiNode{
    int data;
    struct BiNode *left;
    struct BiNode *right;
}BiNode,*BiTree;

void BuildTree(BiTree *T,int *preorder,int *inorder,int ps,int is,int size);
int Search(int *inorder,int i);
void HierarchicalTraversal(BiTree root);
void FreeBiTree(BiTree root);

int main()
{
    int size1,size2;
    scanf("%d",&size1);
    int preorder[size1+1];
    for(int i=0;i<size1;i++){
        scanf("%d",&preorder[i]);
    }
    preorder[size1]=-1;
    scanf("%d",&size2);
    int inorder[size2+1];
    for(int i=0;i<size2;i++){
        scanf("%d",&inorder[i]);
    }
    inorder[size2]=-1;

    BiTree root;
    BuildTree(&root,preorder,inorder,0,0,size1);
    HierarchicalTraversal(root);
    FreeBiTree(root);
    
    return 0;
}

void BuildTree(BiTree *T,int *preorder,int *inorder,int ps,int is,int size){
    if(!size)*T=NULL;
    else{
        int k=Search(inorder,preorder[ps]);
        if(k==-1)*T=NULL;
        else{
            if(!(*T=(BiTree)malloc(sizeof(BiNode))))exit (0);
            (*T)->data=preorder[ps];
            if(k==is)(*T)->left=NULL;
            else BuildTree(&(*T)->left,preorder,inorder,ps+1,is,k-is);
            if(k==is+size-1)(*T)->right=NULL;
            else BuildTree(&(*T)->right,preorder,inorder,ps+1+(k-is),k+1,size-(k-is)-1);
        }
    }
}

int Search(int *inorder,int i){
    for(int k=0;inorder[k]!=-1;k++){
        if(inorder[k]==i)return k;
    }
    return -1;
}

void HierarchicalTraversal(BiTree root){
    if(!root)return;

    BiTree queue[3000];
    int rear=0,front=0;
    queue[rear++]=root;

    while(front<rear){
        BiTree current=queue[front++];
        if(current){
            printf("%d ",current->data);
            queue[rear++]=current->left;
            queue[rear++]=current->right;
        }else{
            int flag=1;
            for(int i=front;i<rear;i++){
                if(queue[i]){
                    flag=0;
                    break;
                }
            }
            if(flag==1)return;
            printf("-1 ");
        }
    }
}

void FreeBiTree(BiTree root){
    if(root==NULL)return;
    FreeBiTree(root->left);
    FreeBiTree(root->right);
    free(root);
}
