#include<stdio.h>
void main()
{
    int a[3][4]={{1,2,3,4},{5,6,7,8},{9,10,11,12}},i,j,sum;
    int (*q)[4]=a;
    for(i=0;i<3;i++)
    {
        sum=0;
        printf("第%d行(",i+1);
        for(j=0;j<4;j++)
        {
            printf("   %d",*(*q+j));
            sum+=*(*q+j);
        }
        printf(")的和是:%d。\n",sum);
        q++;
    }
}