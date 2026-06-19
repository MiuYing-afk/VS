#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Node {

    char id[20];

    char name[50];

    int load;

    struct Node *next;

} Node,*Linklist;


void init(Linklist* head) {

    *head = (Linklist)malloc(sizeof(Node));

    (*head)->next = NULL;

}


void insert(Linklist* head,char id[],char name[],int load){
    Linklist newNode=(Linklist)malloc(sizeof(Node));
    strcpy(newNode->id,id);
    strcpy(newNode->name,name);
    newNode->load=load;
    
    Linklist p=*head;
    while(p->next!=NULL &&strcmp(p->next->id,id)<0){
        p=p->next;
    }
    newNode->next=p->next;
    p->next=newNode; 
}

void printlist(Linklist head){

       Linklist p=head->next;
    while(1){
       printf("%s %s %d",p->id,p->name,p->load);
        p=p->next;
        if(p==NULL){
            break;
        }
        printf("->");
    }
    printf("\n");
}
    
int deletelist(Linklist* head,char name[]){
    Linklist p=*head;
    while(p->next!=NULL){
        if(strcmp(p->next->name,name)==0){
            Linklist q=p->next;
            p->next=q->next;
            free(q);
            return 1;
        }
        p=p->next;
    }
    return 0;
}

int findNode(Linklist head,char name[],int* res){
     Linklist p=head->next;
     while(p!=NULL){
         if(strcmp(p->next->name,name)==0){
             *res=p->next->load;
             return 1;
         }
         p=p->next;
     }
    return 0;
}


int updateNode(Linklist head,char name[],int newload){
    Linklist p=head->next;
    while(p!=NULL){
      if(strcmp(p->name,name)==0){
         p->load=newload;   
         return 1;
      }
        p=p->next;
    }
    return 0;
}

void average(Linklist head){
    int count=0;
    double sum=0;
    double result=0;
    Linklist p=head->next;
    while(p!=NULL){
        sum+=p->load;
        count++;
        p=p->next;
    }
    result=sum/count;
    printf("%.2f",result);
}

void sortList(Linklist head){
   if(head->next==NULL||head->next->next==NULL){
       return;
   }
    int len=0;
    Linklist p=head->next;
    while(p!=NULL){
        len++;
        p=p->next;
    }
    for(int i=0;i<len-1;i++){
        Linklist cur=head->next;
    for(int j=0;j<len-i-1;j++){
        if(cur->load<cur->next->load){
            char tid[20];
            char tname[20];
            int tload;
            
            strcpy(tid,cur->id);
            strcpy(cur->id,cur->next->id);
            strcpy(cur->next->id,tid);
            
            strcpy(tname,cur->name);
            strcpy(cur->name,cur->next->name);
            strcpy(cur->next->name,tname);
            
            tload=cur->load;
            cur->load=cur->next->load;
            cur->next->load=tload;
        }
        cur=cur->next;
     }
    
  }
}

int main() {
    Linklist head;
    init(&head);

    char op;



    while (scanf(" %c", &op) != EOF) {



        if (op == 'q') {

            break;

        }



        else if (op == 'i') {

            char id[20], name[50];

            int load;

            scanf("%s %s %d", id, name, &load);

            insert(&head, id, name, load);
            
            printlist(head);
        }



        else if (op == 'p') {

            printlist(head);

        }



        else if (op == 'd') {

            char name[50];

            scanf("%s", name);
           if(deletelist(&head,name)){
               printlist(head);
           }
            else{
                printf("Not Found");
            }

        }



        else if (op == 'f') {

            char name[50];
            int res;

            scanf("%s", name);

            if(findNode(head,name,&res)){
                printf("%d",res);
            }
            else{
                printf("Not Found");
            }

        }



        else if (op == 'u') {

            char name[50];

            int load;

            scanf("%s %d", name, &load);

           if(updateNode(head, name, load)){
               printlist(head);
           }
            else{
                printf("Not Found");
            }

        }

        else if (op == 'a') {

            average(head);

        }


        else if (op == 's') {

            sortList(head);
            printlist(head);

        }

    }



    return 0;

}