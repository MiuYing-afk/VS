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

void crt_ALGraph(ALGraph *G);
void dispALGraph(ALGraph G);
// 有序插入单个邻接点（核心比较插入逻辑）
void insertNode(VertexNode *vNode, int val);

int main()
{
    ALGraph G;
    crt_ALGraph(&G);
    dispALGraph(G);

    return 0;
}

// 比较插入：按升序插入结点
void insertNode(VertexNode *vNode, int val)
{
    // 新建边结点
    ArcNode *newArc = (ArcNode*)malloc(sizeof(ArcNode));
    newArc->adjvex = val;
    newArc->nextArc = NULL;

    // 链表为空，直接作为首结点
    if (vNode->firstArc == NULL)
    {
        vNode->firstArc = newArc;
        return;
    }

    ArcNode *pre = NULL;
    ArcNode *cur = vNode->firstArc;
    // 循环比较：找到第一个大于val的结点位置
    while (cur != NULL && cur->adjvex < val)
    {
        pre = cur;
        cur = cur->nextArc;
    }

    // 插在链表头部
    if (pre == NULL)
    {
        newArc->nextArc = vNode->firstArc;
        vNode->firstArc = newArc;
    }
    // 插在 pre 和 cur 之间 / 链表尾部
    else
    {
        pre->nextArc = newArc;
        newArc->nextArc = cur;
    }
}

// 创建【有向图】邻接表，单向比较插入
void crt_ALGraph(ALGraph *G){
    scanf("%d%d",&G->vexNum,&G->arcNum);
    for(int i=0;i<G->vexNum;i++){
        G->adjlist[i].vertex=i+1;
        G->adjlist[i].firstArc=NULL;
    }
    for(int i=0;i<G->arcNum;i++){
        int a,b;
        scanf("%d%d",&a,&b);
        // 有向图：只插 a → b，单向插入
        insertNode(&G->adjlist[a-1], b);
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