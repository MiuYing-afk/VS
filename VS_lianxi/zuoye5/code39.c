/*
39. Cantor 表
【问题描述】

现代数学的著名证明之一是 Georg Cantor 证明了有理数是可枚举的。他是用下面这一张表来证明这一命题的：

1/11/1 , 1/21/2 , 1/31/3 , 1/41/4, 1/51/5, …

2/12/1, 2/22/2 , 2/32/3, 2/42/4, …

3/13/1 , 3/23/2, 3/33/3, …

4/14/1, 4/24/2, …

5/15/1, …

…

我们以 Z 字形给上表的每一项编号。第一项是 1/11/1，然后是 1/21/2，2/12/1，3/13/1，2/22/2，…

【输入】

整数N（1≤N≤107）。

【输出】

表中的第 N 项。

【样例输入】

7
【样例输出】

1/4
*/

#include <stdio.h>

int main() {
    int N;
    scanf("%d", &N);
    
    int k = 1;
    // 找到第N项所在的斜线k
    while (k * (k + 1) / 2 < N) {
        k++;
    }
    // 计算在第k条斜线中的位置pos
    int pos = N - k * (k - 1) / 2;
    
    int numerator, denominator;
    if (k % 2 == 1) { // 斜线k为奇数，分子递减、分母递增
        numerator = k - pos + 1;
        denominator = pos;
    } else { // 斜线k为偶数，分子递增、分母递减
        numerator = pos;
        denominator = k - pos + 1;
    }
    
    printf("%d/%d\n", numerator, denominator);
    return 0;
}