/*
# P5461 赦免战俘

## 题目背景

借助反作弊系统，一些在月赛有抄袭作弊行为的选手被抓出来了！

## 题目描述

现有 $2^n\times 2^n (n\le10)$ 名作弊者站成一个正方形方阵等候 kkksc03 的发落。kkksc03 决定赦免一些作弊者。他将正方形矩阵均分为 4 个更小的正方形矩阵，每个更小的矩阵的边长是原矩阵的一半。其中左上角那一个矩阵的所有作弊者都将得到赦免，剩下 3 个小矩阵中，每一个矩阵继续分为 4 个更小的矩阵，然后通过同样的方式赦免作弊者……直到矩阵无法再分下去为止。所有没有被赦免的作弊者都将被处以棕名处罚。

给出 $n$，请输出每名作弊者的命运，其中 0 代表被赦免，1 代表不被赦免。

## 输入格式

一个整数 $n$。

## 输出格式

$2^n \times 2^n$ 的 01 矩阵，代表每个人是否被赦免。数字之间有一个空格。

## 输入输出样例 #1

### 输入 #1

```
3
```

### 输出 #1

```
0 0 0 0 0 0 0 1
0 0 0 0 0 0 1 1
0 0 0 0 0 1 0 1
0 0 0 0 1 1 1 1
0 0 0 1 0 0 0 1
0 0 1 1 0 0 1 1
0 1 0 1 0 1 0 1
1 1 1 1 1 1 1 1
```
*/

#include <stdio.h>
#include <math.h>

// 递归填充矩阵
void fill(int size, int x, int y, int matrix[][1024]) {
    if (size == 1) {
        // 最小单位矩阵，标记为1（未被赦免）
        matrix[x][y] = 1;
        return;
    }
    int half = size / 2;
    // 左上角子矩阵：全部置为0（赦免）
    for (int i = x; i < x + half; i++) {
        for (int j = y; j < y + half; j++) {
            matrix[i][j] = 0;
        }
    }
    // 递归处理剩下的三个子矩阵
    fill(half, x, y + half, matrix);
    fill(half, x + half, y, matrix);
    fill(half, x + half, y + half, matrix);
}

int main() {
    int n;
    scanf("%d", &n);
    int size = (int)pow(2, n); // 计算矩阵边长 2^n
    
    int matrix[1024][1024] = {0}; // 初始化矩阵
    fill(size, 0, 0, matrix);
    
    // 输出矩阵
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}