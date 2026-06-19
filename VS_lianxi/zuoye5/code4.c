/*
3. 要将"China"译成密码
【问题描述】
将明文"China"通过加密方式转换为密文。加密方式：用原字母后面的第n个字母代替原来的字母（n的取值从1到10）。
例如，n=4，则字母"a"后面第4个字母是"e"，用"e"代替"a"。
请编一程序，用赋初值的方法使cl、c2、c3、c4、c5五个变量的初值分别为'C'、'h'、'i'、'n'、'a'，然后输入n的值，
输出经过变换后的密文。
【输入形式】
n
【输出形式】
密文
【样例输入】
4
【样例输出】
Glmre
*/

#include<stdio.h>

int main()
{
    char China[5]={'C','h','i','n','a'};
    int n;
    scanf("%d",&n);
    for(int i=0;i<5;i++){
        China[i]+=n;
    }
    for(int i=0;i<5;i++){
        printf("%c",China[i]);
    }


    return 0;
}