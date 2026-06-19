#include "stdio.h"
#include "stdlib.h"
#include "string.h"

typedef struct Data{
    int num;
    char name[40];
    double price;
}Data;

typedef struct Book{
    Data data;
    struct Book *next;
}Book,*LinkList;

void InitLibrary(LinkList *L);
void InsertBook(LinkList L,int adre,Data e);
void DeleteBook(LinkList L,Data *e);
void PrintLibrary(LinkList L);
int FindBook(LinkList L,Data *e);
int LengthOfLibrary(LinkList L);

int main()
{
    LinkList head;
    int choice;
    int working=1,len=0;
    while(1){
    printf("Please enter the operation you want to perform:\n\
            1.Init the library;\n\
            2.Insert one book;\n\
            3.Delete one book;\n\
            4.Find one book;\n\
            5.Show all the books;\n\
            6.Exit the library.\n");
    scanf("%d",&choice);
    switch(choice){
        case 1:{
            InitLibrary(&head);
            break;
        }
        case 2:{
            Data e;
            int position;
            len=LengthOfLibrary(head);
            printf("Please enter the Position where you want to insert.\n\
                    0 < Position <= %d\n",len+1);
            scanf("%d",&position);
            printf("Please enter the Number of this book.\n");
            printf("Please enter the Name of this book.\n");
            fgets(e.name,40,stdin);
            e.name[strcspn(e.name, "\n")] = '\0';
            printf("Please enter the Price of this book.\n");
            scanf("%lf",&e.price);
            InsertBook(head,position,e);
            break;
        }
        case 3:{
            Data e;
            printf("Please enter the Number of the book you want to Delete.\n");
            scanf("%d",&e.num);
            DeleteBook(head,&e);
            break;
        }
        case 4:{
            PrintLibrary(head);
            break;
        }
        case 5:{
            Data e;
            printf("Please enter the Name of the book you want to Search for.\n");
            fgets(e.name,40,stdin);
            e.name[strcspn(e.name, "\n")] = '\0';
            FindBook(head,&e);
            break;
        }
        case 6:{
            working=0;
            break;
        }
        default:{
            printf("Incorrect input.\n\
                    Please re-enter.\n");
            break;
        }
    }

    if(!working)break;

    }

    return 0;
}

void InitLibrary(LinkList *L){
    (*L)=(LinkList)malloc(sizeof(Book));
    (*L)->next=NULL;
}

void InsertBook(LinkList L,int adre,Data e){
    LinkList p=L->next;
    LinkList t;
    for(int i=0;i<adre-1;i++){
        p=p->next;
    }
    t->next=p->next;
    p->next=t;
    t->data=e;
}

void DeleteBook(LinkList L,Data *e){
    LinkList p=L->next;
    LinkList t;
    while(p){
        if(p->next->data.num==e->num){
            (*e)=p->data;
            t=p->next;
            p->next=t->next;
            free(t);
            return;
        }
        else p=p->next;
    }
    printf("This book does not exist.\n");
}

void PrintLibrary(LinkList L){
    printf("Num    Price    Name\n");
    LinkList p=L->next;
    while(p){
        printf("%4d%4.f%s\n",p->data.num,p->data.price,p->data.name);
        p=p->next;
    }
}

int FindBook(LinkList L,Data *e){
    LinkList p=L->next;
    while(p){
        if(strcmp(p->data.name,(*e).name)){
            (*e)=p->data;
            return 1;
        }
        p=p->next;
    }
    return 0;
}

int LengthOfLibrary(LinkList L){
    int len=0;
    LinkList p=L->next;
    while(p){
        len++;
        p=p->next;
    }
    return len;
}