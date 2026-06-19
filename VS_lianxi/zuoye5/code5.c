/*
4. 求圆周长、圆面积、圆球表面积、圆球体积、圆柱体积
【问题描述】
输入圆半径和圆柱高，求圆周长、圆面积、圆柱体积，结果均保留两位小数。
要求：将pi定义为符号常量，取值3.1416
【输入形式】
半径,高
【输出形式】
圆周长:
圆面积:
圆柱体积:
【样例输入】
1.5,3
【样例输出】
圆周长:9.42
圆面积:7.07
圆柱体积:21.21
*/

#include<stdio.h>
#define pi 3.1416
int main()
{
    float r,h;
    float C(float r),S(float r),V(float r,float h);
    scanf("%f,%f",&r,&h);
    printf("圆周长:%.2f\n"
            "圆面积:%.2f\n"
            "圆柱体积:%.2f",C(r),S(r),V(r,h));

    return 0;
}

float C(float r){
    return 2*pi*r;
}

float S(float r){
    return pi*r*r;
}

float V(float r,float h){
    float area=S(r);
    return area*h;
}