#include<stdio.h>
#include<string.h>
void main()
{
    char s[][8]={"Japan","Korea","China","Germany","India"};
    int i,j;
    char t[8];
    for(i=0;i<4;i++){
        for(j=i+1;j<5;j++){
            if(strcmp(s[i],s[j])>0){
                strcpy(t,s[i]);
                strcpy(s[i],s[j]);
                strcpy(s[j],t);
            }
        }
    }
    for(i=0;i<5;i++)
        puts(s[i]);
}