#include <stdio.h>
#include <string.h>

int main() {
    // 初始化各类字符的计数器
    int upper = 0, lower = 0, digit = 0, space = 0, other = 0;
    char line[1000];  // 存储每行输入
    int lineIndex = 0;
    int c;
    
    while (1) {
        c = getchar();  // 逐个读取字符
        
        // 遇到换行符或文件结束符时，处理当前行
        if (c == '\n' || c == EOF) {
            line[lineIndex] = '\0';  // 字符串结束符
            
            // 检查是否是结束标记"end"
            if (strcmp(line, "end") == 0) {
                break;
            }
            
            // 统计当前行的各类字符
            for (int i = 0; line[i] != '\0'; i++) {
                char ch = line[i];
                if (ch >= 'A' && ch <= 'Z') {
                    upper++;  // 大写字母
                } else if (ch >= 'a' && ch <= 'z') {
                    lower++;  // 小写字母
                } else if (ch >= '0' && ch <= '9') {
                    digit++;  // 数字
                } else if (ch == ' ') {
                    space++;  // 空格
                } else {
                    other++;  // 其他字符
                }
            }
            
            lineIndex = 0;  // 重置行索引，准备读取下一行
        } else {
            // 将字符添加到当前行
            if (lineIndex < 999) {  // 防止缓冲区溢出
                line[lineIndex++] = c;
            }
        }
    }
    
    // 输出统计结果
    printf("%d %d %d %d %d\n", upper, lower, digit, space, other);
    
    return 0;
}