/*
30. 判断互质
【问题描述】

输入两个正整数m和n，判断m和n是否互质（即最大公约数为1），是则输出Yes，否则输出No。

【输入】

两个整数m和n（1<=n,m<2^31），中间用空格隔开。

【输出】

如互质输出Yes，否则输出No。

【样例输入】

36 56
【样例输出】

No
*/

#include<stdio.h>

int gcb(int a,int b);

int main()
{
    int a,b,yue,max,min;
    scanf("%d%d",&a,&b);
    if(a>b)max=a,min=b;
    else if(a<b)max=b,min=a;
    else if(a==b)printf("No");

    yue = gcb( max, min);
    if(yue == 1)printf("Yes");
    else printf("No");

    return 0;
}

int gcb(int a,int b)
{
    while(b!=0)
    {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}