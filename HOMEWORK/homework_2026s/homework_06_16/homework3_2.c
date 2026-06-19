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

void crtGraph(MGraph *G);
int findIndex(MGraph *G,char *tag);
void BFS(MGraph *G,int start, int dist[]);

int main()
{
    MGraph G;
    crtGraph(&G);

    char s[10];
    scanf("%s", s);
    int st = findIndex(&G, s);

    int dist[MAX];
    BFS(&G, st, dist);

    int maxTime = 0;
    for(int i = 0; i < G.vexNum; i++){
        if(dist[i] > maxTime){
            maxTime = dist[i];
        }
    }
    printf("%d\n", maxTime);

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
        scanf(" %s %s",str_a,str_b);
        int ta=findIndex(G,str_a);
        int tb=findIndex(G,str_b);
        G->arcs[ta][tb]=1;
        G->arcs[tb][ta]=1;
    }
}

int findIndex(MGraph *G,char *tag){
    for(int i=0;i<G->vexNum;i++){
        if(strcmp(G->vexs[i],tag)==0)return i;
    }
    return -1;
}

void BFS(MGraph *G, int start, int dist[]) {
    int queue[MAX];
    int rear = 0, front = 0;
    int visited[MAX] = {0};

    for(int i = 0; i < G->vexNum; i++){
        dist[i] = -1;
    }

    visited[start] = 1;
    dist[start] = 0;
    queue[rear++] = start;

    while (front < rear) {
        int cur = queue[front++];
        for (int i = 0; i < G->vexNum; i++) {
            if (!visited[i] && G->arcs[cur][i] == 1) {
                visited[i] = 1;
                dist[i] = dist[cur] + 1;
                queue[rear++] = i;
            }
        }
    }
}