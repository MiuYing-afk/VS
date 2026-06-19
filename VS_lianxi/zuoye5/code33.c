/*
33. 菱形
【问题描述】

输入一个正整数n，输出用1至(2n-1)的数字组成的菱形。

【输入】

正整数n（1<=n<=10）。

【输出】

对应的菱形(见样例)。

【样例输入】

3
【样例输出】

  1 
 123
12345
 123
  1

*/

#include"stdio.h"

int main()
{
    int n, m, fu = 1;
    scanf("%d",&n);
    m = n;
    int hang = n, hang2 =n - 1;
    for( ; hang-- > 0 ;fu += 2)
    {
        int shu = 1, kong = m-- -1 ,fuu = fu;
        while(kong-- >= 0)printf(" ");
        while(fuu-- != 0)printf("%d",shu++);
        printf("\n");
    }
    fu -= 4;
    for( ; hang2-- > 0 ;fu -= 2)
    {
        int shu = 1, kong = n - 1 - hang2 ,fuu = fu;
        while(kong-- >= 0)printf(" ");
        while(fuu-- != 0)printf("%d",shu++);
        printf("\n");
    }

    return 0;
}