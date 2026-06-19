/*
2. 无向图邻接表存储
【问题描述】

给定一个 n 个顶点 m 条边的无向图。请以邻接表的形式输出这一张图。

【输入形式】

第一行输入两个正整数 n 和 m，表示图的顶点数和边数。

第二行开始，往后 m 行，每行输入两个以空格隔开的正整数 u,v，表示 u,v 顶点之间有一条边直接相连。

【输出形式】

输出 n 行。第 i 行首先先输出一个整数 d_i，表示这个顶点的编号，再按照从小到大的顺序，依次输出与顶点 i 直接相连的所有顶点。

【样例输入】

5 5
1 2
2 3
3 5
1 3
3 4
【样例输出】

1 2 3
2 1 3
3 1 2 4 5
4 3
5 3
【样例说明】

本题中顶点编号是连续的，从1开始按顶点数量依次递增，例如样例1中对应的顶点编号分别为1 2 3 4 5；

顶点1和顶点2、3相连，因此第一行为1、2、3；

如果该点没有其他点与它直接相连，则只输出该点编号。
*/

#include "stdio.h"
#include "stdlib.h"

int main()
{
    int **arc;
    int n,op,a,b;
    scanf("%d%d",&n,&op);
    arc=(int**)malloc(n*sizeof(int*));
    for(int i=0;i<n;i++){
        arc[i]=(int*)calloc(n,sizeof(int));
    }

    for(int i=0;i<op;i++){
        scanf("%d%d",&a,&b);
        arc[a-1][b-1]=1;
        arc[b-1][a-1]=1;
    }

    for(int i=0;i<n;i++){
        printf("%d ",i+1);
        for(int j=0;j<n;j++){
            if(arc[i][j]==1&&i!=j)printf("%d ",j+1);
        }
        printf("\n");
    }

    return 0;
}