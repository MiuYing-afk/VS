//int x;p判断x是偶数：x%2==0;
//char c;判段c是否为数字：c>='0'&&c<='9';
//char c;判断c是否为英文字母：c>='A'&&c<='Z'||c>='a'&&c<='z';
//float x,y;或double x,y;判断x==y: fabs ( x - y ) <= 1e-6;
//float x,y;或double x,y;判断x!=y: fabs ( x - y ) <= 1e-6;
//用fans()函数 (绝对值函数) 要用头文件“<math.h>”;

#include<stdio.h>
#include<math.h>

void main()
{
    float a,b,c,p,area;
    printf("请输入三角形的三边：\n");
    scanf("%f%f%f",&a,&b,&c);
    if(a+b>c&&fabs(a-b)<c){
        p=(a+b+c)/2;
        area=sqrt(p*(p-a)*(p-b)*(p-c));
        printf("area=%f\n",area);
    }else{
        prntf("输入数据错误\n");
    }
}
