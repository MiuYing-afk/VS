#include<stdio.h>
#include<stdlib.h>
void main()
{
    int a[10][10];
    int *p;
    int num,max,i;
    printf("请输入方阵的阶数：");
    scanf("%d",&num);
    if(num<1||num>10)
    {
        printf("Wrong number!");
        exit(0);
    }
    printf("请输入%d阶方阵的元素:\n",num);
    for(i=0;i<num;i++)
    {
        for(p=a[i];p<=&a[i][num-1];p++)
        { scanf("%d",p); }
    }
    max=a[0][0];
    printf("方阵是:\n");
    for(i=0;i<num;i++)
    {
        for(p=a[i];p<=&a[i][num-1];p++)
        {
            printf("%6d ",*p);
            if(max<*p)
            { max=*p; }
        }
        printf("\n");
    }
    printf("方阵中最大的元素是：%d\n",max);
}