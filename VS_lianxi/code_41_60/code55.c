/*
题目描述
输入 x,y，输出 [x,y] 区间中闰年个数，并在下一行输出所有闰年年份数字，使用空格隔开。

输入格式
输入两个正整数 x,y，以空格隔开。

输出格式
第一行输出一个正整数，表示 [x,y] 区间中闰年个数。

第二行输出若干个正整数，按照年份单调递增的顺序输出所有闰年年份数字。

输入输出样例
输入 #1复制

1989 2001
输出 #1复制

3
1992 1996 2000
说明/提示
数据保证，1582≤x<y≤3000。
*/

#include"stdio.h"

int main()
{
    int x, y, run[1000]={0}, i = 0;
    int RunNian(int x);
    scanf("%d %d",&x,&y);
    for( int t = x; t <= y; t++)
    {
        if(RunNian(t) == 1)run[i++]=t;
    }
    printf("%d\n", i);
    for(int t=0 ; t < i;t ++)
    {
        printf("%d ",run[t]);
    }

    return 0;
}

int RunNian(int x)
{
    return( (x % 4 == 0 && x % 100 != 0) || (x % 400 == 0) ) ? 1 : 0;
}

// #include"stdio.h"

// int main()
// {
//     int x,y,zong,first;
//     scanf("%d %d", &x, &y);
//     int Pan(int x);
//     int Find(int x);
//     switch( Pan(x) + Pan(y) )
//     {
//         case -2:
//             zong = (y - x)/ 4;
//             break;
//         case 0:
//         case 2:
//             zong = (y - x)/ 4 + 1;
//             break;
//     }
//     printf("%d\n",zong);
//     if(Pan(x)==1)
//     {first = x;}else
//     {first = Find(x);}
//     for(int i = 0; i < zong; i++)
//     {
//         printf("%d ",first);
//         first += 4;
//     }

//     return 0;
// }

// int Pan(int x)
// {
//     if( x %4 == 0)
//     {return 1;}else
//     {return -1;}
// }

// int Find(int x)
// {
//     if(Pan(x + 1) == 1)return x+1;
//     if(Pan(x + 2) == 1)return x+2;
//     if(Pan(x + 3) == 1)return x+3;
// }

// #include <stdio.h>

// // 严格的闰年判断函数：能被4整除但不能被100整除，或能被400整除
// int isLeapYear(int year) {
//     if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
//         return 1;
//     }
//     return 0;
// }

// int main() {
//     int x, y;
//     int count = 0;          // 闰年个数
//     int leap_years[1000] = {0};  // 存储闰年（区间1582-3000最多约350个，1000足够）
    
//     // 输入区间
//     scanf("%d %d", &x, &y);
    
//     // 遍历区间，筛选闰年
//     for (int year = x; year <= y; year++) {
//         if (isLeapYear(year)) {
//             leap_years[count++] = year;  // 存入数组并计数
//         }
//     }
    
//     // 输出结果
//     printf("%d\n", count);
//     for (int i = 0; i < count; i++) {
//         printf("%d ", leap_years[i]);
//     }
    
//     return 0;
// }