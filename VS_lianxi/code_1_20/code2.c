#include<stdio.h>
int main()
{
    int a,b,c,x;
    scanf("%d %d %d\n",&a,&b,&c);
    int num[3]={a,b,c};
    char A,B,C;
    scanf("%c%c%c",&A,&B,&C);
    for(int i=0;i<2;i++)
    {
        for(int j=0;j<2-i;j++)
        {
            if(num[j]>num[j+1])
            {
                x=num[j];
                num[j]=num[j+1];
                num[j+1]=x;
            }
        }
    }
    int d,e,f;
    if(A=='A')
    {
        d=num[0];
        if(B=='B')
        {
            e=num[1];
            f=num[2];
        }
        else{
            f=num[1];
            e=num[2];
        }
    }
    else if(B=='A')
    {
        e=num[0];
        if(A=='B')
        {
            d=num[1];
            f=num[2];
        }
        else{
            f=num[1];
            d=num[2];
        }
    }
    else
    {
        f=num[0];
        if(A=='B')
        {
            d=num[1];
            e=num[2];
        }
        else{
            e=num[1];
            d=num[2];
        }
    }
    printf("%d %d %d",d,e,f);
}