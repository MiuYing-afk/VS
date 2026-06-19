#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct A {
	int num;  //编号
	char name[40];  //书名
	double price;
}A;

typedef struct manage {
	A data;
	struct manage* next;
}manage, * linklist;

void Initlist(linklist* L) {
	(*L) = (linklist)malloc(sizeof(manage));
	(*L)->next = NULL;
}

void Insertbook(linklist L, int i, A book) {
	linklist p = L->next;
	linklist m;
	for (int j = 0; j < i - 1; j++) {
		p = p->next;
	}
	m = (linklist)malloc(sizeof(manage));
	m->data = book;
	m->next = p->next;
	p->next = m;
	printf("插入成功\n");
}

void Deletebook(linklist L, int i) {
	linklist p = L->next;
	linklist m;
	for (int j = 0; j < i - 1; i++) {
		p = p->next;
	}
	m = p->next;
	p->next = m->next;
	free(m);
}

void Showbook(linklist L) {
	linklist p = L->next;
	while (p) {
		printf("%5d%c%.2f", p->data.num, p->data.name, p->data.price);
        //这里的输出因该是输出字符串而不是一个字符
        //你不熟练的话可以把这三个变量分开写
		p = p->next;
	}
}

void Findbook(linklist L) {
	char a[40];
	scanf_s("%s", a);
	linklist p = L->next;
	while (p != NULL) {
		if (strcmp(p->data.name, a) == 0) {
			printf("\n查找成功\n%5d%c%.2f", p->data.num, p->data.name, p->data.price);
            //和Showbook函数一样的问题
			return;
		}
		p = p->next;
	}
	printf("查找失败\n");
}


int main() {
	linklist list;
	Initlist(&list);

	printf("*****************************\n");
	printf("欢迎使用图书管理系统\n");
	printf("1.插入图书信息\n");
	printf("2.删除图书信息\n");
	printf("3.展示图书信息\n");
	printf("4.查找图书信息\n");
	printf("*****************************\n");
	printf("请输入编号\n");

	int choice;
	scanf_s("%d", &choice);

	switch (choice) {
	case 1:
		A bi;
		int j;
		printf("请输入图书信息：");
		scanf_s("%d %c %f", &bi.num, &bi.name, &bi.price);
        //这里不能这么写，你只读入了一个字符，而不是一个字符串
        //你要把这三个变量分开输入，并且加上提示
		printf("请输入插入位置：");
		scanf_s("%d", &j);

		Insertbook(list, j, bi);
		printf("插入成功");

	case 2:
		int k;
		printf("请输入删除图书位置：");
		scanf_s("%d", &k);
		Deletebook(list, k);
		printf("删除成功");

	case 3:
		Showbook(list);

	case 4:
		printf("请输入查找的书籍名称：");
		Findbook(list);
	}




	return 0;
}

//没什么大问题，把部分输出和UI界面改一下就好