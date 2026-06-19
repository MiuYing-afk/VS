//选择排序

#include<stdio.h>

void main()
{
    int i,index,k,n,temp;
    int a[10];
    printf("请输入要排序的整数个数：");
    scanf("%d",&n);
    printf("请输入%d个整数:",n);
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    for(k=0;k<n-1;k++)
    {
        index=k;
         for(i=k+1;i<n;i++)
            if(a[i]<a[index])
                index=i;
        temp=a[index];
        a[index]=a[k];
        a[k]=temp;
    }
    printf("由小到大的排序结果是：");
    for(i=0;i<n;i++)
        printf("%d ",a[i]);
    printf("\n");
}