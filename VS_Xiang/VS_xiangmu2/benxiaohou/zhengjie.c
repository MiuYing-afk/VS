#include <stdio.h>
#include <string.h>

// 判断一个数是否为质数
int isPrime(int n) {
    if (n <= 1) return 0;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return 0;
    }
    return 1;
}

int main() {
    // 字符数组初始化：存储输入的单词和复制后的单词
    char s[100], s_copy[100]; 
    scanf("%s", s);
    
    // 使用strcpy复制字符数组
    strcpy(s_copy, s); 
    
    // 使用strlen获取字符串长度
    int len = strlen(s_copy); 
    
    // 统计每个字母的出现次数（a-z对应下标0-25）
    int count[26] = {0}; // 字符数组初始化，统计次数
    for (int i = 0; i < len; i++) {
        count[s_copy[i] - 'a']++;
    }
    
    // 寻找最大次数maxn和最小次数minn（仅考虑出现过的字母）
    int maxn = 0, minn = 100; // 长度<100，minn初始化为100足够大
    for (int i = 0; i < 26; i++) {
        if (count[i] > 0) { // 只关注出现过的字母
            if (count[i] > maxn) maxn = count[i];
            if (count[i] < minn) minn = count[i];
        }
    }
    
    // 计算差值并判断是否为质数
    int diff = maxn - minn;
    if (isPrime(diff)) {
        printf("Lucky Word\n%d\n", diff);
    } else {
        printf("No Answer\n0\n");
    }
    
    return 0;
}