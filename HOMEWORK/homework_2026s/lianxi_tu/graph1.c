#include "stdio.h"
#include "stdlib.h"
#include "string.h"

#define VNUM 20
#define MAXSIZE 20
#define INF 99999   // 代表无穷大（两点不连通）

typedef int VertexType;
typedef int WeightType;
typedef int InfoType;
typedef int GelemType;

// 邻接矩阵 - 图（无权）
typedef struct {
    VertexType vexs[VNUM];
    int arcs[VNUM][VNUM];
    int vexNum, arcNum;
} MGraph;

// 邻接矩阵 - 网（带权）
typedef struct {
    VertexType vexs[VNUM];
    WeightType arcs[VNUM][VNUM];
    int vexNum, arcNum;
} NetGraph;

// 邻接表 边结点
typedef struct ArcNode {
    int adjvex;
    struct ArcNode *nextArc;
    InfoType info;
} ArcNode;

// 邻接表 顶点表头结点
typedef struct VertexNode {
    GelemType vertex;
    ArcNode *firstArc;
} VertexNode;

// 邻接表整体结构
typedef struct ALGraph {
    VertexNode adjlist[MAXSIZE];
    int vexNum, arcNum;
} ALGraph;

// ===================== 克鲁斯卡尔：边结构体 =====================
typedef struct
{
    int start;
    int end;
    int weight;
} Edge;

// ===================== 函数声明 =====================
// 邻接矩阵相关
void crt_UndirectedGraph(MGraph *G);
void crt_DirectedGraph(MGraph *G);
void dispMGraph(MGraph G);
void DFS_MGraph(MGraph *G, int v, int visited[]);
void BFS_MGraph(MGraph *G, int v, int visited[]);
void DFS_Traverse_MGraph(MGraph *G);
void BFS_Traverse_MGraph(MGraph *G);

// 网 & 度数统计
void crt_UndirectedNet(NetGraph *G);
int getDegree(NetGraph *G, int v);
void showAllDegree(NetGraph *G);

// 邻接表相关
void crt_ALGraph(ALGraph *G);
void crt_ReverseALGraph(ALGraph *G);
void crt_Undir_ALGraph(ALGraph *G);
void dispALGraph(ALGraph G);
void freeALGraph(ALGraph *G);
void Calc_In_Out_Degree(ALGraph *G);
void DFS_ALGraph(ALGraph *G, int v, int visited[]);
void BFS_ALGraph(ALGraph *G, int v, int visited[]);
void DFS_Traverse_ALGraph(ALGraph *G);
void BFS_Traverse_ALGraph(ALGraph *G);

// 迪杰斯特拉 单源最短路径
void Dijkstra(NetGraph *G, int start);
// 普里姆 Prim 最小生成树
void Prim(NetGraph *G);
// 克鲁斯卡尔 Kruskal 最小生成树
void Kruskal(NetGraph *G);

int main()
{
    int op;
    while (1)
    {
        printf("\n========== 图操作菜单 ==========\n");
        printf("0.  退出程序\n");
        printf("1.  创建无向图(邻接矩阵) + 显示\n");
        printf("2.  创建有向图(邻接矩阵) + 显示\n");
        printf("3.  创建无向网(带权) + 查看各顶点度数\n");
        printf("4.  创建无向图(邻接表) + 显示\n");
        printf("5.  创建有向图(普通邻接表) + 显示\n");
        printf("6.  创建有向图(逆邻接表) + 显示\n");
        printf("7.  有向图 计算入度/出度\n");
        printf("8.  邻接矩阵 深度优先遍历(DFS,支持非连通)\n");
        printf("9.  邻接矩阵 广度优先遍历(BFS,支持非连通)\n");
        printf("10. 邻接表 深度优先遍历(DFS,支持非连通)\n");
        printf("11. 邻接表 广度优先遍历(BFS,支持非连通)\n");
        printf("12. 迪杰斯特拉(Dijkstra) 单源最短路径\n");
        printf("13. 普里姆(Prim) 最小生成树\n");
        printf("14. 克鲁斯卡尔(Kruskal) 最小生成树\n");
        printf("请输入选择：");
        scanf("%d", &op);

        MGraph mg;
        NetGraph ng;
        ALGraph alg;
        int startVex;

        switch (op)
        {
            case 1:
                printf("\n--- 无向图 邻接矩阵 ---\n");
                crt_UndirectedGraph(&mg);
                dispMGraph(mg);
                break;
            case 2:
                printf("\n--- 有向图 邻接矩阵 ---\n");
                crt_DirectedGraph(&mg);
                dispMGraph(mg);
                break;
            case 3:
                printf("\n--- 无向网 + 顶点度数 ---\n");
                crt_UndirectedNet(&ng);
                showAllDegree(&ng);
                break;
            case 4:
                printf("\n--- 无向图 邻接表 ---\n");
                crt_Undir_ALGraph(&alg);
                dispALGraph(alg);
                freeALGraph(&alg);
                break;
            case 5:
                printf("\n--- 有向图 普通邻接表 ---\n");
                crt_ALGraph(&alg);
                dispALGraph(alg);
                freeALGraph(&alg);
                break;
            case 6:
                printf("\n--- 有向图 逆邻接表 ---\n");
                crt_ReverseALGraph(&alg);
                dispALGraph(alg);
                freeALGraph(&alg);
                break;
            case 7:
                printf("\n--- 有向图 计算入度/出度 ---\n");
                crt_ALGraph(&alg);
                Calc_In_Out_Degree(&alg);
                freeALGraph(&alg);
                break;
            case 8:
                printf("\n--- 邻接矩阵 深度优先遍历 ---\n");
                crt_UndirectedGraph(&mg);
                DFS_Traverse_MGraph(&mg);
                break;
            case 9:
                printf("\n--- 邻接矩阵 广度优先遍历 ---\n");
                crt_UndirectedGraph(&mg);
                BFS_Traverse_MGraph(&mg);
                break;
            case 10:
                printf("\n--- 邻接表 深度优先遍历 ---\n");
                crt_Undir_ALGraph(&alg);
                DFS_Traverse_ALGraph(&alg);
                freeALGraph(&alg);
                break;
            case 11:
                printf("\n--- 邻接表 广度优先遍历 ---\n");
                crt_Undir_ALGraph(&alg);
                BFS_Traverse_ALGraph(&alg);
                freeALGraph(&alg);
                break;
            case 12:
                printf("\n--- 迪杰斯特拉 单源最短路径 ---\n");
                crt_UndirectedNet(&ng);
                printf("请输入起点顶点编号：");
                scanf("%d", &startVex);
                Dijkstra(&ng, startVex - 1);
                break;
            case 13:
                printf("\n--- 普里姆(Prim) 最小生成树 ---\n");
                crt_UndirectedNet(&ng);
                Prim(&ng);
                break;
            case 14:
                printf("\n--- 克鲁斯卡尔(Kruskal) 最小生成树 ---\n");
                crt_UndirectedNet(&ng);
                Kruskal(&ng);
                break;
            // =================================
            case 0:
                printf("程序已退出\n");
                exit(0);
                break;
            default:
                printf("输入有误，请重新选择！\n");
                break;
        }
    }
    return 0;
}

// ==================== 原有基础函数 ====================
// 创建无向图 邻接矩阵
void crt_UndirectedGraph(MGraph *G) {
    scanf("%d%d", &G->vexNum, &G->arcNum);
    for (int i = 0; i < G->vexNum; i++)
        scanf("%d", &G->vexs[i]);

    for (int i = 0; i < G->vexNum; i++)
        for (int j = 0; j < G->vexNum; j++)
            G->arcs[i][j] = 0;

    for (int k = 0; k < G->arcNum; k++) {
        int i, j;
        scanf("%d%d", &i, &j);
        G->arcs[i - 1][j - 1] = 1;
        G->arcs[j - 1][i - 1] = 1;
    }
}

// 创建有向图 邻接矩阵
void crt_DirectedGraph(MGraph *G) {
    scanf("%d%d", &G->vexNum, &G->arcNum);
    for (int i = 0; i < G->vexNum; i++)
        scanf("%d", &G->vexs[i]);

    for (int i = 0; i < G->vexNum; i++)
        for (int j = 0; j < G->vexNum; j++)
            G->arcs[i][j] = 0;

    for (int k = 0; k < G->arcNum; k++) {
        int i, j;
        scanf("%d%d", &i, &j);
        G->arcs[i - 1][j - 1] = 1;
    }
}

// 显示邻接矩阵
void dispMGraph(MGraph G) {
    printf("顶点集合：");
    for (int i = 0; i < G.vexNum; i++)
        printf("%d ", G.vexs[i]);
    printf("\n邻接矩阵：\n");
    for (int i = 0; i < G.vexNum; i++) {
        for (int j = 0; j < G.vexNum; j++)
            printf("%4d", G.arcs[i][j]);
        printf("\n");
    }
}

// 创建无向网（带权）
void crt_UndirectedNet(NetGraph *G) {
    scanf("%d%d", &G->vexNum, &G->arcNum);
    for (int i = 0; i < G->vexNum; i++)
        scanf("%d", &G->vexs[i]);

    for (int i = 0; i < G->vexNum; i++)
        for (int j = 0; j < G->vexNum; j++)
            G->arcs[i][j] = INF;
    for (int i = 0; i < G->vexNum; i++)
        G->arcs[i][i] = 0;

    for (int k = 0; k < G->arcNum; k++) {
        int i, j, w;
        scanf("%d%d%d", &i, &j, &w);
        G->arcs[i - 1][j - 1] = w;
        G->arcs[j - 1][i - 1] = w;
    }
}

// 计算无向网指定下标顶点的度
int getDegree(NetGraph *G, int v) {
    int degree = 0;
    for (int j = 0; j < G->vexNum; j++) {
        if (G->arcs[v][j] != 0 && G->arcs[v][j] != INF)
            degree++;
    }
    return degree;
}

// 遍历输出所有顶点度数
void showAllDegree(NetGraph *G) {
    printf("\n===== 各顶点度数 =====\n");
    for (int i = 0; i < G->vexNum; i++) {
        int d = getDegree(G, i);
        printf("顶点 %d  的度：%d\n", G->vexs[i], d);
    }
}

// 创建无向图邻接表
void crt_Undir_ALGraph(ALGraph *G)
{
    int i, j, k;
    scanf("%d%d", &G->vexNum, &G->arcNum);
    for (i = 0; i < G->vexNum; i++)
    {
        scanf("%d", &G->adjlist[i].vertex);
        G->adjlist[i].firstArc = NULL;
    }
    for (k = 0; k < G->arcNum; k++)
    {
        scanf("%d%d", &i, &j);
        ArcNode *p1 = (ArcNode *)malloc(sizeof(ArcNode));
        p1->adjvex = j - 1;
        p1->nextArc = G->adjlist[i - 1].firstArc;
        G->adjlist[i - 1].firstArc = p1;

        ArcNode *p2 = (ArcNode *)malloc(sizeof(ArcNode));
        p2->adjvex = i - 1;
        p2->nextArc = G->adjlist[j - 1].firstArc;
        G->adjlist[j - 1].firstArc = p2;
    }
}

// 创建有向图 普通邻接表（出边表）
void crt_ALGraph(ALGraph *G) {
    int i, j, k;
    scanf("%d%d", &G->vexNum, &G->arcNum);
    for (i = 0; i < G->vexNum; i++) {
        scanf("%d", &G->adjlist[i].vertex);
        G->adjlist[i].firstArc = NULL;
    }
    for (k = 0; k < G->arcNum; k++) {
        scanf("%d%d", &i, &j);
        ArcNode *p = (ArcNode *)malloc(sizeof(ArcNode));
        p->adjvex = j - 1;
        p->nextArc = G->adjlist[i - 1].firstArc;
        G->adjlist[i - 1].firstArc = p;
    }
}

// 创建有向图 逆邻接表（入边表）
void crt_ReverseALGraph(ALGraph *G) {
    int i, j, k;
    scanf("%d%d", &G->vexNum, &G->arcNum);
    for (i = 0; i < G->vexNum; i++) {
        scanf("%d", &G->adjlist[i].vertex);
        G->adjlist[i].firstArc = NULL;
    }
    for (k = 0; k < G->arcNum; k++) {
        scanf("%d%d", &i, &j);
        int start = i - 1;
        int end = j - 1;
        ArcNode *p = (ArcNode *)malloc(sizeof(ArcNode));
        p->adjvex = start;
        p->nextArc = G->adjlist[end].firstArc;
        G->adjlist[end].firstArc = p;
    }
}

// 显示邻接表 / 逆邻接表
void dispALGraph(ALGraph G) {
    printf("邻接表内容：\n");
    for (int i = 0; i < G.vexNum; i++) {
        printf("顶点 %d : ", G.adjlist[i].vertex);
        ArcNode *p = G.adjlist[i].firstArc;
        while (p != NULL) {
            printf("%d  ", p->adjvex + 1);
            p = p->nextArc;
        }
        printf("\n");
    }
}

// 释放邻接表动态内存
// 释放邻接表动态内存（加固版）
void freeALGraph(ALGraph *G)
{
    if (G == NULL)
        return;

    for (int i = 0; i < G->vexNum; i++)
    {
        ArcNode *p = G->adjlist[i].firstArc;
        while (p != NULL)
        {
            ArcNode *q = p;
            p = p->nextArc;
            free(q);
        }
        G->adjlist[i].firstArc = NULL;
    }
    G->vexNum = 0;
    G->arcNum = 0;
}

// 计算有向图每个顶点 入度、出度
void Calc_In_Out_Degree(ALGraph *G)
{
    int in[VNUM] = {0};
    int out[VNUM] = {0};
    for (int i = 0; i < G->vexNum; i++)
    {
        ArcNode *p = G->adjlist[i].firstArc;
        while (p != NULL)
        {
            out[i]++;
            in[p->adjvex]++;
            p = p->nextArc;
        }
    }
    printf("\n===== 各顶点入度、出度 =====\n");
    for (int i = 0; i < G->vexNum; i++)
    {
        printf("顶点 %d ：入度=%d , 出度=%d\n",
               G->adjlist[i].vertex, in[i], out[i]);
    }
}

// ==================== 单点遍历（原有） ====================
// 邻接矩阵 深度优先遍历 DFS（递归，单个连通分量）
void DFS_MGraph(MGraph *G, int v, int visited[])
{
    int w;
    visited[v] = 1;
    printf("%d ", G->vexs[v]);

    for (w = 0; w < G->vexNum; w++)
    {
        if (G->arcs[v][w] == 1 && !visited[w])
        {
            DFS_MGraph(G, w, visited);
        }
    }
}

// 邻接矩阵 广度优先遍历 BFS（单个连通分量）
void BFS_MGraph(MGraph *G, int v, int visited[])
{
    int queue[VNUM], front = 0, rear = 0;
    int w;
    visited[v] = 1;
    printf("%d ", G->vexs[v]);
    queue[rear++] = v;

    while (front < rear)
    {
        int cur = queue[front++];
        for (w = 0; w < G->vexNum; w++)
        {
            if (G->arcs[cur][w] == 1 && !visited[w])
            {
                visited[w] = 1;
                printf("%d ", G->vexs[w]);
                queue[rear++] = w;
            }
        }
    }
}

// 邻接表 深度优先遍历 DFS（单个连通分量）
void DFS_ALGraph(ALGraph *G, int v, int visited[])
{
    ArcNode *p;
    visited[v] = 1;
    printf("%d ", G->adjlist[v].vertex);

    p = G->adjlist[v].firstArc;
    while (p != NULL)
    {
        int w = p->adjvex;
        if (!visited[w])
        {
            DFS_ALGraph(G, w, visited);
        }
        p = p->nextArc;
    }
}

// 邻接表 广度优先遍历 BFS（单个连通分量）
void BFS_ALGraph(ALGraph *G, int v, int visited[])
{
    int queue[VNUM], front = 0, rear = 0;
    ArcNode *p;
    visited[v] = 1;
    printf("%d ", G->adjlist[v].vertex);
    queue[rear++] = v;

    while (front < rear)
    {
        int cur = queue[front++];
        p = G->adjlist[cur].firstArc;
        while (p != NULL)
        {
            int w = p->adjvex;
            if (!visited[w])
            {
                visited[w] = 1;
                printf("%d ", G->adjlist[w].vertex);
                queue[rear++] = w;
            }
            p = p->nextArc;
        }
    }
}

// ==================== 全局遍历（支持非连通图） ====================
// 邻接矩阵 全局DFS（连通/非连通都适用）
void DFS_Traverse_MGraph(MGraph *G)
{
    int visited[VNUM] = {0};
    printf("DFS 遍历序列：");
    for (int i = 0; i < G->vexNum; i++)
    {
        if (!visited[i])
        {
            DFS_MGraph(G, i, visited);
        }
    }
    printf("\n");
}

// 邻接矩阵 全局BFS（连通/非连通都适用）
void BFS_Traverse_MGraph(MGraph *G)
{
    int visited[VNUM] = {0};
    printf("BFS 遍历序列：");
    for (int i = 0; i < G->vexNum; i++)
    {
        if (!visited[i])
        {
            BFS_MGraph(G, i, visited);
        }
    }
    printf("\n");
}

// 邻接表 全局DFS（连通/非连通都适用）
void DFS_Traverse_ALGraph(ALGraph *G)
{
    int visited[VNUM] = {0};
    printf("DFS 遍历序列：");
    for (int i = 0; i < G->vexNum; i++)
    {
        if (!visited[i])
        {
            DFS_ALGraph(G, i, visited);
        }
    }
    printf("\n");
}

// 邻接表 全局BFS（连通/非连通都适用）
void BFS_Traverse_ALGraph(ALGraph *G)
{
    int visited[VNUM] = {0};
    printf("BFS 遍历序列：");
    for (int i = 0; i < G->vexNum; i++)
    {
        if (!visited[i])
        {
            BFS_ALGraph(G, i, visited);
        }
    }
    printf("\n");
}

// ===================== 1. 迪杰斯特拉 Dijkstra 单源最短路径 =====================
void Dijkstra(NetGraph *G, int start)
{
    int dist[VNUM];     // 起点到各点最短距离
    int visited[VNUM];  // 是否并入最短路径集合
    int path[VNUM];     // 前驱结点，记录路径
    int n = G->vexNum;

    // 初始化
    for (int i = 0; i < n; i++)
    {
        dist[i] = G->arcs[start][i];
        visited[i] = 0;
        if (dist[i] < INF)
            path[i] = start;
        else
            path[i] = -1;
    }
    visited[start] = 1;

    // 迭代 n-1 次
    for (int i = 1; i < n; i++)
    {
        // 找当前未访问的距离最小点
        int min = INF;
        int u = -1;
        for (int j = 0; j < n; j++)
        {
            if (!visited[j] && dist[j] < min)
            {
                min = dist[j];
                u = j;
            }
        }
        if (u == -1) break; // 剩余点不可达

        visited[u] = 1;
        // 松弛更新
        for (int v = 0; v < n; v++)
        {
            if (!visited[v] && G->arcs[u][v] < INF && dist[u] + G->arcs[u][v] < dist[v])
            {
                dist[v] = dist[u] + G->arcs[u][v];
                path[v] = u;
            }
        }
    }

    // 输出结果
    printf("起点 %d 到各顶点最短路径及长度：\n", G->vexs[start]);
    for (int i = 0; i < n; i++)
    {
        if (i == start) continue;
        printf("到顶点 %d：", G->vexs[i]);
        if (dist[i] >= INF)
        {
            printf("不可达\n");
            continue;
        }
        // 回溯输出路径
        int temp = i;
        while (temp != start)
        {
            printf("%d <- ", G->vexs[temp]);
            temp = path[temp];
        }
        printf("%d    路径长度：%d\n", G->vexs[start], dist[i]);
    }
}

// ===================== 2. 普里姆 Prim 最小生成树（邻接矩阵） =====================
void Prim(NetGraph *G)
{
    int lowcost[VNUM];
    int adjvex[VNUM];
    int visited[VNUM];
    int n = G->vexNum;

    // 从第0个顶点开始构造
    for (int i = 0; i < n; i++)
    {
        lowcost[i] = G->arcs[0][i];
        adjvex[i] = 0;
        visited[i] = 0;
    }
    visited[0] = 1;

    printf("Prim 最小生成树边：\n");
    for (int i = 1; i < n; i++)
    {
        // 选权值最小的边
        int min = INF;
        int u = -1;
        for (int j = 0; j < n; j++)
        {
            if (!visited[j] && lowcost[j] < min)
            {
                min = lowcost[j];
                u = j;
            }
        }
        if (u == -1) break;

        visited[u] = 1;
        printf("(%d, %d)  权值：%d\n", G->vexs[adjvex[u]], G->vexs[u], min);

        // 更新 lowcost
        for (int v = 0; v < n; v++)
        {
            if (!visited[v] && G->arcs[u][v] < lowcost[v])
            {
                lowcost[v] = G->arcs[u][v];
                adjvex[v] = u;
            }
        }
    }
}

// ===================== 3. 克鲁斯卡尔 Kruskal 最小生成树 =====================
// 边排序比较函数
int cmpEdge(const void *a, const void *b)
{
    return ((Edge *)a)->weight - ((Edge *)b)->weight;
}

// 并查集：查找根
int Find(int parent[], int x)
{
    if (parent[x] != x)
        parent[x] = Find(parent, parent[x]);
    return parent[x];
}

// 并查集：合并
void Union(int parent[], int x, int y)
{
    x = Find(parent, x);
    y = Find(parent, y);
    if (x != y)
        parent[y] = x;
}

void Kruskal(NetGraph *G)
{
    Edge edge[VNUM * VNUM];
    int parent[VNUM];
    int n = G->vexNum;
    int cnt = 0;

    // 1. 提取所有边
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (G->arcs[i][j] != 0 && G->arcs[i][j] < INF)
            {
                edge[cnt].start = i;
                edge[cnt].end = j;
                edge[cnt].weight = G->arcs[i][j];
                cnt++;
            }
        }
    }

    // 2. 边按权值升序排序
    qsort(edge, cnt, sizeof(Edge), cmpEdge);

    // 3. 初始化并查集
    for (int i = 0; i < n; i++)
        parent[i] = i;

    printf("Kruskal 最小生成树边：\n");
    int sum = 0;
    int num = 0;
    // 依次选边，不构成环则加入
    for (int i = 0; i < cnt; i++)
    {
        int s = edge[i].start;
        int e = edge[i].end;
        int w = edge[i].weight;
        if (Find(parent, s) != Find(parent, e))
        {
            Union(parent, s, e);
            printf("(%d, %d)  权值：%d\n", G->vexs[s], G->vexs[e], w);
            sum += w;
            num++;
            if (num == n - 1)
                break;
        }
    }
    printf("最小生成树总权值：%d\n", sum);
}