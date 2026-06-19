/*
9. 带权无向图求最短路径（迪杰斯特拉）
【问题描述】

带权无向图（连通或者不连通都要支持）采用邻接矩阵进行存储，图中顶点的类型为字符串。
从指定的源点出发求最短路径。

【输入形式】

第一行输入两个正整数 n 和 m，表示图的顶点数和边数。

第二行输入各个顶点的值，空格分隔。

第三行开始，往后 m 行，每行输入三个以空格隔开的字符串 u,v和整数value，
表示顶点 u与v 之间的一条边，value表示该边的权重。

最后一行输入某个顶点的字符串内容，表示从该顶点出发，对图进行迪杰斯特拉求最短路径。

【输出形式】

输出n行，每一行表示从起始顶点到每个顶点的最短距离，名称与距离之间用空格隔开，
输出顺序和顶点的输入顺序一致，对于不可达的顶点距离为-1。

【样例输入】

5 7

A B C D E

A B 10

A D 30

A E 100 

B C 50

C D 20

C E 10

D E 60

A

【样例输出】

A 0 

B 10

C 50

D 30

E 60

【样例说明】

将以下代码复制到作答区，实现dijkstra函数：

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

// 最短路径数组

int distances[MAX_VERTICES];

// 访问标记数组

int visited[MAX_VERTICES];



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



void printPath(int n){

// 输出最短路径

    for (int i = 0; i < n; i++) {

        if (distances[i] == INF) {

            printf("%s -1\n", vertices[i]);

        } else {

            printf("%s %d\n", vertices[i], distances[i]);

        }

    }

}



// 迪杰斯特拉算法

void dijkstra(int startVertex, int n) {

    

}



int main() {

    int n, m;

    char u[10];

    // 读取顶点数和边数

    scanf("%d %d", &n, &m);

    init(n, m);

    create(n, m);

    // 读取起始顶点

    scanf("%s", u);

    int startVertex = findVertexIndex(u, n);

    // 从指定顶点开始迪杰斯特拉求最短路径

    dijkstra(startVertex, n);

    printPath(n);

    return 0;

}

【评分标准】
*/
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

#define MaxSize 100

typedef struct{
    char vexs[MaxSize][10];
    int arcs[MaxSize][MaxSize];
    int vexNum,arcNum;
}MGraph;

void crt_Graph(MGraph *G);
int findIndex(MGraph *G,char *target);
void Dijkstra(MGraph *G,int start,int dist[]);

int main()
{
    MGraph G;
    crt_Graph(&G);

    char str_start[10];
    scanf(" %s",str_start);
    int start=findIndex(&G,str_start);

    int dist[MaxSize];
    Dijkstra(&G,start,dist);

    for(int i=0;i<G.vexNum;i++){
        printf("%s %d\n",G.vexs[i],dist[i]);
    }

    return 0;
}

void crt_Graph(MGraph *G){
    scanf("%d%d",&G->vexNum,&G->arcNum);
    for(int i=0;i<G->vexNum;i++){
        scanf(" %s",G->vexs[i]);
    }
    for(int i=0;i<G->vexNum;i++){
        for(int j=0;j<G->vexNum;j++)
        G->arcs[i][j]=-1;
    }
    for(int i=0;i<G->vexNum;i++){
        G->arcs[i][i]=0;
    }
    for(int i=0;i<G->arcNum;i++){
        char ta[10],tb[10];
        int degree;
        scanf(" %s %s %d",ta,tb,&degree);
        int a=findIndex(G,ta);
        int b=findIndex(G,tb);
        G->arcs[a][b]=degree;
        G->arcs[b][a]=degree;
    }

}

int findIndex(MGraph *G,char *target){
    for(int i=0;i<G->vexNum;i++){
        if(strcmp(G->vexs[i],target)==0)return i;
    }
    return -1;
}

void Dijkstra(MGraph *G,int start,int dist[]){
    int n=G->vexNum;
    int visited[MaxSize]={0};

    for(int i=0;i<n;i++){
        dist[i]=G->arcs[start][i];
    }
    visited[start]=1;

    for(int k=1;k<n;k++){
        int u=-1;
        int minDis=100000;
        for(int i=0;i<n;i++){
            if(!visited[i]&&dist[i]!=-1&&dist[i]<minDis){
                minDis=dist[i];
                u=i;
            }
        }
        if(u==-1)break;

        visited[u]=1;

        for(int v=0;v<n;v++){
            if(!visited[v]&&G->arcs[u][v]!=-1){
                if(dist[v]==-1){
                    dist[v]=dist[u]+G->arcs[u][v];
                }else if(dist[v]>dist[u]+G->arcs[u][v]){
                    dist[v]=dist[u]+G->arcs[u][v];
                }
            }
        }
    }
}