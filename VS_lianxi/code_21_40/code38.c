#include<stdio.h>
struct student
{
    int num;
    char *name;
    char sex;
    float score;
};
struct student student[5]={
    {101,"Li ping",'M',45},
    {102,"Zhang ping",'M',62.5},
    {103,"He fang",'F',92.5},
    {104,"Cheng ling",'F',87},
    {105,"Wang ming",'M',58}
};
void main()
{
    struct student *p;
    printf("学号\t姓名\t\t性别\t年龄\n");
    for(p=student;p<student+5;p++)
        printf("%d\t%-15s\t%2c\t%2d\n",p->num,p->name,p->sex,p->score);
}