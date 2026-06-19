#include "stdio.h"
#include "stdlib.h"

#define INF 0x3f3f3f3f
#define MAX_VEX 100    // 图最大顶点数量
#define MAX_EDGES 1000 // 图最大边数量

// 边结构体：存储单条邻接边信息
typedef struct {
    int edgeNum;    // 边的编号（输入给出的唯一序号）
    int to;         // 该边指向的目标顶点
}Edge;

// 邻接表链表节点
typedef struct Node {
    Edge edge;              // 节点包含一条边
    struct Node* next;      // 指向下一条邻接边的指针
}Node;

// 图结构体：邻接表存储无向图
typedef struct {
    Node* head[MAX_VEX];    // head[i] 顶点i的邻接链表头指针
    int vexNum;             // 当前图实际顶点总数
    int arcNum;             // 当前图实际边总数
}Graph;

int path[MAX_EDGES]; // 全局数组：保存当前DFS搜索到的路径（存边编号）
int pathIndex;       // 全局变量：path数组当前有效元素下标/路径长度

// 函数声明
void initGraph(Graph *G,int vex);
void addEdge(Graph *G,int edgeNum,int from,int to);
void dfs(Graph* graph, int current, int end, int visited[], int edgeVisited[]) ;

int main()
{
    int n,e;
    // 读取顶点数n、边数e
    scanf("%d%d",&n,&e);

    Graph G;
    initGraph(&G,n); // 初始化一张n个顶点的空图

    // 循环读取e条边
    for(int i=0;i<e;i++){
        int edgeNum,from,to;
        // 输入：边编号 顶点1 顶点2
        scanf("%d%d%d",&edgeNum,&from,&to);
        // 无向图，双向添加邻接关系
        addEdge(&G,edgeNum,from,to);
        addEdge(&G,edgeNum,to,from);
    }

    int visited[MAX_VEX]={0};    // 顶点访问标记：1代表已走过，防止环路
    int edgeVisited[MAX_EDGES]={0}; // 边访问标记（题目模板预留，本题未使用）
    pathIndex=0;                  // 初始路径长度为0
    visited[0]=1;                 // 起点顶点0标记为已访问

    // DFS搜索：从顶点0出发，终点为n-1
    dfs(&G, 0, n - 1, visited, edgeVisited);

    return 0;
}

/**
 * @brief 初始化邻接表图
 * @param G 待初始化的图指针
 * @param vex 顶点总个数
 */
void initGraph(Graph *G,int vex){
    G->vexNum=vex;
    G->arcNum=0;
    // 所有顶点邻接表头置空
    for(int i=0;i<vex;i++){
        G->head[i]=NULL;
    }
}

/**
 * @brief 向邻接表添加一条单向边，链表按边号升序插入，保证输出字典序
 * @param G 图指针
 * @param edgeNum 待插入边的编号
 * @param from 起点顶点
 * @param to 终点顶点
 */
void addEdge(Graph *G,int edgeNum,int from,int to){
    // 新建链表节点
    Node* newNode=(Node*)malloc(sizeof(Node));
    newNode->edge.edgeNum = edgeNum;
    newNode->edge.to = to;
    newNode->next = NULL;

    // 找到链表插入位置：保持边编号从小到大排列
    Node** cur = &G->head[from];
    while(*cur && (*cur)->edge.edgeNum<edgeNum){
        cur=&((*cur)->next);
    }
    // 插入节点
    newNode->next=(*cur);
    (*cur)=newNode;
}

/**
 * @brief 深度优先搜索，枚举所有无环0→终点路径，按边序列输出
 * @param graph 图指针
 * @param current 当前所在顶点
 * @param end 目标终点顶点
 * @param visited 顶点访问标记数组
 * @param edgeVisited 边访问标记数组（模板预留未使用）
 */
void dfs(Graph* graph, int current, int end, int visited[], int edgeVisited[]) {
    // 递归终止条件：当前走到终点，输出整条路径
    if (current == end) {
        // 遍历path数组输出所有边编号
        for (int i = 0; i < pathIndex; i++) {
            if (i > 0) printf(" "); // 除第一个数字前加空格分隔
            printf("%d", path[i]);
        }
        printf("\n"); // 一条路径输出完毕换行
        return;
    }

    // 遍历当前顶点所有相连邻接边
    Node* p = graph->head[current];
    while (p != NULL) {
        int edgeId = p->edge.edgeNum;   // 当前这条边的编号
        int nextVex = p->edge.to;       // 这条边通向的下一个顶点

        // 下一个顶点未访问，走过去不会形成环，允许通行
        if (!visited[nextVex]) {
            path[pathIndex++] = edgeId; // 将当前边存入路径，路径长度+1
            visited[nextVex] = 1;       // 标记下一个顶点已访问

            // 递归深入，走到下一个顶点继续搜索
            dfs(graph, nextVex, end, visited, edgeVisited);

            // ==========回溯（恢复现场）==========
            visited[nextVex] = 0; // 取消顶点访问标记，允许其他路径走该点
            pathIndex--;          // 路径长度回退，舍弃当前这条边
        }
        p = p->next; // 切换下一条邻接边
    }
}