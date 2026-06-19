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
void dispGraph(MGraph *G);
void DFS(MGraph *G,int start,int *visited);
void BFS(MGraph *G,int start);
void Dijkstra(MGraph *G,int start,int *dist);
void PrimMST(MGraph *G,int start,LowCost *lowcost);

int main()
{
    MGraph G;
    char op;
    while(1){
        scanf("%c",&op);
        switch(op){
            case 'c':{
                crtGraph(&G);
                break;
            }
            case 'o':{
                dispGraph(&G);
                break;
            }
            case 'd':{
                char str_start[10];
                scanf(" %s",str_start);
                int visited[MAX]={0};
                DFS(&G,findIndex(&G,str_start),visited);
                printf("\n");
                break;
            }
            case 'b':{
                char str_start[10];
                scanf(" %s",str_start);
                BFS(&G,findIndex(&G,str_start));
                break;
            }
            case 'j':{
                char str_start[10];
                scanf(" %s",str_start);
                int dist[MAX];
                Dijkstra(&G,findIndex(&G,str_start),dist);
                for(int i=0;i<G.vexNum;i++){
                    int dis=-1;
                    if(dist[i]!=INF)dis=dist[i];
                    printf("%s %d\n",G.vexs[i],dis);
                }
                break;
            }
            case 'p':{
                LowCost *lowcost=(LowCost*)malloc(G.vexNum*sizeof(LowCost));
                PrimMST(&G,findIndex(&G,"A"),lowcost);
                free(lowcost);
                break;
            }
            case 'q':{
                printf("程序退出\n");
                exit(0);
                break;
            }
        }
    }

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

int findIndex(MGraph *G,char *tag){
    for(int i=0;i<G->vexNum;i++){
        if(strcmp(G->vexs[i],tag)==0)return i;
    }
    return -1;
}

void dispGraph(MGraph *G){
    int vexNum=G->vexNum;
    for(int i=0;i<vexNum;i++){
        printf("%s ",G->vexs[i]);
    }
    printf("\n");
    for(int i=0;i<vexNum;i++){
        for(int j=0;j<vexNum;j++){
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
    int queue[MAX],visited[MAX]={0};
    int rear=0,front=0;
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

    printf("\n");
}

void Dijkstra(MGraph *G,int start,int *dist){
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

void PrimMST(MGraph *G,int start,LowCost *lowcost){
    int visited[MAX]={0};
    visited[start]=1;

    for(int i=0;i<G->vexNum;i++){
        lowcost[i].weight=G->arcs[start][i];
        if(lowcost[i].weight==INF)lowcost[i].adjNodeNo=-1;
        else lowcost[i].adjNodeNo=start;
    }

    for(int cnt=1;cnt<G->vexNum;cnt++){
        int minPos=-1;
        int minCost=INF;
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