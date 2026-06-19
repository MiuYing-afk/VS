#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_NAME 50
#define MAX_ID 20
#define MAX_PHONE 15
#define MAX_ADDR 100
#define MAX_POSTAL 10
#define MAX_EMAIL 50
#define MAX_GROUP 30

void addStudent();
void deleteStudent();
void modifyStudent();
void searchStudent();
void displayAll();
void groupManagement();
void sortStudents();
void saveToFile();
void loadFromFile();
void freeAllStudents();
int checkDuplicateID(char *id);
void deleteSingle();
void deleteGroup();
void deleteAll(); 

/* 学生信息结构体 */
typedef struct Student {
    char id[MAX_ID];           // 学号
    char name[MAX_NAME];       // 姓名
    char phone[MAX_PHONE];     // 电话号码
    char address[MAX_ADDR];    // 家庭地址
    char postalCode[MAX_POSTAL]; // 邮政编码
    char email[MAX_EMAIL];     // 电子邮件
    char group[MAX_GROUP];     // 所属群组
    struct Student *next;      // 指向下一个节点的指针
} Student;

/* 全局变量 */
Student *head = NULL;          // 链表头指针
int totalCount = 0;            // 总记录数

/* 显示主菜单 */
void showMenu() {
    printf("\n==========================================\n");
    printf("        学生通信录管理系统\n");
    printf("==========================================\n");
    printf("        1. 添加学生记录\n");
    printf("        2. 删除学生记录\n");
    printf("        3. 修改学生记录\n");
    printf("        4. 查询学生记录\n");
    printf("        5. 显示所有记录\n");
    printf("        6. 群组管理\n");
    printf("        7. 排序功能\n");
    printf("        8. 保存数据到文件\n");
    printf("        9. 从文件加载数据\n");
    printf("        0. 退出系统\n");
    printf("==========================================\n");
    printf("请选择操作(0-9): ");
}

/* 主函数 */
int main() {
    int choice;
    
    // 程序启动时自动加载数据
    loadFromFile();
    
    do {
        showMenu();
        scanf("%d", &choice);
        getchar(); // 清除输入缓冲区
        
        switch(choice) {
            case 1: addStudent(); break;
            case 2: deleteStudent(); break;
            case 3: modifyStudent(); break;
            case 4: searchStudent(); break;
            case 5: displayAll(); break;
            case 6: groupManagement(); break;
            case 7: sortStudents(); break;
            case 8: saveToFile(); break;
            case 9: loadFromFile(); break;
            case 0: 
                saveToFile(); // 退出前自动保存
                printf("感谢使用学生通信录管理系统！\n");
                break;
            default: printf("输入错误，请重新选择！\n");
        }
    } while(choice != 0);
    
    // 释放链表内存
    freeAllStudents();
    
    return 0;
}

/* 添加学生记录 */
void addStudent() {
    Student *newStudent, *current;
    char continueFlag;
    
    do {
        newStudent = (Student*)malloc(sizeof(Student));
        if(newStudent == NULL) {
            printf("内存分配失败！\n");
            return;
        }
        
        printf("\n--- 添加学生记录 ---\n");
        
        // 输入学号并检查是否重复
        do {
            printf("请输入学号: ");
            scanf("%s", newStudent->id);
            getchar();
            
            if(checkDuplicateID(newStudent->id)) {
                printf("该学号已存在，请重新输入！\n");
            }
        } while(checkDuplicateID(newStudent->id));
        
        printf("请输入姓名: ");
        scanf("%s", newStudent->name);
        getchar();
        
        printf("请输入电话号码: ");
        scanf("%s", newStudent->phone);
        getchar();
        
        printf("请输入家庭地址: ");
        fgets(newStudent->address, MAX_ADDR, stdin);
        newStudent->address[strcspn(newStudent->address, "\n")] = 0;
        
        printf("请输入邮政编码: ");
        scanf("%s", newStudent->postalCode);
        getchar();
        
        printf("请输入电子邮件: ");
        scanf("%s", newStudent->email);
        getchar();
        
        printf("请输入所属群组: ");
        scanf("%s", newStudent->group);
        getchar();
        
        // 插入链表（尾部插入）
        newStudent->next = NULL;
        
        if(head == NULL) {
            head = newStudent;
        } else {
            current = head;
            while(current->next != NULL) {
                current = current->next;
            }
            current->next = newStudent;
        }
        
        totalCount++;
        printf("学生记录添加成功！\n");
        
        printf("是否继续添加？(y/n): ");
        scanf("%c", &continueFlag);
        getchar();
        
    } while(continueFlag == 'y' || continueFlag == 'Y');
}

/* 检查学号是否重复 */
int checkDuplicateID(char *id) {
    Student *current = head;
    while(current != NULL) {
        if(strcmp(current->id, id) == 0) {
            return 1; // 重复
        }
        current = current->next;
    }
    return 0; // 不重复
}

/* 删除学生记录菜单 */
void deleteStudent() {
    int choice;
    printf("\n--- 删除学生记录 ---\n");
    printf("1. 删除单条记录\n");
    printf("2. 删除整个群组\n");
    printf("3. 删除全部记录\n");
    printf("4. 返回主菜单\n");
    printf("请选择: ");
    scanf("%d", &choice);
    getchar();
    
    switch(choice) {
        case 1: deleteSingle(); break;
        case 2: deleteGroup(); break;
        case 3: deleteAll(); break;
        case 4: return;
        default: printf("输入错误！\n");
    }
}

/* 删除单条记录 */
void deleteSingle() {
    char id[MAX_ID];
    Student *current = head, *prev = NULL;
    
    printf("请输入要删除的学生学号: ");
    scanf("%s", id);
    getchar();
    
    while(current != NULL) {
        if(strcmp(current->id, id) == 0) {
            if(prev == NULL) {
                head = current->next;
            } else {
                prev->next = current->next;
            }
            free(current);
            totalCount--;
            printf("删除成功！\n");
            return;
        }
        prev = current;
        current = current->next;
    }
    printf("未找到该学号的学生记录！\n");
}

/* 删除整个群组 */
void deleteGroup() {
    char group[MAX_GROUP];
    Student *current = head, *prev = NULL, *temp;
    int deletedCount = 0;
    
    printf("请输入要删除的群组名称: ");
    scanf("%s", group);
    getchar();
    
    while(current != NULL) {
        if(strcmp(current->group, group) == 0) {
            if(prev == NULL) {
                head = current->next;
                temp = current;
                current = current->next;
                free(temp);
            } else {
                prev->next = current->next;
                temp = current;
                current = current->next;
                free(temp);
            }
            deletedCount++;
        } else {
            prev = current;
            current = current->next;
        }
    }
    
    if(deletedCount > 0) {
        printf("成功删除 %d 条记录！\n", deletedCount);
        totalCount -= deletedCount;
    } else {
        printf("未找到该群组的记录！\n");
    }
}

/* 删除全部记录 */
void deleteAll() {
    char confirm;
    printf("确定要删除所有记录吗？(y/n): ");
    scanf("%c", &confirm);
    getchar();
    
    if(confirm == 'y' || confirm == 'Y') {
        freeAllStudents();
        head = NULL;
        totalCount = 0;
        printf("所有记录已删除！\n");
    }
}

/* 查询学生记录 */
void searchStudent() {
    int choice;
    printf("\n--- 查询学生记录 ---\n");
    printf("1. 按学号精确查询\n");
    printf("2. 按姓名模糊查询\n");
    printf("3. 按群组查询\n");
    printf("4. 按电话号码查询\n");
    printf("请选择: ");
    scanf("%d", &choice);
    getchar();
    
    switch(choice) {
        case 1: searchByID(); break;
        case 2: searchByName(); break;
        case 3: searchByGroup(); break;
        case 4: searchByPhone(); break;
        default: printf("输入错误！\n");
    }
}

/* 按姓名模糊查询 */
void searchByName() {
    char keyword[MAX_NAME];
    Student *current = head;
    int found = 0;
    
    printf("请输入姓名关键字: ");
    scanf("%s", keyword);
    getchar();
    
    printf("\n查询结果:\n");
    printf("学号\t姓名\t电话\t\t群组\n");
    printf("----------------------------------------\n");
    
    while(current != NULL) {
        if(strstr(current->name, keyword) != NULL) {
            printf("%s\t%s\t%s\t%s\n", 
                   current->id, current->name, 
                   current->phone, current->group);
            found = 1;
        }
        current = current->next;
    }
    
    if(!found) {
        printf("未找到匹配的记录！\n");
    }
}

/* 显示所有记录 */
void displayAll() {
    int choice, pageSize = 10;
    printf("\n--- 显示方式 ---\n");
    printf("1. 列表方式显示\n");
    printf("2. 分页方式显示\n");
    printf("请选择: ");
    scanf("%d", &choice);
    getchar();
    
    if(choice == 1) {
        displayList();
    } else if(choice == 2) {
        displayByPage(pageSize);
    } else {
        printf("输入错误！\n");
    }
}

/* 列表方式显示 */
void displayList() {
    Student *current = head;
    int count = 0;
    
    if(head == NULL) {
        printf("通讯录为空！\n");
        return;
    }
    
    printf("\n学生通信录(共%d条记录):\n", totalCount);
    printf("================================================================================\n");
    printf("序号\t学号\t姓名\t电话\t\t地址\t\t\t群组\n");
    printf("================================================================================\n");
    
    while(current != NULL) {
        count++;
        printf("%d\t%s\t%s\t%s\t%s\t%s\n", 
               count, current->id, current->name, 
               current->phone, current->address, current->group);
        current = current->next;
    }
    printf("================================================================================\n");
}

/* 分页显示 */
void displayByPage(int pageSize) {
    Student *current = head;
    int page = 1, count = 0, totalPages;
    char command;
    
    totalPages = (totalCount + pageSize - 1) / pageSize;
    
    if(head == NULL) {
        printf("通讯录为空！\n");
        return;
    }
    
    do {
        int start = (page - 1) * pageSize;
        int end = page * pageSize;
        int i = 0;
        
        current = head;
        printf("\n第%d页/共%d页:\n", page, totalPages);
        printf("================================================================================\n");
        printf("序号\t学号\t姓名\t电话\t\t群组\n");
        printf("================================================================================\n");
        
        // 定位到当前页起始位置
        while(current != NULL && i < start) {
            current = current->next;
            i++;
        }
        
        // 显示当前页
        while(current != NULL && i < end) {
            printf("%d\t%s\t%s\t%s\t%s\n", 
                   i+1, current->id, current->name, 
                   current->phone, current->group);
            current = current->next;
            i++;
        }
        printf("================================================================================\n");
        
        printf("\n命令: n-下一页, p-上一页, q-退出: ");
        scanf("%c", &command);
        getchar();
        
        if(command == 'n' && page < totalPages) {
            page++;
        } else if(command == 'p' && page > 1) {
            page--;
        }
        
    } while(command != 'q');
}

/* 群组管理 */
void groupManagement() {
    int choice;
    printf("\n--- 群组管理 ---\n");
    printf("1. 查看所有群组\n");
    printf("2. 查看特定群组成员\n");
    printf("3. 重命名群组\n");
    printf("4. 合并群组\n");
    printf("请选择: ");
    scanf("%d", &choice);
    getchar();
    
    switch(choice) {
        case 1: showAllGroups(); break;
        case 2: showGroupMembers(); break;
        case 3: renameGroup(); break;
        case 4: mergeGroups(); break;
        default: printf("输入错误！\n");
    }
}

/* 查看所有群组 */
void showAllGroups() {
    Student *current = head;
    char groups[MAX_GROUP];
    int groupCount = 0, i, j, found;
    
    if(head == NULL) {
        printf("通讯录为空！\n");
        return;
    }
    
    // 收集所有群组名称
    while(current != NULL) {
        found = 0;
        for(i = 0; i < groupCount; i++) {
            if(strcmp(groups[i], current->group) == 0) {
                found = 1;
                break;
            }
        }
        if(!found && strlen(current->group) > 0) {
            strcpy(groups[groupCount], current->group);
            groupCount++;
        }
        current = current->next;
    }
    
    printf("\n所有群组(共%d个):\n", groupCount);
    printf("====================\n");
    for(i = 0; i < groupCount; i++) {
        printf("%d. %s\n", i+1, groups[i]);
    }
}

/* 排序功能 */
void sortStudents() {
    int choice;
    printf("\n--- 排序功能 ---\n");
    printf("1. 按学号排序\n");
    printf("2. 按姓名排序\n");
    printf("3. 按群组排序\n");
    printf("请选择: ");
    scanf("%d", &choice);
    getchar();
    
    switch(choice) {
        case 1: sortByID(); break;
        case 2: sortByName(); break;
        case 3: sortByGroup(); break;
        default: printf("输入错误！\n");
    }
}

/* 按学号排序（冒泡排序） */
void sortByID() {
    if(head == NULL || head->next == NULL) {
        return;
    }
    
    Student *current, *nextNode;
    Student temp;
    int swapped;
    
    do {
        swapped = 0;
        current = head;
        
        while(current->next != NULL) {
            nextNode = current->next;
            
            if(strcmp(current->id, nextNode->id) > 0) {
                // 交换节点数据
                strcpy(temp.id, current->id);
                strcpy(temp.name, current->name);
                strcpy(temp.phone, current->phone);
                strcpy(temp.address, current->address);
                strcpy(temp.postalCode, current->postalCode);
                strcpy(temp.email, current->email);
                strcpy(temp.group, current->group);
                
                strcpy(current->id, nextNode->id);
                strcpy(current->name, nextNode->name);
                strcpy(current->phone, nextNode->phone);
                strcpy(current->address, nextNode->address);
                strcpy(current->postalCode, nextNode->postalCode);
                strcpy(current->email, nextNode->email);
                strcpy(current->group, nextNode->group);
                
                strcpy(nextNode->id, temp.id);
                strcpy(nextNode->name, temp.name);
                strcpy(nextNode->phone, temp.phone);
                strcpy(nextNode->address, temp.address);
                strcpy(nextNode->postalCode, temp.postalCode);
                strcpy(nextNode->email, temp.email);
                strcpy(nextNode->group, temp.group);
                
                swapped = 1;
            }
            current = current->next;
        }
    } while(swapped);
    
    printf("按学号排序完成！\n");
}

/* 排序功能 */
void sortStudents() {
    int choice;
    printf("\n--- 排序功能 ---\n");
    printf("1. 按学号排序\n");
    printf("2. 按姓名排序\n");
    printf("3. 按群组排序\n");
    printf("请选择: ");
    scanf("%d", &choice);
    getchar();
    
    switch(choice) {
        case 1: sortByID(); break;
        case 2: sortByName(); break;
        case 3: sortByGroup(); break;
        default: printf("输入错误！\n");
    }
}

/* 按学号排序（冒泡排序） */
void sortByID() {
    if(head == NULL || head->next == NULL) {
        return;
    }
    
    Student *current, *nextNode;
    Student temp;
    int swapped;
    
    do {
        swapped = 0;
        current = head;
        
        while(current->next != NULL) {
            nextNode = current->next;
            
            if(strcmp(current->id, nextNode->id) > 0) {
                // 交换节点数据
                strcpy(temp.id, current->id);
                strcpy(temp.name, current->name);
                strcpy(temp.phone, current->phone);
                strcpy(temp.address, current->address);
                strcpy(temp.postalCode, current->postalCode);
                strcpy(temp.email, current->email);
                strcpy(temp.group, current->group);
                
                strcpy(current->id, nextNode->id);
                strcpy(current->name, nextNode->name);
                strcpy(current->phone, nextNode->phone);
                strcpy(current->address, nextNode->address);
                strcpy(current->postalCode, nextNode->postalCode);
                strcpy(current->email, nextNode->email);
                strcpy(current->group, nextNode->group);
                
                strcpy(nextNode->id, temp.id);
                strcpy(nextNode->name, temp.name);
                strcpy(nextNode->phone, temp.phone);
                strcpy(nextNode->address, temp.address);
                strcpy(nextNode->postalCode, temp.postalCode);
                strcpy(nextNode->email, temp.email);
                strcpy(nextNode->group, temp.group);
                
                swapped = 1;
            }
            current = current->next;
        }
    } while(swapped);
    
    printf("按学号排序完成！\n");
}

