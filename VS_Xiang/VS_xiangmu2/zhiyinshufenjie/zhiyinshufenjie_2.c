#include<stdio.h>

int main()
{
    int n,i=2;
    printf("请输入一个整数：");
    scanf("%d",&n);
    printf("%d=",n);
    while(n!=i){
        if(n%i==0){
            printf("%d*",i);
            n/=i;
        }else{
            i++;
        }
    }
    printf("%d\n",n);

    return 0;
}