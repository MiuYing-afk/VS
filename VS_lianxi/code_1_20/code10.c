#include<stdio.h>

int main()
{
    int n,t;
    scanf("%d",&n);
    if(n<0){t=n*(-1);}
    if(t%2==0){printf("%d是偶数",n);}
    else{printf("%d是奇数",n);}
    
    return 0;
}