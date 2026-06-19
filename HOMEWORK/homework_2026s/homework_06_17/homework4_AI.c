#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXN 1000

// 用typedef封装图结构，替代全局变量
typedef struct {
    int graph[MAXN][MAXN];
    int inDegree[MAXN];
} Graph;

// 节点比较函数
int compare(const void* a, const void* b) {
    return *(int*)a - *(int*)b;
}

// 初始化图
void initGraph(Graph* g, int n) {
    memset(g->graph, 0, sizeof(g->graph));
    memset(g->inDegree, 0, sizeof(g->inDegree));
}

// 读入边构建图
void createGraph(Graph* g, int m) {
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        g->graph[u][v] = 1;
        g->inDegree[v]++;
    }
}

// 拓扑排序，输出字典序最小序列
void topologicalSort(Graph* g, int n) {
    int cnt = 0;
    int res[MAXN];

    while (cnt < n) {
        // 从小到大找入度为0的最小节点
        int cur = -1;
        for (int i = 1; i <= n; i++) {
            if (g->inDegree[i] == 0) {
                cur = i;
                break;
            }
        }

        res[cnt++] = cur;
        // 消除该点所有出边
        for (int v = 1; v <= n; v++) {
            if (g->graph[cur][v] == 1) {
                g->inDegree[v]--;
            }
        }
        g->inDegree[cur] = -1; // 标记已使用
    }

    // 打印结果
    for (int i = 0; i < n; i++) {
        if (i > 0) printf(" ");
        printf("%d", res[i]);
    }
    printf("\n");
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    Graph g;         // 局部图变量，不再全局
    int nodes[MAXN]; // 局部节点数组
    for (int i = 0; i < n; i++) {
        nodes[i] = i + 1;
    }

    initGraph(&g, n);
    createGraph(&g, m);
    qsort(nodes, n, sizeof(int), compare);
    topologicalSort(&g, n);

    return 0;
}