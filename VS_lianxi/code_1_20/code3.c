// 1. 输入一个日期，输出该日期是本年的第几天。（用if实现）
// 【问题描述】

// 输入一个日期，输出该日期是本年的第几天。

// 【提示】

// 需要考虑本年是否为闰年，本题目要求使用if语句实现

// 【输入】

// 用横线分割的日期，格式为yyyy-mm-dd，
// 【输出】

// 一个整数，表示该日期为本年的第几天
// 【样例输入】

// 2024-3-21
// 【样例输出】

// 81

#include<stdio.h>

int main()
{
    int year,month,day,pan,zong=0;
    scanf("%d-%d-%d",&year,&month,&day);
    if((year%4==0&&year%100!=0)||(year%400==0)){pan=1;}
    else{pan=0;}

    switch(month)
    {
        case 1:zong=day;break;
        case 2:zong=31+day;
                if(day==29){
                    zong--;
                };
                break;
        case 3:zong=31+28+day;break;
        case 4:zong=31+28+31+day;break;
        case 5:zong=62+28+30+day;break;
        case 6:zong=31*3+28+30+day;break;
        case 7:zong=31*3+28+60+day;break;
        case 8:zong=31*4+28+60+day;break;
        case 9:zong=31*5+28+60+day;break;
        case 10:zong=31*5+28+90+day;break;
        case 11:zong=31*6+28+90+day;break;
        case 12:zong=31*6+28+120+day;break;
    }

    if(month>=3&&pan==1)zong++;
    printf("%d",zong);

    return 0;
}

//方法二
#include<stdio.h>
int main()
{
    int year,month,day;
    int days,k,leap;
    int tab[2][13]={{0,31,28,31,30,31,30,31,31,30,31,30,31},
                    {0,31,29,31,30,31,30,31,31,30,31,30,31}};
    printf("请输入日期(格式：年-月-日):");
    scanf("%d-%d-%d",&year,&month,&day);
    leap=((year%4==0)&&(year%100!=0)||(year%400==0));
    for(days=day,k=0;k<month;k++)
        days=days+tab[leap][k];
    printf("%d年%d月%d日是该年的第%d天\n",year,month,day,days);

    return 0;
}