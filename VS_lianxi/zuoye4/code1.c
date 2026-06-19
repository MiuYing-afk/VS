// 1. 统计不同种类字符个数
// 【问题描述】

// 输入一行字符（以换行符结束），分别统计出其中英文字母、空格、数字和其他字符的个数。  

// 【输入】

// 一行字符（以换行符结束）

// 【输出】

// 英文字母、空格、数字和其他字符的个数，用空格分隔

// 【样例输入】

// I am a student 123.
// 【样例输出】

// 11 4 3 1

#include<stdio.h>

int main()
{
    char hang[100];
    int j=0;
    while((hang[j]=getchar())!='\n')
        j++;
    hang[j]='\0';
    int i=0,num1=0,num2=0,num3=0,num4=0;
    while(hang[i]!='\0')
    {
        if(hang[i]>='A'&&hang[i]<='Z'||hang[i]>='a'&&hang[i]<='z')num1++;
        else if(hang[i]==' ')num2++;
        else if(hang[i]>='0'&&hang[i]<='9')num3++;
        else num4++;
        i++;
    }
    printf("%d %d %d %d",num1,num2,num3,num4);
}