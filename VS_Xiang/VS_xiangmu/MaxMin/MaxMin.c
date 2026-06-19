#include<stdio.h>
int main()
{
    
    int a,b,c;
    scanf("%d %d %d",&a,&b,&c);
    int max,min;
    //求最大值
    if(a>=b&&a>=c){
        max=a;
    }else if(b>=a&&b>=c){
        max=b;
    }else if(c>=b&&c>=a){
        max=c;
    }
    //求最小值
    if(a<=b&&a<=c){
        min=a;
    }else if(b<=a&&b<=c){
        min=b;
    }else if(c<=a&&c<=b){
        min=c;
    }
}