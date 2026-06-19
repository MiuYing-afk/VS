/*
6. 对称二叉树
给你一个二叉树的根节点 root ， 检查它是否轴对称。

 

示例 1：（-1表示空节点）



输入：
7（输入节点数量） 1 2 2 3 4 4 3
输出：
true
示例 2：



输入：
7（输入节点数量） 1 2 2 -1 3 -1 3
输出：
false
 

提示：

树中节点数目在范围 [1, 1000] 内

-100 <= Node.val <= 100

 

进阶：你可以运用递归和迭代两种方法解决这个问题吗？

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

int isSymmetric(struct BiNode* root) {
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

    if (isSymmetric(tree)) {
        printf("true\n");
    } else {
        printf("false\n");
    }

    freeBiTree(tree);
    return 0;
}
*/

#include "stdio.h"
#include "stdlib.h"

typedef struct Node{
    int data;
    struct Node* lchild;
    struct Node* rchild;
}BTNode,*BTTree;

void BuildTree(BTTree *root,int *elements,int size);
int isSymmetrical(BTTree T1,BTTree T2);
void Print(BTTree root);
void FreeTree(BTTree root);

int main()
{
    int num;
    scanf("%d",&num);
    int *elements=(int*)malloc(num*sizeof(int));
    for(int i=0;i<num;i++){
        scanf("%d",&elements[i]);
    }
    BTTree root;
    BuildTree(&root,elements,num);
    if(isSymmetrical(root->lchild,root->rchild)){
        printf("true");
    }else{
        printf("false");
    }

    FreeTree(root);
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
                if(j==0){
                    current->lchild=new;
                }else{
                    current->rchild=new;
                }
                queue[rear++]=new;
            }
            i++;
        }
    }
}

int isSymmetrical(BTTree T1,BTTree T2){
    if(T1==NULL){
        if(T2==NULL)return 1;
        else return 0;
    }else if(T2==NULL){
        return 0;
    }

    int flag=1;
    if(T1->data==T2->data)flag*=1;
    else return 0;

    flag *=isSymmetrical(T1->lchild,T2->rchild);
    flag *=isSymmetrical(T1->rchild,T2->lchild);

    return flag;
}

void Print(BTTree root){
    if(root==NULL)return;

    BTTree queue[404];
    int rear=0,front=0;
    queue[rear++]=root;

    while(front<rear){
        BTTree current=queue[front++];
        if(current){
            printf("%d ",current->data);
            queue[rear++]=current->lchild;
            queue[rear++]=current->rchild;
        }else{
            int flag=1;
            for(int i=front;i<rear;i++){
                if(queue[i]){
                    flag=0;
                    break;
                }
            }
            if(flag==1)break;
            printf("-1 ");
        }
    }
}

void FreeTree(BTTree root){
    if(root==NULL)return;
    FreeTree(root->lchild);
    FreeTree(root->rchild);
    free(root);
}
