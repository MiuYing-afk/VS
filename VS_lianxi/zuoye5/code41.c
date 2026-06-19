/*
49. 统计字符串中英文字母、空格、数字和其他字符的个数
【问题描述】

输入一行字符（以换行符结束），分别统计出其中英文字母、空格、数字和其他字符的个数。 
【输入形式】

一行字符（回车结束）

【输出形式】

字母数:
空格数:
数字数:
其它字符数:

【样例输入】

I am a student 123.

【样例输出】

字母数:11
空格数:4
数字数:3
其它字符数:1

*/

#include "stdio.h"

int main()
{
    // 初始化4个计数器：字母、空格、数字、其他字符
    int letter = 0, space = 0, digit = 0, other = 0;
    char c;  // 临时存储读取的字符

    // 循环读取字符，直到遇到换行符结束
    while ((c = getchar()) != '\n')
    {
        // 按ASCII码范围判断字符类型，排他性分类
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
        {
            letter++;  // 英文字母计数
        }
        else if (c == ' ')
        {
            space++;  // 空格计数
        }
        else if (c >= '0' && c <= '9')
        {
            digit++;  // 数字计数
        }
        else
        {
            other++;  // 其他字符计数
        }
    }

    // 按指定格式输出结果
    printf("字母数:%d\n", letter);
    printf("空格数:%d\n", space);
    printf("数字数:%d\n", digit);
    printf("其它字符数:%d\n", other);

    return 0;
}