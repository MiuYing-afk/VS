//求位数

#include<stdio.h>

int main()
{
    int x,t;
    scanf("%d",&x);
    int cnt=0;
    for(t=x;t>0;cnt++){
        t/=10;
    }
    printf("%d的位数是%d",x,cnt);

    return 0;
}