/*
1. 在每个树行中找最大值
给定一棵二叉树的根节点 root(层序) ，请找出该二叉树中每一层的最大值。输入为二叉树的层序遍历，其中空节点用-1代替，输出为从上到下每一层节点的最大值。

 

示例1：



输入:1 3 2 5 3 -1 9
输出:1 3 9
示例2：

输入:1 2 3
输出:1 3
 

提示：

二叉树的节点个数的范围是 [1,104]

-1表示空结点


-231 <= Node.val <= 231 - 1

考生只需补充下列代码即可：void dfs()、vector<int>* largestValues()
 

Auxiliary Code

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

void dfs(vector<int>* res, TreeNode* root, int curHeight) {
    
}

vector<int>* largestValues(TreeNode* root) {
    
}

// 从输入数组构建二叉树的辅助函数
TreeNode* buildTree(const vector<int>* values) {
    if (values->empty()) return nullptr;

    TreeNode* root = new TreeNode((*values)[0]);
    queue<TreeNode*> q;
    q.push(root);

    int i = 1;
    while (i < values->size()) {
        TreeNode* current = q.front();
        q.pop();

        if ((*values)[i] != -1) {  // -1表示空节点
            current->left = new TreeNode((*values)[i]);
            q.push(current->left);
        }
        i++;

        if (i < values->size() && (*values)[i] != -1) {
            current->right = new TreeNode((*values)[i]);
            q.push(current->right);
        }
        i++;
    }

    return root;
}

// 打印结果
void printResult(const vector<int>* result) {
    for (int val : *result) {
        cout << val << " ";
    }
    cout << endl;
}

int main() {
    // 输入二叉树的节点值，用-1表示空节点
    vector<int> treeValues;
    int val;
    while (cin >> val) {
        treeValues.push_back(val);
        if (cin.get() == '\n') break;  // 按回车结束输入
    }

    // 构建二叉树
    TreeNode* root = buildTree(&treeValues);

    // 调用 largestValues 函数并输出结果
    vector<int>* result = largestValues(root);
    printResult(result);

    // 清理内存
    delete result;

    return 0;
}
*/

#include "stdio.h"
#include "stdlib.h"

typedef struct BTNode{
    int data;
    struct BTNode *left;
    struct BTNode *right;
}BTNode,*BTTree;

int main()
{

}