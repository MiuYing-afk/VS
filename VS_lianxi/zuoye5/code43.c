/*
51. 求Sn(a)=a+aa+aaa+…+aa…aaa
【问题描述】

求Sn(a)=a+aa+aaa+…+aa…aaa（有n个a，n<=7）之值，其中a是某一个数字。例如：2+22+222+2222+22222（n=5），a和n由键盘输入。

【输入形式】

a n

【输出形式】

Sn(a)=

【样例输入】

2 3

【样例输出】

S3(2)=246
*/

#include"stdio.h"

int main()
{
    int n,a,jia,Sn=0;
    scanf("%d%d",&n,&a);
    jia=a;
    for(int i=0;i<n;i++)
    {
        Sn+=jia;
        jia=jia*10+a;
    }
    printf("S%d(%d)=%d",n,a,Sn);

    return 0;
}