#include "stdio.h"
#include "stdlib.h"
#include "string.h"

#define MaxSize 50

typedef struct {
    char vexs[MaxSize][10];
    int arcs[MaxSize][MaxSize];
    int vexNum,arcNum;
}MGraph;

int findIndex(char *a,char vexs[MaxSize][10],int n);
void DFS(MGraph G,int start);

int main()
{
    MGraph G;
    scanf("%d%d",&G.vexNum,&G.arcNum);
    for(int i=0;i<G.vexNum;i++){
        scanf(" %s",G.vexs[i]);
    }
    for(int i=0;i<G.vexNum;i++){
        for(int j=0;j<G.vexNum;j++)
        G.arcs[i][j]=0;
    }
    for(int i=0;i<G.arcNum;i++){
        char a_t[10],b_t[10];
        scanf(" %s %s",a_t,b_t);
        int a=findIndex(a_t,G.vexs,G.vexNum);
        int b=findIndex(b_t,G.vexs,G.vexNum);
        G.arcs[a][b]=1;
        G.arcs[b][a]=1;
    }

    char start[10];
    scanf(" %s",start);
    int startIndex=findIndex(start,G.vexs,G.vexNum);
    if(startIndex == -1)
    {
        printf("顶点不存在\n");
        return 0;
    }
    DFS(G,startIndex);

    return 0;
}

int findIndex(char *a,char vexs[MaxSize][10],int n){
    for(int i=0;i<n;i++){
        if(strcmp(a,vexs[i])==0){
            return i;
        }
    }
    return -1;
}

void DFS(MGraph G,int start){
    static int visited[MaxSize]={0};
    visited[start]=1;
    printf("%s ",G.vexs[start]);

    for(int i=0;i<G.vexNum;i++){
        if(visited[i]==0&&G.arcs[start][i]==1){
            DFS(G,i);
        }
    }
}