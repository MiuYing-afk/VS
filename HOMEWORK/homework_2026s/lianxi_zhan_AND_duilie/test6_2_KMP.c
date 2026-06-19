#include <stdio.h>
#include <string.h>

// 1. 生成next数组
void getNext(char* pattern, int* next) {
    int len = strlen(pattern);
    next[0] = -1;  // 第一个元素固定为-1
    int i = 0, j = -1;
    
    while (i < len - 1) {
        if (j == -1 || pattern[i] == pattern[j]) {
            // 匹配成功，指针后移，记录next值
            i++;
            j++;
            next[i] = j;
        } else {
            // 不匹配，j回退
            j = next[j];
        }
    }
}

// 2. KMP匹配函数
// 返回模式串在主串中首次出现的起始下标，没找到返回-1
int KMP(char* text, char* pattern) {
    int textLen = strlen(text);    // 主串长度
    int patLen = strlen(pattern);  // 模式串长度
    int i = 0;  // 主串指针（永不回退）
    int j = 0;  // 模式串指针
    
    // 创建next数组
    int next[patLen];
    getNext(pattern, next);
    
    while (i < textLen && j < patLen) {
        if (j == -1 || text[i] == pattern[j]) {
            // 匹配成功，两个指针都后移
            i++;
            j++;
        } else {
            // 匹配失败，模式串指针按next数组回退
            j = next[j];
        }
    }
    
    // 匹配完成：返回起始下标
    if (j == patLen) {
        return i - j;
    }
    // 未匹配到
    return -1;
}

// 3. 测试
int main() {
    char text[] = "ABABCABCABABD";   // 主串
    char pattern[] = "ABABD";        // 模式串
    
    int index = KMP(text, pattern);
    
    if (index != -1) {
        printf("匹配成功！起始下标：%d\n", index);
    } else {
        printf("未找到匹配的子串\n");
    }
    
    return 0;
}