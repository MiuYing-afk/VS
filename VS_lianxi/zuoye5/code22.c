/*
22. 除法游戏
【问题描述】

小A和小B是一对好朋友，他们的爱好是研究数字。学过除法之后，他们就发明了一个新游戏：两人各说一个数字分别为a和b，
如果a能包含b的所有质数因子，那么A就获胜。但是当数字太大的时候，两个朋友的脑算速度就有点跟不上了。
现在，请你写个程序，来判断胜负吧：输入两个正整数，表示a和b（2≤a, b≤10^18）。
如果a包含了b的所有质数因子，则输出“Yes”，否则输出“No”（输出时没有引号）。

【输入】

两个正整数a和b（2≤a, b≤10^18）,中间用一个空格隔开。

【输出】

如果a包含了b的所有质数因子，则输出“Yes”，否则输出“No”（输出时没有引号）。

【样例输入1】

120 75
【样例输出1】

Yes
【样例输入2】

7 8
【样例输出2】

No
【提示】

考虑a和b的取值范围，选用合理的数据类型
*/
/*
#include <stdio.h>

int main() {
    unsigned long long a, b;
    scanf("%llu %llu", &a, &b);

    // 处理 2 这个特殊质因子（唯一的偶数质数）
    while (b % 2 == 0) {
        if (a % 2 != 0) {  // a 没有 2 这个质因子，直接输 No
            printf("No\n");
            return 0;
        }
        b /= 2;
        a /= 2;
    }

    // 处理奇数质因子（从 3 开始，步长为 2，避免重复检查偶数）
    for (unsigned long long i = 3; i * i <= b; i += 2) {
        while (b % i == 0) {
            if (a % i != 0) {  // a 没有当前质因子 i，输 No
                printf("No\n");
                return 0;
            }
            b /= i;
            a /= i;
        }
    }

    // 若 b 仍大于 1，说明 b 剩余一个大于 sqrt(原 b) 的质因子，需检查 a 是否包含它
    if (b > 1 && a % b != 0) {
        printf("No\n");
        return 0;
    }

    // 所有质因子都满足条件
    printf("Yes\n");
    return 0;
}
*/

#include <stdio.h>

int main() {
    unsigned long long a, b;
    scanf("%llu %llu", &a, &b);

    // 处理质因子 2（唯一偶数质数）
    if (b % 2 == 0) {
        if (a % 2 != 0) {  // a 没有 2 这个质因子 → 输出 No
            printf("No\n");
            return 0;
        }
        // 跳过 b 中所有 2 的因子（不消耗 a 的 2）
        while (b % 2 == 0) {
            b /= 2;
        }
    }

    // 处理所有奇数质因子
    for (unsigned long long i = 3; i * i <= b; i += 2) {
        if (b % i == 0) {
            if (a % i != 0) {  // a 没有 i 这个质因子 → 输出 No
                printf("No\n");
                return 0;
            }
            // 跳过 b 中所有 i 的因子（不消耗 a 的 i）
            while (b % i == 0) {
                b /= i;
            }
        }
    }

    // 若 b 仍大于 1，说明 b 剩余一个大质因子，检查 a 是否包含它
    if (b > 1 && a % b != 0) {
        printf("No\n");
        return 0;
    }

    // 所有质因子 a 都包含
    printf("Yes\n");
    return 0;
}