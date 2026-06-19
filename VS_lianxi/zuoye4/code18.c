/*
18. 输出n行*组成的图形
【问题描述】
编程输出n行*组成的图形。n值由用户输入。
【要求】
第一行n个*，第二行n-1个*，依此类推，第n行1个*。
【输入】
正整数n（0<n<20）
【输出】
题目要求的图形，不输出空格
【样例输入】
5
【样例输出】
*****
****
***
**
*
*/

#include<stdio.h>

int main()
{
    int n;
    char c='*';
    scanf("%d",&n);
    for(int i=n;i>0;i--){
        for(int j=0;j<i;j++){
            putchar(c);
        }
        printf("\n");
    }

    return 0;
}