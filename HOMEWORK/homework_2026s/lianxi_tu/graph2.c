//十字链表有向图

#include "stdio.h"
#include "stdlib.h"

#define MAX_VEX 100

typedef struct ArcNode{
    int tailvex,headvex;
    struct ArcNode *hlink,*tlink;
    int weight;
}ArcNode;

typedef struct VexNode{
    int data;
    ArcNode *firstin,*firstout;
}VexNode;

typedef struct {
    VexNode xlist[MAX_VEX];
    int vexNum,arcNum;
}OLGraph;

void InitOLGraph(OLGraph *G,int n);
void Insert(OLGraph *G,int u,int v,int w);
void PrintOut(OLGraph *G);
void PrintIn(OLGraph *G);

int main()
{
    OLGraph G;
    InitOLGraph(&G, 4);
    Insert(&G, 0, 1, 5);
    Insert(&G, 0, 2, 3);
    Insert(&G, 1, 3, 1);
    Insert(&G, 2, 3, 4);

    PrintOut(&G);
    PrintIn(&G);

    return 0;
}

//初始化十字链表图
void InitOLGraph(OLGraph *G,int n){
    G->vexNum=n;
    G->arcNum=0;
    for(int i=0;i<n;i++){
        G->xlist[i].data=i;
        G->xlist[i].firstin=NULL;
        G->xlist[i].firstout=NULL;
    }
}

//添加有向弧 <u→v>，带权值
void Insert(OLGraph *G,int u,int v,int w){
    ArcNode *arc=(ArcNode*)malloc(sizeof(ArcNode));
    arc->tailvex=u;
    arc->headvex=v;
    arc->weight=w;
    arc->hlink=NULL;
    arc->tlink=NULL;

    arc->tlink=G->xlist[u].firstout;
    G->xlist[u].firstout=arc;

    arc->hlink=G->xlist[v].firstin;
    G->xlist[v].firstin=arc;

    G->arcNum++;
}

//打印所有顶点出边
void PrintOut(OLGraph *G)
{
    for(int i = 0; i < G->vexNum; i++)
    {
        printf("顶点%d 出边：", G->xlist[i].data);
        ArcNode *p = G->xlist[i].firstout;
        while(p)
        {
            printf("%d->%d(w=%d) ", p->tailvex, p->headvex, p->weight);
            p = p->tlink;
        }
        printf("\n");
    }
}

//打印所有顶点入边
void PrintIn(OLGraph *G)
{
    for(int i = 0; i < G->vexNum; i++)
    {
        printf("顶点%d 入边：", G->xlist[i].data);
        ArcNode *p = G->xlist[i].firstin;
        while(p)
        {
            printf("%d->%d(w=%d) ", p->tailvex, p->headvex, p->weight);
            p = p->hlink;
        }
        printf("\n");
    }
}