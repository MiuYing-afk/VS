#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    // 变长数组在 C99 及以上支持，这里假设编译器支持
    int arr[n][n];

    // 初始化数组为 0
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            arr[i][j] = 0;
        }
    }

    int hang = 0, lie = (n - 1) / 2;
    arr[hang][lie] = 1;

    for (int k = 2; k <= n * n; k++) {
        if (hang == 0 && lie != n - 1) {
            // 情况1：(K-1)在第一行但不在最后一列
            hang = n - 1;
            lie += 1;
        } else if (hang != 0 && lie == n - 1) {
            // 情况2：(K-1)在最后一列但不在第一行
            hang -= 1;
            lie = 0;
        } else if (hang == 0 && lie == n - 1) {
            // 情况3：(K-1)在第一行最后一列
            hang += 1;
        } else {
            // 情况4：(K-1)既不在第一行，也不在最后一列
            int new_hang = hang - 1;
            int new_lie = lie + 1;
            if (new_hang >= 0 && new_lie < n && arr[new_hang][new_lie] == 0) {
                hang = new_hang;
                lie = new_lie;
            } else {
                hang += 1;
            }
        }
        arr[hang][lie] = k;
    }

    // 输出幻方，每行数字用空格分隔
    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < n; j++) {
    //         printf("%d", arr[i][j]);
    //         if (j != n - 1) {
    //             printf(" ");
    //         }
    //     }
    //     printf("\n");
    // }
 for(int i=0;i<n;i++){
        int j;
        for(j=0;j<n;j++){
            printf("%d ",arr[i][j]);
        if(j==n-1){
            printf("\n");
            }
        }
    }
    return 0;
}