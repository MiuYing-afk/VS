/*
4. 树的深度
在树的孩子兄弟链表中,每棵子树根与它的左子树根是双亲与孩子的关系,每棵子树根与它的右子树根是兄弟关系,所以每棵子树的高度是(左子树高度+1)和右子树高度的最大值。给定树的层序遍历以及各个结点的度，输出树的深度。

 

示例 1：

1733558150023.png

输入：层序=[ABCDE],各结点的度=[2 0 1 1 0],要插入的父节点和孩子节点=[B F] 
输出：深度=[4]
示例 2：

输入：层序=[RABCDEFGHK],各结点的度：[3 2 0 1 0 0 3 0 0 0]
输出：深度=[4]
 

提示：

树中节点数目在范围 [0, 100] 内

-100 <= Node.val <= 100

输入层序之间没有空格，如A、B、C三个结点输入为ABC

输入结点的度之间有空格如示例一A、B、C、D、E五个结点的度输入应为：2 0 1 1 0

考生只需补充以下函数即可：int Depth(Node* T)


Auxiliary Code

#include <iostream>
#include <string>
#include <vector>
#include <cstring>  // for strcmp

using namespace std;

struct Node {
    char data;
    struct Node* firstchild, * nextsibling;
};

// 根据树结点的层次序列e和各结点的度degree构造树的子女兄弟链表
void createChildAndSiblingTree(Node** root, string e, vector<int> degree) {
    if (e.length() == 0) {  // 空树
        *root = NULL;
        return;
    }

    Node** Q = new Node * [e.length()];  // 辅助数组，用于存放树结点的地址
    for (int i = 0; i < e.length(); i++) {  // 初始化所有的树结点
        Q[i] = new Node();
        Q[i]->data = e[i];
        Q[i]->firstchild = Q[i]->nextsibling = NULL;
    }

    int k = 0;
    for (int i = 0; i < e.length(); i++) {  // 扫描所有结点
        int d = degree[i];
        if (d > 0) {  // 度大于0，有子树
            k++;
            Q[i]->firstchild = Q[k];  // 紧随的元素为第一个子女
            while (--d > 0) {  // 后续的子女存到兄弟链中
                Q[k]->nextsibling = Q[k + 1];
                k++;
            }
        }
    }
    *root = Q[0];  // 根存在Q[0]所指的结点
    delete[] Q;
}

// 计算树的深度
int Depth(Node* T) {  // T是树的孩子兄弟链表根节点
    
}

int main() {
    string e;
    int n;
    vector<int> degree;

    // 输入节点数据和度
    cin >> e;

    degree.resize(e.length());
    for (int i = 0; i < e.length(); i++) {
        cin >> degree[i];
    }

    Node* root = NULL;
    createChildAndSiblingTree(&root, e, degree);  // 创建树

    // 计算树的深度
    int depth = Depth(root);
    cout << depth << endl;

    return 0;
}
*/

#include "stdio.h"
#include "stdlib.h"
#include "string.h"

#define MAXNUM 102
char DataElem[MAXNUM];
int Degree[MAXNUM];

typedef struct BTNode{
    char data;
    struct BTNode *firstchild;
    struct BTNode *nextsibling;
}BTNode,*BTTree;

BTTree CreateNode(char data);
BTTree CreateTree(char *DataElem,int *Degree,int num);
int Depth(BTTree root);

int main()
{
    BTTree root;
    int num=0;
    for(int i=0;i<MAXNUM;i++){
        char temp;
        scanf("%c",&temp);
        if(temp=='\n')break;
        else{
            num++;
            DataElem[i]=temp;
        }
    }
    for(int i=0;i<num;i++){
        scanf("%d",&Degree[i]);
    }
    root=CreateTree(DataElem,Degree,num);

    int depth=Depth(root);
    printf("%d",depth);

    return 0;
}

BTTree CreateNode(char data){
    BTTree new=(BTTree)malloc(sizeof(BTNode));
    new->data=data;
    new->firstchild=NULL;
    new->nextsibling=NULL;
    return new;
}

BTTree CreateTree(char *DataElem,int *Degree,int num){
    BTTree Q[MAXNUM];
    for(int i=0;i<num;i++){
        Q[i]=CreateNode(DataElem[i]);
    }
    int k=0;
    for(int i=0;i<num;i++){
        int d=Degree[i];
        if(d>0){
            k++;
            Q[i]->firstchild=Q[k];
            while(--d>0){
                Q[k]->nextsibling=Q[k+1];
                k++;
            }
        }
    }
    return Q[0];
}

int Depth(BTTree root){
    if(root==NULL)return 0;

    int max_depth=0;
    int kid_depth=Depth(root->firstchild)+1;
    int bro_depth=Depth(root->nextsibling);

    if(kid_depth>max_depth)max_depth=kid_depth;
    if(bro_depth>max_depth)max_depth=bro_depth;

    return max_depth;
}