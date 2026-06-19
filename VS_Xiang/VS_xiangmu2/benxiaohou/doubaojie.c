#include <stdio.h>
#include <math.h>
// 用于存储字母出现次数的数组
int count[26] = {0};

// 判断一个数是否为质数的函数
int isPrime(int num) {
    // 小于 2 的数不是质数
    if (num < 2) {
        return 0;
    }
    for (int i = 2; i <= sqrt(num); i++) {
        // 如果能被整除，不是质数
        if (num % i == 0) {
            return 0;
        }
    }
    // 是质数
    return 1;
}

int main() {
    char word[101];
    // 输入单词
    scanf("%s", word);

    // 统计每个字母的出现次数
    for (int i = 0; word[i] != '\0'; i++) {
        // 计算字母对应的数组索引（a 对应 0，b 对应 1，...，z 对应 25）
        count[word[i] - 'a']++;
    }

    int maxn = 0, minn = 100;
    // 找出出现次数最多和最少的字母的次数
    for (int i = 0; i < 26; i++) {
        if (count[i] > 0) {
            if (count[i] > maxn) {
                maxn = count[i];
            }
            if (count[i] < minn) {
                minn = count[i];
            }
        }
    }

    int diff = maxn - minn;
    // 判断差值是否为质数
    if (isPrime(diff)) {
        printf("Lucky Word\n%d\n", diff);
    } else {
        printf("No Answer\n0\n");
    }

    return 0;
}