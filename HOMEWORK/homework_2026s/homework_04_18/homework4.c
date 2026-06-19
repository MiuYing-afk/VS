/*
4. 合并二叉树
给你两棵二叉树： root1 和 root2 。

想象一下，当你将其中一棵覆盖到另一棵之上时，两棵树上的一些节点将会重叠（而另一些不会）。你需要将这两棵树合并成一棵新二叉树。合并的规则是：如果两个节点重叠，那么将这两个节点的值相加作为合并后节点的新值；否则，不为 null 的节点将直接作为新二叉树的节点。

返回合并后的二叉树。

注意: 合并过程必须从两个树的根节点开始。

 

示例 1：（-1表示空节点）



输入：
4（输入节点数量） 1 3 2 5
7（输入节点数量） 2 1 3 -1 4 -1 7
输出：
3 4 5 5 4 -1 7
示例 2：

输入：
1（输入节点数量） 1
2（输入节点数量） 1 2
输出：
2 2
 

提示：

两棵树中的节点数目在范围 [0, 2000] 内

-104 <= Node.val <= 104

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

BiTree mergeTrees(BiTree t1, BiTree t2) {
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
    int m, mm;
    scanf("%d", &n);
    nn = n;
    int elements1[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &elements1[i]);
        if (elements1[i] == -1) {
            nn--;
        }
    }
    scanf("%d", &m);
    mm = m;
    int elements2[m];
    for (int i = 0; i < m; i++) {
        scanf("%d", &elements2[i]);
        if (elements2[i] == -1) {
            mm--;
        }
    }

    BiTree t1 = createBiTree(elements1, n);
    BiTree t2 = createBiTree(elements2, m);

    BiTree merged = mergeTrees(t1, t2);

    hierarchicalTraversal(merged);

    free(t1);
    free(t2);
    free(merged);
    return 0;
}
*/

#include "stdio.h"
#include "string.h"
#include "stdlib.h"

typedef struct Node{
    char data;
    struct Node *lchild;
    struct Node *rchild;
}BTNode,*BTTree;

void BuildTree(BTTree *root,int *elements,int size);
BTTree MergeTree(BTTree root1,BTTree root2);
void Print(BTTree root);
void ClearTree(BTTree root);

int main()
{
    BTTree root,root1,root2;
    int num1,num2;
    scanf("%d",&num1);
    int *elements1=(int*)malloc(num1*sizeof(int));
    for(int i=0;i<num1;i++){
        scanf("%d",&elements1[i]);
    }
    scanf("%d",&num2);
    int *elements2=(int*)malloc(num2*sizeof(int));
    for(int i=0;i<num2;i++){
        scanf("%d",&elements2[i]);
    }
    
    BuildTree(&root1,elements1,num1);
    BuildTree(&root2,elements2,num2);
    root=MergeTree(root1,root2);
    Print(root);

    ClearTree(root);
    free(elements1);
    free(elements2);

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

    BTTree queue[2005];
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

BTTree MergeTree(BTTree root1,BTTree root2){
    if(root1==NULL&&root2==NULL){
        return NULL;
    }
    if(root1 == NULL){
        return root2;
    }
    if(root2 == NULL){
        return root1;
    }

    BTTree ROOT=(BTTree)malloc(sizeof(BTNode));
    ROOT->data = root1->data + root2->data;

    ROOT->lchild=MergeTree(root1->lchild,root2->lchild);
    ROOT->rchild=MergeTree(root1->rchild,root2->rchild);

    return ROOT;
}

void Print(BTTree root){
    if(!root)return;

    BTTree queue[2005];
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
            if(flag)break;
            printf("-1 ");
        }
    }
}

void ClearTree(BTTree root){
    if(root==NULL)return;
    ClearTree(root->lchild);
    ClearTree(root->rchild);
    free(root);
}