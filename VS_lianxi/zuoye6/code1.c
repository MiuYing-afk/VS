/*
1. 统计文章中的各种字符个数
【问题描述】
有一篇文章，共有多行文字（不超过10行）, 最后一行为"end"。
要求分别统计出其中英文大写字母、小写字母、数字、空格以及其它字符的个数。统计结果不包括最后一行的"end"。
【输入】
多行文字（不超过10行）, 最后一行为"end"。
【输出】
用空格分隔的5个整数，分别是文中英文大写字母、小写字母、数字、空格以及其它字符的个数，统计结果不包括最后一行的"end"
【样例输入】
I am a student.
123456
ASDFG
end
【样例输出】
6 10 6 3 1
*/

#include<stdio.h>
#include<string.h>

int main()
{
    int big=0,small=0,num=0,kong=0,other=0;
    char putin[100];
     while (1)
    {
        if (fgets(putin, sizeof(putin), stdin) == NULL)break;
        putin[strcspn(putin, "\n")] = '\0';
        if (strcmp(putin, "end") == 0)break;
        for(int i=0;i<10;i++)
        {
            if(strcmp(putin[i],"end")==0)break;
            for(int j=0;putin[i]!='\0';j++)
            {
                if(putin[i]>='A'&&putin[i]<='Z'){big++;}
                    else if(putin[i]>='a'&&putin[i]<='z'){small++;}
                else if(putin[i]>='0'&&putin[i]<='9'){num++;}
                else if(putin[i]==' '){kong++;}
                else{other++;}
            }
        }
    }
    printf("%d %d %d %d %d",big,small,num,kong,other);

    return 0;
}