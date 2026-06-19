
// 4. 通过函数统计字符串中各字母的个数
// 【问题描述】
// 【已经给出主函数，编写自定义函数 void  counta_z(char str[ ], int count[ ])，
//  统计给定字符串str中各个字母出现的次数（存放到数组count中），不区分大小写。

// 在main函数中输入一个字符串，调用该函数进行计算，然后输出统计结果（按字典顺序输出各字母的个数，如果个数为0则不输出）。


// 【输入】

// 一行字符串（可能有空格）
// 【输出】

// 按字典顺序依次输出该字符串中各字母的个数，不区分大小写，如果个数为0则不输出。
// 【样例输入】

// many Mary % Mary
// 【样例输出】

// a出现的次数为:3
// m出现的次数为:3
// n出现的次数为:1
// r出现的次数为:2
// y出现的次数为:3


// 【样例说明】

// 注意输出的顺序

#include<stdio.h>
int main()
{   void counta_z(char string[],int count[ ]);
    char str[255];
    int cnt[26]={0};
    int i;
    gets(str);
    counta_z(str,cnt);
    for(i=0;i<26;i++)
        if(cnt[i])
          printf("%c出现的次数为:%d\n",i+'a',cnt[i]);
}

void counta_z(char string[],int count[ ])
{
    int i=0;
    for(;string[i]!='\0';i++)
    {
        if(string[i]>='a'&&string[i]<='z'){count[string[i]-'a']++;}
        else if(string[i]>='A'&&string[i]<='Z'){count[string[i]-'A']++;}
    }
}