/*
10. 判断象限
【问题描述】

从键盘上输入直角坐标系上一个点的坐标（x,y）,编程实现判断该点属于第几象限。

【要求】

（1）x和y都是实型变量

（2）请注意在x坐标轴上、y坐标轴上和原点上的数据。

【输入】

一个点的坐标（x,y），x和y用空格分隔

【输出】

该点所处对象限，输出的内容包括：

该点在第一象限

该点在第二象限

该点在第三象限

该点在第四象限

该点在x轴上

该点在y轴上

该点在原点

【样例输入】

1.5 -1
【样例输出】


该点在第四象限
*/

#include<stdio.h>

int main()
{
    int x,b;
    scanf("%d %d",&x,&b);

    if(x>0){
        if(b>0)printf("该点在第一象限");
        else if(b<0)printf("该点在第四象限");
        else printf("该点在x轴上");
    }else if(x<0){
        if(b>0)printf("该点在第二象限");
        else if(b<0)printf("该点在第三象限");
        else printf("该点在x轴上");
    }else{
        if(b!=0)printf("该点在y轴上");
        else printf("该点在原点");
    }

    return 0;
}