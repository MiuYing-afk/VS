/*
35. 钞票兑换
【问题描述】

将任意给定的整百元钞票，兑换成10元、20元、50元小钞票形式。输出兑换方案总数。


【输入】

需要兑换的钞票总数n（100<=n<=1000000，n是100的整倍数）。

【输出】

方案总数。

【样例输入】

100
【样例输出】

10
*/

/*错误方法*/
// #include"stdio.h"

// int main()
// {
//     int money,cnt = 0, _10 =0, _20 = 0, _50 = 0;
//     scanf("%d",&money);
//     for(; _50 *50 <= money;_50 ++)
//     {
//         for(; _20 *20 <= money;_20 ++)
//         {
//             for(; _10 *10 <= money;_10 ++)
//             {
//                 if(_50 *50 + _20 *20 + _10 *10 == money)cnt++;
//             }
//         }
//     }
//     printf("%d",cnt);

//     return 0;
// }

// /*循环嵌套法*/
// #include "stdio.h"

// int main()
// {
//     long long money, cnt = 0;  // 用long long防止大数溢出
//     int _50, _20, _10;
//     scanf("%lld", &money);

//     // 遍历50元的可能数量（0到money/50）
//     for (_50 = 0; _50 * 50 <= money; _50++)
//     {
//         // 遍历20元的可能数量（基于50元使用后的剩余金额）
//         for (_20 = 0; _20 * 20 <= money - _50 * 50; _20++)
//         {
//             // 10元的数量由剩余金额唯一确定（无需循环，直接计算）
//             long long remaining = money - _50 * 50 - _20 * 20;
//             if (remaining % 10 == 0)  // 剩余金额能被10整除，即为有效方案
//             {
//                 cnt++;
//             }
//         }
//     }

//     printf("%lld", cnt);
//     return 0;
// }

// /*数学公式法*/
// //有BUG
// #include "stdio.h"

// int main()
// {
//     long long n, cnt = 0;
//     scanf("%lld", &n);
//     long long k = n / 10;  // 5x + 2y ≤ k

//     // 遍历x的所有可能（x≥0，5x≤k）
//     for (long long x = 0; 5 * x <= k; x++)
//     {
//         long long remaining = k - 5 * x;
//         // y的可能数量：0到remaining/2，共 (remaining / 2) + 1 种
//         cnt += (remaining / 2) + 1;
//     }

//     printf("%lld", cnt);
//     return 0;
// }

#include"stdio.h"

int main()
{
    int n,_1=0,_2=0,_5=0,cnt=0;
    scanf("%d",&n);
    n/=10;
    for(;_5*5<=n;_5++)
    {
        int m=n;
        m-=_5*5;
        cnt+=(m/2+1);
    }
    printf("%d",cnt);

    return 0;
}