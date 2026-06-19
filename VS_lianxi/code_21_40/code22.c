#include<stdio.h>
#include<string.h>
void main()
{
    char *name[]={"Follow me","BASIC","Great Wall","FORTRAN","Computer"};
    char *temp;
    int i,j,k;
    for(i=0;i<4;i++)
    {
        k=i;
        for(j=i+1;j<5;j++)
        {
            if(strcmp(name[k],name[j])>0)
                k=j;
        }
        if(k!=i)
        {
            temp=name[i];
            name[i]=name[k];
            name[k]=temp;
        }
    }
    for(i=0;i<5;i++)
        { printf("%s\n",name[i]); }
}