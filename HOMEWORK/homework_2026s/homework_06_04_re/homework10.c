#include "stdio.h"
#include "stdlib.h"
#include "string.h"

#define MAXSIZE 100
#define INF 0x3f3f3f3f

typedef struct {
    char vexs[MAXSIZE][10];
    int arcs[MAXSIZE][MAXSIZE];
    int vexNum,arcNum;
}MGraph;

typedef struct {
    int adjNodeNo;
    int weight;
}LowCost;

void crtGraph(MGraph *G);
int findIndex(MGraph *G,char *tag);
void MSTGraph(MGraph *G,int start,LowCost *lowcost);

int main()
{
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
    flag[start]=1;

    for(int i=0;i<G->vexNum;i++){
        lowcost[i].weight=G->arcs[start][i];
        if(lowcost[i].weight==INF)lowcost[i].adjNodeNo=-1;
        else lowcost[i].adjNodeNo=start;
    }

    for(int cnt=1;cnt<G->vexNum;cnt++){
        int minCost=INF;
        int minPos=-1;
        for(int i=0;i<G->vexNum;i++){
            if(flag[i]==0&&lowcost[i].weight<minCost){
                minCost=lowcost[i].weight;
                minPos=i;
            }
        }
        if(minPos==-1)break;

        int p=lowcost[minPos].adjNodeNo;
        char *u=G->vexs[p];
        char *v=G->vexs[minPos];
        if(strcmp(u,v)<0)printf("%s-%s %d\n",u,v,lowcost[minPos].weight);
        else printf("%s-%s %d\n", v, u, lowcost[minPos].weight);

        flag[minPos]=1;

        for(int i=0;i<G->vexNum;i++){
            if(flag[i]==0&&G->arcs[minPos][i]!=INF){
                if(G->arcs[minPos][i] < lowcost[i].weight){
                    lowcost[i].weight = G->arcs[minPos][i];
                    lowcost[i].adjNodeNo = minPos;
                }
            }
        }
    }
}
