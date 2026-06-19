/*
8. 分解质因数
【问题描述】
输入一个大于1的正整数，将其分解质因数。例如：输入90，输出90=2*3*3*5。
【要求】
用while循环完成 
【输入】
一个大于1的正整数
【输出】
参考样例输出的格式输出该正整数分解质因数的结果，没有空格，质因数从小到大排列
【样例输入1】
90
【样例输出1】
90=2*3*3*5
【样例输入2】
2
【样例输出2】
2=2
*/

#include<stdio.h>
#include<stdlib.h>

int main()
{
    int n;
    scanf("%d",&n);
    printf("%d=",n);
    int t=n;
    for(int i=2;i<=n;i++)
    {
        if(t%i==0)
        {
            if(t==i){
                printf("%d",i);
                exit(0);
            }else{
                printf("%d*",i);
                t/=i;
            }
            i=1;
        }
    }    

    return 0;
}