#include "stdio.h"
#include "string.h"
#include "stdlib.h"

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
    char ttarget[10];
    scanf(" %s",ttarget);
    int target=findIndex(G,ttarget);
    BFS(G,target);

    return 0;
}

void crt_Graph(MGraph *G){
    scanf("%d%d",&G->vexNum,&G->arcNum);
    for(int i=0;i<G->vexNum;i++){
        scanf(" %s",G->vexs[i]);
    }
    for(int i=0;i<G->vexNum;i++){
        for(int j=0;j<G->vexNum;j++)
        G->arcs[i][j]=0;
    }
    for(int i=0;i<G->arcNum;i++){
        char a_t[10],b_t[10];
        scanf(" %s %s",a_t,b_t);
        int a=findIndex(*G,a_t);
        int b=findIndex(*G,b_t);
        G->arcs[b][a]=1;
        G->arcs[a][b]=1;
    }

}

int findIndex(MGraph G,char *target){
    for(int i=0;i<G.vexNum;i++){
        if(strcmp(G.vexs[i],target)==0)
        return i;
    }
    return -1;
}

void BFS(MGraph G,int start){
    int queue[MaxSize];
    int rear=0,front=0;
    int visited[MaxSize]={0};
    visited[start]=1;
    printf("%s",G.vexs[start]);
    queue[rear++]=start;

    while(front<rear){
        int current=queue[front++];
        for(int i=0;i<G.vexNum;i++){
            if(G.arcs[current][i]==1&&visited[i]==0){
                visited[i]=1;
                printf(" %s",G.vexs[i]);
                queue[rear++]=i;
            }
        }
    }

}