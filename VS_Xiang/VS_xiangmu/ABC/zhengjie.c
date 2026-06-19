#include <stdio.h>

int main() {
    int nums[3];
    char order[4];  // 用于存储3个字符的顺序和结束符
    
    // 读取三个整数
    scanf("%d %d %d", &nums[0], &nums[1], &nums[2]);
    
    // 读取输出顺序
    scanf("%s", order);
    
    // 对三个数进行排序 (从小到大)
    // 简单的冒泡排序
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2 - i; j++) {
            if (nums[j] > nums[j + 1]) {
                // 交换两个数
                int temp = nums[j];
                nums[j] = nums[j + 1];
                nums[j + 1] = temp;
            }
        }
    }
    
    // 此时nums[0]=A, nums[1]=B, nums[2]=C
    
    // 按照指定顺序输出
    for (int i = 0; i < 3; i++) {
        switch (order[i]) {
            case 'A': printf("%d", nums[0]); break;
            case 'B': printf("%d", nums[1]); break;
            case 'C': printf("%d", nums[2]); break;
        }
        // 在每个数后输出空格，最后一个数也输出空格（符合题目示例）
        printf(" ");
    }
    printf("\n");
    
    return 0;
}
