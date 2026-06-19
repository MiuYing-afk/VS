//数组学习

#include<stdio.h>

int main()
{
    int x;
    double sum=0;
    int cnt=0;
    int number[100];      //定义数组
    scanf("%d",&x);
    while(x!=-1){
        number[cnt]=x;    //对数组中的元素赋值
        sum+=x;
        cnt++;
        scanf("%d",&x);
    }
    if(cnt>0){
        int i;
        double average = sum / cnt;
        for(i=0;i<cnt;i++){
            if(number[i]>average){          //使用数组中的元素
                printf("%d ",number[i]);
            }
        }
    }

    return 0;
}