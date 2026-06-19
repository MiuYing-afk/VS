/*
题目描述
cyrcyr 今天在种树，他在一条直线上挖了 n 个坑。这 n 个坑都可以种树，但为了保证每一棵树都有充足的养料，cyrcyr 不会在相邻的两个坑中种树。而且由于 cyrcyr 的树种不够，他至多会种 k 棵树。假设 cyrcyr 有某种神能力，能预知自己在某个坑种树的获利会是多少（可能为负），请你帮助他计算出他的最大获利。

输入格式
第一行，两个正整数 n,k。

第二行，n 个整数，第 i 个数表示在直线上从左往右数第 i 个坑种树的获利。

输出格式
输出一个数，表示 cyrcyr 种树的最大获利。

输入输出样例
输入 #1复制

6 3 
100 1 -1 100 1 -1
输出 #1复制

200
说明/提示
对于 20% 的数据，n≤20。

对于 50% 的数据，n≤6000。

对于 100% 的数据，1≤n≤300000，1≤k≤ 
2
n
​
 ，在一个地方种树获利的绝对值在 10 
6
  以内。
*/

#include "stdio.h"
#include "string.h"
#include "stdlib.h"


int Much1[300010];
int Much2[300010];

int partition(int *Much,int low,int high);
void quickSort(int *arr,int low,int high);
void swap(int *a,int *b);

int main()
{
    int n,k,len=0;
    memset(Much2, -1, sizeof(Much2));
    scanf("%d %d",&n,&k);
    int money=0;
    for(int i=0;i<n;i++){
        scanf("%d",&Much1[i]);
    }
    for(int i=0,j=0;i<n;i++){
        if(Much1[i]>-1){
            Much2[j++]=Much1[i];
            len++;
        }
    }
    quickSort(Much2,0,len-1);
    for(int i=0;i<k&&i<len;i++){
        money+=Much2[i];
    }
    printf("%d",money);

    return 0;
}


int partition(int *Much,int low,int high){
    int pivot=Much[high];
    int i=low-1;

    for(int j=low;j<high;j++){
        if(Much[j]>=pivot){
            i++;
            swap(&Much[i],&Much[j]);
        }
    }

    swap(&Much[i+1],&Much[high]);
    return i+1;
}

void swap(int *a,int *b){
    int t=*a;
    *a=*b;
    *b=t;
}

void quickSort(int *arr,int low,int high){
    if(low<high){
        int pi=partition(arr,low,high);
        quickSort(arr,low,pi-1);
        quickSort(arr,pi+1,high);
    }
}