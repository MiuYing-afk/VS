#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Node{
	char id[20];
	char name[50];
	int load;
	struct Node *next;
}Node,*List;

List InitList(List L){
	L = (Node*)malloc(sizeof(Node));
	L->next=NULL;
	return L;
}

void PrintfNode(List L){
	if (L->next == NULL) return;
	Node *p=L->next;
	while(p->next!= NULL){
		printf("%s %s %d->",p->id,p->name,p->load);
        p=p->next;
	}
	p=p->next;
	printf("%s %s %d",p->id,p->name,p->load);
}

void InsertNode(List L){
	Node *p=L->next;
	Node *s = (Node*)malloc(sizeof(Node));
	scanf("%s %s %d",s->id,s->name,&s->load);
    while(p->next!=NULL && strcmp(p->id,s->id)<0)
		p=p->next;
	s=p->next;p->next=s;
	PrintfNode(L);
}


int main(){
	List L;
	InitList();
	char op;
	while(scanf("%c",&op)!=EOF){
		if (op=='i'){
			InsertNode(L);
		}
	}
}
