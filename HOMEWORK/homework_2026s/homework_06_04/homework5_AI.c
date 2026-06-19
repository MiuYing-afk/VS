#include <stdio.h>
#include <string.h>

#define MAX 100  // 最大顶点数

// 全局变量（方便递归函数访问）
int n;                  // 顶点数
char vertex[MAX][10];   // 存储顶点字符串
int graph[MAX][MAX];    // 邻接矩阵
int visited[MAX];       // 访问标记数组

// 查找顶点在数组中的下标
int findIndex(char *v) {
    for (int i = 0; i < n; i++) {
        if (strcmp(vertex[i], v) == 0) {
            return i;
        }
    }
    return -1;
}

// 深度优先遍历
void dfs(int v) {
    // 1. 标记当前顶点已访问
    visited[v] = 1;
    // 2. 输出当前顶点
    printf("%s ", vertex[v]);
    
    // 3. 遍历所有邻接顶点
    for (int i = 0; i < n; i++) {
        // 如果有边 且 未访问
        if (graph[v][i] == 1 && visited[i] == 0) {
            dfs(i);
        }
    }
}

int main() {
    int m;
    // 1. 输入顶点数和边数
    scanf("%d %d", &n, &m);
    
    // 2. 输入顶点
    for (int i = 0; i < n; i++) {
        scanf("%s", vertex[i]);
    }
    
    // 3. 初始化邻接矩阵为0
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            graph[i][j] = 0;
        }
    }
    
    // 4. 输入m条边，构建邻接矩阵
    char u[10], v[10];
    for (int i = 0; i < m; i++) {
        scanf("%s %s", u, v);
        int a = findIndex(u);
        int b = findIndex(v);
        graph[a][b] = 1;
        graph[b][a] = 1;  // 无向图，双向赋值
    }
    
    // 5. 初始化访问标记
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
    }
    
    // 6. 输入起点，开始DFS
    char start[10];
    scanf("%s", start);
    int startIndex = findIndex(start);
    dfs(startIndex);
    
    return 0;
}