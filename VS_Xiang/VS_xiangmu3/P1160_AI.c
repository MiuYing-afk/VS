#include <stdio.h>
#include <stdlib.h>

#define MAXN 100010  // 最大节点数量

int left[MAXN];   // left[i] 表示 i 号节点的**左边**是谁
int right[MAXN];  // right[i] 表示 i 号节点的**右边**是谁
int del[MAXN];    // del[i] = 1 表示 i 号节点已经被删除

int main() {
    int n, m;
    scanf("%d", &n);  // 输入节点总数 n

    // 初始化：1号节点最开始左右都没有节点（用0表示空）
    left[1] = 0;
    right[1] = 0;

    // ----------------------
    // 第一步：建链表（插入 n-1 个节点）
    // ----------------------
    for (int i = 2; i <= n; i++) {
        int k, p;
        scanf("%d %d", &k, &p);  // 把 i 插到 k 的 左(p=0) 或 右(p=1)

        if (p == 0) {
            // 插到 k 的**左边**
            left[i] = left[k];    // i 的左边 = 原来 k 的左边
            right[i] = k;         // i 的右边 = k

            if (left[k] != 0) {   // 如果 k 原来有左边节点
                right[left[k]] = i;  // 让那个节点的右边指向 i
            }
            left[k] = i;  // k 的左边变成 i
        } else {
            // 插到 k 的**右边**
            right[i] = right[k];  // i 的右边 = 原来 k 的右边
            left[i] = k;          // i 的左边 = k

            if (right[k] != 0) {  // 如果 k 原来有右边节点
                left[right[k]] = i;  // 让那个节点的左边指向 i
            }
            right[k] = i;  // k 的右边变成 i
        }
    }

    // ----------------------
    // 第二步：删除 m 个节点
    // ----------------------
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        int x;
        scanf("%d", &x);

        if (del[x]) continue;  // 已经删过了，跳过
        del[x] = 1;            // 标记删除

        // 把 x 从链表中“摘下来”
        if (left[x] != 0) {
            right[left[x]] = right[x];  // 左邻居的右边 = 我的右邻居
        }
        if (right[x] != 0) {
            left[right[x]] = left[x];   // 右邻居的左边 = 我的左邻居
        }
    }

    // ----------------------
    // 第三步：找到链表头（最左边的节点）
    // ----------------------
    int head = 1;
    while (left[head] != 0) {  // 一直往左找，直到左边为空
        head = left[head];
    }

    // ----------------------
    // 第四步：遍历输出整条链表
    // ----------------------
    while (head != 0) {
        printf("%d ", head);
        head = right[head];  // 一直往右走
    }
    printf("\n");

    return 0;
}