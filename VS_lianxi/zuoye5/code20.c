/*
19. ABC
【问题描述】

三个整数分别为 
A
,
B
,
C
A,B,C。这三个数字不会按照这样的顺序给你，但它们始终满足条件：
A
<
B
<
C
A<B<C。

为了看起来更加简洁明了，我们希望你可以按照给定的顺序重新排列它们。

【输入】

第一行包含三个正整数 
A
,
B
,
C
A,B,C，不一定是按这个顺序。这三个数字都小于或等于 
100
100。

第二行包含三个大写字母 
A
A、
B
B 和 
C
C（它们之间没有空格）表示所需的顺序。

【输出】

在一行中按指定顺序输出 
A
A，
B
B 和 
C
C，用空格隔开。



【样例输入1】

1 5 3
ABC
【样例输出1】

1 3 5
【样例说明1】
输入的3个数字，按照大小顺序可以知道A=1，B=3, C=5。按照指定的ABC的顺序输出为：1 3 5



【样例输入2】

6 4 2
CAB
【样例输出2】

6 2 4
【样例说明2】
输入的3个数字，按照大小顺序可以知道A=2，B=4, C=6。按照指定的CAB顺序输出为：6 2 4
*/

#include <stdio.h>

int main() {
    int num[3];
    char order[4]; // 存3个字母+结束符
    int A, B, C;
    
    // 输入三个整数
    scanf("%d %d %d", &num[0], &num[1], &num[2]);
    // 输入指定顺序
    scanf("%s", order);
    
    // 排序（冒泡排序），得到A<B<C
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2 - i; j++) {
            if (num[j] > num[j+1]) {
                int temp = num[j];
                num[j] = num[j+1];
                num[j+1] = temp;
            }
        }
    }
    A = num[0]; // 最小
    B = num[1]; // 中间
    C = num[2]; // 最大
    
    // 按指定顺序输出
    for (int i = 0; i < 3; i++) {
        switch (order[i]) {
            case 'A': printf("%d", A); break;
            case 'B': printf("%d", B); break;
            case 'C': printf("%d", C); break;
        }
        if (i < 2) printf(" "); // 最后一个数后不加空格
    }
    printf("\n");
    
    return 0;
}