/*
50. 求最大公约数和最小公倍数
【问题描述】

输入两个正整数m和n，求其最大公约数和最小公倍数。 
【输入形式】

m,n

【输出形式】

最大公约数是
最小公倍数是

【样例输入】

2,3

【样例输出】

最大公约数是1
最小公倍数是6
*/

#include"stdio.h"

int main()
{
    int i,a,b,yue,bei;
    scanf("%d,%d",&a,&b);
    if(a<b){
        i=a;a=b;b=i;
    }
    bei = a*b;
    while(b!=0)
    {
        i=a%b;
        a=b;
        b=i;
    }
    yue = a;
    bei /= a;
    printf("最大公约数是%d\n最小公倍数是%d",yue,bei);


    return 0;
}

// #include "stdio.h"

// int main()
// {
//     // 定义变量：temp临时存储交换值/余数，num1/num2存储原始输入，gcd最大公约数，lcm最小公倍数
//     int temp, num1, num2, gcd, lcm;
//     // 读取逗号分隔的两个正整数
//     scanf("%d,%d", &num1, &num2);
    
//     // 保存原始值（用于后续计算最小公倍数，避免辗转相除时覆盖原始值）
//     int a = num1;
//     int b = num2;
    
//     // 确保a >= b，简化辗转相除逻辑
//     if (a < b)
//     {
//         temp = a;
//         a = b;
//         b = temp;
//     }
    
//     // 先计算两数乘积（用于后续求最小公倍数）
//     lcm = a * b;
    
//     // 辗转相除法求最大公约数
//     while (b != 0)
//     {
//         temp = a % b;  // 求余数
//         a = b;         // 除数作为新的被除数
//         b = temp;      // 余数作为新的除数
//     }
//     gcd = a;          // 余数为0时，a即为最大公约数
//     lcm /= gcd;       // 最小公倍数 = 两数乘积 / 最大公约数
    
//     // 按题目样例格式输出，每行对应一个结果
//     printf("最大公约数是%d\n", gcd);
//     printf("最小公倍数是%d\n", lcm);

//     return 0;
// }