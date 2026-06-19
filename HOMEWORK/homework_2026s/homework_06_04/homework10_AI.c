#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define MAX_VERTICES 100
#define INF 20000

// 邻接矩阵表示图
int adjMatrix[MAX_VERTICES][MAX_VERTICES];
// 顶点数组
char vertices[MAX_VERTICES][10];
// 最小生成树的边
int parent[MAX_VERTICES];
// 关键值数组
int key[MAX_VERTICES];
// 访问标记数组
int mstSet[MAX_VERTICES];

void init(int n, int m){
// 初始化邻接矩阵
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) {
                adjMatrix[i][j] = 0;
            } else {
                adjMatrix[i][j] = INF;
            }
        }
    }
}

// 查找顶点索引
int findVertexIndex(char u[], int n) {
    for (int i = 0; i < n; i++) {
        if (strcmp(vertices[i], u) == 0) {
            return i;
        }
    }
    return -1; // 顶点未找到
}

void create(int n, int m){
    char u[10], v[10];
    // 读取顶点
    for (int i = 0; i < n; i++) {
        scanf("%s", vertices[i]);
    }

    // 读取边并构建邻接矩阵
    for (int i = 0; i < m; i++) {
        int value;
        scanf("%s %s %d", u, v, &value);
        int uIndex = findVertexIndex(u, n);
        int vIndex = findVertexIndex(v, n);
        adjMatrix[uIndex][vIndex] = value;
        adjMatrix[vIndex][uIndex] = value; // 无向图，对称
    }
}

void printPrim(int n){
    // 输出最小生成树的边
    for (int i = 1; i < n; i++) {
        printf("%s-%s %d\n", vertices[parent[i]], vertices[i], adjMatrix[i][parent[i]]);
    }
}

// Prim算法
void prim(int n) {
    // 初始化key、mstSet数组
    for (int i = 0; i < n; i++) {
        key[i] = INF;
        mstSet[i] = 0;
    }
    // 从0号顶点(顶点A)开始生成MST
    key[0] = 0;
    parent[0] = -1; // 根节点无父结点

    // 循环选出n个顶点
    for (int cnt = 0; cnt < n; cnt++) {
        // 步骤1：选不在MST里、key最小的顶点u
        int min = INF, u = -1;
        for (int i = 0; i < n; i++) {
            if (!mstSet[i] && key[i] < min) {
                min = key[i];
                u = i;
            }
        }
        mstSet[u] = 1; // 加入生成树

        // 步骤2：更新u邻接点的key值
        for (int v = 0; v < n; v++) {
            // 不在MST、有边、原key更大才更新
            if (!mstSet[v] && adjMatrix[u][v] != INF && adjMatrix[u][v] < key[v]) {
                key[v] = adjMatrix[u][v];
                parent[v] = u;
            }
        }
    }
}

int main() {
    int n, m;
    // 读取顶点数和边数
    scanf("%d %d", &n, &m);
    init(n, m);
    create(n, m);
    // 使用Prim算法构造最小生成树
    prim(n);
    printPrim(n);
    return 0;
}