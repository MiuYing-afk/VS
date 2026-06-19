#include <stdio.h>
#include <stdlib.h>

#define MAXN 200002
int f[MAXN], d[MAXN];
int n, minn;

// 带路径压缩的查找函数
int find(int x) {
    if (f[x] != x) {
        int root = find(f[x]);
        d[x] += d[f[x]];  // 更新x到根的距离
        f[x] = root;
    }
    return f[x];
}

void check(int a, int b) {
    int ra = find(a);
    int rb = find(b);
    if (ra != rb) {
        // 不连通，合并集合
        f[ra] = rb;
        d[ra] = d[b] + 1 - d[a];
    } else {
        // 形成环，计算环长并更新最小值
        int circle = d[a] + d[b] + 1;
        if (circle < minn)
            minn = circle;
    }
}

int main() {
    int i, t;
    scanf("%d", &n);
    for (i = 1; i <= n; i++) {
        f[i] = i;
        d[i] = 0;
    }
    minn = 0x7fffffff;
    for (i = 1; i <= n; i++) {
        scanf("%d", &t);
        check(i, t);
    }
    printf("%d", minn);
    return 0;
}