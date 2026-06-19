#include <stdio.h>

int main() {
    int l, m;
    scanf("%d %d", &l, &m);
    // 标记树是否被移除，0 表示保留，1 表示移除
    int tree[l + 1];
    // 初始时所有树都保留
    for (int i = 0; i <= l; i++) {
        tree[i] = 0;
    }
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        // 标记区间 [u, v] 内的树为移除
        for (int j = u; j <= v; j++) {
            tree[j] = 1;
        }
    }
    int remaining = 0;
    // 统计保留的树的数量
    for (int i = 0; i <= l; i++) {
        if (tree[i] == 0) {
            remaining++;
        }
    }
    printf("%d\n", remaining);
    return 0;
}