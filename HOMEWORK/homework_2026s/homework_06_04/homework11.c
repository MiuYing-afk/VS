/*
11. 无向图求连通分量
【问题描述】

给定一个无向图（不一定连通），包含n个节点和m条边，节点编号从1到n。
请找出图中所有的连通分量，并输出每个连通分量中的节点结合。

【输入形式】

第一行包含两个整数n和m（1≤n,m≤100），分别表示图中的节点数和边数。

接下来的m行，每行包含两个整数u和v，（1≤u,v≤n, 且u≠v），表示无向图的一条边连接节点u和v。

【输出形式】

输出多行，每行是一个连通分量的节点集合，节点编号按升序排列。输出的各连通分量按任意顺序排列。

【样例输入1】

6 4
1 2
2 3
4 5
5 6
【样例输出1】

1 2 3
4 5 6
【样例输入2】

5 0
【样例输出2】

1
2
3
4
5
*/

#include "stdio.h"
#include "stdlib.h"

#define MAX_VEXS_SIZE 105

typedef struct {
    int arcs[MAX_VEXS_SIZE][MAX_VEXS_SIZE];
    int arcNum,vexNum;
}MGraph;

void crtGraph(MGraph *G);
void DFS(MGraph *G,int *visited,int tag);
void CC(MGraph *G);

int main()
{
    MGraph G;
    crtGraph(&G);
    CC(&G);

    return 0;
}

void crtGraph(MGraph *G){
    scanf("%d%d",&G->vexNum,&G->arcNum);
    for(int i=0;i<G->vexNum;i++){
        for(int j=0;j<G->vexNum;j++){
            G->arcs[i][j]=0;
        }
    }
    for(int i=0;i<G->arcNum;i++){
        int ta,tb;
        scanf("%d%d",&ta,&tb);
        G->arcs[ta-1][tb-1]=1;
        G->arcs[tb-1][ta-1]=1;
    }
}

void DFS(MGraph *G,int *visited,int tag){
    if(tag<0||tag>=G->vexNum)return;

    visited[tag]=1;
    for(int i=0;i<G->vexNum;i++){
        if(!visited[i]&&G->arcs[tag][i]==1)DFS(G,visited,i);
    }
}

void CC(MGraph *G){
    int visited[MAX_VEXS_SIZE]={0};
    int start=0;
    int tag=1;
    while(tag){
        DFS(G,visited,start);
        for(int i=0;i<G->vexNum;i++){
            if(visited[i]==1){
                printf("%d ",i+1);
                visited[i]=2;
            }
        }
        printf("\n");
        tag=0;
        for(int i=0;i<G->vexNum;i++){
            if(visited[i]==0){
                tag=1;
                start=i;
                break;
            }
        }
    }
}