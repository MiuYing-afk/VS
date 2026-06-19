/*
34. 乘法口诀
【问题描述】

根据给定的n，输出乘法口诀表的前n行。

【输入】

正整数n（1<=n<=9）。

【输出】

乘法口诀的前n行。

【样例输入】

3
【样例输出】

1*1=1
1*2=2 2*2=4
1*3=3 2*3=6 3*3=9

*/

#include"stdio.h"

int main()
{
    int n, hang = 1;
    scanf("%d",&n);
    for(; hang <= n; hang++)
    {
        int lie = 1;
        for(; lie <= hang; lie++)
        {
            printf("%d*%d=%d ", lie, hang, hang * lie);
        }
        printf("\n");
    }
    return 0;
}