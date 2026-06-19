/*
2. 删除给定值的叶子节点
给你一棵以 root 为根的二叉树和一个整数 target ，请你删除所有值为 target 的 叶子节点 。

注意，一旦删除值为 target 的叶子节点，它的父节点就可能变成叶子节点；如果新叶子节点的值恰好也是 target ，那么这个节点也应该被删除。

也就是说，你需要重复此过程直到不能继续删除。输入输出均为层序遍历。

 

示例 1：



输入：root = [1,2,3,2,-1,2,4], target = 2输出：[1,-1,3,-1,4]解释：上面左边的图中，绿色节点为叶子节点，且它们的值与 target 相同（同为 2 ），它们会被删除，得到中间的图。
有一个新的节点变成了叶子节点且它的值与 target 相同，所以将再次进行删除，从而得到最右边的图。
示例 2：



输入：root = [1,3,3,3,2], target = 3输出：[1,3,-1,-1,2]
示例 3：



输入：root = [1,2,-1,2,-1,2], target = 2输出：[1]解释：每一步都删除一个绿色的叶子节点（值为 2）。
 

提示：

树中节点数量的范围是 [1, 3000]。

1 <= Node.val, target <= 1000

-1表示空节点

输入时不需输入逗号，每个节点之间以空格隔开如root=[1，3，3，3，2]输入时应为1 3 3 3 2，输出同样

考生只需补充以下代码即可：TreeNode* removeLeafNodes(TreeNode* root, int target)
Auxiliary Code

#include <iostream>
#include <queue>
using namespace std;

  struct TreeNode {
      int val;
      TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };


class Solution {
public:
    // 移除叶子节点
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        
        
    }

    // 打印二叉树（层序遍历），空节点打印为-1
    void printTree(TreeNode* root) {
        if (!root) {
            cout << "-1 ";  // 如果树为空，直接输出-1
            return;
        }
        queueq;
        q.push(root);
        bool firstNonNullFound = false;  // 用于标记是否找到第一个非空节点
        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            // 如果节点为nullptr（空节点），输出-1
            if (!node) {
                cout << "-1 ";
                continue;
            }

            // 输出当前节点的值
            cout << node->val << " ";

            // 如果节点有左子树或右子树，继续将子节点放入队列
            if (node->left || node->right) {
                q.push(node->left);
                q.push(node->right);
            }
        }
        cout << endl;
    }
};

// 从输入构建二叉树的辅助函数
TreeNode* buildTree(const int* values, int size, int index = 0) {
    if (index >= size || values[index] == -1) {
        return nullptr;  // -1 表示空节点
    }
    TreeNode* node = new TreeNode(values[index]);
    node->left = buildTree(values, size, 2 * index + 1);  // 左子树
    node->right = buildTree(values, size, 2 * index + 2); // 右子树
    return node;
}

int main() {
    Solution solution;

    // 输入二叉树的节点值，-1 表示空节点
    int treeValues[500];  // 假设树的节点数最大为500
    int treeSize = 0;
    int val;
    while (cin >> val) {
        treeValues[treeSize++] = val;
        if (cin.get() == '\n') break;  // Enter key结束输入
    }

    // 构建二叉树
    TreeNode* root = buildTree(treeValues, treeSize);

    // 输入目标值
    int target;
    cin >> target;

    // 移除叶子节点
    root = solution.removeLeafNodes(root, target);

    // 打印处理后的二叉树
    solution.printTree(root);

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

void crt_Tree(BTTree *root,int *values,int num);
void deleTag(BTTree *root,int tag);
void printTree(BTTree root);
int isLeaf(BTTree *node);

int main()
{
    BTTree root;
    int values[3005]={0},num=0,temp;
    while(scanf("%d",&temp)!=EOF){
        values[num++]=temp;
        if(getchar()=='\n')break;
    }
    crt_Tree(&root,values,num);

    int target;
    scanf("%d",&target);
    deleTag(&root,target);
    printTree(root);

    return 0;
}

void crt_Tree(BTTree *root,int *values,int num){
    if(num<=0||values[0]==-1){
        (*root)=NULL;
        return;
    }

    (*root)=(BTTree)malloc(sizeof(BTNode));
    (*root)->data=values[0];
    (*root)->left=(*root)->right=NULL;

    BTTree queue[3005];
    int rear=0,front=0;
    queue[rear++]=(*root);

    int i=1;
    while(i<num){
        BTTree cur=queue[front++];
        for(int j=0;j<2&&i<num;j++){
            if(values[i]!=-1){
                BTTree new=(BTTree)malloc(sizeof(BTNode));
                new->data=values[i];
                new->left=new->right=NULL;
                if(j==0){
                    cur->left=new;
                }else{
                    cur->right=new;
                }
                queue[rear++]=new;
            }
            i++;
        }
    }
}

int isLeaf(BTTree *node){
    return (*node)!=NULL&&(*node)->left==NULL&&(*node)->right==NULL;
}

void deleTag(BTTree *root,int tag){
    if(*root==NULL)return;

    if(isLeaf(root)){
        if((*root)->data==tag){
            free(*root);
            (*root)=NULL;
            return;
        }
    }else{
        deleTag(&(*root)->left,tag);
        deleTag(&(*root)->right,tag);
    }

    if(isLeaf(root)){
        if((*root)->data==tag){
            free(*root);
            (*root)=NULL;
            return;
        }
    }
}

void printTree(BTTree root){
    if(root==NULL){
        printf("-1");
        return;
    }

    BTTree queue[3005];
    int rear=0,front=0;
    queue[rear++]=root;

    while(front<rear){
        BTTree cur=queue[front++];
        if(cur!=NULL){
            printf("%d ",cur->data);
            queue[rear++]=cur->left;
            queue[rear++]=cur->right;
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