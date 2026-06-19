/*
4. 树的结点插入
由于树是层次结构,任何一个结点的插人,必须已知它的双亲结点。
根据双亲的值在孩子兄弟链表中进行查找,如果存在,得到双亲结点的地址,否则为空。
如果找到的双亲结点,它的第一个孩子结点地址为空,则双亲结点没有孩子,新插入的孩子结点
为第一个孩子结点;反之,可以在第一个孩子结点的兄弟链上找到最后一个孩子结点,将新结点
插入为最后一个孩子。新插入的结点一定是叶子结点。给定树的层序遍历以及各个结点的度，
输入要插入的父节点和孩子结点，输出插入后的树的层序遍历以及各个结点的度。

 

示例 1：

1733558150023.png1733558199740.png

输入：层序=[ABCDE],各结点的度=[2 0 1 1 0],要插入的父节点和孩子节点=[B F] 
输出：层序=[ABCFDE],各结点的度=[2 1 1 0 1 0]
示例 2：

输入：层序 = [RABCDEFGHK],各结点的度：[3 2 0 1 0 0 3 0 0 0],
      要插入的父节点和孩子节点=[B L] 
输出：层序=[RABCDELFGHK],各结点的度：[3 2 1 1 0 0 0 3 0 0 0]
 

提示：

树中节点数目在范围 [0, 100] 内

-100 <= Node.val <= 100

输入层序之间没有空格，如A、B、C三个结点输入为ABC

输入结点的度之间有空格如示例一A、B、C、D、E五个结点的度输入应为：2 0 1 1 0

考生只需补充以下函数即可：int InsertBiT(Node*& T, char fa, char ch)


Auxiliary Code

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct Node {
    char data[20];  // 节点数据
    struct Node* firstchild;  // 第一个孩子节点
    struct Node* nextsibling;  // 下一个兄弟节点
} Node, *CSTree;

// 创建新节点
CSTree createNode(const char* data) {
    CSTree node = (CSTree)malloc(sizeof(Node));
    strcpy(node->data, data);
    node->firstchild = node->nextsibling = NULL;
    return node;
}

// 使用层序序列和度数构建孩子兄弟树
CSTree buildTree(const char* levelOrder, const int* degrees, int n) {
    if (n == 0) return NULL;

    // 创建所有节点
    CSTree* nodes = (CSTree*)malloc(n * sizeof(CSTree));
    for (int i = 0; i < n; i++) {
        char data[2] = {levelOrder[i], '\0'};
        nodes[i] = createNode(data);
    }

    int childIndex = 1;  // 当前可用的孩子节点索引
    for (int i = 0; i < n; i++) {
        int degree = degrees[i];
        if (degree > 0) {
            // 第一个孩子
            nodes[i]->firstchild = nodes[childIndex];
            childIndex++;
            
            // 剩余的作为兄弟
            CSTree current = nodes[i]->firstchild;
            for (int j = 1; j < degree; j++) {
                current->nextsibling = nodes[childIndex];
                current = current->nextsibling;
                childIndex++;
            }
        }
    }

    CSTree root = nodes[0];
    free(nodes);
    return root;
}

// 前序遍历查找节点
void PreSearchBiT(CSTree T, char fa, CSTree* p) {
     if (T == NULL) return;   
    if (T->data[0] == fa) {  // 修改这里
        *p = T;
        return;
    }
    PreSearchBiT(T->firstchild, fa, p);
    if (*p != NULL) return;
    
    PreSearchBiT(T->nextsibling, fa, p);
}

// 插入节点
int InsertBiT(CSTree T, char fa, char ch) {
    
}

// 层序遍历树并更新度数
void LevelOrderTraversal(CSTree root, char* levelOrder, int* degrees, int* n) {
    if (root == NULL) return;

    CSTree queue[100];
    int front = 0, rear = 0;
    queue[rear++] = root;
    *n = 0;

    while (front < rear) {
        CSTree current = queue[front++];
        levelOrder[(*n)++] = current->data[0];

        // 计算当前节点的度数
        int degree = 0;
        CSTree child = current->firstchild;
        while (child != NULL) {
            degree++;
            queue[rear++] = child;
            child = child->nextsibling;
        }
        degrees[*n - 1] = degree;
    }
}

int main() {
    char levelOrder[100];
    int degrees[100];
    int n;
    char fa, ch;

    // 输入层序序列
    scanf("%s", levelOrder);
    n = strlen(levelOrder);

    // 输入各节点的度
    for (int i = 0; i < n; i++) {
        scanf("%d", &degrees[i]);
    }

    // 输入要插入的父节点和孩子节点
    scanf(" %c %c", &fa, &ch);  // 注意空格用于跳过换行符

    // 构建树
    CSTree root = buildTree(levelOrder, degrees, n);

    // 插入节点
    int result = InsertBiT(root, fa, ch);
    if (!result) {
        printf("父节点 %c 未找到\n", fa);
        return 1;
    }

    // 重新进行层序遍历并计算度数
    char newLevelOrder[100];
    int newDegrees[100];
    int newN;
    LevelOrderTraversal(root, newLevelOrder, newDegrees, &newN);
    newLevelOrder[newN] = '\0';

    // 输出结果
    printf("%s", newLevelOrder);
    printf("\n");
    for (int i = 0; i < newN; i++) {
        printf("%d", newDegrees[i]);
        if (i < newN - 1) {
            printf(" ");
        }
    }

    // 释放树的内存 (实际应用中需要实现完整的释放函数)
    return 0;
}
*/


#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "stdbool.h"

typedef struct Node{
    char data;
    struct Node *firstchild;
    struct Node *nextbrother;
}CSNode,*CSTree;

CSTree CreatNode(const char data);
CSTree BuildCSTree(const char *levelorder,int *degrees,int len);
CSTree ParentSearchBit(CSTree T,char pa);
int InsertNode(CSTree *T,char pa,char ch);
void LevelOrderTraversal(CSTree root,char *levelorder,int *degrees,int *newlen);

int main()
{
    char levelorder[105];
    int degrees[105];
    int len;
    char pa,ch;

    scanf("%s",levelorder);
    len=strlen(levelorder);

    for(int i=0;i<len;i++){
        scanf("%d",degrees+i);
    }

    scanf(" %c %c",&pa,&ch);

    CSTree root=BuildCSTree(levelorder,degrees,len);
    int result=InsertNode(&root,pa,ch);
    if(!result){
        printf("父节点 %c 未找到\n", pa);
        return 1;
    }

    char newlevelorder[105];
    int newdegrees[105],newlen;
    LevelOrderTraversal(root,newlevelorder,newdegrees,&newlen);
    newlevelorder[newlen]='\0';

    printf("%s\n",newlevelorder);
    for(int i=0;i<newlen;i++){
        printf("%d ",newdegrees[i]);
    }

    return 0;
}

CSTree CreatNode(const char data){
    CSTree newnode=(CSTree)malloc(sizeof(CSNode));
    newnode->data=data;
    newnode->nextbrother=newnode->firstchild=NULL;
    return newnode;
}

CSTree BuildCSTree(const char *levelorder,int *degrees,int len){
    if(len==0)return NULL;

    CSTree *nodes=(CSTree*)malloc(len*sizeof(CSNode));
    for(int i=0;i<len;i++){
        nodes[i]=CreatNode(levelorder[i]);
    }

    int childIndex=1;
    for(int i=0;i<len;i++){
        int degree=degrees[i];
        if(degree>0){
            nodes[i]->firstchild=nodes[childIndex++];
            CSTree current=nodes[i]->firstchild;
            for(int j=1;j<degree;j++){
                current->nextbrother=nodes[childIndex++];
                current=current->nextbrother;
            }
        }
    }

    CSTree root=nodes[0];
    free(nodes);
    return root;
}

CSTree ParentSearchBit(CSTree T,char pa){
    if(T==NULL)return NULL;
    if(T->data==pa)return T;
    CSTree res=ParentSearchBit(T->firstchild,pa);
    if(res)return res;
    return ParentSearchBit(T->nextbrother,pa);
}
    
int InsertNode(CSTree *T,char pa,char ch){
    if(*T==NULL)return 0;

    CSTree p=NULL,q,s;
    p=ParentSearchBit(*T,pa);
    if(p){
        s=CreatNode(ch);
        if(!p->firstchild)p->firstchild=s;
        else{
            q=p->firstchild;
            while(q->nextbrother)q=q->nextbrother;
            q->nextbrother=s;
        }
        return 1;
    }

    return 0;
}

void LevelOrderTraversal(CSTree root,char *levelorder,int *degrees,int *newlen){
    if(root==NULL)return;

    CSTree queue[105];
    int rear=0,front=0;
    queue[rear++]=root;
    *newlen=0;

    while(front<rear){
        CSTree current=queue[front++];
        levelorder[(*newlen)++]=current->data;

        int degree=0;
        CSTree child=current->firstchild;
        while(child){
            degree++;
            queue[rear++]=child;
            child=child->nextbrother;
        }
        degrees[*newlen-1]=degree;
    }
}