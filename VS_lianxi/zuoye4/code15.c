/*
15. 元音字母出现的次数
【问题描述】
统计输入的一串字符中每个元音字母(a，e，i，o，u)出现的次数，输入#以作为结束。
【输入形式】
一串字符（没有大写字母，但是可能包括字母以外的字符），输入#以作为结束
【输出形式】
每个元音字母(a，e，i，o，u)出现的次数，输出格式参考样例输出，注意冒号使用英文字符，没有空格。
【样例输入】
sample123#
【样例输出】
a:1
e:1
i:0
o:0
u:0
*/

#include<stdio.h>

int main()
{
    char arr[100]={0};
    scanf("%s",arr);
    int num_a=0,num_e=0,num_i=0,num_o=0,num_u=0;
    for(int i=0;arr[i]!='\0';i++){
        if(arr[i]=='a'){
            num_a++;
        }else if(arr[i]=='e'){
            num_e++;
        }else if(arr[i]=='i'){
            num_i++;
        }else if(arr[i]=='o'){
            num_o++;
        }else if(arr[i]=='u'){
            num_u++;
        }
    }

    printf("a:%d\ne:%d\ni:%d\no:%d\nu:%d\n",num_a,num_e,num_i,num_o,num_u);

    return 0;
}