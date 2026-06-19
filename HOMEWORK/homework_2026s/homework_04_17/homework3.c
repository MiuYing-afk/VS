/*
3. 二叉树最大宽度
给你一棵二叉树的根节点 root ，返回树的 最大宽度 。

树的 最大宽度 是所有层中最大的 宽度 。





每一层的 宽度 被定义为该层最左和最右的非空节点（即，两个端点）之间的长度。将这个二叉树视作与满二叉树结构相同，两端点间会出现一些延伸到这一层的 null 节点，这些 null 节点也计入长度。

题目数据保证答案将会在  32 位 带符号整数范围内。

 

示例 1：（-1表示空节点）



输入：
7（输入节点数量） 1 3 2 5 3 -1 9
输出：
4
解释：最大宽度出现在树的第 3 层，宽度为 4 (5,3,-1,9) 。
示例 2：



输入：
10（输入节点数量） 1 3 2 5 -1 -1 9 6 -1 7 
输出：
7
解释：最大宽度出现在树的第 4 层，宽度为 7 (6,-1,-1,-1,-1,-1,7) 。
示例 3：



输入：
4（输入节点数量） 1 3 2 5
输出：
2
解释：最大宽度出现在树的第 2 层，宽度为 2 (3,2) 。
 

提示：

树中节点的数目范围是 [1, 3000]

-1表示空节点

-100 <= Node.val <= 100

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

int widthOfBinaryTree(BiTree root){
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

    printf("%d", widthOfBinaryTree(tree));

    freeBiTree(tree);
    return 0;
}
*/


//未成功
#include "stdio.h"
#include "stdlib.h"

typedef struct BiNode{
    int data,num;
    struct BiNode *lchild;
    struct BiNode *rchild;
}BiNode,*BiTree;

BiTree CreatTree(const int *levelorder,int size);
int WidthOfBinaryTree(BiTree T,int size);
void Free(BiTree root);

int main()
{
    int n;
    int elements[3000];
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&elements[i]);
    }
    BiTree root;
    root=CreatTree(elements,n);
    int width=WidthOfBinaryTree(root,n);
    printf("%d",width);

    return 0;
}

BiTree CreatTree(const int *levelorder,int size){
    if(size==0||levelorder[0]==-1)return NULL;

    BiTree root=(BiTree)malloc(sizeof(BiNode));
    root->data=levelorder[0];
    root->num=1;
    root->lchild=NULL;
    root->rchild=NULL;

    BiTree queue[3000];
    int rear=0,front=0;
    queue[rear++]=root;

    int i=1;
    while(i<size){
        BiTree current=queue[front++];
        for(int j=0;j<2&&i<size;j++){
            if(levelorder[i]!=-1){
                BiTree child=(BiTree)malloc(sizeof(BiNode));
                child->data=levelorder[i];
                child->lchild=NULL;
                child->rchild=NULL;
                if(j==0){
                    current->lchild=child;
                    current->lchild->num=2*current->num;
                }else{
                    current->rchild=child;
                    current->rchild->num=2*current->num+1;
                }
                queue[rear++]=child;
            }
            i++;
        }
    }

    return root;
}

int WidthOfBinaryTree(BiTree T,int size){
    if(!T)return 0;
    int layer=1;
    int first,last,max=1;
    BiTree queue1[3000];
    int queue2[3000];
    int rear1=0,rear2=0,front1=0,front2=0;

    queue1[rear1++]=T;
    queue2[rear2++]=T->num;

    int i=1;
    while(i<size){
        BiTree current=queue1[front1++];
        if(current->lchild){
            queue1[rear1++]=current->lchild;
            queue2[rear2++]=current->lchild->num;
        }
        if(current->rchild){
            queue1[rear1++]=current->rchild;
            queue2[rear2++]=current->rchild->num;
        }
    }

    while(1){
        int width=0;
        first=last=queue2[front2++];
        if(queue2[front2]>=2*layer){
            layer++;
            width=last-first+1;
        }else{
            last=queue2[front2++];
        }
        if(width>=max)max=width;
        if(front2==rear2)break;
    }
    return max;
}

void Free(BiTree root){
    if(root==NULL)return;
    Free(root->lchild);
    Free(root->rchild);
    free(root);
}
