/*
【问题描述】

给定长度为 2n 的数组, 你的任务是将这些数分成 n 对, 例如 (a1, b1), (a2, b2), ..., (an, bn) ，使得从1 到 n 的 min(ai, bi) 总和最大。
【输入形式】

一行整数，长度为偶数2n
【输出形式】

一个整数，代表最大的“最小值之和”
【样例输入】

1 4 3 2
【样例输出】

4
【样例说明】

拆分成 (1, 2), (3, 4) 后，每对的最小值分别为1、3，因此为 4
【评分标准】
*/

#include"stdio.h"

void swap(int *arr,int len);

int main()
{
    int arr[1000]={0},sum=0,n=0,num=0;
    char arr_1[10000]={0};
    
    //这玩意按回车不会跳出去
    // while(scanf("%d",&arr[n])==1)
    // {
    //     n++;
    // }
    
    fgets(arr_1,10000,stdin);

    //大于九的数字会识别成多个单数，不对
    // for(int i=0;i<5000&&arr_1[i]!='\0';i++)
    // {
    //     if('0'<=arr_1[i]&&arr_1[i]<='9')
    //     {
    //         arr[n++]=arr_1[i]-'0';
    //     }
    // }

    for(int i=0;i<10000 && arr_1[i]!='\0';i++)
    {
        if('0'<=arr_1[i] && arr_1[i]<='9')
        {
            num=num*10+(arr_1[i]-'0');
        }else if (arr_1[i]==' '){
            arr[n++]=num;
            num=0;
        }
    }

    if(num!=0)
    {
        arr[n++]=num;
    }

    swap(arr,n);

    for(int i=0;i<n;i+=2)
    {
        sum+=arr[i];
    }

    printf("%d",sum);

    return 0;
}

void swap(int *arr,int len)
{
    for(int i=0;i<len-1;i++)
    {
        for(int j=0;j<len-i-1;j++)
        {
            if(*(arr+j)>*(arr+j+1))
            {
                int k=*(arr+j);
                *(arr+j)=*(arr+j+1);
                *(arr+j+1)=k;
            }
        }
    }
}