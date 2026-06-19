/*
8. 有向图深度优先遍历
【问题描述】

有向图（连通或者不连通都要支持）采用邻接表进行存储（采用头插法构建），图中顶点的类型为字符串。从指定的源点出发进行深度优先遍历。

【输入形式】

第一行输入两个正整数 n 和 m，表示图的顶点数和边数。

第二行输入各个顶点对应的字符串，空格分隔。

第三行开始，往后 m 行，每行输入两个以空格隔开的字符串 u,v，表示顶点 u指向v 的一条边。

最后一行输入某个顶点的字符串内容，表示从该顶点出发，对图进行深度优先遍历。

【输出形式】

输出一行，从顶点开始按照深度优先遍历的顺序输出每个顶点的字符串名称，每个名称之间以空格隔开。

【样例输入】

5 7
A B C D E
A B
A D
A E
B C
C E
D C
D E
A
【样例输出】

A E D C B
【样例说明】

将下面代码复制到作答区，实现DFS：


#include <stdio.h>

#include <stdlib.h>

#include <string.h>



#define MAX_VERTICES 100



// 邻接表节点

typedef struct Node {

    int vertex;

    struct Node* next;

} Node;



// 邻接表

Node* adjList[MAX_VERTICES];

// 访问标记数组

int visited[MAX_VERTICES];

// 顶点数组

char vertices[MAX_VERTICES][10];

// 顶点字符串到索引的映射

int vertexMap[MAX_VERTICES];



// 创建邻接表节点

Node* createNode(int v) {

    Node* newNode = (Node*)malloc(sizeof(Node));

    newNode->vertex = v;

    newNode->next = NULL;

    return newNode;

}



// 添加边到邻接表

void addEdge(int start, int end) {

    Node* newNode = createNode(end);

    newNode->next = adjList[start];

    adjList[start] = newNode;

}



void init(int n){

    // 初始化邻接表和访问标记数组

    for (int i = 0; i < n; i++) {

        adjList[i] = NULL;

        visited[i] = 0;

        vertexMap[i] = -1;

    }

}



void create(int n, int m){

    char u[10], v[10];

    // 读取顶点

    for (int i = 0; i < n; i++) {

        scanf("%s", vertices[i]);

        vertexMap[i] = i;

    }



    // 读取边并构建邻接表

    for (int i = 0; i < m; i++) {

        scanf("%s %s", u, v);

        int uIndex = -1, vIndex = -1;

        // 找到顶点u和v在顶点数组中的索引

        for (int j = 0; j < n; j++) {

            if (strcmp(vertices[j], u) == 0) uIndex = j;

            if (strcmp(vertices[j], v) == 0) vIndex = j;

        }

        // 建立有向图的邻接表

        addEdge(uIndex, vIndex);

    }

}



int getstart(int n){

    int startVertex = 0;

    char u[10];

    // 读取起始顶点并找到其在顶点数组中的索引

    scanf("%s", u);

    for (int i = 0; i < n; i++) {

        if (strcmp(vertices[i], u) == 0) {

            startVertex = i;

            break;

        }

    }

    return startVertex;

}





// 深度优先遍历函数

void DFS(int vertex) {



}



// 主函数

int main() {

    int n, m;

    // 读取顶点数和边数

    scanf("%d %d", &n, &m);

    init(n);

    create(n, m);

    int startVertex = getstart(n);

    // 从指定顶点开始深度优先遍历

    DFS(startVertex);

    return 0;

}


*/

#include "stdio.h"
#include "stdlib.h"
#include "string.h"

int n;
int graph[100][100];
int visited[100];
char vertex[100][10];

int findIndex(char *v);
void dfs(int v);

int main()
{
    int m;
    scanf("%d %d",&n,&m);

    for(int i=0;i<n;i++){
        scanf("%s",vertex[i]);
    }

    char u[10],v[10];
    for(int i=0;i<m;i++){
        scanf("%s %s",u,v);
        int a=findIndex(u);
        int b=findIndex(v);
        graph[a][b]=1;
    }

    for(int i=0;i<n;i++){
        visited[i]=0;
    }

    char start[10];
    scanf("%s",start);
    int startIndex=findIndex(start);
    dfs(startIndex);

    return 0;
}

int findIndex(char *v){
    for(int i=0;i<n;i++){
        if(strcmp(vertex[i],v)==0){
            return i;
        }
    }
    return -1;
}

void dfs(int v){
    visited[v]=1;
    printf("%s ",vertex[v]);

    for(int i=n-1;i>=0;i--){
        if(graph[v][i]==1&&visited[i]==0){
            dfs(i);
        }
    }
}