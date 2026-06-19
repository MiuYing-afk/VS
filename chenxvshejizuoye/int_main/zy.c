/******************预处理模块和结构体******************/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#define SIZE 50
#define LEN sizeof(struct student)
#define FORMAT "%-12d%-12s%-12.1f%-12.1f%-12.1f%-12.1f\n"
#define DATA stu[i].num,stu[i].name,stu[i].chinese,stu[i].math,stu[i].english,stu[i].sum
 
/******************函数声明与简介******************/
void enter();			/*录入学生联系方式信息*/
void list();			/*显示学生基本信息*/
void search();			/*查找学生联系方式信息*/
void Delete();			/*删除学生信息*/
void sort();			/*按学号排序*/
void add();				/*插入学生信息*/
void alter();				/*修改学生信息*/
void search_num();		/*学号查找学生联系方式信息*/
void search_name();		/*名字查找学生联系方式信息*/
 
/******************定义通讯录结构体******************/
struct student
{
	char num[10];			/*学号*/
	char name[20];		/*名字*/
	char phone[12];		/*电话号码*/
}stu[SIZE];				/*定义全结构体数组*/
 
/******************主函数******************/
int main()
{
	int select;
	struct student s;
	system("cls");		/*清屏*/
	do					/*显示目录*/
	{
		printf("\t\t********************MENU***********************\n\n");
		printf("\t\t    0. 输入记录\n");
		printf("\t\t    1. 显示记录\n");
		printf("\t\t    2. 查找已有的记录\n");
		printf("\t\t    3. 删除一条记录\n");
		printf("\t\t    4. 插入一条记录\n");
		printf("\t\t    5. 修改一条记录\n");
		printf("\t\t    6. 对通讯录排序\n");
		printf("\t\t    7. 退出系统\n");
		printf("\t\t***********************************************\n");
		printf("\n请选择(0~7):\n");
		scanf("%d", &select);		/*输入选择功能的编号*/
		switch (select)
		{
		case 0:enter(); break;		/*录入记录功能函数调用*/
		case 1:list(); break;		/*显示记录功能函数调用*/
		case 2:search(); break;		/*查找记录功能函数调用*/
		case 3:Delete(); break;		/*删除记录功能函数调用*/
		case 4:add(); break;			/*插入记录功能函数调用*/
		case 5:alter(); break;			/*修改记录功能函数调用*/
		case 6:sort(); break;		/*记录排序功能函数调用*/
		case 7:exit(0);				/*退出功能*/
		default:printf("input error.\n"); break;   //超出选择数据,打印出“input error.”
		}
	} while (select != 6);
}
 
	/******************录入学生信息******************/
	void enter()
	{
		FILE*fp;								//定义文件指针
		int i, n = 0;							//变量表示记录的条数
		for (i = 0; i < SIZE; i++)					//最多可输入50条
		{
			printf("\n请输入学生%d:\n", i + 1);	//显示输入第几个学生
			printf("学号是:");				//输入学生学号
			scanf("%s", stu[i].num);
			printf("姓名是:");				//输入学生姓名
			scanf("%s", stu[i].name);
			printf("电话号码是:");				//输入学生电话号码
			scanf("%s", stu[i].phone);
			n++;
			printf("\n是否继续添加?(y/n):\n");	//选择继续添加数据还是停止添加
			if (getch() != 'y');
				break;
		}
		if ((fp = fopen("stu.txt", "a+")) == NULL)	//打开指定文件
		{
			printf("文件操作失败\n");
			exit(0);							//退出程序运行
		}									//到了这里表示打开文件成功，且文件用fp来控制
		for (i = 0; i < n; i++)						//数组写入文件
			if (fwrite(&stu[i], LEN, 1, fp) != 1)
				printf("写入文件失败\n");
		fclose(fp);
		system("cls");						//所有输入结束后清屏
	}
 
	/******************显示学生信息******************/
	void list()
	{
		FILE*fp;								//定义文件指针
		int i, n;
		if ((fp = fopen("stu.txt", "rb")) == NULL)	//打开指定文件
		{
			printf("文件打开失败\n");
			exit(0);							//退出程序运行
		}									//到了这里表示打开文件成，且文件用fp来控制
		i = 0;
		while (fread(&stu[i], LEN, 1, fp) != 0)		//计算读取的文件个数
			i++;
		n = i;
		for (i = 0; i < n; i++)
			fread(&stu[i], LEN, 1, fp);			//读取文件
		fclose(fp);
		system("cls");						//结束后清屏，使目录美观
		printf("\n\t\t*************** 以下为通讯录所有信息 ************\n");
		printf("\t\t编号\t姓名\t电话号码\n");
		printf("\n\t\t************************************************\n");
		for (i = 0; i < n; i++)
			printf("\t\t%s\t%s\t%s\n", stu[i].num, stu[i].name, stu[i].phone);
		printf("\n\t\t__________________按任意键继续__________________\n");
		getch();
		system("cls");						//所有输入结束后清屏并返回目录界面
	}
 
	/******************查找学生信息******************/
	void search()
	{
		int sel;
		system("cls");						//清屏
		do {									//显示查找方式菜单
			printf("\n\t\t************** 按学号或姓名查找****************\n");
			printf("\n\t\t1----------------------用学号查找\n");
			printf("\t\t2----------------------用姓名查找\n");
			printf("\t\t3----------------------退出本次查找\n");
			printf("\n\t\t***************** 按姓名查找 *******************\n");
			printf("\n请选择(1~3):\n");
			scanf("%d", &sel);					//输入对应功能的编号
			switch (sel)
			{
			case 1:search_num(); break;		/*学号查找学生联系方式信息*/
			case 2:search_name(); break;	/*姓名查找学生联系方式信息*/
			case 3:break;					//退出本次查找并打印出“输入有误！”，重新选择查找方式
			default:printf("输入有误！\n"); break;
			}
		} while (sel != 3);
		system("cls");						//退出查找，清屏
	}
 
	/******************学号查找学生信息******************/
	void search_num()
	{
		FILE*fp;								//定义文件指针
		int i, n;
		char num[10];							//学号
		if ((fp = fopen("stu.txt", "rb")) == NULL)	//打开指定文件
		{
			printf("文件打开失败！\n");
			exit(0);							//退出程序运行
		}									//到了这里表示打开文件成功，且文件用fp来控制
		i = 0;
		while (fread(&stu[i], LEN, 1, fp) != 0)		//扫描文件
			i++;
		n = i;									//记录个数
		for (i = 0; i < n; i++)
			fread(&stu[i], LEN, 1, fp);			//逐一读出来,放进stu数组中
		fclose(fp);
		printf("\n输入编号:");
		scanf("%s", num);						//输入查找学号
		for (i = 0; i < n; i++)
		{
			if (strcmp(num, stu[i].num) == 0)		//文件中有这条记录
			{
				printf("\n\t\t***********************************************\n");
				printf("你要找的记录为：\n");
				printf("\t\t学号\t姓名\t电话号码\n");
				printf("\t\t%s\t%s\t%s\n", stu[i].num, stu[i].name, stu[i].phone);
				break;
			}								//显示该条记录，并继续查找下一条记录
		}
		printf("\n\t\t***********************************************\n");
		if (i == n)								//文件中没有这条记录
		{
			system("cls");					//清屏
			printf("\n\n\n\n\t\t未找到所需记录!\n");
			getch();
		}									//退出本次查找
	}
 
	/******************姓名查找学生信息******************/
	void search_name()
	{
		FILE*fp;								//定义文件指针
		int i, j, flag, n;
		char name[20];						//姓名
		if ((fp = fopen("stu.txt", "rb")) == NULL)	//打开指定文件
		{
			printf("文件打开失败！\n");
			exit(0);							//退出程序运行
		}									//到了这里表示打开文件成功，且文件用fp来控制
		i = 0;
		while (fread(&stu[i], LEN, 1, fp) != 0)		//扫描文件
			i++;
		n = i;									//记录个数
		for (i = 0; i < n; i++)
			fread(&stu[i], LEN, 1, fp);			//逐一读出来,放进stu数组中
		fclose(fp);
		printf("\n请输入需要查找的学生姓名:");
		scanf("%s", name);						//输入查找姓名
		flag = 0;
		for (i = 0; i < n; i++)
		{
			if (strcmp(name, stu[i].name) == 0)		//文件中有这条记录
			{
				printf("\n\t\t***********************************************\n");
				printf("查找的记录信息为：\n:");
				printf("\t\t编号\t姓名\t电话号码\n");
				printf("\t\t%s\t%s\t%s\n", stu[i].num, stu[i].name, stu[i].phone);
				flag = 1;							//标记成功
			}								    //显示该条记录，并继续查找下一条记录
		}
		printf("\n\t\t***********************************************\n");
		if (flag != 1)								//失败
		{
			system("cls");						//清屏
			printf("\n\n\n\n\t\t未找到所需记录！\n");
			getch();
		}										//退出本次查找
	}
	/******************删除学生信息******************/
	void Delete()
	{
		FILE*fp;								//定义文件指针
		int i, j, n, flag;
		struct student temp;
		char num[10];							//学号
		if ((fp = fopen("stu.txt", "rb")) == NULL)	//打开指定文件
		{
			printf("文件打开失败！\n");
			exit(0);							//退出程序运行
		}									//到了这里表示打开文件成功，且文件用fp来控制
		i = 0;
		while (fread(&stu[i], LEN, 1, fp) != 0)		//扫描文件
			i++;
		n = i;									//记录个数
		printf("\n请输入要删除的学号:");
		scanf("%s", num);
		flag = 1;								//标记是否找到并删除，1未找到，0已找到
		for (i = 0; i < n; i++)
		{
			if (strcmp(num, stu[i].num) == 0)		//查到了
			{
				for (j = i; j < n - 1; j++)			//依次向前移位
				{
					strcpy(stu[j].name, stu[j + 1].name);
					strcpy(stu[j].num, stu[j + 1].num);
					strcpy(stu[j].phone, stu[j + 1].phone);
				}
				flag = 0;							//标记已删除
				n--;								//逻辑有效数少1
			}
		}
		fp = fopen("stu.txt", "wb");				//打开或建立一个二进制文件，只允许写数据
		for (i = 0; i < n; i++)
			fwrite(&stu[i], LEN, 1, fp);			//重写记录
		fclose(fp);
		if (flag == 1)							//未被修改过
		{
			printf("\n记录未找到!\n按任意键继续......\n\n");
			getch();							//停留
			system("cls");					//清屏
			return;
		}
		else									//被修改过
		{
			printf("\n\n删除成功!\n\n");
			printf("按任意键重新查看所有记录\n");
			getch();							//停留
			system("cls");					//清屏，重新显示目录
		}
		fclose(fp);
		fp = fopen("stu.txt", "rb");				//重读记录
		for (i = 0; i < n; i++)						//开始冒泡排序
			for (j = i + 1; j < n; j++)
				if (strcmp(stu[i].num, stu[j].num) > 0)
				{
					temp = stu[i];
					stu[i] = stu[j];
					stu[j] = temp;
				}
		printf("\n\t\t***********************************************\n");
		printf("\t\t编号\t姓名\t电话号码\n");
		i = 0;
		while (fread(&stu[i], LEN, 1, fp) != 0)		//显示所有记录
		{
			printf("%s\t%s\t%s\n", stu[i].num, stu[i].name, stu[i].phone);
			i++;
		}
		printf("\n\t\t***********************************************\n");
		fclose(fp);
		getch();								//停留
		system("cls");							//清屏,并显示主目录
	}
 
 
	/******************插入学生信息******************/
	void add()
	{
		FILE*fp;								//定义文件指针
		int i, j, n;
		struct student s;						//输入插入的信息
		printf("学号是:");
		scanf("%s", s.num);
		printf("姓名是:");
		scanf("%s", s.name);
		printf("电话号码是:");
		scanf("%s", s.phone);
		if ((fp = fopen("stu.txt", "rb")) == NULL)	//打开指定文件
		{
			printf("文件打开失败！\n");
			exit(0);							//退出程序运行
		}										//到了这里表示打开文件成功，且文件用fp来控制
		i = 0;
		while (fread(&stu[i], LEN, 1, fp) != 0)		//扫描文件
			i++;
		n = i;									//记录个数
		for (i = 0; i < n; i++)
		{
			if (strcmp(s.num, stu[i].num) == 0)		//判断学号是否存在
			{
				printf("学号已存在，无法插入！\n");
				getch();
				system("cls");					//清屏
				return;							//学号存在，返回目录
			}
			fread(&stu[i], sizeof(struct student), 1, fp);	//学号不存在，读出数据
		}
		fclose(fp);								//插入信息到文件中
		strcpy(stu[n].name, s.name);
		strcpy(stu[n].num, s.num);
		strcpy(stu[n].phone, s.phone);
		n++;
		printf("\n新的记录集合是:\n");
		printf("\n\t\t***********************************************\n");
		printf("\t\t编号\t姓名\t电话号码\n");
		printf("\n\t\t***********************************************\n");
		fp = fopen("stu.txt", "wb");
		for (i = 0; i < n; i++)								//打印出新的文件信息
		{
			fwrite(&stu[i], sizeof(struct student), 1, fp);
			printf("%s\t%s\t%s\n", stu[i].num, stu[i].name, stu[i].phone);
		}
		fclose(fp);
		getch();										//停留
		system("cls");									//清屏,并显示主目录
	}
	/******************修改学生信息******************/
	void alter()
	{
		FILE*fp;										//定义文件指针
		int i, j, n, flag, kk;
		struct student s;
		if ((fp = fopen("stu.txt", "rb")) == NULL)			//打开指定文件
		{
			printf("文件打开失败！\n");
			exit(0);									//退出程序运行
		}											//到这里表示打开文件成功，且文件用fp来控制
		i = 0;
		while (fread(&stu[i], LEN, 1, fp) != 0)				//扫描文件
			i++;
		n = i;											//记录个数
		printf("学号是:");							//输入学号
		scanf("%s", s.num);
		kk = 0;
		for (i = 0; i < n; i++)
		{
			flag = strcmp(s.num, stu[i].num);
			if (flag == 0)								//判断学号是否存在
			{
				printf("该学号已存在，修改数据！");		//存在，修改数据
				printf("修改后的姓名是:");
				scanf("%s", s.name);
				printf("修改后的电话号码是:");
				scanf("%s", s.phone);
				strcpy(stu[i].name, s.name);
				strcpy(stu[i].phone, s.phone);
				kk = 1;
			}
			else
				fread(&stu[i], sizeof(struct student), 1, fp);	//读出数据
 
		}
		if (kk == 0)
		{
			printf("该学号不存在，无法修改！");
 
		}
		fclose(fp);										//插入信息到文件中
		printf("\n新的记录集合是:\n");
		printf("\n\t\t***********************************************\n");
		printf("\t\t编号\t姓名\t电话号码\n");
		printf("\n\t\t***********************************************\n");
		fp = fopen("stu.txt", "wb");
		for (i = 0; i < n; i++)									//打印出新的文件信息
		{
			fwrite(&stu[i], sizeof(struct student), 1, fp);
			printf("\t\t%s\t%s\t%s\n", stu[i].num, stu[i].name, stu[i].phone);
		}
		fclose(fp);
		getch();											//停留
		system("cls");									//清屏,并显示主目录
	}
 
	/******************排序******************/
	void sort()
	{
		FILE*fp;										//定义文件指针
		int i, j, n;
		struct student temp;
		if ((fp = fopen("stu.txt", "rb")) == NULL)			//打开指定文件
		{
			printf("文件打开失败！\n");
			exit(0);									//退出程序运行
		}											//到了这里表示打开文件成功，且文件用fp来控制
		i = 0;
		while (fread(&stu[i], LEN, 1, fp) != 0)				//扫描文件
			i++;
		n = i;											//记录文件个数
		for (i = 0; i < n; i++)								//读出数据
			fread(&stu[i], LEN, 1, fp);
		fclose(fp);
		for (i = 0; i < n; i++)								//开始冒泡排序
			for (j = i + 1; j < n; j++)
				if (strcmp(stu[i].num, stu[j].num) > 0)
				{
					temp = stu[i];
					stu[i] = stu[j];
					stu[j] = temp;
				}
		printf("排序完成,按任意键查看排序好的记录。\n");
		getch();
		system("cls");								//清屏
		printf("\n\t\t***********************************************\n");
		printf("\t\t编号\t姓名\t电话号码\n");
		for (i = 0; i < n; i++)
			printf("\t\t%s\t%s\t%s\n", stu[i].num, stu[i].name, stu[i].phone);
		fp = fopen("stu.txt", "wb");						//打开指定文件
		for (i = 0; i < n; i++)								//将排好序的信息写入文件
			fwrite(&stu[i], LEN, 1, fp);
		printf("\n\t\t***********************************************\n");
		fclose(fp);
	}