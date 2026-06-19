#include <stdio.h>
#include <stdlib.h>

typedef struct Edge {
    int id;
    int u, v;
    int weight;
} Edge;

// 并查集查找，带路径压缩
int find(int parent[], int i) {
    if (parent[i] != i) {
        parent[i] = find(parent, parent[i]);
    }
    return parent[i];
}

// 合并两个集合
void unionSet(int parent[], int x, int y) {
    parent[y] = x;
}

// qsort比较函数：按权重升序
int compareWeight(const void *a, const void *b) {
    Edge *a1 = (Edge *)a;
    Edge *b1 = (Edge *)b;
    return a1->weight - b1->weight;
}

// 将新边插入result数组，保持id升序
void insertSorted(Edge result[], int *e, Edge edge) {
    int pos = *e;
    // 后移比它id大的元素
    while (pos > 0 && result[pos - 1].id > edge.id) {
        result[pos] = result[pos - 1];
        pos--;
    }
    result[pos] = edge;
    (*e)++;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    Edge edges[m];
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d %d", &edges[i].id, &edges[i].u, &edges[i].v, &edges[i].weight);
    }

    // 所有边按权重从小到大排序
    qsort(edges, m, sizeof(Edge), compareWeight);

    int parent[n];
    for (int i = 0; i < n; i++)
        parent[i] = i;

    int minCost = 0;
    Edge result[m];
    int e = 0;

    // Kruskal核心循环
    for (int i = 0; i < m; i++) {
        int u = edges[i].u;
        int v = edges[i].v;
        int set_u = find(parent, u);
        int set_v = find(parent, v);

        // 不在同一集合，选这条边
        if (set_u != set_v) {
            insertSorted(result, &e, edges[i]);
            minCost += edges[i].weight;
            unionSet(parent, set_u, set_v);
        }
    }

    // 输出
    printf("%d\n", minCost);
    for (int i = 0; i < e; i++)
        printf("%d ", result[i].id);
    printf("\n");

    return 0;
}