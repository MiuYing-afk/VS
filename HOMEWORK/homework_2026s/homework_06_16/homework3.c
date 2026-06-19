/*
3. 最短用时
【问题描述】

在一个网络里有若干节点，假设每两个节点间通信需要的时间为1，现在给某个节点发送信号，多长时间后，网络里所有节点都能收到该信号。

【输入形式】

第一行输入两个正整数 n 和 m，分别表示图的顶点数和边数。

第二行输入 n 个以空格隔开的字符串，表示图中所有顶点的名称。

第三行开始，往后 m 行，每行输入两个以空格隔开的字符串 u、v ，表示从顶点 u 和顶点 v 之间的一条边。

最后一行输入字符串 s ，表示起点。

【输出形式】

输出一个整数，表示从起点 s 给所有顶点传送完数据所需时间。

【样例输入】

7 9

A B

A C

A D

A G

B C

B D

C F

E F

F G

C

【样例输出】

2

【样例说明】

参考一下代码，完成bfs函数：

#include <stdio.h>

#include <stdlib.h>

#include <string.h>



#define MAXN 1000

#define NAME_LEN 10



typedef struct Node {

    char name[NAME_LEN];

    int visited;

    int time;

    struct Node* next;

} Node;



Node graph[MAXN];

char start[NAME_LEN];

int n, m;



void initGraph() {

    for (int i = 0; i < n; i++) {

        graph[i].name[0] = '\0';

        graph[i].visited = 0;

        graph[i].time = -1;

        graph[i].next = NULL;

    }

}



int getIndex(char* name) {

    for (int i = 0; i < n; i++) {

        if (strcmp(graph[i].name, name) == 0) {

            return i;

        }

    }

    return -1;

}



void addEdge(char* u, char* v) {

    int i = getIndex(u);

    int j = getIndex(v);

    Node* newNode = (Node*)malloc(sizeof(Node));

    strcpy(newNode->name, v);

    newNode->next = graph[i].next;

    graph[i].next = newNode;



    newNode = (Node*)malloc(sizeof(Node));

    strcpy(newNode->name, u);

    newNode->next = graph[j].next;

    graph[j].next = newNode;

}



void bfs(char* start) {

    

}



int main() {

    scanf("%d %d", &n, &m);

    initGraph();



    for (int i = 0; i < n; i++) {

        scanf("%s", graph[i].name);

    }



    char u[NAME_LEN], v[NAME_LEN];

    for (int i = 0; i < m; i++) {

        scanf("%s %s", u, v);

        addEdge(u, v);

    }



    scanf("%s", start);

    bfs(start);



    int maxTime = 0;

    for (int i = 0; i < n; i++) {

        if (graph[i].time > maxTime) {

            maxTime = graph[i].time;

        }

    }



    printf("%d\n", maxTime);

    return 0;

}


【评分标准】
*/

//妈的，用错算法了，重做
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

#define MAX 100
#define INF 0x3f3f3f3f

typedef struct {
    char vexs[MAX][10];
    int arcs[MAX][MAX];
    int vexNum,arcNum;
}MGraph;

typedef struct {
    int adjNodeNo;
    int weight;
}LowCost;

void crtGraph(MGraph *G);
int findIndex(MGraph *G,char *tag);
void PrimMST(MGraph *G,int start);

int main()
{
    MGraph G;

    return 0;
}

void crtGraph(MGraph *G){
    scanf("%d%d",&G->vexNum,&G->arcNum);
    for(int i=0;i<G->vexNum;i++){
        scanf(" %s",G->vexs[i]);
    }
    for(int i=0;i<G->vexNum;i++){
        for(int j=0;j<G->vexNum;j++)
            G->arcs[i][j]=INF;
    }
    for(int i=0;i<G->vexNum;i++){
        G->arcs[i][i]=1;
    }
    for(int i=0;i<G->arcNum;i++){
        char str_a[10],str_b[10];
        scanf(" %s %s",str_a,str_b);
        int a=findIndex(G,str_a);
        int b=findIndex(G,str_b);
        G->arcs[a][b]=1;
        G->arcs[b][a]=1;
    }
}

int findIndex(MGraph *G,char *tag){
    for(int i=0;i<G->vexNum;i++){
        if(strcmp(G->vexs[i],tag)==0)return i;
    }
    return -1;
}

void PrimMST(MGraph *G,int start){
    int n=G->vexNum;
    LowCost *lowcost=(LowCost*)malloc(sizeof(LowCost));
    int visited[MAX]={0};
    visited[start]=1;

    for(int i=0;i<n;i++){
        lowcost[i].weight=G->arcs[start][i];
        if(lowcost[i].weight==INF)lowcost[i].adjNodeNo=-1;
        else lowcost[i].adjNodeNo=start;
    }

    for(int cnt=1;cnt<n;cnt++){
        int minCost=INF;
        int minPos=-1;

        for(int i=0;i<n;i++){
            if(visited[i]==0&&lowcost[i].weight<minCost){
                minCost=lowcost[i].weight;
                minPos=i;
            }
        }
        if(minPos==-1){
            printf("error\n");
            return;
        }

        visited[minPos]=1;
        for(int i=0;i<n;i++){
            if(visited[i]==0&&G->arcs[minPos][i]!=INF){
                if(lowcost[i].weight>G->arcs[minPos][i]){
                    lowcost[i].weight=G->arcs[minPos][i];
                    lowcost[i].adjNodeNo=minPos;
                }
            }
        }
    }
}