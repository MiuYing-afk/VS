#include <cstdio>
#include <set>
#include <algorithm>

const int maxn = 100005;

int n, ans, tx, tn;
int a[maxn], sx[maxn], sn[maxn];

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) scanf("%d", a + i);
  for (int i = 1; i <= n; ++i) {
    while (tn && a[sn[tn]] >= a[i]) --tn;
    while (tx && a[sx[tx]] < a[i]) --tx;
    int k = std::upper_bound(sn + 1, sn + 1 + tn, sx[tx]) - sn;
    if (k != (tn + 1)) {
      ans = std::max(ans, i - sn[k] + 1);
    }
    sn[++tn] = i;
    sx[++tx] = i;
  }
  printf("%d\n", ans);
  return 0;
}


/*
#include <stdio.h>
#include <stdlib.h>  // 用于 bsearch

const int maxn = 100005;
int n, ans, tx, tn;
int a[maxn], sx[maxn], sn[maxn];

// 用于 bsearch 的比较函数
int cmp(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
    }

    for (int i = 1; i <= n; ++i) {
        // 维护最小值单调栈
        while (tn && a[sn[tn]] >= a[i]) {
            --tn;
        }
        // 维护最大值单调栈
        while (tx && a[sx[tx]] < a[i]) {
            --tx;
        }

        // C++ upper_bound 替换为 C bsearch
        int target = sx[tx];
        int *pos = (int *)bsearch(
            &target,
            sn + 1,
            tn,
            sizeof(int),
            cmp
        );
        int k = 0;
        if (pos != NULL) {
            k = pos - sn;
        } else {
            k = tn + 1;
        }

        if (k != tn + 1) {
            int len = i - sn[k] + 1;
            if (len > ans) {
                ans = len;
            }
        }

        sn[++tn] = i;
        sx[++tx] = i;
    }

    printf("%d\n", ans);
    return 0}
*/