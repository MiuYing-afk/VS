/*
5. 通过函数求子串在字符串中的位置
【问题描述】
已经给出主函数，编写自定义函数int  substring(char s[], char sub[])，
查找sub串在字符串s中第一次出现的位置，若找到，函数返回对应位置，否则返回-1。

在main函数中输入主串和子串，调用该函数并输出结果。

【注意】

字符串s的第1个字符的位置为1。例如s串为“abcdefg”，sub串为“def”，则返回值为4。

【样例输入】


abcdefgdefg
def
【样例输出】

子串def在字符串abcdefgdefg中第一次出现的位置是4
*/
#include <stdio.h>
int main( )
{   int  substring(char s[], char sub[]);
    char s[99],sub[99];
    gets(s);
    gets(sub);
    if(substring(s,sub)==-1)
           printf("没有找到子串%s",sub);
    else
           printf("子串%s在字符串%s中第一次出现的位置是%d",sub,s,substring(s,sub));
}

// int  substring(char s[], char sub[])
// {
//     int i=0,j=0;
//     for(;s[i]!='\0';i++)
//     {
//         if()
//     }
// }

int my_strlen(char s[]) {
    int len = 0;
    while (s[len] != '\0') { // 循环直到遇到字符串结束符'\0'
        len++;
    }
    return len;
}

// 查找子串sub在主串s中第一次出现的位置
int substring(char s[], char sub[]) {
    int i, j, k;
    int len_s = my_strlen(s);   // 主串长度
    int len_sub = my_strlen(sub); // 子串长度
    
    // 子串长度为0或大于主串长度，直接返回-1
    if (len_sub == 0 || len_sub > len_s) {
        return -1;
    }
    
    // 遍历主串，寻找子串的起始位置
    for (i = 0; i <= len_s - len_sub; i++) {
        k = i;
        // 逐个字符比对子串
        for (j = 0; j < len_sub; j++) {
            if (s[k] != sub[j]) {
                break; // 字符不匹配，跳出内层循环
            }
            k++;
        }
        // 如果内层循环完整执行（j等于子串长度），说明找到匹配
        if (j == len_sub) {
            return i + 1; // 位置从1开始，所以i+1
        }
    }
    return -1; // 未找到子串
}
