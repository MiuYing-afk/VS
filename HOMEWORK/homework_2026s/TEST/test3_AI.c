#include "stdio.h"
#include "stdlib.h"

typedef struct Node{
	int userID;
	int Load;
	struct Node *lchild;
	struct Node *rchild;
}BTNode,*BTTree;

// 插入结点（BST，不允许重复ID）
int InsertNode(BTTree *root, int id, int load);
// 查找
void FindNode(BTTree root, int id);
// BST 删除指定结点（标准BST删除）
int DeleteNode(BTTree *root, int id);
// 递归销毁整棵树
void DeleteTree(BTTree root);
// 统计总和、结点数
void AverageCount(BTTree root, int *sum, int *num);
// 查找最大负荷
void MaxLoad(BTTree root, int *maxId, int *maxLoad);
// 中序遍历（解决末尾空格）
void PrintTree(BTTree root, int *first);

int main()
{
	BTTree root = NULL;
	char choice;
	while(1){
		scanf(" %c",&choice);
		switch(choice){
			case 'i':{
				int id, load;
				scanf("%d%d", &id, &load);
				if(InsertNode(&root, id, load)){
					printf("插入成功\n");
				}
				break;
			}
			case 'd':{
				int id;
				scanf("%d", &id);
				DeleteNode(&root, id);
				break;
			}
			case 'f':{
				int id;
				scanf("%d", &id);
				FindNode(root, id);
				break;
			}
			case 't':{
				int first = 1;
				PrintTree(root, &first);
				printf("\n");
				break;
			}
			case 'a':{
				int sum = 0, num = 0;
				AverageCount(root, &sum, &num);
				if(num == 0) break;
				double ave = sum * 1.0 / num;
				printf("%.2f\n", ave);
				break;
			}
			case 'm':{
				if(root == NULL) break;
				int maxId = root->userID;
				int maxLoad = root->Load;
				MaxLoad(root, &maxId, &maxLoad);
				printf("%d %d\n", maxId, maxLoad);
				break;
			}
			case 'q':{
				DeleteTree(root);
				printf("程序退出");
				return 0;
			}
		}
	}
	return 0;
}

// BST 插入：返回1成功，0重复ID
int InsertNode(BTTree *root, int id, int load)
{
	if(*root == NULL)
	{
		*root = (BTTree)malloc(sizeof(BTNode));
		(*root)->userID = id;
		(*root)->Load = load;
		(*root)->lchild = (*root)->rchild = NULL;
		return 1;
	}
	if(id == (*root)->userID)
	{
		return 0; // 重复ID，不插入
	}
	else if(id < (*root)->userID)
	{
		return InsertNode(&(*root)->lchild, id, load);
	}
	else
	{
		return InsertNode(&(*root)->rchild, id, load);
	}
}

// 查找
void FindNode(BTTree root, int id)
{
	if(root == NULL)
	{
		printf("Not Found\n");
		return;
	}
	if(root->userID == id)
	{
		printf("%d\n", root->Load);
		return;
	}
	if(id < root->userID)
		FindNode(root->lchild, id);
	else
		FindNode(root->rchild, id);
}

// 递归实现 BST 删除（标准写法）
int DeleteNode(BTTree *root, int id)
{
	BTTree p, q;
	if(*root == NULL) return 0;

	// 找到待删结点
	if(id < (*root)->userID)
		return DeleteNode(&(*root)->lchild, id);
	else if(id > (*root)->userID)
		return DeleteNode(&(*root)->rchild, id);
	else
	{
		// 情况1：左孩子为空，右孩子顶替
		if((*root)->lchild == NULL)
		{
			p = *root;
			*root = (*root)->rchild;
			free(p);
		}
		// 情况2：右孩子为空，左孩子顶替
		else if((*root)->rchild == NULL)
		{
			p = *root;
			*root = (*root)->lchild;
			free(p);
		}
		// 情况3：左右都有孩子 → 找中序前驱（左子树最右结点）
		else
		{
			p = *root;
			q = (*root)->lchild;
			while(q->rchild)
			{
				p = q;
				q = q->rchild;
			}
			// 用前驱数据覆盖当前结点
			(*root)->userID = q->userID;
			(*root)->Load = q->Load;
			// 删除前驱结点
			if(p != *root)
				p->rchild = q->lchild;
			else
				p->lchild = q->lchild;
			free(q);
		}
		return 1;
	}
}

// 销毁整棵树
void DeleteTree(BTTree root)
{
	if(root == NULL) return;
	DeleteTree(root->lchild);
	DeleteTree(root->rchild);
	free(root);
}

// 统计总负荷、结点数
void AverageCount(BTTree root, int *sum, int *num)
{
	if(root == NULL) return;
	*sum += root->Load;
	(*num)++;
	AverageCount(root->lchild, sum, num);
	AverageCount(root->rchild, sum, num);
}

// 遍历找最大负荷
void MaxLoad(BTTree root, int *maxId, int *maxLoad)
{
	if(root == NULL) return;
	if(root->Load > *maxLoad)
	{
		*maxId = root->userID;
		*maxLoad = root->Load;
	}
	MaxLoad(root->lchild, maxId, maxLoad);
	MaxLoad(root->rchild, maxId, maxLoad);
}

// 中序遍历，控制末尾无多余空格
void PrintTree(BTTree root, int *first)
{
	if(root == NULL) return;
	PrintTree(root->lchild, first);

	if(*first)
	{
		printf("%d %d", root->userID, root->Load);
		*first = 0;
	}
	else
	{
		printf(" %d %d", root->userID, root->Load);
	}

	PrintTree(root->rchild, first);
}