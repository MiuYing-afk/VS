#include "stdio.h"
#include "stdlib.h"

typedef struct Edge {
    int id;
    int u,v;
    int weight;
}Edge;

int compareWeight(const void *a,const void *b);
int find(int *parent,int i);
void unionSet(int *parent,int x,int y);
void insertSorted(Edge *result,int *finalEdges,Edge edge);

int main()
{
    int vexNum,arcNum;
    scanf("%d%d",&vexNum,&arcNum);

    Edge* edges=(Edge*)malloc(arcNum*sizeof(Edge));
    for(int i=0;i<arcNum;i++){
        scanf("%d%d%d%d",edges[i].id,edges[i].u,edges[i].v,edges[i].weight);
    }

    qsort(edges,arcNum,sizeof(Edge),compareWeight);

    int *parent=(int*)malloc(sizeof(int));
    for(int i=0;i<vexNum;i++)parent[i]=i;

    int minCost=0;//累加最小生成树所有选中边的总权值
    Edge *result=(Edge*)malloc(arcNum*sizeof(Edge));//用来保存最终被选进最小生成树的所有边；
    int finalEdges=0;

    for(int i=0;i<arcNum;i++){
        int u=edges[i].u;
        int v=edges[i].v;
        int set_u=find(parent,u);
        int set_v=find(parent,v);

        if(set_u!=set_v){
            insertSorted(result,&finalEdges,edges[i]);
            minCost+=edges[i].weight;
            unionSet(parent,set_u,set_v);
        }
    }

    printf("%d\n", minCost);
    for(int i=0;i<finalEdges;i++)
        printf("%d ", result[i].id);
    printf("\n");

    free(edges);
    free(parent);
    free(result);

    return 0;
}

//按照权值,从小到大排序
int compareWeight(const void *a,const void *b){
    Edge *a1=(Edge*)a;
    Edge *b1=(Edge*)b;
    return a1->weight-b1->weight;//返回负数,a1放左边;返回正数,a1放右边
}


int find(int *parent,int i){
    if(parent[i]!=i){
        parent[i]=find(parent,parent[i]);
    }
    return parent[i];
}

void unionSet(int *parent,int x,int y){
    parent[y]=x;
}

void insertSorted(Edge *result,int *finalEdges,Edge edge){
    int pos=*finalEdges;
    while(pos>0&&result[pos-1].id>edge.id){
        //直插法理顺编号
        result[pos]=result[pos-1];
        pos--;
    }    
    result[pos]=edge;
    (*finalEdges)++;
}