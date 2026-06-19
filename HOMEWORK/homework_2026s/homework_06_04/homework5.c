/*
5. 无向图深度优先遍历
【问题描述】

无向图（连通或者不连通都要支持）采用邻接矩阵进行存储，图中顶点的类型为字符串。
从指定的源点出发进行深度优先遍历。

【输入形式】

第一行输入两个正整数 n 和 m，表示图的顶点数和边数。

第二行依次输入顶点字符串，用空格隔开。

第三行开始，往后 m 行，每行输入两个以空格隔开的字符串 u,v，表示顶点 u与v 之间的一条边。

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
C D
C E
D E
B
【样例输出】

B A D C E

【样例说明】从B节点开始深度优先遍历依次经过A、D、C、E。

将以下代码复制到作答区，完成dfs函数编写：


#include <stdio.h>

#include <stdlib.h>

#include <string.h>



#define MAX_VERTICES 100



// 邻接矩阵表示图

int adjMatrix[MAX_VERTICES][MAX_VERTICES];

// 访问标记数组

int visited[MAX_VERTICES];

// 顶点数组

char vertices[MAX_VERTICES][10];



void init(int n, int m){



    for (int i = 0; i < n; i++) {

        for (int j = 0; j < n; j++) {

            adjMatrix[i][j] = 0;

        }

        visited[i] = 0;

    }

}



void create(int n, int m){

    char u[10], v[10];

     // 读取顶点

    for (int i = 0; i < n; i++) {

        scanf("%s", vertices[i]);

    }



    // 读取边并构建邻接矩阵

    for (int i = 0; i < m; i++) {

        scanf("%s %s", u, v);

        int uIndex = -1, vIndex = -1;

        // 找到顶点u和v在顶点数组中的索引

        for (int j = 0; j < n; j++) {

            if (strcmp(vertices[j], u) == 0) uIndex = j;

            if (strcmp(vertices[j], v) == 0) vIndex = j;

        }

        // 建立无向图的邻接矩阵

        adjMatrix[uIndex][vIndex] = 1;

        adjMatrix[vIndex][uIndex] = 1;

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

void DFS(int vertex, int n) {



}



// 主函数

int main() {

    int n, m;



    // 读取顶点数和边数

    scanf("%d %d", &n, &m);



    // 初始化邻接矩阵和访问标记数组

    init(n, m);



    //构建邻接矩阵

    create(n, m);



    // 读取起始顶点并找到其在顶点数组中的索引

    int startVertex = getstart(n);



    // 从指定顶点开始深度优先遍历

    DFS(startVertex, n);



    return 0;

}


【评分标准】
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
        graph[b][a]=1;
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

    for(int i=0;i<n;i++){
        if(graph[v][i]==1&&visited[i]==0){
            dfs(i);
        }
    }
}