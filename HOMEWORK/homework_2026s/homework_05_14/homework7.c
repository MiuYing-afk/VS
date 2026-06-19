/*
7. 二叉树展开为链表
给你二叉树的根结点 root ，请你将它展开为一个单链表：

展开后的单链表应该同样使用 TreeNode ，其中 right 子指针指向链表中下一个结点，而左子指针始终为 null 。

展开后的单链表应该与二叉树 先序遍历 顺序相同。



示例 1：（-1表示空节点）



输入：
7（输入节点数量） 1 2 5 3 4 -1 6
输出：
1 -1 2 -1 3 -1 4 -1 5 -1 6
示例 2：

输入：
0（输入节点数量）
输出：
示例 3：

输入：
1（输入节点数量） 0
输出：
0


提示：

树中结点数在范围 [0, 2000] 内

-100 <= Node.val <= 100



进阶：你可以使用原地算法（O(1) 额外空间）展开这棵树吗？

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

void flatten(BiTree root) {
    // Code here...
}

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

    flatten(tree);

    hierarchicalTraversal(tree);

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
void Trans(BTTree root);
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
    Trans(root);
    Print(root);
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

void Trans(BTTree root){
    BTTree current=root;
    while(current){
        if(current->lchild){
            BTTree rmost=current->lchild;
            while(rmost->rchild){
                rmost=rmost->rchild;
            }
            rmost->rchild=current->rchild;
            current->rchild=current->lchild;
            current->lchild=NULL;
        }
        current=current->rchild;
    }
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
