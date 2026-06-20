#include "stdio.h"
#include "stdlib.h"

typedef struct Edge {
    int id;
    int u,v;
    int weight;
}Edge;

int main()
{
    int vexNum,arcNum;
    scanf("%d%d",&vexNum,&arcNum);

    Edge* edges=(Edge*)malloc(arcNum*sizeof(Edge));
    for(int i=0;i<arcNum;i++){
        scanf("%d%d%d%d",edges[i].id,edges[i].u,edges[i].v,edges[i].weight);
    }

    return 0;
}