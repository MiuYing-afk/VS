#include "stdio.h"
#include "stdlib.h"
#include "string.h"

#define INF 0x3f3f3f3f
#define MAX 100

typedef struct MGraph {
    char vexs[MAX][10];
    int arcs[MAX][MAX];
    int vexNum,arcNum;
}MGraph;

typedef struct LowCost {
    int adjNodeNo;
    int weight;
}LowCost;

int findIndex(MGraph *G,char *tag);
void crtGraph(MGraph *G);
void dispGraph(MGraph *G);
void DFS(MGraph *G,int start,int *visited);
void BFS(MGraph *G,int start);
void PrimMST(MGraph *G,int start,LowCost *lowcost);
void Dikstra(MGraph *G,int start,int *dist);
int** Floyd(MGraph *G);

int main()
{
    MGraph G;

    return 0;
}

int findIndex(MGraph *G,char *tag){
    for(int i=0;i<G->vexNum;i++){
        if(strcmp(G->vexs[i],tag)==0)return i;
    }
    return -1;
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
    for(int i=0;i<G->vexNum;i++)G->arcs[i][i]=0;
    for(int i=0;i<G->arcNum;i++){
        char str_a[10],str_b[10];
        int degree;
        scanf(" %s %s %d",str_a,str_b,&degree);
        int a=findIndex(G,str_a);
        int b=findIndex(G,str_b);
        G->arcs[a][b]=degree;
        G->arcs[b][a]=degree;
    }
}

void dispGraph(MGraph *G){
    for(int i=0;i<G->vexNum;i++){
        printf("%s ",G->vexs[i]);
    }
    printf("\n");
    for(int i=0;i<G->vexNum;i++){
        for(int j=0;j<G->vexNum;j++){
            if(G->arcs[i][j]==INF)printf("    0");
            else printf("%5d",G->arcs[i][j]);
        }
        printf("\n");
    }
}

void DFS(MGraph *G,int start,int *visited){
    if(start<0)return;
    visited[start]=1;
    printf("%s ",G->vexs[start]);

    for(int i=0;i<G->vexNum;i++){
        if(visited[i]==0&&G->arcs[start][i]!=INF)DFS(G,i,visited);
    }
}

void BFS(MGraph *G,int start){
    if(start<0)return;
    int queue[MAX];
    int rear=0,front=0;
    int visited[MAX]={0};
    visited[start]=1;
    queue[rear++]=start;
    printf("%s",G->vexs[start]);

    while(front<rear){
        int cur=queue[front++];
        for(int i=0;i<G->vexNum;i++){
            if(visited[i]==0&&G->arcs[cur][i]!=INF){
                printf(" %s",G->vexs[i]);
                visited[i]=1;
                queue[rear++]=i;
            }
        }
    }
}

void PrimMST(MGraph *G,int start,LowCost *lowcost){
    int visited[MAX]={0};
    visited[start]=1;

    for(int i=0;i<G->vexNum;i++){
        lowcost[i].weight=G->arcs[start][i];
        if(lowcost[i].weight==INF)lowcost[i].adjNodeNo=-1;
        else lowcost[i].adjNodeNo=start;
    }

    for(int cnt=1;cnt<G->vexNum;cnt++){
        int minCost=INF;
        int minPos=-1;
        for(int i=0;i<G->vexNum;i++){
            if(visited[i]==0&&lowcost[i].weight<minCost){
                minCost=lowcost[i].weight;
                minPos=i;
            }
        }
        if(minPos==-1)break;
        visited[minPos]=1;

        char *u=G->vexs[lowcost[minPos].adjNodeNo];
        char *v=G->vexs[minPos];
        printf("%s-%s %d\n",u,v,lowcost[minPos].weight);

        for(int i=0;i<G->vexNum;i++){
            if(visited[i]==0&&G->arcs[minPos][i]!=INF){
                if(lowcost[i].weight>G->arcs[minPos][i]){
                    lowcost[i].weight=G->arcs[minPos][i];
                    lowcost[i].adjNodeNo=minPos;
                }
            }
        }
    }
}

void Dikstra(MGraph *G,int start,int *dist){
    if(start<0)return;

    int visited[MAX]={0};
    visited[start]=1;

    for(int i=0;i<G->vexNum;i++){
        dist[i]=G->arcs[start][i];
    }

    for(int cnt=0;cnt<G->vexNum;cnt++){
        int minPos=-1;
        int minCost=INF;
        for(int i=0;i<G->vexNum;i++){
            if(visited[i]==0&&dist[i]!=INF&&dist[i]<minCost){
                minCost=dist[i];
                minPos=i;
            }
        }
        if(minPos==-1)break;
        visited[minPos]=1;

        for(int i=0;i<G->vexNum;i++){
            if(visited[i]==0&&G->arcs[minPos][i]!=INF){
                if(dist[i]==INF){
                    dist[i]=dist[minPos]+G->arcs[minPos][i];
                }else if(dist[i]>dist[minPos]+G->arcs[minPos][i]){
                    dist[i]=dist[minPos]+G->arcs[minPos][i];
                }
            }
        }
    }
}


int** Floyd(MGraph *G){
    int num=G->vexNum;
    int **path=(int**)malloc(sizeof(int*)*num);
    for(int i=0;i<num;i++)path[i]=(int*)malloc(num*sizeof(int));

    for(int i=0;i<G->vexNum;i++){
        for(int j=0;j<G->vexNum;j++){
            path[i][j]=G->arcs[i][j];
        }
    }

    for(int k=0;k<num;k++){
        for(int i=0;i<num;i++){
            for(int j=0;j<num;j++){
                if(path[i][k]!=INF&&path[k][j]!=INF){
                    if(path[i][j]>path[i][k]+path[k][j]){
                        path[i][j]=path[i][k]+path[k][j];
                    }
                }
            }
        }
    }

    return path;
}