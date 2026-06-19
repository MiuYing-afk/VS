#include<stdio.h>
enum week
{Sun,Mon,Tue,Wed,Thu,Fri,Sat};

enum week day(enum week w,int n)
{
    return(enum week)(((int)w+n)%7);
}

void main()
{
    enum week w0,wn;
    int n;
    printf("输入当天为星期几和之后的天数:");
    scanf("%d%d",&w0,&n);
    wn=day(w0,n);
    if(wn==Sun)
        printf("%d天后是星期天!\n");
    else
        printf("%d天后是星期%d\n",n,wn);
}