/*
1. 无向图邻接矩阵存储
【问题描述】

给定一个 n个顶点 m 条边的无向图。请以邻接矩阵的形式输出这一张图。

【输入形式】

第一行输入两个正整数 n 和 m，表示图的顶点数和边数。

第二行开始，往后 m 行，每行输入两个以空格隔开的正整数 u,v，表示 u,v 顶点之间有一条边直接相连。

【输出形式】

输出 n 行 n 列的矩阵，以空格隔开每一行之间的数表示邻接矩阵。第 i 行第 j 列的数为 1 则表示
顶点 i,j 之间有一条边直接相连；若为 0 则表示没有直接相连的边。

【样例输入】

5 5
1 2
2 3
3 5
1 3
3 4
【样例输出】

0 1 1 0 0
1 0 1 0 0
1 1 0 1 1
0 0 1 0 0
0 0 1 0 0
【样例说明】输出一个5 * 5的矩阵，第一行第二列元素为1，表示顶点1和顶点2之间有一条直接相连的边。
【评分标准】
*/

#include "stdio.h"
#include "stdlib.h"

int main()
{
    int **arc;
    int n,op;
    scanf("%d%d",&n,&op);
    arc=(int**)malloc(n*sizeof(int*));
    for(int i=0;i<n;i++){
        arc[i]=(int*)calloc(n,sizeof(int));
    }

    int a,b;
    for(int i=0;i<op;i++){
        scanf("%d%d",&a,&b);
        arc[a-1][b-1]=1;
        arc[b-1][a-1]=1;
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            printf("%d",arc[i][j]);
            if(j<n-1)printf(" ");
        }
        printf("\n");
    }

    return 0;
}