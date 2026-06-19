/*
14. 输出[m, n]间的全部素数
【问题描述】
输出[m, n]间的全部素数（质数）。
【输入】
正整数m和n（m<n），用空格分隔
【输出】
输出[m, n]间的全部素数（质数），要求每行最多输出5个素数，用空格分隔。
【样例输入】
1 20
【样例输出】
2 3 5 7 11
13 17 19
*/

#include<stdio.h>

int main()
{
    int m,n,cnt=0,num[100]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,91,97};
    scanf("%d %d",&m,&n);
    for(int i=2;i<=n;i++)
    {
        if(i<m)continue;
        if(num[i]<=n){
            printf("%d",num[i]);
            cnt++;
        }
        if(cnt==5){
            printf("\n");
            cnt=0;
        }
    }

    return 0;
}



//豆包解

#include <stdio.h>
// 判断一个数是否为素数
int isPrime(int num) {
    if (num <= 1) {
        return 0;
    }
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return 0;
        }
    }
    return 1;
}
int main() {
    int m, n, count = 0;
    // 输入 m 和 n
    scanf("%d %d", &m, &n);
    for (int i = m; i <= n; i++) {
        // 判断是否为素数
        if (isPrime(i)) {
            // 输出素数，格式控制
            printf("%d ", i);
            count++;
            // 每行最多输出 5 个素数，换行
            if (count % 5 == 0) {
                printf("\n");
            }
        }
    }
    // 如果最后一行不足 5 个素数，换行
    if (count % 5 != 0) {
        printf("\n");
    }
    return 0;
}