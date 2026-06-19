#include "stdio.h"
#include "stdlib.h"

typedef struct{
    int vexs[20];
    int arcs[20][20];
    int vexNum,arcNum;
}MGraph;

void crt_Graph(MGraph *G);
void dispGraph(MGraph G);

int main()
{
    MGraph G;
    crt_Graph(&G);
    dispGraph(G);

    return 0;
}

void crt_Graph(MGraph *G){
    scanf("%d%d",&G->vexNum,&G->arcNum);
    int i,j;
    for(i=0;i<G->vexNum;i++){
        for(j=0;j<G->vexNum;j++){
            G->arcs[i][j]=0;
        }
    }
    for(int k=0;k<G->arcNum;k++){
        scanf("%d%d",&i,&j);
        G->arcs[i-1][j-1]=1;
        G->arcs[j-1][i-1]=1;
    }
}

void dispGraph(MGraph G){
    for(int i=0;i<G.vexNum;i++){
        for(int j=0;j<G.vexNum;j++){
            printf("%d",G.arcs[i][j]);
            if(j<G.vexNum-1)printf(" ");
        }
        printf("\n");
    }
}