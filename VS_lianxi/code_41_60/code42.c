#include<stdio.h>
#include<string.h>
struct person
{
    char name[10];
    int  age;
    char job[10];
    union
    {
        int classNo;
        char office[30];
    }depa;
};
void main()
{
    struct person body[2];
    int n,i;
    for(i=0;i<2;i++)
    {
        printf("请输入:姓名,年龄,职业(student或teacher)和部门(班级或教研室):\n");
        scanf("%s%d%s",body[i].name,&body[i].age,body[i].job);
        if(strcmp(body[i].job,"student")==0)
            scanf("%d",&body[i].depa.classNo);
        else if(strcmp(body[i].job=="teacher")==0)
            scanf("%s",body[i].depa.office);
    }
    printf("姓名\t\t年龄\t职业\t\t班级/教研室\n");
    for(i=0;i<2;i++)
    {
        if(strcmp(body[i].job,"student")==0)
            printf("%-15s\t%d\t%s\t\t%d\n",
                body[i].name,body[i].age,body[i].job,body[i].depa.classNo);
        else if(strcmp(body[i].job=="teacher")==0)
                printf("%-15s\t%d\t%s\t\t%d\n",
                    body[i].name,body[i].age,body[i].job,body[i].depa.office);
    }
}