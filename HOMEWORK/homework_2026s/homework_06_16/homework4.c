/*
4. 带权有向图求两个顶点之间的最短路径（Floyd）
【问题描述】

给定一个带权有向图，图中顶点的类型为字符串，求两个指定顶点之间的最短路径长度。采用 Floyd 算法计算所有顶点之间的最短路径。

【输入形式】

第一行输入两个正整数 n 和 m，分别表示图的顶点数和边数。

第二行输入 n 个以空格隔开的字符串，表示图中所有顶点的名称。

第三行开始，往后 m 行，每行输入两个以空格隔开的字符串 u、v 和一个整数 w，表示从顶点 u 到顶点 v 的一条边及其权重 w（可能为负数）。

最后一行输入两个字符串 s 和 t，分别表示起点和终点。

【输出形式】

输出一个整数，表示从起点 s 到终点 t 的最短路径长度。

【样例输入】

4 5
A B C D
A B 2
B C -3
C D 2
A C 4
D B 1
A D
【样例输出】

1
【样例说明】

将以下代码复制到作答区，完成floyd函数

#include <stdio.h>

#include <stdlib.h>

#include <string.h>



#define MAXN 100

#define INF 0x3f3f3f3f



// 构建一个邻接矩阵来存储图的信息，元素类型为int，用于存放边的权重

int graph[MAXN][MAXN];

// 用于存储顶点名称的数组

char vertices[MAXN][MAXN];



void init(int n){

// 读取顶点名称

    for (int i = 0; i < n; i++) {

        scanf("%s", vertices[i]);

    }

    // 初始化邻接矩阵为无穷大，即表示两点之间初始没有边相连

    for (int i = 0; i < n; i++) {

        for (int j = 0; j < n; j++) {

            graph[i][j] = INF;

        }

    }

}



void create(int n, int m){

// 读取边的信息，更新邻接矩阵中对应的权重值

    for (int i = 0; i < m; i++) {

        char u[MAXN], v[MAXN];

        int w = 0;

        scanf("%s %s %d", u, v, &w);

        // 找到输入的顶点u和v在顶点数组中的下标

        int ui = 0, vi = 0;

        for (int j = 0; j < n; j++) {

            if (strcmp(u, vertices[j]) == 0) {

                ui = j;

            }

            if (strcmp(v, vertices[j]) == 0) {

                vi = j;

            }

        }

        graph[ui][vi] = w;

    }

}



int findIndex(char s[], int n){

    for (int i = 0; i < n; i++) {

        if (strcmp(s, vertices[i]) == 0) {

            return i;

        }

    }

    return -1;

}





// Floyd算法核心函数

void floyd(int n) {

   

}



int main() {

    int n, m;

    scanf("%d %d", &n, &m);

    init(n);

    create(n, m);

    char s[MAXN], t[MAXN];

    scanf("%s %s", s, t);

    // 找到起点和终点在顶点数组中的下标

    int start = 0, end = 0;

    start = findIndex(s, n);

    end = findIndex(t, n);

    // 执行Floyd算法

    floyd(n);

    // 输出起点到终点的最短路径长度

    printf("%d\n", graph[start][end]);

    return 0;

}


【评分标准】
*/

#include "stdio.h"
#include "stdlib.h"
#include "string.h"

#define MAX 100
#define INF 0x3f3f3f3f

typedef struct {
    char vexs[MAX][10];
    int arcs[MAX][MAX];
    int vexNum,arcNum;
}MGraph;

void crtGraph(MGraph *G);
int findIndex(MGraph *G,char *tag);
void Floyd(MGraph *G);

int main()
{
    MGraph G;
    crtGraph(&G);
    Floyd(&G);

    char s[10], t[10];
    scanf("%s %s", s, t);
    int st = findIndex(&G, s);
    int ed = findIndex(&G, t);
    printf("%d", G.arcs[st][ed]);
    return 0;
}

void crtGraph(MGraph *G){
    scanf("%d%d",&G->vexNum,&G->arcNum);
    for(int i=0;i<G->vexNum;i++){
        scanf(" %s",G->vexs[i]);
    }
    for(int i=0;i<G->vexNum;i++){
        for(int j=0;j<G->vexNum;j++){
            G->arcs[i][j]=INF;
        }
    }
    for(int i=0;i<G->vexNum;i++)G->arcs[i][i]=0;
    for(int i=0;i<G->arcNum;i++){
        char str_a[10],str_b[10];
        int degree;
        scanf(" %s %s %d",str_a,str_b,&degree);
        int ta=findIndex(G,str_a);
        int tb=findIndex(G,str_b);
        G->arcs[ta][tb]=degree;
    }
}

int findIndex(MGraph *G,char *tag){
    for(int i=0;i<G->vexNum;i++){
        if(strcmp(G->vexs[i],tag)==0)return i;
    }
    return -1;
}

void Floyd(MGraph *G)
{
    // 1. 取出顶点总数，简化代码
    int n = G->vexNum;
    int k, i, j;

    // 2. 三层循环：k 中转点，i 起点，j 终点
    for(k = 0; k < n; k++)
    {
        for(i = 0; i < n; i++)
        {
            for(j = 0; j < n; j++)
            {
                // 3. 判断：i能走到k 并且 k能走到j（防止无穷大相加溢出出错）
                if(G->arcs[i][k] != INF && G->arcs[k][j] != INF)
                {
                    // 4. 松弛核心：比较两条路线哪个更短
                    // 路线1：i 直接走到 j，距离 G->arcs[i][j]
                    // 路线2：i → k → j，距离 G->arcs[i][k] + G->arcs[k][j]
                    if(G->arcs[i][j] > G->arcs[i][k] + G->arcs[k][j])
                    {
                        // 路线2更短，更新i到j的最短距离
                        G->arcs[i][j] = G->arcs[i][k] + G->arcs[k][j];
                    }
                }
            }
        }
    }
}