/*
2. 二叉树的叶子节点数
给定一个二叉树的根节点 root ，返回其叶子节点数。

 

示例 1：



输入：
4（输入节点数量） 1 -1 2 3
输出：1
-1表示空节点

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

void leafCount(BiTree root, int *count) {
    // Code Here
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

    int count = 0;
    leafCount(tree, &count);
    printf("%d", count);

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

void InitBiTree(BiTree *T,int ele);
void BuildTree_xianxv(BiTree *T,int *elements,int size,int *address);
void BuildTree_cengci(BiTree *T,int *elements,int size);
void MidPrint(BiTree T);
int Leaves(BiTree T);

int main()
{
    BiTree root;
    int num;
    scanf("%d",&num);
    int *elements=(int*)malloc((num)*sizeof(int));
    for(int i=0;i<num;i++){
        scanf("%d",&elements[i]);
    }
    BuildTree_cengci(&root,elements,num);
    printf("%d",Leaves(root));

    return 0;
}

void InitBiTree(BiTree *T,int ele){
    if(!((*T)=(BiTree)malloc(sizeof(BiNode))))exit (0);
    (*T)->data=ele;
    (*T)->left=NULL;
    (*T)->right=NULL;    
}

void BuildTree_xianxv(BiTree *T,int *elements,int size,int *address){
    if(size<=0||*address>size||*(elements+*address)==-1){
        (*T)=NULL;
        return;
    }
    (*T)->data=*(elements+*address);
    (*address)++;
    BuildTree_xianxv(&(*T)->left,elements,size,address);
    BuildTree_xianxv(&(*T)->right,elements,size,address);
}

void BuildTree_cengci(BiTree *T,int *elements,int size){
    if(size<=0||elements[0]==-1){
        (*T)=NULL;
        return;
    }
    InitBiTree(T,elements[0]);

    BiTree queue[100];
    int rear=0,front=0;
    queue[rear++]=(*T);

    int i=1;
    while(i<size){
        BiTree current=queue[front++];
        for(int j=0;j<2&&i<size;j++){
            if(elements[i]!=-1){
                BiTree child;
                InitBiTree(&child,elements[i]);
                if(j==0){
                    current->left=child;
                }else{
                    current->right=child;
                }
                queue[rear++]=child;
            }
            i++;
        }
    }
}

void MidPrint(BiTree T){
    if(T==NULL){
        return;
    }
    MidPrint(T->left);
    printf("%d ",T->data);
    MidPrint(T->right);
}

int Leaves(BiTree T){
    int leaves=0;
    if(T==NULL)return 0;
    if(!T->left&&!T->right)return 1;
    leaves+=Leaves(T->left);
    leaves+=Leaves(T->right);
    return leaves;
}