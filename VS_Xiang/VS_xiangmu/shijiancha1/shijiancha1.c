#include <stdio.h>

int main()
{
    int hour1,minter1;
    int hour2,minter2;

    printf("请输入起始时间：几点几分\n");
    scanf("%d %d",&hour1,&minter1);
    printf("请输入终止时间：几点几分\n");
    scanf("%d %d",&hour2,&minter2);

    int t1=hour1*60+minter1;
    int t2=hour2*60+minter2;
    int t=t2-t1;

    printf("相差时间%d小时%d分钟",t/60,t%60);

    return 0;
}