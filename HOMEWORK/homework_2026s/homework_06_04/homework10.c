/*
10. 带权无向图求最小生成树（prim）
【问题描述】

带权无向图（连通或者不连通都要支持）采用邻接矩阵进行存储，图中顶点的类型为字符串。
基于PRIM算法构造图的最小生成树。

【输入形式】

第一行输入两个正整数 n 和 m，表示图的顶点数和边数。

第二行输入 n 个以空格隔开的字符串，表示图中所有顶点的名称。

第三行开始，往后 m 行，每行输入三个以空格隔开的字符串 u,v和整数value，
表示顶点 u与v 之间的一条边，value表示该边的权重。

【输出形式】

输出n-1行，每一行表示最小生成树的一条边的信息，名称与名称之前用-连接，名称和权重之间用空格隔开。

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

【样例输出】

A-B 10

A-D 30

C-D 20

C-E 10

【样例说明】

将以下代码复制到代码区，完成prim函数。

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

【评分标准】
*/

#include "stdio.h"
#include "stdlib.h"
#include "string.h"

#define MAXSIZE 100
#define INF 0x3f3f3f3f

typedef struct {
    char vexs[MAXSIZE][10];
    int arcs[MAXSIZE][MAXSIZE];
    int arcNum,vexNum;
}MGraph;

typedef struct {
    int weight;
    int adjNodeNo;
}LowCost;

void crtGraph(MGraph *G);
int findIndex(MGraph *G,char *tag);
void MSTGraph(MGraph *G,int start,LowCost *lowcost);

int main(){
    MGraph G;
    crtGraph(&G);

    LowCost *lowcost=(LowCost*)malloc(G.vexNum*sizeof(LowCost));
    MSTGraph(&G,0,lowcost);

    free(lowcost);
    return 0;
}

void crtGraph(MGraph *G){
    scanf("%d%d",&G->vexNum,&G->arcNum);
    for(int i=0;i<G->vexNum;i++){
        scanf(" %s",G->vexs[i]);
    }
    for(int i=0;i<G->vexNum;i++){
        for(int j=0;j<G->vexNum;j++){
            G->arcs[i][j]=INF;
        }
    }
    for(int i=0;i<G->vexNum;i++){
        G->arcs[i][i]=0;
    }
    for(int i=0;i<G->arcNum;i++){
        char str_a[10],str_b[10];
        int degree;
        scanf(" %s %s %d",str_a,str_b,&degree);
        int ta=findIndex(G,str_a);
        int tb=findIndex(G,str_b);
        G->arcs[ta][tb]=degree;
        G->arcs[tb][ta]=degree;
    }
}

int findIndex(MGraph *G,char *tag){
    for(int i=0;i<G->vexNum;i++){
        if(strcmp(G->vexs[i],tag)==0)return i;
    }
    return -1;
}

void MSTGraph(MGraph *G,int start,LowCost *lowcost){
    int flag[MAXSIZE]={0};
    int n = G->vexNum;
    flag[start] = 1;

    for(int i=0;i<n;i++){
        lowcost[i].weight = G->arcs[start][i];
        if(lowcost[i].weight == INF)
            lowcost[i].adjNodeNo = -1;
        else
            lowcost[i].adjNodeNo = start;
    }

    for(int cnt = 1; cnt < n; cnt++){
        int minCost = INF;
        int minPos = -1;

        for(int k=0;k<n;k++){
            if(flag[k]==0 && lowcost[k].weight < minCost){
                minCost = lowcost[k].weight;
                minPos = k;
            }
        }
        if(minPos == -1) break;

        int p = lowcost[minPos].adjNodeNo;
        char *u = G->vexs[p];
        char *v = G->vexs[minPos];
        if (strcmp(u, v) < 0)
            printf("%s-%s %d\n", u, v, lowcost[minPos].weight);
        else
            printf("%s-%s %d\n", v, u, lowcost[minPos].weight);

        flag[minPos] = 1;

        for(int k=0;k<n;k++){
            if(flag[k]==0 && G->arcs[minPos][k] != INF){
                if(G->arcs[minPos][k] < lowcost[k].weight){
                    lowcost[k].weight = G->arcs[minPos][k];
                    lowcost[k].adjNodeNo = minPos;
                }
            }
        }
    }
}