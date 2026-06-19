/*
2. 带权无向图 - 考试 - 最小生成树
【问题描述】

带权无向图（连通或者不连通都要支持）采用邻接矩阵进行存储，图中顶点的类型为字符串，完成以下操作：

1. 创建图的邻接矩阵

2. 输出图的顶点和邻接矩阵

3. 从指定的源点出发进行深度优先遍历

4. 从指定的源点出发进行广度优先遍历

5. 基于PRIM算法构造图的最小生成树

注意：c为创建图的邻接矩阵；o为输出图的顶点和邻接矩阵；d为深度优先遍历；b为广度优先遍历；
p为PRIM算法；q为程序退出操作



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



操作4：默认从A点出发，基于PRIM算法构造图的最小生成树

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

p

q

【样例输出】


A-B 10

A-D 30

D-C 20

C-E 10

程序退出
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

typedef struct {
    int adjNodeNo;
    int weight;
}LowCost;

void crtGraph(MGraph *G);
int findIndex(MGraph *G,char *tag);
void dispGraph(MGraph *G);
void DFS(MGraph *G,int *visited,int start);
void BFS(MGraph *G,int start);
void MSTGraph(MGraph *G,int start,LowCost *lowcost);

int main()
{
    MGraph G;
    char op;
    while(1){
        scanf("%c",&op);
        switch(op){
            case 'c':{
                crtGraph(&G);
                break;
            }
            case 'o':{
                dispGraph(&G);
                break;
            }
            case 'd':{
                int visited[MAX]={0};
                char str_start[10];
                scanf(" %s",str_start);
                DFS(&G,visited,findIndex(&G,str_start));
                printf("\n");
                break;
            }
            case 'b':{
                char str_start[10];
                scanf(" %s",str_start);
                BFS(&G,findIndex(&G,str_start));
                break;
            }
            case 'p':{
                LowCost *lowcost=(LowCost*)malloc(G.vexNum*sizeof(LowCost));
                char str_start[10]="A";
                MSTGraph(&G,findIndex(&G,str_start),lowcost);
                break;
            }
            case 'q':{
                printf("程序退出\n");
                exit(0);
                break;
            }
            default :{}
        }
    }

    return 0;
}

void crtGraph(MGraph *G){
    scanf("%d%d",&G->vexNum,&G->arcNum);
    for(int i=0;i<G->vexNum;i++){
        scanf(" %s",G->vexs[i]);
    }
    for(int i=0;i<G->vexNum;i++){
        for(int j=0;j<G->vexNum;j++)
        G->arcs[i][j]=INF;
    }
    for(int i=0;i<G->vexNum;i++)G->arcs[i][i]=0;
    for(int i=0;i<G->arcNum;i++){
        char str_a[10],str_b[10];
        int degree;
        scanf(" %s %s %d",str_a,str_b,&degree);
        int ta=findIndex(G,str_a);
        int tb=findIndex(G,str_b);
        G->arcs[ta][tb]=degree;
        G->arcs[tb][ta]=degree;
    }
}

int findIndex(MGraph *G,char *tag){
    for(int i=0;i<G->vexNum;i++){
        if(strcmp(G->vexs[i],tag)==0)return i;
    }
    return -1;
}

void dispGraph(MGraph *G){
    if(G->vexNum<=0)return ;
    printf("%s",G->vexs[0]);
    for(int i=1;i<G->vexNum;i++){
        printf(" %s",G->vexs[i]);
    }
    printf("\n");
    for(int i=0;i<G->vexNum;i++){
        for(int j=0;j<G->vexNum;j++){
            if(G->arcs[i][j]==INF)printf("    0");
            else printf("%5d",G->arcs[i][j]);
        }
        printf("\n");
    }
}

void DFS(MGraph *G,int *visited,int start){
    if(start<0)return;
    visited[start]=1;
    printf("%s ",G->vexs[start]);

    for(int i=0;i<G->vexNum;i++){
        if(visited[i]==0&&G->arcs[start][i]!=INF)DFS(G,visited,i);
    }
}

void BFS(MGraph *G,int start){
    if(start<0)return;
    int queue[MAX];
    int visited[MAX]={0};
    int rear=0,front=0;
    visited[start]=1;
    queue[rear++]=start;
    printf("%s",G->vexs[start]);

    while(front<rear){
        int cur=queue[front++];
        for(int i=0;i<G->vexNum;i++){
            if(visited[i]==0&&G->arcs[cur][i]!=INF){
                printf(" %s",G->vexs[i]);
                visited[i]=1;
                queue[rear++]=i;
            }
        }
    }
    printf("\n");
}

void MSTGraph(MGraph *G,int start,LowCost *lowcost){
    int visited[MAX]={0};
    visited[start]=1;

    for(int i=0;i<G->vexNum;i++){
        lowcost[i].weight=G->arcs[start][i];
        if(lowcost[i].weight==INF){
            lowcost[i].adjNodeNo=-1;
        }else{
            lowcost[i].adjNodeNo=start;
        }
    }

    for(int cnt=1;cnt<G->vexNum;cnt++){
        int MinCost=INF;
        int MinPos=-1;

        for(int i=0;i<G->vexNum;i++){
            if(visited[i]==0&&lowcost[i].weight<MinCost){
                MinCost=lowcost[i].weight;
                MinPos=i;
            }
        }
        if(MinPos==-1)break;

        char *u=G->vexs[lowcost[MinPos].adjNodeNo];
        char *v=G->vexs[MinPos];
        printf("%s-%s %d\n",u,v,lowcost[MinPos].weight);

        visited[MinPos]=1;
        for(int i=0;i<G->vexNum;i++){
            if(visited[i]==0&&G->arcs[MinPos][i]!=INF){
                if(lowcost[i].weight>G->arcs[MinPos][i]){
                    lowcost[i].weight=G->arcs[MinPos][i];
                    lowcost[i].adjNodeNo=MinPos;
                }
            }
        }
    }
}
