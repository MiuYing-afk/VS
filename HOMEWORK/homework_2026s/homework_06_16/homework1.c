/*
1. 最少布线
【问题描述】

某学校有主要办公科研楼有教五楼、教一楼、教三楼、教二楼、图书馆、主楼等。该校网络中心计划要给相关建筑物间铺设光缆进行网络连通，请给出用料最少的铺设方案。编写程序输入一个办公区域分布图及建筑物之间的距离，计算出用料最少的铺设方案（只有一组最优解，不用考虑多组解)。

【输入形式】

办公区域分布图的顶点（即建筑物）按照自然数（0，1，2，n-1）进行编号，从标准输入中首先输入两个正整数，分别表示线路图的顶点的数目和边的数目，然后在接下的行中输入每条边的信息，每条边占一行，具体形式如下：



<n> <e>

<id> <vi> <vj> <weight>

...

即顶点vi和vj之间边的权重是weight，边的编号是id。

【输出形式】

输出铺设光缆的最小用料数，然后另起一行输出需要铺设的边的id，并且输出的id值按照升序输出。

【样例输入】

6 10

1 0 1 600

2 0 2 100

3 0 3 500

4 1 2 500

5 2 3 500

6 1 4 300

7 2 4 600

8 2 5 400

9 3 5 200

10 4 5 600

【样例输出】

1500

2 4 6 8 9

【样例说明】

样例输入说明该分布图有6个顶点，10条边；顶点0和1之间有条边，边的编号为1，权重为600；顶点0和2之间有条边，权重为100，其它类推。其对应图如下：

image.png

参考以下代码，完成find、unionSet、insertSorted函数：

#include <stdio.h>

#include <stdlib.h>



typedef struct Edge {

    int id;

    int u, v;

    int weight;

} Edge;



int find(int parent[], int i) {

   

}



void unionSet(int parent[], int x, int y) {

    

}



int compareWeight(const void *a, const void *b) {

    Edge *a1 = (Edge *)a;

    Edge *b1 = (Edge *)b;

    return a1->weight - b1->weight;

}



void insertSorted(Edge result[], int *e, Edge edge) {

    

}



int main() {

    int n, m;

    scanf("%d %d", &n, &m);

    

    Edge edges[m];

    for (int i = 0; i < m; i++) {

        scanf("%d %d %d %d", &edges[i].id, &edges[i].u, &edges[i].v, &edges[i].weight);

    }



    qsort(edges, m, sizeof(Edge), compareWeight);



    int parent[n];

    for (int i = 0; i < n; i++)

        parent[i] = i;



    int minCost = 0;

    Edge result[m];

    int e = 0;



    for (int i = 0; i < m; i++) {

        int u = edges[i].u;

        int v = edges[i].v;

        int set_u = find(parent, u);

        int set_v = find(parent, v);



        if (set_u != set_v) {

            insertSorted(result, &e, edges[i]);

            minCost += edges[i].weight;

            unionSet(parent, set_u, set_v);

        }

    }



    printf("%d\n", minCost);

    for (int i = 0; i < e; i++)

        printf("%d ", result[i].id);

    printf("\n");



    return 0;

}

【评分标准】
*/

#include "stdio.h"
#include "stdlib.h"

#define MAX_VEX 100
#define INF 0x3f3f3f3f

typedef struct {
    int id;
    int u,v;
    int weight;
}Edge;

int find(int *parent,int i);
void unionSet(int *parent,int x,int y);
int compareWeight(const void *a,const void *b);
void insertSorted(Edge *result,int *e,Edge edge);

int main()
{
    int n,m;
    scanf("%d%d",&n,&m);

    Edge edges[m];
    for(int i=0;i<m;i++){
        scanf("%d%d%d%d",&edges[i].id,&edges[i].u,&edges[i].v,&edges[i].weight);
    }

    qsort(edges,m,sizeof(Edge),compareWeight);

    int parent[n];
    for(int i=0;i<n;i++)parent[i]=i;

    int minCost =0;
    Edge result[m];
    int e=0;

    for(int i=0;i<m;i++){
        int u=edges[i].u;
        int v=edges[i].v;
        int set_u=find(parent,u);
        int set_v=find(parent,v);

        if(set_u!=set_v){
            insertSorted(result,&e,edges[i]);
            minCost+=edges[i].weight;
            unionSet(parent,set_u,set_v);
        }
    }

    printf("%d\n",minCost);
    for(int i=0;i<e;i++){
        printf("%d ",result[i].id);
    }
    printf("\n");

    return 0;
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

int compareWeight(const void *a,const void *b){
    Edge *a1=(Edge*)a;
    Edge *b1=(Edge*)b;
    return a1->weight - b1->weight;
}

void insertSorted(Edge *result,int *e,Edge edge){
    int pos=*e;
    while(pos>0&&result[pos-1].id>edge.id){
        result[pos]=result[pos-1];
        pos--;
    }
    result[pos]=edge;
    (*e)++;
}
