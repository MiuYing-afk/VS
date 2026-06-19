
// 【问题描述】
// 已经给出主函数，编写自定义函数void cpy(char s[ ],char c[ ])，将字符串s中的元音字母复制到字符串c中。

// 主函数读入一行字符串（可能包括空格），然后通过调用cpy函数实现将字符串中的元音字符复制到另一个字符串c中，然后将c输出。

// 【注意】

// 元音字符按照在原字符串中的出现顺序存放，重复的元音字母重复存放，保持原本的大小写。


// 【输入】

// 一行字符串，可能包括空格
// 【输出】

// 字符串中的元音字母，保持原本的顺序，重复元音字母重复输出，且保持原本的大小写。
// 【样例输入】

// A good girl.
// 【样例输出】

// Aooi

#include <stdio.h>
int main()
{   void cpy(char s[ ],char c[ ]);
    char str[80],c[80];
    gets(str);
    cpy(str,c);
    puts(c);
}

// void cpy(char s[ ],char c[ ])
// {
//     int i=0,j=0;
//     for(;s[j]!='\0';j++)
//     {
//         if(s[j]=='a')c[i]=s[j];
//         else if(s[j]=='e')c[i]=s[j];
//         else if(s[j]=='i')c[i]=s[j];
//         else if(s[j]=='o')c[i]=s[j];
//         else if(s[j]=='u')c[i]=s[j];
//         else if(s[j]=='A')c[i]=s[j];
//         else if(s[j]=='E')c[i]=s[j];
//         else if(s[j]=='I')c[i]=s[j];
//         else if(s[j]=='O')c[i]=s[j];
//         else if(s[j]=='U')c[i]=s[j];
//         i++;
//     }
// }

void cpy(char s[], char c[])
{
    int i = 0, j = 0;
    for (; s[j] != '\0'; j++)
    {
        // 检查是否为元音字母（大小写）
        if (s[j] == 'a' || s[j] == 'e' || s[j] == 'i' || s[j] == 'o' || s[j] == 'u' ||
            s[j] == 'A' || s[j] == 'E' || s[j] == 'I' || s[j] == 'O' || s[j] == 'U')
        {
            c[i] = s[j];  // 复制元音字母
            i++;          // 只有复制了字符才增加索引
        }
    }
    c[i] = '\0';  // 给结果字符串添加结束符
}