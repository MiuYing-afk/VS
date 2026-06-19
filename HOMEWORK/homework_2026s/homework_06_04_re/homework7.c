#include "stdio.h"
#include "stdlib.h"
#include "string.h"

#define MaxSize 50

typedef struct {
    char vexs[MaxSize][10];
    int arcs[MaxSize][MaxSize];
    int vexNum,arcNum;
}MGraph;

void crt_Graph(MGraph *G);
int findIndex(MGraph G,char *target);
void BFS(MGraph G,int start);

int main()
{
    MGraph G;
    crt_Graph(&G);
    char strStart[10];
    scanf(" %s",strStart);
    int start=findIndex(G,strStart);
    BFS(G,start);

    return 0;
}

void crt_Graph(MGraph *G){
    scanf("%d%d",&G->vexNum,&G->arcNum);
    for(int i=0;i<G->vexNum;i++){
        scanf(" %s",G->vexs[i]);
    }
    for(int i=0;i<G->vexNum;i++){
        for(int j=0;j<G->vexNum;j++){
            G->arcs[i][j]=0;
        }
    }
    for(int i=0;i<G->arcNum;i++){
        char ta[10],tb[10];
        scanf(" %s %s",ta,tb);
        int a=findIndex(*G,ta);
        int b=findIndex(*G,tb);
        G->arcs[a][b]=1;
    }
}

int findIndex(MGraph G,char *target){
    for(int i=0;i<G.vexNum;i++){
        if(strcmp(G.vexs[i],target)==0)return i;
    }
    return -1;
}

void BFS(MGraph G,int start){
    int queue[MaxSize];
    int visited[MaxSize]={0};
    int rear=0,front=0;
    if(start==-1)return;
    queue[rear++]=start;
    visited[start]=1;
    printf("%s",G.vexs[start]);

    while(front<rear){
        int current=queue[front++];
        for(int i=G.vexNum-1;i>=0;i--){
            if(G.arcs[current][i]==1&&visited[i]==0){
                printf(" %s",G.vexs[i]);
                queue[rear++]=i;
                visited[i]=1;
            }
        }
    }
}