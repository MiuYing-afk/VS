/*
2. 交通网最低消耗
【问题描述】

有几座互相连接的城市，现在需要在他们之间搭设交通网，请设计一种消耗最低的交通网。

【输入形式】

第一行输出城市数量。

第二行开始输入一张图，表示为城市之间的邻接矩阵，A[i][j]为城市 i 到城市 j 之间的距离，-1代表不可达。

【输出形式】

输出一个整数，表示最低消耗。

【样例输入】

4

-1 2 3 4

2 -1 4 -1

3 4 -1 5

4 -1 5 -1

【样例输出】

9

【样例说明】

参考以下代码，完成primMST函数：

#include <stdio.h>

#include <limits.h>



#define MAXCITIES 100

#define INF 0x3f3f3f3f



// 用于找到未在最小生成树中且具有最小键值的顶点

int minKey(int key[], int mstSet[], int n) {

    int min = INT_MAX, min_index = -1;

    for (int v = 0; v < n; v++)

        if (mstSet[v] == 0 && key[v] < min)

            min = key[v], min_index = v;

    return min_index;

}



// 普里姆算法实现，计算最小生成树的权重总和

int primMST(int graph[MAXCITIES][MAXCITIES], int n) {

    

}



int main() {

    int n;

    scanf("%d", &n);

    int graph[MAXCITIES][MAXCITIES];



    // 读取邻接矩阵

    for (int i = 0; i < n; i++)

        for (int j = 0; j < n; j++){

            scanf("%d", &graph[i][j]);

            if(graph[i][j] == -1)

                graph[i][j] = INF;

        }

            

    // 打印解决方案

    printf("%d\n", primMST(graph, n));

    return 0;

}


【评分标准】
*/


//两大致命硬伤：
// 不可达 -1 没转换成无穷大；
// 最小权变量 minCost 初始值设为 -1，导致找不到任何有效边。
#include "stdio.h"
#include "stdlib.h"

#define MAX 100

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
    G->arcNum=0;
    for(int i=0;i<G->vexNum;i++){
        for(int j=0;j<G->vexNum;j++){
            scanf("%d",&G->arcs[i][j]);
        }
    }
    for(int i=0;i<G->vexNum;i++){
        for(int j=i;j<G->vexNum;j++){
            if(G->arcs[i][j]!=-1)
            G->arcNum++;
        }
    }
}

int PrimMST(Graph *G){
    LowCost *lowcost=(LowCost*)malloc(G->vexNum*sizeof(LowCost));

    int visited[MAX]={0};
    visited[0]=1;

    for(int i=0;i<G->vexNum;i++){
        lowcost[i].weight=G->arcs[0][i];
        if(lowcost[i].weight==-1){
            lowcost[i].adjNodeNo=-1;
        }else{
            lowcost[i].adjNodeNo=0;
        }
    }

    int sum=0;
    for(int cnt=1;cnt<G->vexNum;cnt++){
        int minPos=-1;
        int minCost=-1;
        for(int i=0;i<G->vexNum;i++){
            if(visited[i]==0&&lowcost[i].weight<minCost){
                minPos=i;
                minCost=lowcost[i].weight;
            }
        }
        if(minPos==-1)break;
        sum+=minCost;
        visited[minPos]=1;

        for(int i=0;i<G->vexNum;i++){
            if(visited[i]==0&&G->arcs[minPos][i]!=-1){
                if(lowcost[i].weight>G->arcs[minPos][i]){
                    lowcost[i].weight=G->arcs[minPos][i];
                    lowcost[i].adjNodeNo=minPos;
                }
            }
        }
    }

    free(lowcost);
    return sum;
}