#include "stdio.h"
#include "stdlib.h"
#define MAX 100
#define INF 0x3f3f3f3f

typedef struct {
    int arcs[MAX][MAX];
    int vexNum,arcNum;
}Graph;

typedef struct {
    int adjNodeNo;
    int weight;
}LowCost;

void crtGraph(Graph *G);
int PrimMST(Graph *G);

int main()
{
    Graph G;
    crtGraph(&G);
    printf("%d\n",PrimMST(&G));
    return 0;
}

void crtGraph(Graph *G){
    scanf("%d",&G->vexNum);
    for(int i=0;i<G->vexNum;i++){
        for(int j=0;j<G->vexNum;j++){
            scanf("%d",&G->arcs[i][j]);
            // 核心修复：-1转为无穷大
            if(G->arcs[i][j] == -1)
                G->arcs[i][j] = INF;
        }
    }
}

int PrimMST(Graph *G){
    int n = G->vexNum;
    LowCost *lowcost=(LowCost*)malloc(n*sizeof(LowCost));
    int visited[MAX]={0};
    visited[0]=1;

    // 初始化lowcost
    for(int i=0;i<n;i++){
        lowcost[i].weight=G->arcs[0][i];
        if(lowcost[i].weight == INF){
            lowcost[i].adjNodeNo=-1;
        }else{
            lowcost[i].adjNodeNo=0;
        }
    }

    int sum = 0;
    // 生成树共n-1条边，循环n-1次
    for(int cnt=1;cnt<n;cnt++){
        int minPos=-1;
        int minCost=INF; // 修复：初始化为无穷大
        // 找未访问的最小权值点
        for(int i=0;i<n;i++){
            if(!visited[i] && lowcost[i].weight < minCost){
                minCost=lowcost[i].weight;
                minPos=i;
            }
        }
        // 不连通图直接退出
        if(minPos==-1) break;
        // 累加这条最小边
        sum += minCost;
        visited[minPos]=1;

        // 更新lowcost数组
        for(int i=0;i<n;i++){
            if(!visited[i] && G->arcs[minPos][i] != INF){
                if(G->arcs[minPos][i] < lowcost[i].weight){
                    lowcost[i].weight=G->arcs[minPos][i];
                    lowcost[i].adjNodeNo=minPos;
                }
            }
        }
    }

    free(lowcost);
    return sum;
}