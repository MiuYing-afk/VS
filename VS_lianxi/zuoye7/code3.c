#include<stdio.h>

int max_same(float a[][6],int n)
{
    int temp=0,b[6];
    for(int i=0;i<n;i++)
    {
     for(int j=0;j<n;j++)
        {
         if(a[i][j]>temp)
           temp=a[i][j];
        }   
        b[i]=temp;
        temp=0;
    }
    for(int i=0;i<n;i++)
    {
     if(b[i]!=b[0])return 0;
    }
    return 1;
}

int main(void )
{  
     float a[6][6];
     int i, j, n;
     scanf("%d",&n);

    for(i=0;i<n;i++)
         for(j=0;j<n;j++)
            scanf("%f",&a[i][j]);

    if(max_same(a,n))
          printf("YES\n");
   else
          printf("NO\n");
}

