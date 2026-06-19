#include "stdio.h"
#include "stdlib.h"

typedef struct ArcNode{
    int adjvex;
    struct ArcNode *nextArc;
}ArcNode;

typedef struct VertexNode{
    int vertex;
    ArcNode *firstArc;
}VertexNode;

typedef struct ALGraph{
    VertexNode adjlist[20];
    int vexNum,arcNum;
}ALGraph;

void crt_ALGraph(ALGraph *G);
void dispALGraph(ALGraph G);

int main()
{
    ALGraph G;
    crt_ALGraph(&G);
    dispALGraph(G);

    return 0;
}

void crt_ALGraph(ALGraph *G){
    scanf("%d%d",&G->vexNum,&G->arcNum);
    for(int i=0;i<G->vexNum;i++){
        G->adjlist[i].vertex=i+1;
        G->adjlist[i].firstArc=NULL;
    }
    for(int i=0;i<G->arcNum;i++){
        int a,b;
        scanf("%d%d",&a,&b);
        ArcNode *p=G->adjlist[a-1].firstArc;
        if(p==NULL){
            p=(ArcNode*)malloc(sizeof(ArcNode));
            p->adjvex=b;
            p->nextArc=NULL;
            G->adjlist[a-1].firstArc=p;
        }else{
            while(p->nextArc!=NULL)p=p->nextArc;
            ArcNode *new=(ArcNode*)malloc(sizeof(ArcNode));
            new->adjvex=b;
            new->nextArc=p->nextArc;
            p->nextArc=new;
        }
    }
}

void dispALGraph(ALGraph G){
    for(int i=0;i<G.vexNum;i++){
        printf("%d",G.adjlist[i].vertex);
        ArcNode *p=G.adjlist[i].firstArc;
        while(p!=NULL){
            printf(" %d",p->adjvex);
            p=p->nextArc;
        }
        if(i<G.vexNum-1)printf("\n");
    }
}