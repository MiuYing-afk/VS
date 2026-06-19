/*
3. 扩展题 喧闹和富有
【问题描述】

有一组 n 个人作为实验对象，从 0 到 n - 1 编号，其中每个人都有不同数目的钱，以及不同程度的安静值（quietness）。为了方便起见，我们将编号为 x 的人简称为 "person x "。

给你一个数组 richer ，其中 richer[i] = [ai, bi] 表示 person ai 比 person bi 更有钱。另给你一个整数数组 quiet ，其中 quiet[i] 是 person i 的安静值。richer 中所给出的数据 逻辑自洽（也就是说，在 person x 比 person y 更有钱的同时，不会出现 person y 比 person x 更有钱的情况 ）。

【输入形式】

第一行输入整数n和整数m，分别表示人数和richer数组的元素个数。

第二行开始接下来m行每一行由ai和bi两个整数组成，用空格隔开，表示person ai 比 person bi 更有钱。

最后一行n个整数组成表示每个人的安静值，它们用空格分隔。

【输出形式】

输出一行，n个整数组成的answer，answer[x] = y 的前提是，在所有拥有的钱肯定不少于 person x 的人中，person y 是最不安静的人（也就是安静值 quiet[y] 最小的人）。

【样例输入】

8 7

1 0

2 1

3 1

3 7

4 3

5 3

6 3

3 2 5 4 6 1 7 0

【样例输出】

5 5 2 5 4 5 6 7

【样例说明】

answer[0] = 5， person 5 比 person 3 有更多的钱，person 3 比 person 1 有更多的钱，person 1 比 person 0 有更多的钱。 唯一较为安静（有较低的安静值 quiet[x]）的人是 person 7， 但是目前还不清楚他是否比 person 0 更有钱。 answer[7] = 7， 在所有拥有的钱肯定不少于 person 7 的人中（这可能包括 person 3，4，5，6 以及 7）， 最安静（有较低安静值 quiet[x]）的人是 person 7。 其他的答案也可以用类似的推理来解释。



参考以下代码，完成loundAndRich函数：

#include <stdio.h>

#include <stdlib.h>

#include <string.h>



#define MAXN 500



// 构建图，使用邻接表的方式表示

typedef struct ListNode {

    int val;

    struct ListNode *next;

} ListNode;



// 初始化邻接表节点

ListNode *initListNode(int val) {

    ListNode *node = (ListNode *)malloc(sizeof(ListNode));

    node->val = val;

    node->next = NULL;

    return node;

}



// 释放邻接表节点内存

void freeList(ListNode *head) {

    ListNode *cur = head;

    while (cur!= NULL) {

        ListNode *next = cur->next;

        free(cur);

        cur = next;

    }

}



// 计算喧闹和富有结果的函数

void loudAndRich(int richer[][2], int richerSize, int quiet[], int quietSize, int result[]) {

    

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

【评分标准】
*/

#include "stdio.h"
#include "stdlib.h"

#define MAX 100
#define INF 0x3f3f3f3f
