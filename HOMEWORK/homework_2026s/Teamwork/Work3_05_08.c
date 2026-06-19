/*
1. 电影榜单管理系统
【问题描述】

2025年春节档电影市场表现强劲，总票房突破200亿元，创下历史新高。现需要构建一个电影榜单管理系统，以便记录和管理电影信息。榜单按票房降序排列。

基本要求：使用带头结点的单向链表存储电影信息，每部电影包括以下字段：

•   影片名（char数组）

•   票房（单位为“亿”，使用int类型存储即可）

•   豆瓣评分（float类型，小数形式）



电影榜单示例如下：

影片名    票房(亿)  豆瓣评分
哪吒之魔童闹海    80    8.5
唐探1900    34    6.5
封神第二部:战火西岐    12    5.9
熊出没·重启未来    5    7.1
蛟龙行动    2    6.6


功能要求：

创建：输入若干电影信息，按票房降序创建电影榜单；

插入：输入节点信息，按票房降序插入，票房相同的情况下，新插入的节点在榜单中更靠前；

输出：按正确格式输出电影榜单信息；

查找：按票房名次查找输出电影信息，其中电影名带书名号；

删除：删除豆瓣评分低于指定分数的电影。



【输入形式】

每行输入一个操作命令及相应信息，具体如下：

创建操作输入c，接着输入元素个数，最后逐行输入若干电影的信息；

输出操作输入p

插入操作输入i，接着依次输入影片名、票房、豆瓣评分对应的值，用空格隔开，如i 射雕英雄传:侠之大者 5 5.5

查找操作输入f，接着输入票房名次，如f 3

删除操作输入d，接着输入豆瓣评分，如d 6.0

退出程序输入q

【输出形式】

电影榜单信息输出格式示例如下：

影片名    票房(亿)    豆瓣评分
哪吒之魔童闹海    80    8.5
唐探1900    34    6.5
其中各元素之间包含4个空格，豆瓣评分对应的值应保留1位小数。


查找操作输出格式如下：

《哪吒之魔童闹海》，票房：80亿，评分：8.5
若查找票房排名第n的电影不存在，则输出：

第n名电影不存在

【样例输入1】

c 3
熊出没·重启未来 5 7.1
封神第二部:战火西岐 12 5.9
哪吒之魔童闹海 80 8.5
p
q
【样例输出1】


影片名    票房(亿)    豆瓣评分
哪吒之魔童闹海    80    8.5
封神第二部:战火西岐    12    5.9
熊出没·重启未来    5    7.1
【样例输入2】

i 射雕英雄传:侠之大者 5 5.5
p
q
【样例输出2】

影片名    票房(亿)    豆瓣评分
哪吒之魔童闹海    80    8.5
封神第二部:战火西岐    12    5.9
射雕英雄传:侠之大者    5    5.5
熊出没·重启未来    5    7.1
【样例输入3】

f 3
f 4
q
【样例输出3】

《熊出没·重启未来》，票房：5亿，评分：7.1
第4名电影不存在

【样例输入4】

d 6.0
p
q
【样例输出4】


影片名    票房(亿)    豆瓣评分
哪吒之魔童闹海    80    8.5
熊出没·重启未来    5    7.1
【样例输入5】

i 封神第二部:战火西岐 12 5.9
i 哪吒之魔童闹海 80 8.5
i 熊出没·重启未来 5 7.1
i 唐探1900 34 6.5
i 蛟龙行动 2 6.6
d 7.0
p
q
【样例输出5】


影片名    票房(亿)    豆瓣评分
哪吒之魔童闹海    80    8.5
熊出没·重启未来    5    7.1
【样例说明】

样例输入 2、3、4 中的操作都以样例输入1中输入的信息为基础。

【辅助代码】

下列代码作为参考，数据结构定义与核心功能函数需自行实现。

int main() {
    char command;  // 存储操作命令
    char name[50];
    int boxOffice;
    float rating;
    
    LinkList head;
    InitList(&head);
    while (scanf("%c", &command) != EOF)  {
        if (command == 'c') {
            int num = 0;
            scanf("%d", &num);
            getchar();
            Movie* movies = (Movie*)malloc(num * sizeof(Movie));
            for(int i = 0; i < num; i++) {
                scanf("%s %d %f", movies[i].name, &movies[i].boxOffice, &movies[i].rating);
                getchar();
             }
            head = createList(movies, num);
        }
        else if (command == 'i') {
            scanf("%s%d%f", name, &boxOffice, &rating);
            insertSorted(head, name, boxOffice, rating);
        }
        else if (command == 'f') {
            int n;
            scanf("%d", &n);
            LinkList movie = findNth(head, n);
            if (movie) {
                printf("《%s》，票房：%d亿，评分：%.1f\n",
                    movie->name, movie->boxOffice, movie->rating);
            }
            else {
                printf("第%d名电影不存在\n", n);
            }
        }
        else if (command == 'd') {
            scanf("%f", &rating);
            deleteLowRating(head, rating);
        }
        else if (command == 'p') {
            printf("影片名    票房(亿)    豆瓣评分\n");
            printList(head);
        }
        else if(command == 'q') {
	    exit(0);
        }
    }
    return 0;
}
*/

#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "math.h"

typedef struct Node{
    char Name[60];
    int Box;
    double Rating;
    struct Node *next;
}ListNode,*LinkList;

void InitList(LinkList *head);
void CreatNode(LinkList head);
void Print(LinkList head);
void InsertNode(LinkList head);
void FindNode(LinkList head);
void DeleteNode(LinkList head);
void ClearList(LinkList head);
int Length(LinkList head);

int main()
{
    LinkList head;
    InitList(&head);
    char choice;
    while(1){
        scanf(" %c",&choice);
        switch(choice){
            case 'c':{
                int num;
                scanf("%d",&num);
                for(int i=0;i<num;i++){
                    CreatNode(head);
                }
                break;
            }

            case 'p':{
                Print(head);
                break;
            }

            case 'i':{
                InsertNode(head);
                break;
            }

            case 'f':{
                FindNode(head);
                break;
            }

            case 'd':{
                DeleteNode(head);
                break;
            }

            case 'q':{
                ClearList(head);
                exit(0);
            }

            default:{
                getchar();
                break;
            }
        }
    }

    return 0;
}

void InitList(LinkList *head){
    (*head)=(LinkList)malloc(sizeof(ListNode));
    (*head)->next=NULL;
}

void CreatNode(LinkList head){
    LinkList p=head;
    LinkList new=(LinkList)malloc(sizeof(ListNode));
    scanf(" %s",new->Name);
    scanf("%d",&new->Box);
    scanf("%lf",&new->Rating);
    while(p->next!=NULL){
        if(p->next->Box<=new->Box)break;
        p=p->next;
    }
    new->next=p->next;
    p->next=new;
}

void Print(LinkList head){
    LinkList last=head->next;
    printf("影片名    票房(亿)    豆瓣评分\n");
    while(last){
        printf("%s    %d    %.1f\n",last->Name,last->Box,last->Rating);
        last=last->next;
    }
}

void InsertNode(LinkList head){
    LinkList new=(LinkList)malloc(sizeof(ListNode));
    scanf(" %s",new->Name);
    scanf("%d",&new->Box);
    scanf("%lf",&new->Rating);
    LinkList p=head;
    while(p->next!=NULL&&p->next->Box>new->Box){
        p=p->next;
    }
    new->next=p->next;
    p->next=new;
}

void FindNode(LinkList head){
    int address;
    scanf("%d",&address);
    if(address>Length(head)||address<=0){
        printf("第%d名电影不存在\n",address);
    }else{
        LinkList p=head->next;
        for(int i=1;i<address;i++){
            p=p->next;
        }
        printf("《%s》，票房：%d亿，评分：%.1f\n",p->Name,p->Box,p->Rating);
    }
}

void DeleteNode(LinkList head){
    double Rate;
    scanf("%lf",&Rate);
    LinkList p=head;
    while(p->next){
        if(p->next->Rating<Rate||fabs(p->next->Rating-Rate)<1e-6){
            LinkList tag=p->next;
            p->next=tag->next;
            free(tag);
        }
        //写成if(p->next)p=p->next过不了
        else p=p->next;
    }
}

void ClearList(LinkList head){
    LinkList last=head->next;
    while(last){
        head->next=last->next;
        free(last);
        last=head->next;
    }
}

int Length(LinkList head){
    LinkList last=head->next;
    int len=0;
    while(last){
        len++;
        last=last->next;
    }
    return len;
}