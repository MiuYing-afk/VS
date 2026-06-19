#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE 10005

// 二叉树结点结构体
typedef struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

/*
 * 动态数组结构体：替代C++ vector<int>*
 * data：存储结果
 * len：当前有效元素个数
 */
typedef struct VecInt {
    int* data;
    int len;
} VecInt;

TreeNode* queueBuf[MAX_QUEUE];
int qFront = 0, qRear = 0;

VecInt* createVec();
void pushBack(VecInt* vec, int num);
void freeVec(VecInt* vec);
void dfs(VecInt* res, TreeNode* root, int curHeight);
VecInt* largestValues(TreeNode* root);
void qPush(TreeNode* p);
TreeNode* qPop();
int qEmpty();
TreeNode* buildTree(int* values, int n);
void printResult(VecInt* res);
void freeTree(TreeNode* root);

int main() {
    int inputArr[10005];
    int cnt = 0;
    int tmp;

    // 循环读取输入，空格/回车分隔
    while (scanf("%d", &tmp) != EOF) {
        inputArr[cnt++] = tmp;
        if (getchar() == '\n') break;
    }

    // 构建二叉树
    TreeNode* root = buildTree(inputArr, cnt);
    // 求每层最大值
    VecInt* ans = largestValues(root);
    // 输出
    printResult(ans);

    // 内存释放
    freeVec(ans);
    freeTree(root);

    return 0;
}

// 创建空动态数组
VecInt* createVec() {
    VecInt* vec = (VecInt*)malloc(sizeof(VecInt));
    vec->len = 0;
    vec->data = NULL;
    return vec;
}

// 数组尾部追加元素
void pushBack(VecInt* vec, int num) {
    vec->data = (int*)realloc(vec->data, sizeof(int) * (vec->len + 1));
    vec->data[vec->len++] = num;
}

// 释放动态数组内存
void freeVec(VecInt* vec) {
    if (vec) {
        free(vec->data);
        free(vec);
    }
}

// DFS：res存每层最大值，root当前结点，curHeight当前层数(从0开始)
void dfs(VecInt* res, TreeNode* root, int curHeight) {
    if (root == NULL)
        return;

    // 当前层还没有数据：直接放入当前值为本层最大值
    if (curHeight == res->len) {
        pushBack(res, root->val);
    } else {
        // 当前层已有值，更新最大值
        if (root->val > res->data[curHeight]) {
            res->data[curHeight] = root->val;
        }
    }

    dfs(res, root->left, curHeight + 1);
    dfs(res, root->right, curHeight + 1);
}

// 主函数：返回每层最大值数组
VecInt* largestValues(TreeNode* root) {
    VecInt* res = createVec();
    if (root == NULL)
        return res;
    dfs(res, root, 0);
    return res;
}

void qPush(TreeNode* p) {
    queueBuf[qRear++] = p;
}

TreeNode* qPop() {
    return queueBuf[qFront++];
}

int qEmpty() {
    return qFront >= qRear;
}

/*
 * 根据输入数组构建二叉树
 * values：输入数组首地址，n：数组长度，-1代表空节点
 */
TreeNode* buildTree(int* values, int n) {
    if (n == 0) return NULL;
    // 重置队列
    qFront = qRear = 0;

    TreeNode* root = (TreeNode*)malloc(sizeof(TreeNode));
    root->val = values[0];
    root->left = root->right = NULL;
    qPush(root);

    int idx = 1;
    while (!qEmpty() && idx < n) {
        TreeNode* cur = qPop();
        // 左孩子
        if (values[idx] != -1) {
            TreeNode* l = (TreeNode*)malloc(sizeof(TreeNode));
            l->val = values[idx];
            l->left = l->right = NULL;
            cur->left = l;
            qPush(l);
        }
        idx++;
        // 右孩子
        if (idx < n && values[idx] != -1) {
            TreeNode* r = (TreeNode*)malloc(sizeof(TreeNode));
            r->val = values[idx];
            r->left = r->right = NULL;
            cur->right = r;
            qPush(r);
        }
        idx++;
    }
    return root;
}

// 打印结果
void printResult(VecInt* res) {
    for (int i = 0; i < res->len; i++) {
        printf("%d ", res->data[i]);
    }
    printf("\n");
}

// 释放整棵树内存（可选，防止内存泄漏）
void freeTree(TreeNode* root) {
    if (root == NULL) return;
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}
