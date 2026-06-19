/*
4. 拓扑排序
【问题描述】

给定一个有向无环图（DAG），图中包含 n 个顶点，标号为 1 到 n。请输出该图的字典序最小的拓扑排序。

字典序最小的定义是：在所有合法的拓扑排序中，第一个顶点尽量小，若第一个顶点相同，则比较第二个顶点，依此类推。

【输入形式】

第一行输入两个正整数 n 和 m，分别表示图的顶点数和边数。

接下来 m 行，每行输入两个以空格隔开的正整数 u,v，表示从顶点 u 到顶点 v 有一条有向边。

【输出形式】

输出一行，表示该图的字典序最小的拓扑排序。顶点之间用单个空格隔开。

【样例输入】

6 6

1 2

1 3

2 4

3 4

5 2

6 3

【样例输出】

1 5 6 2 3 4

【样例说明】

将以下代码复制到作答区，完成topologicalSort函数：

#include <stdio.h>

#include <stdlib.h>

#include <string.h>



#define MAXN 1000



int graph[MAXN][MAXN]; // 邻接矩阵存储图

int inDegree[MAXN];    // 入度数组

int nodes[MAXN];       // 节点数组（用于存储 1 到 n 的节点编号）



// 按字典序（节点编号）从小到大对数组排序

int compare(const void* a, const void* b) {

    return *(int*)a - *(int*)b;

}



void init(int n){

// 初始化图和节点数组

    memset(graph, 0, sizeof(graph));

    memset(inDegree, 0, sizeof(inDegree));

    for (int i = 0; i < n; i++) {

        nodes[i] = i + 1;

    }

}



void create(int n, int m){

    // 读取边并构建图

    for (int i = 0; i < m; i++) {

        int u, v;

        scanf("%d %d", &u, &v);

        graph[u][v] = 1;

        inDegree[v]++;

    }

}



// 拓扑排序

void topologicalSort(int n) {

    

}



int main() {

    int n, m;

    scanf("%d %d", &n, &m);

    init(n);

    create(n, m);

    // 对节点按字典序排序（只需要一次）

    qsort(nodes, n, sizeof(int), compare);

    // 执行拓扑排序

    topologicalSort(n);

    return 0;

}


【评分标准】
*/

#include "stdio.h"
#include "stdlib.h"
#include "string.h"

int main()
{
    

    return 0;
}