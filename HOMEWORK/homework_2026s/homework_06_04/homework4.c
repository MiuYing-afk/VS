/*
4. 有向图邻接表存储
【问题描述】

给定一个 n 个顶点 m 条边的有向图。请以邻接表的形式输出这一张图。

【输入形式】

第一行输入两个正整数 n 和 m，表示图的顶点数和边数。

第二行开始，往后 m 行，每行输入两个以空格隔开的正整数 u,v，表示顶点 u指向v 的一条边。

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

2 3

3 4 5

4

5

【样例说明】顶点1有一条指向顶点2的边，顶点4和顶点5没有指向任何节点的边。
【评分标准】
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