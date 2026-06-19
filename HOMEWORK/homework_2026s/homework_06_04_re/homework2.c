#include "stdio.h"
#include "stdlib.h"

typedef struct ArcNode{
    int adjvex;
    struct ArcNode *nextArc;
}ArcNode;

typedef struct VertexNode{
    int vertex;
    ArcNode *firstArc;
}VertexNode;

typedef struct ALGraph{
    VertexNode adjlist[20];
    int vexNum,arcNum;
}ALGraph;

void insertSortNode(VertexNode *u, int v);
void crt_ALGraph(ALGraph *G);
void dispALGraph(ALGraph G);

int main()
{
    ALGraph G;
    crt_ALGraph(&G);
    dispALGraph(G);

    return 0;
}

// 有序插入：在顶点 u 的邻接链表中，插入编号为 v 的邻接点（升序）
void insertSortNode(VertexNode *u, int v){
    ArcNode *newNode = (ArcNode *)malloc(sizeof(ArcNode));
    newNode->adjvex = v;
    newNode->nextArc = NULL;

    // 情况1：链表为空，直接做首结点
    if (u->firstArc == NULL)
    {
        u->firstArc = newNode;
        return;
    }

    ArcNode *pre = NULL;
    ArcNode *cur = u->firstArc;
    // 往后找：找到第一个 adjvex > v 的位置，插在它前面
    while (cur != NULL && cur->adjvex < v)
    {
        pre = cur;
        cur = cur->nextArc;
    }

    // 情况2：插在链表最前面
    if (pre == NULL)
    {
        newNode->nextArc = u->firstArc;
        u->firstArc = newNode;
    }
    // 情况3：插在 pre 和 cur 中间 / 链表末尾
    else
    {
        pre->nextArc = newNode;
        newNode->nextArc = cur;
    }
}

void crt_ALGraph(ALGraph *G)
{
    scanf("%d%d", &G->vexNum, &G->arcNum);
    // 初始化顶点表
    for (int i = 0; i < G->vexNum; i++)
    {
        G->adjlist[i].vertex = i + 1;
        G->adjlist[i].firstArc = NULL;
    }

    for (int i = 0; i < G->arcNum; i++)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        // 无向图：双向有序插入
        insertSortNode(&G->adjlist[a - 1], b);
        insertSortNode(&G->adjlist[b - 1], a);
    }
}

void dispALGraph(ALGraph G){
    for(int i=0;i<G.vexNum;i++){
        printf("%d",G.adjlist[i].vertex);
        ArcNode *p=G.adjlist[i].firstArc;
        while(p!=NULL){
            printf(" %d",p->adjvex);
            p=p->nextArc;
        }
        if(i<G.vexNum-1)printf("\n");
    }
}