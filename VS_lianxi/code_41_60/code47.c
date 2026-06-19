#include<stdio.h>
#include<stdlib.h>
#define NULL 0
struct student
{
    int num;
    char name[20];
    struct student * next;
};

struct student * create( ) /*创建链表,返回指向链表头的指针*/
{
    struct student * p,* head;
    int num;
    p=(struct student *)malloc(sizeof(struct student));
    head=p;
    printf("请输入学号(输入0退出):");
    scanf("%d",&num);
    if(num==0)
        return NULL;
    else
        do
        {
            p->num=num;
            printf("请输入学生姓名:");
            scanf("%s",p->name);
            printf("请输入学号(输入0退出):");
            scanf("%d",&num);
            if(num!=0)
            {
                p->next=(struct student *)malloc(sizeof(struct student));
                p=p->next;
            }
            else
            {
                p->next=NULL;
                return head;
            }
        } while(1);
}

void print(struct student * head) /*输出链表*/
{
    struct student * p=head;
    while(p!=NULL)
    {
        printf("%d %s\n",p->num,p->name);
        p=p->next;
    }
    return;
}

struct student * deletenode(struct student * head,int num)
{
    struct student * p1, * p2=head;
    if(head==NULL)
    {
        printf("list is null!\n"); /*空链表*/
        return head;
    }
    else
        while(p2->num!=num && p2->next!=NULL)
        {
            p1=p2;
            p2=p2->next;
        }
    if(p2->num==num) /*找到了需要删除的结点*/
    {
        if(p2==head) /*需要删除的是第一个结点*/
        {
            p1=p2->next;
            free(head); /*释放删除结点所占的内存*/
            return p1;
        }
        else
        {
            p1->next=p2->next; /*需要删除的不是第一个结点*/
            free(p2); /*释放删除结点所占的内存*/
            return head;
        }
    }
    else /*没有找到需要删除的结点*/
    {
        printf("student number %d not been found!\n",num);
        return head;
    }
}

struct student * insertnode(struct student * head)
{
    struct student * new, *p=head, *q;
    int key;
    /*生成新结点new*/
    new=(struct student *)malloc(sizeof(struct student));
    printf("Input the new student number:");
    scanf("%d", &new->num);
    printf("Input the new student name:");
    scanf("%s", new->name);
    printf("Input the key student number:");
    scanf("%d", &key);

    /*查找关键结点*/
    while(p!=NULL)
    {
        if(p->num==key)
            break;
        else
        {
            q=p;
            p=p->next;
        }
    }

    if(p==head)
    {
        /*把新结点new插入到链表的开头*/
        new->next=head;
        head=new;
        return head;
    }
    else if(p!=NULL)
    {
        /*找到了关键结点*/
        q->next=new;
        new->next=p;
    }
    else
    {
        /*未找到关键结点，将new加入到链表的末尾*/
        q->next=new;
        new->next=NULL;
    }
    return head;
}

void main( )
{
    struct student * head;

    head=create( );
    print(head);
}