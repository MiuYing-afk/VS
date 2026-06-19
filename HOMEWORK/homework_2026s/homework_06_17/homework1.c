/*
1. 社交网络好友关系分析
【问题描述】

假设你是一名社交应用的开发者，目前正在实现一个核心功能：分析用户之间的好友关系。在这个应用里，好友关系是双向的（无向图表示），并且每位用户都由一个唯一的整数 ID 表示。你的任务是编写一个程序，实现以下三个主要功能：

1、创建操作：构建好友关系网络

根据给定的用户数量及他们之间的好友关系，创建并存储一个邻接矩阵来表示这个社交网络。

2、输出操作：展示好友关系图

打印出当前构建好的邻接矩阵。

3、查找操作：查找用户间的好友关系

从一个起始用户出发，利用深度优先遍历 (DFS) 算法，找出其好友关系路径。

注意：

1、用户编号是从 1 开始的。

2、样例输入仅作为格式参考。

【输入形式】

创建操作：第一行输入一个整数 n，表示用户的总数（按1,2,3,...,n依次编号）。接下来输入若干行，每行包含两个整数 a 和 b，空格分隔，表示用户 a 和用户 b 是好友关系。输入以0 0结尾，表示好友关系输入结束。

输出操作：共一行，输入操作码 -1。

查找操作：共一行，输入操作码 -2 表示查找，空格分隔，接着输入一个整数 u 表示起始用户。

【输出形式】

输出操作：逐行打印邻接矩阵，矩阵元素之间用空格分隔。

查找操作：输出深度优先遍历结果，相邻用户之间用空格分隔。

【样例输入1】

5
1 2
1 3
1 5
2 4
2 5
3 4
4 5
0 0
-1
【样例输出1】

0 1 1 0 1
1 0 0 1 1
1 0 0 1 0
0 1 1 0 1
1 1 0 1 0
【样例输入2】

5
1 2
1 3
1 5
2 4
2 5
3 4
4 5
0 0
-2 1
【样例输出2】

1 2 4 3 5
*/

#include "stdio.h"
#include "stdlib.h"

#define MAX 100

typedef struct {
    int arcs[MAX][MAX];
    int vexNum;
}MGraph;

void crtGraph(MGraph *G);
void dispGraph(MGraph *G);
void DFS(MGraph *G,int start,int *dist);

int main()
{
    MGraph G;
    crtGraph(&G);

    int op;
    scanf("%d",&op);

    if(op==-1)dispGraph(&G);
    else{
        int dist[MAX]={0};
        int start;
        scanf("%d",&start);
        DFS(&G,start-1,dist);
        printf("\n");
    }

    return 0;
}

void crtGraph(MGraph *G){
    scanf("%d",&G->vexNum);
    for(int i=0;i<G->vexNum;i++){
        for(int j=0;j<G->vexNum;j++){
            G->arcs[i][j]=0;
        }
    } 
    for(int i=0;i<G->vexNum*G->vexNum;i++){
        int ta,tb;
        scanf("%d%d",&ta,&tb);
        if(ta==0&&tb==0)break;
        G->arcs[ta-1][tb-1]=1;
        G->arcs[tb-1][ta-1]=1;
    }
}

void dispGraph(MGraph *G){
    for(int i=0;i<G->vexNum;i++){
        for(int j=0;j<G->vexNum;j++){
            printf("%d",G->arcs[i][j]);
            if(j<G->vexNum-1)printf(" ");
        }
        printf("\n");
    }
}

void DFS(MGraph *G,int start,int *dist){
    if(start<0)return;

    printf("%d ",start+1);
    dist[start]=1;

    for(int i=0;i<G->vexNum;i++){
        if(dist[i]==0&&G->arcs[start][i]!=0)DFS(G,i,dist);
    }
}