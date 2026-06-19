#include<stdio.h>

int main() {
    int w, x, h, q;
    // 正确读取宽、长、高和切割次数
    scanf("%d %d %d %d", &w, &x, &h, &q);
    int nums[q][6];
    for (int i = 0; i < q; i++) {
        for (int j = 0; j < 6; j++) {
            scanf("%d", &nums[i][j]);
        }
    }
    // 初始化三维数组，标记小方块是否被蒸发，0表示未蒸发，1表示蒸发
    int V[w][x][h];
    for (int i = 0; i < w; i++) {
        for (int j = 0; j < x; j++) {
            for (int k = 0; k < h; k++) {
                V[i][j][k] = 0;
            }
        }
    }

    for (int i = 0; i < q; i++) {
        // 注意输入的坐标是从1开始的，数组下标从0开始，所以要减1
        int x1 = nums[i][0] - 1;
        int y1 = nums[i][1] - 1;
        int z1 = nums[i][2] - 1;
        int x2 = nums[i][3] - 1;
        int y2 = nums[i][4] - 1;
        int z2 = nums[i][5] - 1;
        for (int j = x1; j <= x2; j++) {
            for (int k = y1; k <= y2; k++) {
                for (int l = z1; l <= z2; l++) {
                    V[j][k][l] = 1;
                }
            }
        }
    }

    int cnt = 0;
    for (int i = 0; i < w; i++) {
        for (int j = 0; j < x; j++) {
            for (int k = 0; k < h; k++) {
                if (V[i][j][k] == 0) {
                    cnt++;
                }
            }
        }
    }

    printf("%d", cnt);

    return 0;
}