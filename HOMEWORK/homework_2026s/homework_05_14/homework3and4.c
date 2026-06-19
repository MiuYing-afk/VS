/*
3. 二叉树的中序遍历——任务分析法
给定一个二叉树的根节点 root ，使用 任务分析法，返回 它的 中序 遍历 。

4. 二叉树的中序遍历——路径分析法
给定一个二叉树的根节点 root ，使用 路径分析法，返回 它的 中序 遍历 。

示例 1：



输入：
4(输入节点数量) 1 -1 2 3
输出：
1 3 2
示例 2：

输入：
0(输入节点数量)
输出：
示例 3：

输入：
1(输入节点数量) 1
输出：
1
 

提示：

树中节点数目在范围 [0, 100] 内

-100 <= Node.val <= 100

*/

/*
任务分析法 = 用栈模拟递归 → 做遍历（中序 / 前序 / 后序）
路径分析法 = 沿着根→叶子的一条条路径去做计算 / 输出
*/

#include "stdio.h"
#include "stdlib.h"

typedef struct Node{
    int data;
    struct Node *lchild;
    struct Node *rchild;
}BTNode,*BTTree;

void BuildTree(BTTree *root,int *elements,int size);
void MidPrint_digui(BTTree root);
void MidPrint_Task(BTTree root);
void MidPrint_Path(BTTree root, int path[], int top);
void ClearTree(BTTree root);

int main()
{
    BTTree root;
    int num;
    scanf("%d",&num);
    int *elements = (int*)malloc(num*sizeof(int));
    for(int i = 0; i < num; i++){
        scanf("%d",&elements[i]);
    }
    BuildTree(&root,elements,num);
    // MidPrint_digui(root);
    // MidPrint_Task(root);
    int path[404];
    int top=0;
    MidPrint_Path(root,path,top);

    ClearTree(root);
    free(elements);
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

//递归中序输出
void MidPrint_digui(BTTree root){
    if(root==NULL)return;

    MidPrint_digui(root->lchild);
    printf("%d ",root->data);
    MidPrint_digui(root->rchild);
}

// 任务分析法
void MidPrint_Task(BTTree root)
{
    if(root == NULL) return;
    BTTree stack[404];
    int top = -1;
    BTTree p = root;

    while(p != NULL || top != -1)
    {
        // 任务1：一路往左走，全部压栈
        while(p != NULL)
        {
            stack[++top] = p;
            p = p->lchild;
        }
        // 任务2：弹出节点，访问
        p = stack[top--];
        printf("%d ", p->data);
        // 任务3：转向右子树
        p = p->rchild;
    }
}

//路径分析法
//不是，你这除了加了一个path来记录路径外，你和递归有什么区别啊
void MidPrint_Path(BTTree root, int path[], int top){
    if(root == NULL)
        return;

    // 当前节点进入路径
    path[top++] = root->data;

    // 走左子树路径
    MidPrint_Path(root->lchild, path, top);

    // 中序访问：左路径走完，访问当前
    printf("%d ", root->data);

    // 走右子树路径
    MidPrint_Path(root->rchild, path, top);

    // 回溯：退出当前路径
    top--;
}

void ClearTree(BTTree root){
    if(root==NULL)return;

    ClearTree(root->lchild);
    ClearTree(root->rchild);
    free(root);
}