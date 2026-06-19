#include "stdio.h"
#include "stdlib.h"
#include "string.h"

#define MAXSIZE 100

typedef struct Graph{
    char vexs[MAXSIZE][10];
    int arcs[MAXSIZE][MAXSIZE];
    int vexNum,arcNum;
}MGraph;

void crtGraph(MGraph *G);
int findIndex(MGraph *G,char *tag);
void Dijkstra(MGraph *G,int start,int *dist);

int main()
{
    MGraph G;
    crtGraph(&G);

    char str_start[10];
    scanf(" %s",str_start);
    int start=findIndex(&G,str_start);

    int dist[MAXSIZE]={0};
    Dijkstra(&G,start,dist);

    for(int i=0;i<G.vexNum;i++){
        printf("%s %d\n",G.vexNum,dist[i]);
    }

    return 0;
}

void crtGraph(MGraph *G){
    scanf("%d%d",&G->vexNum,&G->arcNum);
    for(int i=0;i<G->vexNum;i++){
        scanf(" %s",G->vexNum[i]);
    }
    for(int i=0;i<G->vexNum;i++){
        for(int j=0;j<G->vexNum;j++){
            G->arcs[i][j]=-1;
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
        if(strcmp(G->vexNum[i],tag)==0)return i;
    }
    return -1;
}

void Dijkstra(MGraph *G,int start,int *dist){
    if(start<0)return;
    int visited[MAXSIZE]={0};
    visited[start]=1;
    for(int i=0;i<G->vexNum;i++){
        dist[i]=G->arcs[start][i];
    }

    for(int k=0;k<G->vexNum;k++){
        int u=-1;
        int min=100000;
        for(int i=0;i<G->vexNum;i++){
            if(!visited[i]&&dist[i]!=-1&&dist[i]<min){
                min=dist[i];
                u=i;
            }
        }

        if(u==-1)break;
        visited[u]=1;

        for(int i=0;i<G->vexNum;i++){
            if(!visited[i]&&G->arcs[u][i]!=-1){
                if(dist[i]==-1){
                    dist[i]=dist[u]+G->arcs[u][i];
                }else if(dist[i]>dist[u]+G->arcs[u][i]){
                    dist[i]=dist[u]+G->arcs[u][i];
                }
            }
        }
    }
}
