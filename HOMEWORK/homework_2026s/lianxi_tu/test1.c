/*
1. 带权无向图 - 考试 - 最短路径
【问题描述】

带权无向图（连通或者不连通都要支持）采用邻接矩阵进行存储，图中顶点的类型为字符串，完成以下操作：

1. 创建图的邻接矩阵

2. 输出图的顶点和邻接矩阵

3. 从指定的源点出发进行深度优先遍历

4. 从指定的源点出发进行广度优先遍历

5. 迪杰斯特拉求最短路径

注意：c为创建图的邻接矩阵；o为输出图的顶点和邻接矩阵；d为深度优先遍历；b为广度优先遍历；j为迪杰斯特拉算法；q为程序退出操作



操作1：创建图的邻接矩阵并输出图的顶点和邻接矩阵

【样例输入】


c

5 7

A B C D E

A B 10

A D 30

A E 100 

B C 50

C D 20

C E 10

D E 60

o

q

【样例输出】


A B C D E 

    0   10    0   30  100

   10    0   50    0    0

    0   50    0   20   10

   30    0   20    0   60

  100    0   10   60    0

程序退出

【样例说明】


5 7 // 5为顶点数量，7为边的数量

A B C D E  // 顶点的名称

A B 10  // 边的权值

A D 30

A E 100 

B C 50

C D 20

C E 10

D E 60

注意：输出邻接矩阵的每个位置的值时采用printf("%5d")的格式



操作2：从指定的源点出发进行深度优先遍历

【样例输入】


c

5 7

A B C D E

A B 10

A D 30

A E 100 

B C 50

C D 20

C E 10

D E 60

d

B

q

【样例输出】


B A D C E

程序退出




操作3：从指定的源点出发进行广度优先遍历

【样例输入】


c

5 7

A B C D E

A B 10

A D 30

A E 100 

B C 50

C D 20

C E 10

D E 60

b

A

q

【样例输出】


A B D E C

程序退出



操作4：从指定的源点出发，使用迪杰斯特拉求最短路径

【样例输入】


c

5 7

A B C D E

A B 10

A D 30

A E 100 

B C 50

C D 20

C E 10

D E 60

j

A

q

【样例输出】


A 0 

B 10

C 50

D 30

E 60

程序退出
*/

#include "stdio.h"
#include "stdlib.h"
#include "string.h"

#define MaxSize 100

typedef struct {
    char vexs[MaxSize][10];
    int arcs[MaxSize][MaxSize];
    int vexNum,arcNum;
}Graph;

void crt_Graph(Graph *G);
void dispGraph(Graph G);
void DFS(Graph *G,int *visited,int start);
void BFS(Graph *G,int start);
void Dijkstra(Graph *G,int start,int *dist);
int findIndex(Graph *G,char *tag);

int main()
{
    Graph G;
    char op;
    while(1){
        scanf("%c",&op);
        switch(op){
            case 'c':{
                crt_Graph(&G);
                break;
            }
            case 'o':{
                dispGraph(G);
                break;
            }
            case 'd':{
                char str_start[10];
                scanf(" %s",str_start);
                int start=findIndex(&G,str_start);
                int visited[MaxSize]={0};
                DFS(&G,visited,start);
                printf("\n");
                break;
            }
            case 'b':{
                char str_start[10];
                scanf(" %s",str_start);
                int start=findIndex(&G,str_start);
                BFS(&G,start);
                break;
            }
            case 'j':{
                char str_start[10];
                scanf(" %s",str_start);
                int start=findIndex(&G,str_start);
                int dist[MaxSize];
                Dijkstra(&G,start,dist);
                for(int i=0;i<G.vexNum;i++){
                    printf("%s %d\n",G.vexs[i],dist[i]);
                }
                break;
            }
            case 'q':{
                printf("程序退出\n");
                exit(0);
            }
            default :{
            }
        }
    }

    return 0;
}

void crt_Graph(Graph *G){
    scanf("%d%d",&G->vexNum,&G->arcNum);
    for(int i=0;i<G->vexNum;i++){
        scanf(" %s",G->vexs[i]);
    }
    for(int i=0;i<G->vexNum;i++){
        for(int j=0;j<G->vexNum;j++)
        G->arcs[i][j]=-1;
    }
    for(int i=0;i<G->vexNum;i++)
        G->arcs[i][i]=0;
    for(int i=0;i<G->arcNum;i++){
        char ta[10],tb[10];
        int degree;
        scanf(" %s %s %d",ta,tb,&degree);
        int a=findIndex(G,ta);
        int b=findIndex(G,tb);
        G->arcs[a][b]=degree;
        G->arcs[b][a]=degree;
    }
}

void dispGraph(Graph G){
    for(int i=0;i<G.vexNum;i++){
        printf("%s ",G.vexs[i]);
    }
    printf("\n");
    for(int i=0;i<G.vexNum;i++){
        for(int j=0;j<G.vexNum;j++){
            if(G.arcs[i][j]<=0){
                printf("    0");
            }else{
                printf("%5d",G.arcs[i][j]);
            }
        }
        printf("\n");
    }
}

void DFS(Graph *G,int *visited,int start){
    visited[start]=1;
    printf("%s ",G->vexs[start]);

    for(int i=0;i<G->vexNum;i++){
        if(!visited[i]&&G->arcs[start][i]>0)DFS(G,visited,i);
    }
}

void BFS(Graph *G,int start){
    int queue[MaxSize];
    int rear=0,front=0;
    int visited[MaxSize]={0};
    visited[start]=1;
    printf("%s",G->vexs[start]);
    queue[rear++]=start;

    while(front<rear){
        int cur=queue[front++];
        for(int i=0;i<G->vexNum;i++){
            if(!visited[i]&&G->arcs[cur][i]>0){
                printf(" %s",G->vexs[i]);
                visited[i]=1;
                queue[rear++]=i;
            }
        }
    }

    printf("\n");
}

void Dijkstra(Graph *G,int start,int *dist){
    int visited[MaxSize]={0};

    for(int i=0;i<G->vexNum;i++){
        dist[i]=G->arcs[start][i];
    }
    visited[start]=1;

    for(int i=0;i<G->vexNum;i++){
        int u=-1;
        int min=100000;
        for(int j=0;j<G->vexNum;j++){
            if(visited[j]==0&&dist[j]!=-1&&dist[j]<min){
                min=dist[j];
                u=j;
            }
        }
        if(u==-1)break;

        visited[u]=1;

        for(int k=0;k<G->vexNum;k++){
            if(visited[k]==0&&G->arcs[u][k]!=-1){
                if(dist[k]==-1){
                    dist[k]=dist[u]+G->arcs[u][k];
                }else if(dist[k]>dist[u]+G->arcs[u][k]){
                    dist[k]=dist[u]+G->arcs[u][k];
                }
            }
        }
    }
}

int findIndex(Graph *G,char *tag){
    for(int i=0;i<G->vexNum;i++){
        if(strcmp(G->vexs[i],tag)==0)return i;
    }
    return -1;
}