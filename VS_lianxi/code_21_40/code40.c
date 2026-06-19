#include<stdio.h>
#include<string.h>
#include<process.h>
#define MAXSIZE 50

struct TelInfo
{
    char name[10];
    char telno[10];
};
int Append(struct TelInfo telList[],int *len,struct TelInfo telInfo);
char *Find(struct TelInfo telList[],int *len,char *name);
int  Delete(struct TelInfo telList[],int *len,char *name);
void Out(struct TelInfo telList[],int len);

int Append(struct TelInfo telList[],int *len,struct TelInfo telInfo)
{
    int length;
    length=*len;
    if(length==MAXSIZE)
        return 0;
    telList[length]=telInfo;
    length++;
    *len=length;
    return 1;
}

char *Find(struct TelInfo telList[],int *len,char *name)
{
    int i,length=*len;
    for(i=0;i<length;i++)
        if(strcmp(telList[i].name,name)==0)
            return telList[i].telno;
    return NULL;
}

int Delete(struct TelInfo telList[], int *len, char *name)
{
    int i, j, length = *len;
    for (i = 0; i < length; i++)
    {
        if (strcmp(telList[i].name, name) == 0)
            break;
    }
    if (i < length)
    {
        for (j = i; j < length; j++)
            telList[j] = telList[j + 1];
        (*len)--;
        return 1;
    }
    else
        return 0;
}

struct TelInfo
{
    char name[10];
    char telno[10];
};

void Out(struct TelInfo telList[], int len)
{
    int i, length = len;
    printf("\n姓名        号码\n");
    for (i = 0; i < length; i++)
        printf("%10s%10s\n", telList[i].name, telList[i].telno);
}

void main()
{
    int choice;          
    char name[10];       
    struct TelInfo telList[MAXSIZE];
    int len = 0;         
    while (1)
    {
        printf("手机通信录功能选项:1:插入 2:删除 3:查询 4:输出 0:退出\n请选择操作:");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1: 
                struct TelInfo tel;
                printf("输入要插入的姓名、电话(以空格隔开)\n");
                scanf("%s%s", tel.name, tel.telno);
                Append(telList, &len, tel);
                break;
            case 2: 
                printf("请输入要删除的联系人姓名:\n");
                scanf("%s", name);
                Delete(telList, &len, name);
                break;
            case 3: 
                printf("请输入要查找的联系人姓名:\n");
                scanf("%s", name);
                if (char *p = Find(telList, &len, name))
                    printf("该联系人的电话为:%s\n", p);
                else
                    printf("没有该联系人！\n");
                break;
            case 4: 
                printf("电话号码表为:");
                Out(telList, len);
                break;
            case 0: 
                return;
            default:
                continue;
        }
    }
}