/*
3. 求Sn(a)
【问题描述】

求Sn(a)=a+aa+aaa+…+aa…aaa（有n个a，n<=7）之值，其中a是某一个数字。例如：S5(2)2+22+222+2222+22222，a和n由键盘输入。

要求输入语句为：scanf("%d%d",&a,&n); 

【输入】

整数n和a（1≤n≤7,0≤a≤9），用空格分隔

【输出】

求Sn(a)的值，输出格式参考样例输出

【样例输入】

3 2
【样例输出】

S3(2)=246
*/

#include<stdio.h>

int main()
{
    int n,a,Sn_a=0,t=0;
    scanf("%d %d",&n,&a);
    for(int i=0;i<n;i++)
    {
        t=t*10+a;
        Sn_a+=t;
    }
    printf("S%d(%d)=%d",n,a,Sn_a);

    return 0;
}

