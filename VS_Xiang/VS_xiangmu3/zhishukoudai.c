/*
题目描述
小 A 有一个质数口袋，里面可以装各个质数。他从 2 开始，依次判断各个自然数是不是质数，如果是质数就会把这个数字装入口袋。

口袋的负载量就是口袋里的所有数字之和。

但是口袋的承重量有限，装的质数的和不能超过 L。给出 L，请问口袋里能装下几个质数？将这些质数从小往大输出，然后输出最多能装下的质数的个数，数字之间用换行隔开。

输入格式
一行一个正整数 L。

输出格式
将这些质数从小往大输出，然后输出最多能装下的质数个数。

输入输出样例
输入 #1复制

100
输出 #1复制

2
3
5
7
11
13
17
19
23
9
输入 #2复制

5
输出 #2复制

2
3
2
输入 #3复制

11
输出 #3复制

2
3
5
3
说明/提示
数据保证，1≤L≤10 
5
 。
*/

// #include<stdio.h>

// int main()
// {
//     int L,sum=2,num=1,n;
//     int Pan(int n);
//     scanf("%d",&L);
//     if(L == 1)
//     {
//         printf("0");
//         return 0;
//     }
//     printf("2\n");
//     // if(L == 2)
//     // {
//     //     printf("1");
//     //     return 0;
//     // }
//     for(int i=3;sum<L;i += 2)
//     {
//         if(Pan(i))
//         {
//             printf("%d\n",i);
//             sum+=i;
//             num++;
//         }
//     }
//     printf("%d",num);

//     return 0;
// }

// int Pan(int n)
// {
//     if(n==2||n==3||n==5||n==7)return 1;
//     if(n==1||n==4||n==6||n==8)return 0;
//     for(int i=3;i*i<=n;i+=2)
//     {
//         if(n%i==0)return 0;
//     }
//     return 1;
// }

#include<stdio.h>

// 优化后的质数判断函数
int isPrime(int n) {
    // 小于2的数不是质数
    if (n < 2) return 0;
    // 2是唯一偶质数
    if (n == 2) return 1;
    // 偶数直接排除
    if (n % 2 == 0) return 0;
    // 仅需检查奇数因子，到sqrt(n)即可
    for (int i = 3; i * i <= n; i += 2) {
        if (n % i == 0) return 0;
    }
    return 1;
}

int main() {
    int L, sum = 0, count = 0;
    scanf("%d", &L);

    // 从2开始遍历质数，直到总和超过L
    for (int i = 2;; i++) {
        if (isPrime(i)) {
            // 提前判断：加上当前质数是否超过L
            if (sum + i > L) {
                break;
            }
            // 未超过则累加、计数、输出
            sum += i;
            count++;
            printf("%d\n", i);
        }
    }
    // 输出最终个数
    printf("%d\n", count);

    return 0;
}