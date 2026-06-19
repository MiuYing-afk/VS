#include "stdio.h"

typedef struct {
    int vexs[20];
    int arcs[20][20];
    int vexNum,arcNum;
}MGraph;

void crt_MGraph(MGraph *G);
void dispMGraph(MGraph G);

int main()
{
    MGraph G;
    crt_MGraph(&G);
    dispMGraph(G);

    return 0;
}

void crt_MGraph(MGraph *G){
    scanf("%d%d",&G->vexNum,&G->arcNum);
    for(int i=0;i<G->vexNum;i++){
        for(int j=0;j<G->vexNum;j++){
            G->arcs[i][j]=0;
        }
    }
    for(int k=0;k<G->arcNum;k++){
        int a,b;
        scanf("%d%d",&a,&b);
        G->arcs[a-1][b-1]=1;
    }
}

void dispMGraph(MGraph G){
    for(int i=0;i<G.vexNum;i++){
        for(int j=0;j<G.vexNum;j++){
            printf("%d",G.arcs[i][j]);
            if(j<G.vexNum-1)printf(" ");
        }
        printf("\n");
    }
}