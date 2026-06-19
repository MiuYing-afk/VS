#include<stdio.h>
struct student
{
    int num;
    char name[10];
    float score;
};

void OutPut(struct student stu)
{
    printf("学生的信息是:\n学号\t姓名\t\t成绩\n%d\t%s\t%.2f\n"
                ,stu.num,stu.name,stu.score);
};

int main()
{
    struct student stu1={10001,"ZhangShan",95};
    OutPut(stu1);

    return 0;
}