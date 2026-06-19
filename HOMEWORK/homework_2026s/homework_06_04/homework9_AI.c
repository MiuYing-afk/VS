#include <stdio.h>
#include <string.h>
#include <limits.h>

#define MAXN 100  // 最大顶点数
#define INF INT_MAX  // 无穷大，表示不可达

// 全局变量（方便函数调用）
char vertex[MAXN][20];  // 存储顶点名称（字符串）
int graph[MAXN][MAXN];  // 邻接矩阵
int dist[MAXN];         // 存储最短路径长度
int visited[MAXN];      // 标记顶点是否已求出最短路径
int n;                  // 顶点数

// 查找顶点在数组中的下标
int findIndex(char *v) {
    for (int i = 0; i < n; i++) {
        if (strcmp(vertex[i], v) == 0) {
            return i;
        }
    }
    return -1;
}

// 迪杰斯特拉算法：start为起点下标
void dijkstra(int start) {
    // 初始化
    for (int i = 0; i < n; i++) {
        dist[i] = graph[start][i];  // 初始距离为起点到各点的直接距离
        visited[i] = 0;             // 所有顶点未访问
    }
    dist[start] = 0;    // 起点到自身距离为0
    visited[start] = 1; // 标记起点已处理

    // 遍历n-1次，处理剩余所有顶点
    for (int i = 1; i < n; i++) {
        // 第一步：找到未访问的、距离最小的顶点minIndex
        int min = INF;
        int minIndex = -1;
        for (int j = 0; j < n; j++) {
            if (!visited[j] && dist[j] < min) {
                min = dist[j];
                minIndex = j;
            }
        }

        // 无可达顶点，提前退出（处理不连通图）
        if (minIndex == -1) break;
        visited[minIndex] = 1; // 标记该顶点已处理

        // 第二步：松弛操作，更新最短路径
        for (int j = 0; j < n; j++) {
            // 如果j未访问、minIndex到j可达、且新路径更短
            if (!visited[j] && graph[minIndex][j] != INF && dist[minIndex] != INF
                && dist[j] > dist[minIndex] + graph[minIndex][j]) {
                dist[j] = dist[minIndex] + graph[minIndex][j];
            }
        }
    }
}

int main() {
    int m;
    // 1. 输入顶点数n和边数m
    scanf("%d %d", &n, &m);

    // 2. 初始化邻接矩阵：全部设为无穷大
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            graph[i][j] = INF;
        }
    }

    // 3. 输入顶点名称
    for (int i = 0; i < n; i++) {
        scanf("%s", vertex[i]);
    }

    // 4. 输入m条边，构建邻接矩阵（无向图）
    char u[20], v[20];
    int weight;
    for (int i = 0; i < m; i++) {
        scanf("%s %s %d", u, v, &weight);
        int uIdx = findIndex(u);
        int vIdx = findIndex(v);
        graph[uIdx][vIdx] = weight;
        graph[vIdx][uIdx] = weight; // 无向图双向赋值
    }

    // 5. 输入起点
    char startVertex[20];
    scanf("%s", startVertex);
    int start = findIndex(startVertex);

    // 6. 执行迪杰斯特拉算法
    dijkstra(start);

    // 7. 按输入顺序输出结果，不可达输出-1
    for (int i = 0; i < n; i++) {
        if (dist[i] == INF) {
            printf("%s -1\n", vertex[i]);
        } else {
            printf("%s %d\n", vertex[i], dist[i]);
        }
    }

    return 0;
}