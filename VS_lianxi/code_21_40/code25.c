#include<stdio.h>
int *max(int *,int *);
void main()
{
    int a=10,b=20,*p=NULL;
    p=max(&a,&b);
    printf("%d\n",*p);
}

int *max(int *x,int *y)
{
    if(*x>*y)
        { return x; }
    else
        { return y; }
}