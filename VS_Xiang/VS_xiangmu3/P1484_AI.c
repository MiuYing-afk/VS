#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 数组最大长度（题目要求 3e5）
#define MAXN 300010

// 堆节点结构：val=收益值，idx=在原数组里的下标
typedef struct {
    long long val;  // 收益必须用 long long，防止溢出
    int idx;
} Node;

// 大根堆（优先队列），用来每次取最大收益
Node heap[MAXN * 2];
int heapSize = 0;  // 堆当前大小

// 双向链表：记录每个位置的左边、右边是谁
int left[MAXN], right[MAXN];
// 删除标记：1=这个位置已经不能选了
int del[MAXN];
// 存每个位置的收益
long long a[MAXN];

// 交换两个堆节点
void swap(Node *x, Node *y) {
    Node t = *x;
    *x = *y;
    *y = t;
}

// 大根堆：插入一个节点
void push(Node x) {
    heap[++heapSize] = x;  // 放到堆最后
    int i = heapSize;
    
    // 上浮：比父亲大就交换，维护大根堆
    while (i > 1 && heap[i].val > heap[i/2].val) {
        swap(&heap[i], &heap[i/2]);
        i /= 2;
    }
}

// 大根堆：删除堆顶（最大值）
void pop() {
    heap[1] = heap[heapSize--];  // 最后一个元素挪到堆顶
    int i = 1;
    
    // 下沉：把堆顶下沉到正确位置
    while (1) {
        int l = i*2, r = i*2+1, maxi = i;
        if (l <= heapSize && heap[l].val > heap[maxi].val) maxi = l;
        if (r <= heapSize && heap[r].val > heap[maxi].val) maxi = r;
        if (maxi == i) break;  // 不用再换了
        swap(&heap[i], &heap[maxi]);
        i = maxi;
    }
}

// 获取堆顶（当前最大收益）
Node top() {
    return heap[1];
}

int main() {
    int n, k;
    // n个位置，最多种k棵树
    scanf("%d%d", &n, &k);

    // 初始化每个位置的收益 + 建堆 + 建双向链表
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &a[i]);    // 读入收益
        push((Node){a[i], i});   // 把收益和下标压入堆
        left[i] = i-1;           // 左边是 i-1
        right[i] = i+1;          // 右边是 i+1
    }
    right[n] = 0;  // 最后一个位置右边没有了，设为0

    // 最终答案（总收益）
    long long ans = 0;

    // 要选 k 棵树
    while (k--) {
        // 跳过所有被标记删除的节点（无效节点）
        while (heapSize && del[top().idx]) pop();

        // 堆空了 或 最大收益都是负数 → 不选了，直接结束
        if (heapSize == 0 || top().val < 0) break;

        // 取出当前最大收益的节点
        Node cur = top();
        pop();

        // 选中它！收益加进去
        ans += cur.val;

        // 当前节点的下标 p，左边 l，右边 r
        int p = cur.idx;
        int l = left[p];
        int r = right[p];

        // ======================
        // 核心：反悔贪心操作
        // 把 p 的值改成：左+右 - 当前
        // 下次再选到 p 就相当于：
        // 取消选 p，改为选 l 和 r
        // ======================
        a[p] = a[l] + a[r] - a[p];
        cur.val = a[p];
        push(cur);  // 把新值放回堆

        // 标记 l 不可选
        if (l) {
            del[l] = 1;
            // 链表删除 l：p 的左边 变成 l 的左边
            if (left[l]) right[left[l]] = p;
            left[p] = left[l];
        }

        // 标记 r 不可选
        if (r) {
            del[r] = 1;
            // 链表删除 r：p 的右边 变成 r 的右边
            if (right[r]) left[right[r]] = p;
            right[p] = right[r];
        }
    }

    // 输出答案
    printf("%lld\n", ans);
    return 0;
}