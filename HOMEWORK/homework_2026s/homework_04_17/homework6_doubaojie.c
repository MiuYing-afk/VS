#include "stdio.h"
#include "stdlib.h"
#include "string.h"

typedef struct BTNode {
    int lflag, rflag;
    char data;
    struct BTNode *lchild;
    struct BTNode *rchild;
} BTNode, *BTTree;

BTTree Inithead();
BTTree CreatNode(char data);
void CreatBTTree(BTTree *T, char *levelorder);
void ClueBTTree(BTTree head, BTTree T);
void InClue(BTTree T, BTTree *pre);
BTTree InPostNode(BTTree p);
void PrintBTTree(BTTree head);

int main() {
    BTTree head = Inithead();
    char levelorder[105];
    scanf("%s", levelorder);

    BTTree T = NULL;
    CreatBTTree(&T, levelorder);

    if (T) {
        head->lchild = T; // 头结点左孩子指向根
        ClueBTTree(head, T);
    } else {
        head->lchild = head; // 空树时，左孩子指向自己
    }

    PrintBTTree(head);
    return 0;
}

// 创建头结点
BTTree Inithead() {
    BTTree head = (BTTree)malloc(sizeof(BTNode));
    if (!head) {
        printf("内存分配失败！\n");
        exit(1);
    }
    head->lflag = 0;
    head->rflag = 1;
    head->lchild = NULL;
    head->rchild = head;
    return head;
}

// 创建结点
BTTree CreatNode(char data) {
    if (data == '#') return NULL;
    BTTree new = (BTTree)malloc(sizeof(BTNode));
    if (!new) {
        printf("内存分配失败！\n");
        exit(1);
    }
    new->data = data;
    new->lchild = new->rchild = NULL;
    new->lflag = new->rflag = 0;
    return new;
}

// 先序建树（无全局变量版本）
void CreatBTTree(BTTree *T, char *levelorder) {
    static int idx = 0;
    if (levelorder[idx] == '\0') {
        idx = 0; // 重置，方便下次调用
        *T = NULL;
        return;
    }
    if (levelorder[idx] == '#') {
        *T = NULL;
        idx++;
        return;
    }
    *T = CreatNode(levelorder[idx++]);
    CreatBTTree(&(*T)->lchild, levelorder);
    CreatBTTree(&(*T)->rchild, levelorder);
}

// 递归中序线索化辅助函数
void InClue(BTTree T, BTTree *pre) {
    if (!T) return;

    InClue(T->lchild, pre);

    // 处理左线索
    if (!T->lchild) {
        T->lflag = 1;
        T->lchild = *pre;
    }
    // 处理前驱的右线索
    if (*pre && !(*pre)->rchild) {
        (*pre)->rflag = 1;
        (*pre)->rchild = T;
    }

    *pre = T;
    InClue(T->rchild, pre);
}

// 对外线索化函数，含头结点处理
void ClueBTTree(BTTree head, BTTree T) {
    BTTree pre = head;
    InClue(T, &pre);

    // 收尾：最后一个结点的右线索连回头结点
    pre->rflag = 1;
    pre->rchild = head;

    // 头结点的右孩子指向最后一个结点
    head->rchild = pre;
}

// 查找中序后继
BTTree InPostNode(BTTree p) {
    if (p->rflag == 1) {
        return p->rchild;
    } else {
        BTTree q = p->rchild;
        while (q->lflag == 0) {
            q = q->lchild;
        }
        return q;
    }
}

// 中序遍历线索二叉树，输出标志位
void PrintBTTree(BTTree head) {
    if (head->lchild == head) return;

    BTTree p = head->lchild;
    while (p->lflag == 0) {
        p = p->lchild;
    }

    while (p != head) {
        printf("%d%d ", p->lflag, p->rflag);
        p = InPostNode(p);
    }
}