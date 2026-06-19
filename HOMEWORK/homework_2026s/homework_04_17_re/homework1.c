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

int main()
{
    int size1,size2;
    scanf("%d",&size1);
    int *preorder=(int*)malloc((size1+1)*sizeof(int));
    for(int i=0;i<size1;i++){
        scanf("%d",&preorder[i]);
    }
    preorder[size1]=-1;
    scanf("%d",&size2);
    int *inorder=(int*)malloc((size2+1)*sizeof(int));
    for(int i=0;i<size2;i++){
        scanf("%d",&inorder[i]);
    }
    inorder[size2]=-1;



    free(preorder);free(inorder);

    return 0;
}


void BuildTree(BiTree *T,int *preorder,int *inorder,int ps,int is,int size){
    if(size<=0)*T=NULL;
    else{
        int k=Search(inorder,preorder[ps]);
        if(k==-1)(*T)=NULL;
        else{
            if(!((*T)=(BiTree)malloc(sizeof(BiNode))))exit(0);
            (*T)->data=preorder[k];
            if(k==is)(*T)->left=NULL;
            else BuildTree(&(*T)->left,preorder,inorder,ps+1,is,k-is);
            
        }
    }
}

int Search(int *inorder,int i){
    for(int k=0;inorder[k]!=-1;k++){
        if(inorder[k]==i)return k;
    }
    return -1;
}