#include<stdio.h>
void main()
{
    char *name[5]={"gain","much","stronger","point",0};
    char **p=name;
    int i;
    while(*p)
    {
        for(i=0;*(*p+i);i++)
            { printf("%c",*(*p+i)); }
        printf("\n");
        p++;
    }
}