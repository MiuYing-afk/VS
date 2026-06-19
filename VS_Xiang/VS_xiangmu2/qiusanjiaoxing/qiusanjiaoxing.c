/*
题目描述
模仿例题，打印出不同方向的正方形，然后打印三角形矩阵。中间有个空行。

输入格式
输入矩阵的规模，不超过 9。

输出格式
输出矩形和三角形

输入输出样例
输入 #1复制

4
输出 #1复制

01020304
05060708
09101112
13141516

      01
    0203
  040506
07080910
*/

#include<stdio.h>

int main()
{
    int n;
    scanf("%d",&n);
    int i,j=0,cnt=0;

    for(i=1;i<=n*n;i++){
        if(j<n){
          printf("%02d",i);
          j++;
        }else{
          i--;
          j=0;
          printf("\n");
        }
    }
    printf("\n");
    printf("\n");
    for(i=1;i<=n*(n+1)/2;i++){
      for(j=0;j<n-i;j++){
        printf("  ");
      }
      printf("%02d",i);
    }

    return 0;
}