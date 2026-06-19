#include<stdio.h>
#include<string.h>
struct person
{
    char name[20];
    int count;
}leader[3]={"Li",0,"Zhang",0,"Wang",0};

void main()
{
    char name[20];
    int i;
    printf("请输入10张选票的所投候选人姓名:\n");
    for(i=1;i<=10;i++){
        scanf("%s",name);
        for(int j=0;j<3;j++){
            if(strcmp(name,leader[j].name)==0)
                leader[j].count++;
        }
    }
    printf("统计结果:\n");
    for(i=0;i<3;i++){
        printf("%5s:%d票\n",leader[i].name,leader[i].count);
    }
}
