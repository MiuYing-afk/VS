/*
2. 以字符串“根左子树右子树”形式创建二叉链表
以字符串“根左子树右子树”形式创建二叉链表 

示例 1：

IMG_1882.jpeg

输入：ABC##DE#G##F###
输出：AB#CD##EF#G




Auxiliary Code

#include <stdio.h>
#include <stdlib.h>
typedef char ElementType;

typedef struct BiNode {
    ElementType data;
    struct BiNode *left;
    struct BiNode *right;
} BiNode, *BiTree;

void crt_tree(BiTree *T) {
    // Code Here
}

void hierarchicalTraversal(BiTree root) {
    if (!root) return;

    BiNode *queue[100];
    int front = 0, rear = 0;

    queue[rear++] = root;

    while (front < rear) {
        BiNode *current = queue[front++];
        if (current) {
            printf("%c", current->data);
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
            printf("#");
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
    BiTree tree;
    crt_tree(&tree);

    hierarchicalTraversal(tree);

    free(tree);
    return 0;
}
*/

#include "stdio.h"
#include "stdlib.h"

typedef struct BTNode{
    char data;
    struct BTNode *lchild;
    struct BTNode *rchild;
}BTNode,*BTTree;

void CreateTree(BTTree *T);
void PrintTree(BTTree root);
void ClearTree(BTTree root);

int main()
{
    BTTree root;
    CreateTree(&root);
    PrintTree(root);
    ClearTree(root);

    return 0;
}

void CreateTree(BTTree *T){
    char temp;
    scanf (" %c",&temp);
    if(temp=='#'){
        (*T)=NULL;
        return;
    }
    (*T)=(BTTree)malloc(sizeof(BTNode));
    (*T)->data=temp;
    CreateTree(&(*T)->lchild);
    CreateTree(&(*T)->rchild);
}

void PrintTree(BTTree root){
    if(root==NULL)return;

    BTTree queue[404];
    int rear=0,front=0;
    queue[rear++]=root;

    while(front<rear){
        BTTree current=queue[front++];
        if(current){
            printf("%c",current->data);
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
            if(flag==1)return;
            printf("#");
        }
    }
}

void ClearTree(BTTree root){
    if(root==NULL)return;
    ClearTree(root->lchild);
    ClearTree(root->rchild);
    free(root);
}