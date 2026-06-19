/*
5. 判断两个数的高k位是否相等
【问题描述】
编写一个函数  int fun(int m,int n,int k)   ，其中m，n , k是三个正整数(k不大于m和n的位数)，判断 m和n 的高 k 位是否相等。
在主程序中输入这三个数, 如果 m和n 的高 k 位相等。输出"YES"；否则，输出"NO"。
【样例输入】
123456 12389 3
【样例输出】
YES
*/

#include<stdio.h>
#include<math.h>
int fun(int m,int n,int k);

int main( )
{ int m,n,k;
  scanf("%d%d%d",&m,&n,&k);
   if(fun(m,n,k))
        printf("YES\n");
    else 
         printf("NO\n");
}

// int fun(int m,int n,int k)
// {
//     int t1,t2;

// }

// int reverse(int n)
// {
//     int t;
//     for(;n!=0;n/=10)
//     {

//     }
// }

int fun(int m, int n, int k) {
    // 计算m的位数
    int len_m = 0;
    int temp_m = m;
    while (temp_m > 0) {
        temp_m /= 10;
        len_m++;
    }
    
    // 计算n的位数
    int len_n = 0;
    int temp_n = n;
    while (temp_n > 0) {
        temp_n /= 10;
        len_n++;
    }
    
    // 计算高k位的权重
    int weight_m = pow(10, len_m - k);
    int weight_n = pow(10, len_n - k);
    
    // 提取高k位并比较
    int high_m = m / weight_m;
    int high_n = n / weight_n;
    
    return high_m == high_n ? 1 : 0;
}