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
    InitBiTree(T);

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
    if(T==NULL)return leaves;
    leaves+=Leaves(T->left);
    leaves+=Leaves(T->right);
    return leaves;
}