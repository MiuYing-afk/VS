#include "stdio.h"
#include "stdlib.h"

typedef struct Node{
    int data;
    struct Node *lchild;
    struct Node *rchild;
}BTNode,*BTTree;

void BuildTree(BTTree *root,int *elements,int size);
void ReverseTree(BTTree *Root,BTTree root);
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
    BTTree root,troot;
    BuildTree(&troot,elements,num);
    ReverseTree(&root,troot);
    Print(root);
    FreeTree(root);
    FreeTree(troot);

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

void ReverseTree(BTTree *Root,BTTree root){
    if(root==NULL){
        (*Root)=NULL;
        return;
    }

    (*Root)=(BTTree)malloc(sizeof(BTNode));
    (*Root)->data=root->data;
    (*Root)->lchild=(*Root)->rchild=NULL;
    ReverseTree(&(*Root)->lchild,root->rchild);
    ReverseTree(&(*Root)->rchild,root->lchild);
    
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
