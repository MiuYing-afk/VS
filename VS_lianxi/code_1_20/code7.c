/*
5. 4个整数由小到大输出
【问题描述】

输入4个整数，要求按由小到大的顺序输出。 

【要求】

此题使用if语句采用依次比较的方法排出其大小顺序。在学习了循环和数组以后，可以有更多的排序方法。 

【输入】

4个整数，用空格分隔

【输出】

由小到大输出4个整数，用空格分隔

【样例输入】

2 5 9 3
【样例输出】

2 3 5 9
*/

// #include<stdio.h>

// int main()
// {
//     int a,b,c,d;
//     scanf("%d%d%d%d",&a,&b,&c,&d);
    

//     return 0;
// }

#include <stdio.h>

int main() {
    int a, b, c, d;
    int temp;
    
    // 输入4个整数
    scanf("%d %d %d %d", &a, &b, &c, &d);
    
    // 使用if语句进行排序（冒泡排序思想）
    // 第一轮比较：确保a是最小的
    if (a > b) { temp = a; a = b; b = temp; }
    if (a > c) { temp = a; a = c; c = temp; }
    if (a > d) { temp = a; a = d; d = temp; }
    
    // 第二轮比较：确保b是第二小的
    if (b > c) { temp = b; b = c; c = temp; }
    if (b > d) { temp = b; b = d; d = temp; }
    
    // 第三轮比较：确保c是第三小的
    if (c > d) { temp = c; c = d; d = temp; }
    
    // 输出排序结果
    printf("%d %d %d %d\n", a, b, c, d);
    
    return 0;
}
