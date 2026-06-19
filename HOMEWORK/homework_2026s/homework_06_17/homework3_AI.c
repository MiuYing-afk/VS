#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXN 500

// 邻接表节点
typedef struct ListNode {
    int val;
    struct ListNode *next;
} ListNode;

ListNode *initListNode(int val) {
    ListNode *node = (ListNode *)malloc(sizeof(ListNode));
    node->val = val;
    node->next = NULL;
    return node;
}

void freeList(ListNode *head) {
    ListNode *cur = head;
    while (cur != NULL) {
        ListNode *next = cur->next;
        free(cur);
        cur = next;
    }
}

// 拓扑排序实现 loudAndRich
void loudAndRich(int richer[][2], int richerSize, int quiet[], int quietSize, int result[]) {
    int n = quietSize;
    ListNode *graph[MAXN];  // 正向邻接表 a->b
    int inDegree[MAXN];     // 记录每个点入度
    int dp[MAXN];           // dp[i]为答案缓存

    // 初始化
    memset(graph, 0, sizeof(graph));
    memset(inDegree, 0, sizeof(inDegree));
    for (int i = 0; i < n; i++) {
        dp[i] = i;
    }

    // 构建正向图 + 统计入度
    for (int i = 0; i < richerSize; i++) {
        int a = richer[i][0];
        int b = richer[i][1];
        // 头插法插入链表
        ListNode *newNode = initListNode(b);
        newNode->next = graph[a];
        graph[a] = newNode;
        inDegree[b]++;
    }

    // 拓扑队列（数组模拟队列）
    int queue[MAXN];
    int front = 0, rear = 0;
    for (int i = 0; i < n; i++) {
        if (inDegree[i] == 0) {
            queue[rear++] = i;
        }
    }

    // BFS拓扑遍历
    while (front < rear) {
        int u = queue[front++];
        ListNode *p = graph[u];
        while (p != NULL) {
            int v = p->val;
            // 用u的最优更新v的最优
            if (quiet[dp[u]] < quiet[dp[v]]) {
                dp[v] = dp[u];
            }
            inDegree[v]--;
            if (inDegree[v] == 0) {
                queue[rear++] = v;
            }
            p = p->next;
        }
    }

    // 结果拷贝
    for (int i = 0; i < n; i++) {
        result[i] = dp[i];
    }

    // 释放邻接表内存
    for (int i = 0; i < n; i++) {
        freeList(graph[i]);
    }
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    int richer[m][2];
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &richer[i][0], &richer[i][1]);
    }
    int quiet[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &quiet[i]);
    }
    int result[n];
    loudAndRich(richer, m, quiet, n, result);
    for (int i = 0; i < n; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");
    return 0;
}