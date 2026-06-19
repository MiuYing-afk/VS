/*
4. 网络延迟时间
【问题描述】

有 n 个网络节点，标记为 1 到 n。

给你一个列表 times，表示信号经过 有向 边的传递时间。 times[i] = (ui, vi, wi)，其中 ui 是源节点，vi 是目标节点， wi 是一个信号从源节点传递到目标节点的时间。

现在，从某个节点 K 发出一个信号。需要多久才能使所有节点都收到信号？如果不能使所有节点收到信号，返回 -1 。

【输入形式】

第一行输入两个正整数 n 和 m，分别表示图的顶点数和边数。

第二行开始，往后 m 行，每行输入两个以空格隔开的整数 u、v 和一个整数 w，表示从顶点 u 到顶点 v 的一条边及其权重 w。

最后一行输入k，表示起始顶点。

【输出形式】

输出一个整数表示所有节点收到信号所需时间。

【样例输入】

4 3

2 1 1

2 3 1

3 4 1

2

【样例输出】

2

【样例说明】

参考以下代码，完成networkDelayTime：

#include <stdio.h>

#include <stdlib.h>

#include <limits.h>



#define MAXN 105



// 定义边结构体

typedef struct Edge {

    int v;

    int w;

    struct Edge *next;

} Edge;



// 定义节点结构体，包含边链表头指针

typedef struct Node {

    Edge *head;

} Node;



// 图结构体，包含节点数组

typedef struct Graph {

    Node nodes[MAXN];

} Graph;



// 初始化图

void initGraph(Graph *g, int n) {

    for (int i = 1; i <= n; i++) {

        g->nodes[i].head = NULL;

    }

}



// 添加边到图中

void addEdge(Graph *g, int u, int v, int w) {

    Edge *edge = (Edge *)malloc(sizeof(Edge));

    edge->v = v;

    edge->w = w;

    edge->next = g->nodes[u].head;

    g->nodes[u].head = edge;

}



// 找到未访问节点中距离最小的节点编号

int minDistance(int dist[], int n, int sptSet[]) {

    int min = INT_MAX, min_index = -1;

    for (int v = 1; v <= n; v++) {

        if (sptSet[v] == 0 && dist[v] <= min) {

            min = dist[v];

            min_index = v;

        }

    }

    return min_index;

}





int networkDelayTime(Graph *g, int n, int k) {

    

}

int main() {

    int n, m;

    scanf("%d %d", &n, &m);

    Graph g;

    initGraph(&g, n);

    for (int i = 0; i < m; i++) {

        int u, v, w;

        scanf("%d %d %d", &u, &v, &w);

        addEdge(&g, u, v, w);

    }

    int k;

    scanf("%d", &k);

    int result = networkDelayTime(&g, n, k);

    printf("%d\n", result);

    return 0;

}


【评分标准】
*/

#include "stdio.h"
#include "stdlib.h"

#define MAX 100
#define INF 0x3f3f3f3f

typedef struct {
    int arcs[MAX][MAX];
    int vexNum,arcNum;
}Graph;


void crtGraph(Graph *G);
void Dijkstra(Graph *G,int start);

int main()
{
    Graph G;
    crtGraph(&G);
    int target;
    scanf("%d",&target);
    Dijkstra(&G,target-1);

    return 0;
}

void crtGraph(Graph *G){
    scanf("%d %d",&G->vexNum,&G->arcNum);
    for(int i=0;i<G->vexNum;i++){
        for(int j=0;j<G->vexNum;j++){
            G->arcs[i][j]=INF;
        }
    }
    for(int i=0;i<G->vexNum;i++)G->arcs[i][i]=0;
    for(int i=0;i<G->arcNum;i++){
        int a,b,degree;
        scanf("%d %d %d",&a,&b,&degree);
        G->arcs[a-1][b-1]=degree;
    }
}

void Dijkstra(Graph *G,int start){
    int dist[MAX];
    int visited[MAX]={0};
    visited[start]=1;

    for(int i=0;i<G->vexNum;i++){
        dist[i]=G->arcs[start][i];
    }

    for(int cnt=0;cnt<G->vexNum;cnt++){
        int minPos=-1;
        int minCost=INF;

        for(int i=0;i<G->vexNum;i++){
            if(visited[i]==0&&dist[i]<minCost){
                minPos=i;
                minCost=dist[i];
            }
        }
        if(minPos==-1)break;

        visited[minPos]=1;
        for(int i=0;i<G->vexNum;i++){
            if(visited[i]==0&&G->arcs[minPos][i]!=INF){
                if(dist[i]==INF){
                    dist[i]=G->arcs[minPos][i]+dist[minPos];
                }else if(dist[i]>G->arcs[minPos][i]+dist[minPos]){
                    dist[i]=G->arcs[minPos][i]+dist[minPos];
                }
            }
        }
    }

    int minTime=0;
    for(int i=0;i<G->vexNum;i++){
        if(dist[i]!=INF){
            if(dist[i]>minTime)minTime=dist[i];
        }else{
            printf("-1\n");
            return;
        }
    }
    printf("%d\n",minTime);
}