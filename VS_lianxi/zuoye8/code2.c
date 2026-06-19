/*

3. 通过函数删除一个字符串中连续相同的字符
【问题描述】
已经给出主函数，编写自定义函数void del_samechar(char str[ ])，删除字符串str中所有连续相同的字符。

在主函数中读入一行字符串，通过调用自定义函数实现删除字符串中的相同字符，然后输出该字符串。

【输入】

一行字符

串（可能包括空格）
【输出】删除了连续相同字符后的字符串
【样例输入】
aabaaama
【样例输出】
bma
*/

#include<stdio.h>
#include<string.h>
int main()
{   void del_samechar(char str[ ]);
    char str[100];
    gets(str);
    del_samechar(str);
    puts(str);
}

void del_samechar(char str[ ])
{
    char temp[100];
    int j=0,i=1;
    if(str[1]!=str[0])
    {
        temp[0]=str[0];
        j=1;
    }
    for(;str[i]!='\0';i++)
    {
        if(str[i]!=str[i-1]&&str[i]!=str[i+1])
        {
            temp[j]=str[i];
            j++;
        }
    }
    temp[j]='\0';
    for(i=0;temp[i]!='\0';i++)
    {
        str[i]=temp[i];
    }
    str[i]='\0';
}