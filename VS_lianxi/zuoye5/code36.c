/*
36. 数根
【问题描述】
数根是这样定义的：对于一个正整数n，将它的各个数位上的数字相加得到一个新数，如果这个数是一位数，我们就称之为n的数根，
否则重复处理直到它成为一个一位数。
例如，n=34，3+4=7，7是一位数，所以7是34的数根。
再如，n=345，3+4+5=12，1+2=3，3是一位数，所以3是345的数根。
对于输入数字n，编程计算它的数根。

【输入】

正整数n（1<=n<2^31）。

【输出】

n的数根。

【样例输入】

345
【样例输出】

3
*/
#include"stdio.h"

int shugen(int n);
int main()
{
    int n,temp;
    scanf("%d",&n);
    temp = shugen(n);
    for(; temp >=10 ;)
    {
        temp = shugen(temp);
    }
    printf("%d",temp);
    return 0;
}

int shugen(int n)
{
    int ShuGen = 0;
    scanf("%d",&n);
    for(; n > 0; n /= 10)
    {
        ShuGen += n % 10;
    }
    return ShuGen;
}