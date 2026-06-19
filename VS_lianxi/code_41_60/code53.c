/*
题目描述
给出平面坐标上不在一条直线上三个点坐标 (x 
1
​
 ,y 
1
​
 ),(x 
2
​
 ,y 
2
​
 ),(x 
3
​
 ,y 
3
​
 )，坐标值是实数，且绝对值不超过 100.00，求围成的三角形周长。保留两位小数。

对于平面上的两个点 (x 
1
​
 ,y 
1
​
 ),(x 
2
​
 ,y 
2
​
 )，则这两个点之间的距离 dis= 
(x 
2
​
 −x 
1
​
 ) 
2
 +(y 
2
​
 −y 
1
​
 ) 
2
 
​
 。

输入格式
输入三行，第 i 行表示坐标 (x 
i
​
 ,y 
i
​
 )，以一个空格隔开。

输出格式
输出一个两位小数，表示由这三个坐标围成的三角形的周长。

输入输出样例
输入 #1复制

0 0
0 3
4 0
输出 #1复制

12.00
说明/提示
数据保证，坐标均为实数且绝对值不超过 100，小数点后最多仅有 3 位。
*/

#include"stdio.h"
#include"math.h"

int main()
{
    double Length(double x1, double y1, double x2, double y2);
    double x1,y1,x2,y2,x3,y3,s1,s2,s3,len;
    scanf("%lf %lf",&x1,&y1);
    scanf("%lf %lf",&x2,&y2);
    scanf("%lf %lf",&x3,&y3);
    s1 = Length( x1, y1, x2, y2 );
    s2 = Length( x2, y2, x3, y3 );
    s3 = Length( x3, y3, x1, y1 );
    len = s1 + s2 + s3;
    printf("%.2f",len);

    return 0;
}

double Length(double x1, double y1, double x2, double y2)
{
    double dx=(( x1 -x2 )*( x1 - x2 ));
    double dy=(( y1 -y2 )*( y1 - y2 ));
    return sqrt( dx + dy );
}
