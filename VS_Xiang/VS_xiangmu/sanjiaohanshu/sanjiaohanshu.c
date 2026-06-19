/*
题目描述
输入一组勾股数 a,b,c（a

=b

=c），用分数格式输出其较小锐角的正弦值。（要求约分。）

输入格式
一行，包含三个正整数，即勾股数 a,b,c（无大小顺序）。

输出格式
一行，包含一个分数，即较小锐角的正弦值

输入输出样例
输入 #1复制

3 5 4
输出 #1复制

3/5
说明/提示
数据保证：a,b,c 为正整数且 ∈[1,10 
9
 ]。
*/

#include<stdio.h>

int main()
{
    int a,b,c;
    scanf("%d %d %d",&a,&b,&c);
    int max,min;
    //求最大值
    if(a>=b&&a>=c){
        max=a;
    }else if(b>=a&&b>=c){
        max=b;
    }else if(c>=b&&c>=a){
        max=c;
    }
    //求最小值
    if(a<=b&&a<=c){
        min=a;
    }else if(b<=a&&b<=c){
        min=b;
    }else if(c<=a&&c<=b){
        min=c;
    }
    //辗转相除法求最大公约数
    int i,j,k;
    j=min;k=max;
    while(k!=0){
        i=j%k;
        j=k;
        k=i;
    }

    printf("%d/%d",min/j,max/j);

    return 0;
}