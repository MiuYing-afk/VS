/*
6. 通过函数实现字符排序
【问题描述】
已经给出主函数，编写自定义函数void sortchar(char x[])，
将一个字符串（可能有空格）中的字符按照有小到大的顺序排序,
排序后的字符串不包括空格。
【样例输入】
Hello World!  
【样例输出】
!HWdellloor
*/
#include<stdio.h>
#include<string.h>
int main()
{   void sortchar(char x[]);
    char s[80];
    gets(s);
    sortchar(s);
    puts(s);
}

void sortchar(char x[])
{
    char temp[80];
    int i=0,j=0;
    for(;x[i]!='\0';i++)
    {
        if(x[i]!=' ')
        {
            temp[j++]=x[i];
        }
    }
    temp[j]='\0';

    char t=temp[0];
    for(i=0;temp[i]!='\0';i++)
    {
        for(j=0;temp[j]!='\0';j++)
        {
            if(temp[j]>temp[j+1])
            {
                char t=temp[j];
                temp[j]=temp[j+1];
                temp[j+1]=t;
            }
        }
    }

    for(i=0;temp[i]!='\0';)
    {
        x[i]=temp[i++];
    }
    x[i]='\0';
}