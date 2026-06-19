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