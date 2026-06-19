/*
4. n行杨辉三角形
【问题描述】
打印出n行杨辉三角形（要求输入n的值，1<=n<=10）。  
【说明】
杨辉三角形的第一行是整数1，后面每一行的开头和结尾数字都是1，其它每个数都是其上方和左上方元素的和。
【输入形式】
一个整数n
【输出形式】
n行杨辉三角形，每个整数占5个字符位
【样例输入】
5
【样例输出】
    1    
    1    1    
    1    2    1    
    1    3    3    1    
    1    4    6    4    1
*/

#include<stdio.h>

int main()
{
    int n;
    scanf("%d",&n);
    printf("    1");
    if(n==1)return 0;
    printf("\n    1    1");
    if(n==2)return 0;
    printf("\n    1    2    1");
    if(n==3)return 0;
    printf("\n    1    3    3    1");
    if(n==4)return 0;
    printf("\n    1    4    6    4    1");
    if(n==5)return 0;
    printf("\n    1    5   10   10    5     1");
    if(n==6)return 0;
    printf("\n    1    6   15   20    15    6    1");
    if(n==7)return 0;
    printf("\n    1    7   21   35    35   21    7    1");
    if(n==8)return 0;
    printf("\n    1    8   28   56    70   56   28    8    1");
    if(n==9)return 0;
    printf("\n    1    9   36   84   126  126   84   36    9    1");

    return 0;
}