#include<stdio.h>
#include<stdlib.h>
#define NULL 0

struct student
{
    int num;
    char name[20];
    float score;
    struct student *next=NULL;
};

struct student *create_Stu(); /* 创建链表 */
struct student *insert_Stu(struct student *head, struct student *new); /* 插入结点 */
struct student *delete_Stu(struct student *head, int num); /* 删除结点 */
void print_Stu(struct student *head); /* 遍历链表 */

void main()
{
    struct student *head=NULL, *p;
    int choice, num;
    do
    {
        printf("Please select operation:\n");
        printf("1.Create  2.Insert  3.Delete  4.Print  0.Exit\n");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1: /* 创建链表 */
                head = create_Stu();
                break;
            case 2: /* 插入结点 */
                if((p=(struct student *)malloc(sizeof(struct student)))==NULL)
                {
                    printf("No space available. Please select again.\n");
                    break;
                }
                printf("New student number:");
                scanf("%d", &p->num);
                printf("New student name:");
                scanf("%s", p->name);
                printf("New student score:");
                scanf("%f", &p->score);
                head = insert_Stu(head, p);
                break;
            case 3: /* 删除结点 */
                printf("Student number you want to delete:\n");
                scanf("%d", &num);
                head = delete_Stu(head, num);
                break;
            case 4: /* 输出链表 */
                print_Stu(head);
                break;
            case 0:
                exit(1);
        }
    } while(choice!=0);
}

/* 创建链表 */
struct student *create_Stu()
{
    struct student *head=NULL, *p;
    while(1)
    {
        if((p=(struct student *)malloc(sizeof(struct student)))==NULL)
        {
            printf("No space available. Creation failed.\n");
            break;
        }
        printf("Student number(0 to exit):");
        scanf("%d", &p->num);
        if(p->num==0)
            break;
        printf("Student name:");
        scanf("%s", p->name);
        printf("Student score:");
        scanf("%f", &p->score);
        p->next = NULL;
        if(head==NULL)
            head = p;
        else
        {
            struct student *q = head;
            while(q->next!=NULL)
                q = q->next;
            q->next = p;
        }
    }
    return head;
}

/* 插入结点 */
struct student *insert_Stu(struct student *head, struct student *new)
{
    struct student *p=head, *q;
    if(head==NULL) /* 原链表为空 */
    {
        new->next = NULL;
        return new;
    }
    while(p->num < new->num) /* 查找关键结点 */
    {
        q = p;
        p = p->next;
        if(p==NULL)
            break;
    }
    if(p==head) /* 把新结点插入到链表的开头 */
    {
        new->next = head;
        head = new;
    }
    else if(p==NULL) /* 将新结点加入到链表的末尾 */
    {
        q->next = new;
        new->next = NULL;
    }
    else /* 将新结点插入到链表的中间 */
    {
        q->next = new;
        new->next = p;
    }
    return head;
}

/* 删除结点 */
struct student *delete_Stu(struct student *head, int num)
{
    struct student *p1, *p2=head;
    if(head==NULL)
    {
        printf("list is null!\n"); /* 空链表 */
        return head;
    }
    while(p2->num!=num && p2->next!=NULL)
    {
        p1 = p2;
        p2 = p2->next;
    }
    if(p2->num == num) /* 找到了需要删除的结点 */
    {
        if(p2 == head) /* 需要删除的是第一个结点 */
        {
            p1 = p2->next;
            free(p2);
            return p1;
        }
        else
        {
            p1->next = p2->next;
            free(p2);
        }
    }
    else /* 没有找到需要删除的结点 */
    {
        printf("Student number %d not been found!\n", num);
    }
    return head;
}

/* 输出链表 */
void print_Stu(struct student *head)
{
    struct student *p=head;
    while(p!=NULL)
    {
        printf("%d %s %.1f\n", p->num, p->name, p->score);
        p = p->next;
    }
    return;
}