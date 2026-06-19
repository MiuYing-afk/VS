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