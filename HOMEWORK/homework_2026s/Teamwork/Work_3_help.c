#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct film {
	char name[100];
	int sale;
	float score;
	struct film* next;
}film;
int initelist(film* head) {
	head->sale = 0;
	head->score = 0;
	head->next = NULL;
	return 1;
}
int createlist(film* head) {
	film* l = head;
	film* p = head;
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		film* newnode = (film*)malloc(sizeof(film));
		scanf(" %s", &newnode->name);
		scanf("%d", &newnode->sale);
		scanf("%f", &newnode->score);
		int check = 0;
		p = head;
		while (p->next != NULL) {
			if (newnode->sale > p->next->sale) {
				film* temp = p->next;
				p->next = newnode;
				newnode->next = temp;
				p = newnode;
				check = 1;
				break;
			}
			else if (newnode->sale == p->next->sale) {
				if (newnode->score > p->next->score) {
					film* temp = p->next;
					p->next = newnode;
					newnode->next = temp;
					p = newnode;
					check = 1;
					break;
				}
				else {
					p = p->next;
					film* temp = p->next;
					p->next = newnode;
					newnode->next = temp;
					p = newnode;
					check = 1;
					break;
				}
			}
			else p = p->next;
		}
		if (check == 0) {
			l->next = newnode;
			newnode->next = NULL;
			l = newnode;
		}
	}
	return 1;
}
int insertlist(film* head) {
	film* newnode = (film*)malloc(sizeof(film));
	scanf(" %s", &newnode->name);
	scanf("%d", &newnode->sale);
	scanf("%f", &newnode->score);
	int check = 0;
	film* p = head;
	while (p->next != NULL) {
		if (newnode->sale > p->next->sale) {
			film* temp = p->next;
			p->next = newnode;
			newnode->next = temp;
			p = newnode;
			check = 1;
			break;
		}
		else if (newnode->sale == p->next->sale) {
			if (newnode->score > p->next->score) {
				film* temp = p->next;
				p->next = newnode;
				newnode->next = temp;
				p = newnode;
				check = 1;
				break;
			}
			else {
				p = p->next;
				film * temp = p->next;
				p->next = newnode;
				newnode->next = temp;
				p = newnode;
				check = 1;
				break;
			}
		}
		else p = p->next;
	}
	if (check == 0) {
		p->next = newnode;
		newnode->next = NULL;
		p = newnode;
	}
	return 1;
}
int findlist(film* head){
	film* l = head;
	int order;
	int count = 1;
	int check = 0;
	scanf("%d", &order);
	while (l->next != NULL) {
		if (count == order) {
			printf("《%s》，", l->next->name);
			printf("票房：%d亿，", l->next->sale);
			printf("评分：%.1f\n", l->next->score);
			check = 1;
			break;
		}
		else {
			l = l->next;
			count++;
		}
	}
	if (check == 0) {
		printf("第%d名电影不存在\n", order);
	}
	return 1;
}
int deletelist(film* head) {
	film* l = head;
	float score;
	int check = 0;
	scanf("%f", &score);
	while (l->next != NULL) {
		if (l->next->score <= score) {
			if (l->next->next != NULL) {
				l->next = l->next->next;
				check = 1;
			}
			else l->next = NULL;
		}
		else l = l->next;
	}
	return 1;
}
void printlist(film* head) {
	film* l = head;
	printf("影片名    票房(亿)    豆瓣评分\n");
	while (l->next != NULL) {
		printf("%s    ", l->next->name);
		printf("%d    ", l->next->sale);
		printf("%.1f\n", l->next->score);
		l = l->next;
	}
}
int main() {
	film head;
	initelist(&head);
	char op;
	int keepgoing = 1;
	while (keepgoing) {
		scanf(" %c", &op);
		switch (op) {
		case 'c':
			createlist(&head);
			break;
		case 'p':
			printlist(&head);
			break;
		case 'i':
			insertlist(&head);
			break;
		case 'f':
			findlist(&head);
			break;
		case 'd':
			deletelist(&head);
			break;
		case 'q':
			keepgoing = 0;
			break;
		}
	}
}