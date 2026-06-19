#include <stdio.h>
#include <stdlib.h>

// -------------------- 二叉树结点定义 --------------------
typedef char TElemType;
typedef struct BiTNode {
    TElemType data;
    struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;

// -------------------- 栈定义（存路径） --------------------
#define MAXSIZE 100
typedef struct {
    TElemType data[MAXSIZE];
    int top; // 栈顶指针，-1 表示空栈
} Stack;

// 初始化栈
void InitStack(Stack *S) {
    S->top = -1;
}

// 入栈
int Push(Stack *S, TElemType x) {
    if (S->top >= MAXSIZE - 1) return 0; // 栈满
    S->data[++S->top] = x;
    return 1;
}

// 出栈
int Pop(Stack *S, TElemType *x) {
    if (S->top == -1) return 0; // 栈空
    *x = S->data[S->top--];
    return 1;
}

// 判断栈是否为空
int StackEmpty(Stack *S) {
    return S->top == -1;
}

// 打印栈中所有元素（从栈底到栈顶，即从根到叶子）
void PrintStack(Stack *S) {
    printf("路径: ");
    for (int i = 0; i <= S->top; i++) {
        printf("%c ", S->data[i]);
    }
    printf("\n");
}

// -------------------- 创建二叉树（按先序序列，# 表示空） --------------------
// 例如输入: A B D # # # C # #  对应树:
//      A
//     / \
//    B   C
//   /
//  D
void CreateBiTree(BiTree *T) {
    char ch;
    scanf(" %c", &ch);
    if (ch == '#') {
        *T = NULL;
    } else {
        *T = (BiTree)malloc(sizeof(BiTNode));
        (*T)->data = ch;
        CreateBiTree(&(*T)->lchild);
        CreateBiTree(&(*T)->rchild);
    }
}

// -------------------- 核心函数：输出根到所有叶子的路径 --------------------
void AllPath(BiTree T, Stack *S) {
    if (T != NULL) {
        // 1. 当前结点入栈
        Push(S, T->data);

        // 2. 判断是否为叶子结点
        if (T->lchild == NULL && T->rchild == NULL) {
            PrintStack(S); // 是叶子，打印路径
        } else {
            // 不是叶子，递归处理左右子树
            AllPath(T->lchild, S);
            AllPath(T->rchild, S);
        }

        // 3. 回溯：当前结点出栈
        TElemType temp;
        Pop(S, &temp);
    }
}

// -------------------- 主函数测试 --------------------
int main() {
    BiTree T;
    Stack S;
    InitStack(&S);

    printf("请输入二叉树的先序序列（# 表示空结点）：\n");
    CreateBiTree(&T);

    printf("根到所有叶子结点的路径：\n");
    AllPath(T, &S);

    return 0;
}