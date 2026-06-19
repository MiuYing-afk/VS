#include <stdio.h>
#include <stdlib.h>

// 定义链栈节点结构
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// 定义链栈结构
typedef struct {
    Node* top;  // 栈顶指针
    int size;   // 栈长度
} LinkedStack;

// 1. 初始化链栈
void initStack(LinkedStack* stack) {
    stack->top = NULL;
    stack->size = 0;
}

// 2. 判断是否为空
int isEmpty(LinkedStack* stack) {
    return stack->top == NULL;
}

// 3. 进栈
void push(LinkedStack* stack, int element) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = element;
    newNode->next = stack->top;  // 新节点指向原栈顶
    stack->top = newNode;        // 栈顶指向新节点
    stack->size++;
}

// 4. 出栈
int pop(LinkedStack* stack) {
    if (isEmpty(stack)) {
        return -1; // 题目保证操作合法，无需处理
    }
    Node* temp = stack->top;
    int val = temp->data;
    stack->top = stack->top->next;
    free(temp);
    stack->size--;
    return val;
}

// 5. 取栈顶元素
int top(LinkedStack* stack) {
    return stack->top->data;
}

// 6. 求栈长
int length(LinkedStack* stack) {
    return stack->size;
}

// 7. 遍历栈（栈顶 -> 栈底）
void traverse(LinkedStack* stack) {
    Node* p = stack->top;
    while (p != NULL) {
        printf("%d", p->data);
        if (p->next != NULL) {
            printf(" ");
        }
        p = p->next;
    }
    printf("\n");
}

// 主函数（完全按照题目辅助代码逻辑）
int main() {
    LinkedStack stack;
    initStack(&stack);
    int n, element;
    char operation;

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf(" %c", &operation); // 空格吸收换行符
        switch (operation) {
            case 'i':
                initStack(&stack);
                break;
            case 'e':
                printf("%s\n", isEmpty(&stack) ? "True" : "False");
                break;
            case 'p':
                scanf("%d", &element);
                push(&stack, element);
                break;
            case 'o':
                printf("%d\n", pop(&stack));
                break;
            case 't':
                printf("%d\n", top(&stack));
                break;
            case 'l':
                printf("%d\n", length(&stack));
                break;
            case 'f':
                traverse(&stack);
                break;
            default:
                printf("Invalid operation.\n");
        }
    }
    return 0;
}