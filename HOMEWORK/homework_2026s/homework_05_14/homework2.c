/*
2. 电网故障诊断结果回溯（求二叉树叶结点到根路径）
【问题描述】

在电网调度分析系统中，常用二叉树表示“故障诊断决策过程”或“设备状态分支关系”。现输入一棵二叉树结点的层序遍历结果，其中“-1”表示该位置为空结点。请输出该二叉树中每个叶子结点到根结点的路径，以反映各终端诊断结果向上回溯到根决策节点的过程。

【输入形式】

输入一棵二叉树的层序遍历序列，其中结点之间以空格分隔，“-1”表示空结点。

【输出形式】

按要求输出每个叶子结点到根结点的路径。每条路径中，结点顺序为“叶子结点 → … → 根结点”。 

示例 1：



输入：层序=[1 -1 2 3]
输出：叶子到根的路径=[3 2 1]
示例 2：

1733562196831.png

输入：层序=[1 2 3 -1 4 -1 5 -1 -1 6]
输出：叶子到根的路径=[4 2 1
                    6 5 3 1]
 

提示：

树中节点数目在范围 [0, 100] 内

-100 <= Node.val <= 100

输入层序之间有空格，如1、2、3三个结点输入为1 2 3

考生只需补充以下函数即可：void AllBiTreePath(BiTree T, stack<int>& s)


Auxiliary Code

#include <iostream>
#include <stack>
#include <vector>
#include <queue>
#include <sstream>

using namespace std;

// 二叉树的节点结构
struct BiTreeNode {
    int data;                   // 树节点的数据
    BiTreeNode* lchild;         // 左子节点
    BiTreeNode* rchild;         // 右子节点
};

typedef BiTreeNode* BiTree;

// 打印栈中的元素
void PrintStack(stack<int>& s) {
    stack<int> temp = s;  // 创建一个临时栈来打印
    while (!temp.empty()) {
        cout << temp.top() << " ";
        temp.pop();
    }
    cout << endl;
}

// 按路径遍历二叉树并打印所有从根到叶子的路径
void AllBiTreePath(BiTree T, stack<int>& s) {
   
}

// 按层次遍历构建二叉树
BiTree BuildTreeFromArray(const vector<int>& arr) {
    if (arr.empty() || arr[0] == -1) return nullptr; // 如果数组为空或者根节点为空，返回空树

    BiTree root = new BiTreeNode{ arr[0], nullptr, nullptr };  // 创建根节点
    queue<BiTree> nodeQueue;  // 使用队列来帮助层次遍历
    nodeQueue.push(root);  // 将根节点加入队列

    int index = 1;  // 从数组的第二个元素开始

    while (!nodeQueue.empty() && index < arr.size()) {
        BiTree currentNode = nodeQueue.front();
        nodeQueue.pop();  // 出队当前节点

        // 处理左子节点
        if (index < arr.size() && arr[index] != -1) {
            currentNode->lchild = new BiTreeNode{ arr[index], nullptr, nullptr };
            nodeQueue.push(currentNode->lchild);  // 将新节点加入队列
        }
        ++index;

        // 处理右子节点
        if (index < arr.size() && arr[index] != -1) {
            currentNode->rchild = new BiTreeNode{ arr[index], nullptr, nullptr };
            nodeQueue.push(currentNode->rchild);  // 将新节点加入队列
        }
        ++index;
    }

    return root;
}

int main() {
    // 用户输入数组来构建二叉树
    string input;
    getline(cin, input);  // 获取用户输入的一行字符串

    // 使用 stringstream 将输入的字符串分割成数字
    stringstream ss(input);
    vector<int> arr;
    int val;

    while (ss >> val) {
        arr.push_back(val);  // 将每个输入的数字存入数组
    }

    // 构建二叉树
    BiTree tree = BuildTreeFromArray(arr);

    // 使用栈来存储路径
    stack<int> s;
    AllBiTreePath(tree, s);  // 输出从根到叶子的所有路径

    return 0;
}
*/

#include "stdio.h"
#include "stdlib.h"

typedef struct Node{
    int data;
    struct Node *lchild;
    struct Node *rchild;
}BTNode,*BTTree;

typedef struct Stack{
    int data[404];
    int top;
}Stack;


void BuildTree(BTTree *root,int *elements,int size);
void InitStack(Stack *S);
int Push(Stack *S, int x);
int Pop(Stack *S, int *x);
int StackEmpty(Stack *S);
void PrintStack(Stack *S);
void PrintAllLeaves(BTTree root,Stack *S);

int main()
{
    BTTree root;
    // int num=1;
    // int elements[404];
    // scanf("层序=[%d",&elements[0]);
    // char temp;
    // scanf(" %c",&temp);
    // for(int i = 1;temp != ']'; i++){
    //     if(temp == '-'){
    //         elements[i] = -1;
    //         temp=getchar();
    //     }else{
    //         elements[i] = (temp - '0');
    //     }
    //     num++;
    //     scanf(" %c",&temp);
    // }
    // getchar();
    int elements[404];
    int num = 0;
    int val;

    // OJ标准安全输入：忽略无关字符，只读数字
    //第一个数字前面所有字符全部自动忽略
    //中间的空格、括号、换行也自动忽略
    //如果输入是纯字母、纯符号、没有任何数字,scanf 直接返回 不是 1
    while(scanf("%d",&val) == 1){
        elements[num++] = val;
        // 最多100个节点，题目限制
        if(num >= 100) break;
    }
    BuildTree(&root,elements,num);

    Stack S;
    InitStack(&S);
    PrintAllLeaves(root,&S);

    return 0;
}

void BuildTree(BTTree *root,int *elements,int size){
    if(size == 0 || elements[0] == -1){
        (*root) = NULL;
        return;
    }

    (*root) = (BTTree)malloc(sizeof(BTNode));
    (*root)->data = elements[0];
    (*root)->lchild = (*root)->rchild = NULL;

    BTTree queue[404];
    int rear = 0,front = 0;
    queue[rear++] = (*root);

    int i = 1;
    while(i < size){
        BTTree current = queue[front++];
        for(int j = 0; j < 2 && i < size; j++){
            if(elements[i] != -1){
                BTTree new = (BTTree)malloc(sizeof(BTNode));
                new->data = elements[i];
                new->lchild = new->rchild = NULL;
                if(j==0){
                    current->lchild = new;
                }else{
                    current->rchild = new;
                }
                queue[rear++] = new;
            }
            i++;
        }
    }
}

void InitStack(Stack *S){
    S->top = -1;
}

int Push(Stack *S, int x) {
    if (S->top >= 404 - 1) return 0;
    S->data[++S->top] = x;
    return 1;
}

int Pop(Stack *S, int *x) {
    if (S->top == -1) return 0;
    *x = S->data[S->top--];
    return 1;
}

int StackEmpty(Stack *S) {
    return S->top == -1;
}

void PrintStack(Stack *S) {
    for (int i = S->top; i >= 0; i--) {
        printf("%d ", S->data[i]);
    }
}

void PrintAllLeaves(BTTree root,Stack *S){
    if(root){
        Push(S,root->data);

        if(!root->lchild&&!root->rchild){
            PrintStack(S);
            printf("\n");
        }else{
            PrintAllLeaves(root->lchild,S);
            PrintAllLeaves(root->rchild,S);
        }

        int temp;
        Pop(S,&temp);
    }
}