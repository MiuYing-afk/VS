/*
1. 配电网状态无效分支清理（二叉树剪枝）
【问题描述】

在配电网状态监测系统中，常用一棵二叉树表示分层设备状态结构。树中每个结点的值只可能为 0 或 1，其中：

1 表示该设备节点或其下属分支中存在“有效运行状态”；

0 表示该设备节点及其分支当前无有效状态信息。

现要求对这棵二叉树进行状态剪枝：删除所有结点值全为 0 的子树。

这里，结点 node 的子树是指以 node 为根的整棵子树，包括 node 本身以及它的所有后代结点。

【输入形式】

第一行输入一个整数 n，表示按层序输入的结点数量。

第二行输入该二叉树的层序遍历序列，其中结点值为 0 或 1，输入“-1”表示空结点。

【输出形式】

输出剪枝后的二叉树层序遍历结果，空结点仍用“-1”表示。

 

示例 1:（-1表示空节点）



输入: 
5(输入节点数量) 1 -1 0 0 1
输出: 
1 -1 0 -1 1
示例 2:



输入: 
7(输入节点数量) 1 0 1 0 0 0 1
输出: 
1 -1 1 -1 1
示例 3:



输入: 
8(输入节点数量) 1 1 0 1 1 0 1 0
输出: 
1 1 0 1 1 -1 1
 

提示:

二叉树的节点个数的范围是 [1,200]

二叉树节点的值只会是 0 或 1



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

BiTree pruneTree(BiTree root){
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

    hierarchicalTraversal(pruneTree(tree));

    free(tree);
    return 0;
}
*/

#include "stdio.h"
#include "stdlib.h"

typedef struct Node{
    int state;
    struct Node *lchild;
    struct Node *rchild;
}BTNode,*BTTree;

void BuildTree(BTTree *root,int* states,int size);
int CutTree(BTTree *root);
void Print_cenci(BTTree root);

int main()
{
    BTTree root;
    int num;
    scanf("%d",&num);
    int *states=(int*)malloc(num*sizeof(int));
    for(int i=0;i<num;i++){
        scanf("%d",&states[i]);
    }
    BuildTree(&root,states,num);
    CutTree(&root);
    Print_cenci(root);

    return 0;
}

void BuildTree(BTTree *root,int* states,int size){
    if(size==0||states[0]==-1){
        (*root)=NULL;
        return;
    }

    (*root)=(BTTree)malloc(sizeof(BTNode));
    (*root)->state=states[0];
    (*root)->lchild=(*root)->rchild=NULL;

    BTTree queue[404];
    int rear=0,front=0;
    queue[rear++]=(*root);

    int i=1;
    while(i<size){
        BTTree current=queue[front++];
        for(int j=0;j<2&&i<size;j++){
            if(states[i]!=-1){
                BTTree new = (BTTree)malloc(sizeof(BTNode));
                new->state = states[i];
                new->lchild = new->rchild = NULL;
                if(j==0){
                    current->lchild = new;
                }else{
                    current->rchild = new;
                }
                queue[rear++] = new;
            }
            i++;
        }
    }
}

int CutTree(BTTree *root){
    if(*root==NULL)return 0;

    int flag1=0;
    flag1 += CutTree(&(*root)->lchild);
    flag1 += CutTree(&(*root)->rchild);

    if(flag1==0&&(*root)->state==0){
        free(*root);
        *root = NULL;
        return 0;
    }else{
        return 1;
    }

}

void Print_cenci(BTTree root){
    if(root==NULL)return;

    BTTree queue[404];
    int rear=0,front=0;
    queue[rear++]=root;

    while(front<rear){
        BTTree current = queue[front++];
        if(current){
            printf("%d ",current->state);
            queue[rear++] = current->lchild;
            queue[rear++] = current->rchild;
        }else{
            int flag=1;
            for(int i = front; i < rear; i++){
                if(queue[i]){
                    flag = 0;
                    break;
                }
            }
            if(flag==1)break;
            printf("-1 ");
        }
    }
}