/*
14. 回文质数
【问题描述】

因为 
151
151 既是一个质数又是一个回文数（从左到右和从右到左是看一样的），所以 
151
151 是回文质数。

写一个程序来找出范围 
[
a
,
b
]
(
5
≤
a
<
b
≤
100
,
000
,
000
)
[a,b](5≤a<b≤100,000,000)（一亿）间的所有回文质数。

【提示】

提示 1: 找出所有的回文数再判断它们是不是质数（素数）

提示 2: 要产生正确的回文数，你可能需要几个像下面这样的循环。

产生长度为 
5
5 的回文数：



for (d1 = 1; d1 <= 9; d1+=2) {    // 只有奇数才会是素数      
       for (d2 = 0; d2 <= 9; d2++) {          
              for (d3 = 0; d3 <= 9; d3++) {            
                        palindrome = 10000*d1 + 1000*d2 +100*d3 + 10*d2 + d1;//(处理回文数...)          
               }      
       }  
 }


【输入】

第一行输入两个正整数 
a
a 和 
b
b。5≤a<b≤100,000,000

【输出】

输出一个回文质数的列表，一行一个。

【样例输入】

5 500
【样例输出】

5
7
11
101
131
151
181
191
313
353
373
383

*/

#include<stdio.h>
#include<math.h>

int Length(int num);
int Judge_PrimeNum(int num);
int Judge_Palindrome(int num);

int main()
{
    int a,b;
    scanf("%d %d",&a,&b);
    for(int i=a;i<=b;i++)
    {
        if(Judge_PrimeNum(i)!=0)
        {
            if(Judge_Palindrome(i)!=0)
            printf("%d\n",i);
        }
    }
    // a=Length(a);
    // b=Length(b);
    // printf("%d %d",a,b);

    return 0;
}
int Length(int num)
{
    int length=1;
    for(;(num/=10)!=0;length++);
    return length;
}

int Judge_PrimeNum(int num)
{
    if(num%2==0)return 0;
    for(int i=3;i<=sqrt(num);i+=2)
    {
        if(num%i==0)return 0;
    }
    return num;
}

// int Judge_Palindrome(int num)
// {
//     int len=Length(num),No[10]={0},temp=num;
//     for(int i=0;temp!=0;i++)
//     {
//         No[i]=temp%10;
//         temp/=10;
//     }
//     for(int i=0;i<(len+1)/2;i++)
//     {
//         if(No[i]!=No[len-i-1])return 0;
//     }
//     return 1;
// }

int Judge_Palindrome(int num)
{
    int temp=num;  // 保存原数字（避免修改后无法对比）
    int reverse_num=0;  // 存储逆序数
    
    // 构造逆序数：从低位到高位拼接
    while (temp>0)
    {
        reverse_num=reverse_num*10+temp%10;  // 取当前最低位，拼到逆序数末尾
        temp=temp/10;  // 去掉当前最低位
    }
    
    // 逆序数与原数相等则为回文数
    return (reverse_num==num)? 1:0;
}