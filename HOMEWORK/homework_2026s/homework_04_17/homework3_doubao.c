#include "stdio.h"
#include "stdlib.h"

// 把num改成无符号长 long，防止溢出
typedef struct BiNode{
    int data;
    unsigned long long num;  // 这里必须改
    struct BiNode *lchild;
    struct BiNode *rchild;
}BiNode,*BiTree;

BiTree CreatTree(const int *levelorder,int size);
int WidthOfBinaryTree(BiTree T);  // 去掉多余的size
void Free(BiTree root);

int main()
{
    int n;
    int elements[3000];
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&elements[i]);
    }
    BiTree root = CreatTree(elements,n);
    int width = WidthOfBinaryTree(root);
    printf("%d",width);
    Free(root);
    return 0;
}

// 1. 补上 return root
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
                    child->num = current->num * 2;
                }else{
                    current->rchild=child;
                    child->num = current->num * 2 + 1;
                }
                queue[rear++]=child;
            }
            i++;
        }
    }
    return root;  // 你原来这里漏了！！！
}

// 2. 宽度函数重写为正确的层序+编号
int WidthOfBinaryTree(BiTree T){
    if(!T) return 0;

    BiTree q_node[3000];
    unsigned long long q_num[3000];
    int front = 0, rear = 0;

    q_node[rear] = T;
    q_num[rear] = T->num;
    rear++;

    int max_width = 0;

    while(front < rear){
        int level_size = rear - front;
        unsigned long long left = q_num[front];
        unsigned long long right = left;

        // 一层一层处理！核心！
        for(int i=0; i<level_size; i++){
            BiTree cur = q_node[front];
            right = q_num[front];
            front++;

            if(cur->lchild){
                q_node[rear] = cur->lchild;
                q_num[rear] = cur->lchild->num;
                rear++;
            }
            if(cur->rchild){
                q_node[rear] = cur->rchild;
                q_num[rear] = cur->rchild->num;
                rear++;
            }
        }

        int width = right - left + 1;
        if(width > max_width){
            max_width = width;
        }
    }
    return max_width;
}

void Free(BiTree root){
    if(root==NULL)return;
    Free(root->lchild);
    Free(root->rchild);
    free(root);
}