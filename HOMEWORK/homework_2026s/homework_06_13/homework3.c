/*
3. 独立路径数计算
【问题描述】

老张和老王酷爱爬山，每周必爬一次香山。有次两人为从东门到香炉峰共有多少条路径发生争执，于是约定一段时间内谁走过对方没有走过的路线多谁胜。

给定一线路图（无向连通图，两顶点之间可能有多条边），编程计算从起始点至终点共有多少条独立路径，并输出相关路径信息。

注：独立路径指的是从起点至终点的一条路径中至少有一条边是与别的路径中所不同的，同时路径中不存在环路。

【输入形式】

图的顶点按照自然数（0,1,2,...,n）进行编号，其中顶点0表示起点，顶点n-1表示终点。从标准输入中首先输入两个正整数n,e，分别表示线路图的顶点的数目和边的数目，然后在接下的e行中输入每条边的信息，具体形式如下：




<n> <e>

<e1> <vi1> <vj1>

<e2> <vi2> <vj2>

...

<en> <vin> <vjn>


说明：第一行<n>为图的顶点数,<e>表示图的边数；第二行<e1> <vi1> <vj1>分别为边的序号（边序号的范围在[0,1000）之间，即包括0不包括1000）和这条边的两个顶点（两个顶点之间有多条边时，边的序号会不同），中间由一个空格分隔；其它类推。

【输出形式】

输出从起点0到终点n-1的所有路径（用边序号的序列表示路径且路径中不能有环），每行表示一条由起点到终点的路径（由边序号组成，中间有一个空格分隔，最后一个数字后跟回车），并且所有路径按照字典序输出。

【样例输入】

6 8

1 0 1

2 1 2

3 2 3

4 2 4

5 3 5

6 4 5

7 0 5

8 0 1

【样例输出】

1 2 3 5

1 2 4 6

7

8 2 3 5

8 2 4 6

【样例说明】

样例输入构成的图如下：

image.png

参考以下代码，完成dfs函数：

#include <stdio.h>

#include <stdlib.h>

#include <string.h>



#define MAX_VERTICES 100

#define MAX_EDGES 1000



typedef struct {

    int edgeNum; // 边的序号

    int to;      // 连接的顶点

} Edge;



typedef struct Node {

    Edge edge;

    struct Node* next;

} Node;



typedef struct {

    Node* head[MAX_VERTICES];

    int numVertices, numEdges;

} Graph;



// 路径存储

int path[MAX_EDGES];

int pathIndex;



// 初始化图

void initGraph(Graph* graph, int vertices) {

    graph->numVertices = vertices;

    graph->numEdges = 0;

    for (int i = 0; i < vertices; i++) {

        graph->head[i] = NULL;

    }

}



// 添加边（按边号有序插入）

void addEdge(Graph* graph, int edgeNum, int from, int to) {

    Node* newNode = (Node*)malloc(sizeof(Node));

    newNode->edge.edgeNum = edgeNum;

    newNode->edge.to = to;

    newNode->next = NULL;



    Node** current = &graph->head[from];

    while (*current && (*current)->edge.edgeNum < edgeNum) {

        current = &((*current)->next);

    }

    newNode->next = *current;

    *current = newNode;

}



// DFS 寻找所有路径

void dfs(Graph* graph, int current, int end, int visited[], int edgeVisited[]) {

    

}



int main() {

    int n, e;

    scanf("%d %d", &n, &e);



    Graph graph;

    initGraph(&graph, n);



    // 输入边的信息

    for (int i = 0; i < e; i++) {

        int edgeNum, from, to;

        scanf("%d %d %d", &edgeNum, &from, &to);

        addEdge(&graph, edgeNum, from, to);

        addEdge(&graph, edgeNum, to, from); // 无向图

    }



    // 初始化访问状态

    int visited[MAX_VERTICES] = {0};

    int edgeVisited[MAX_EDGES] = {0};

    pathIndex = 0;



    // 从起点开始 DFS

    visited[0] = 1;

    dfs(&graph, 0, n - 1, visited, edgeVisited);



    return 0;

}

【评分标准】
*/

