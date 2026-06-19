/*
4. 实现整型数组元素升序排列
【问题描述】编写一个函数void sort(int a[],int n)，实现整型数组元素的升序排列。
在main函数中输入数组元素个数和各个元素（不超过10个整数），之后调用sort函数进行排序，在主函数中输出排序后的结果。
【输入形式】
共2行
第1行输入元素个数
第2行输入各个元素，数据之间用空格分隔
【输出形式】
第1行输出排序之前的数组，每个数据后面用一个空格分隔
第2行输出排序之后的数组，每个数据后面用一个空格分隔
【样例输入】
5
1  9  4  5  7
【样例输出】
排序之前的数组:1 9 4 5 7
排序之后的数组:1 4 5 7 9 
*/

#include<stdio.h>
void sort(int a[],int n);

int main()
{
    int a[10],i,n;
    scanf("%d",&n);
    for(i=0;i<n;i++)
          scanf("%d",&a[i]);
    printf("排序之前的数组:");
    for(i=0;i<n;i++)
          printf("%d ",a[i]);
    sort(a,n);
    printf("\n排序之后的数组:");
    for(i=0;i<n;i++)
         printf("%d ",a[i]);
}

// void sort(int a[],int n)
// {
//     int b[10]={0}; 
//     for(int i=0;i<n;i++)
//     {
//       for(int j=0;j<n;j++)
//       {
//          if(b[i]<a[j])b[i]=a[j];
//       }
//     }
//     for(int i=0;i<n;i++)
//     {
//       a[i]=b[i];
//     }
// }

void sort(int a[], int n)
{
    int i, j, temp;
    // 外层循环控制排序轮数
    for(i = 0; i < n - 1; i++)
    {
        // 内层循环控制每轮比较次数
        for(j = 0; j < n - 1 - i; j++)
        {
            // 如果前一个元素大于后一个元素，则交换它们
            if(a[j] > a[j + 1])
            {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}