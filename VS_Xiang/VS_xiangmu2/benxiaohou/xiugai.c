#include<stdio.h>
#include<math.h>

int cha;  // 用int变量存储最大次数与最小次数的差值，去掉指针

// 函数声明移到main外面
void LuckWord(char word[]);  // 不需要返回值，改为void
void zhishu(int cha);        // 参数改为int，不需要指针

int main()
{
    char word[101];
    scanf("%s", word);
    LuckWord(word);  // 调用统计函数
    return 0;
}

// 统计每个字母的出现次数，计算最大-最小次数的差值
void LuckWord(char word[])
{
    int count[26] = {0};  // 存储a-z每个字母的出现次数
    // 第一步：统计每个字母出现的次数
    for(int i = 0; word[i] != '\0'; i++){
        int index = word[i] - 'a';  // 字母转索引（a->0, b->1...z->25）
        count[index]++;
    }
    // 第二步：找最大次数和最小次数（只统计出现过的字母）
    int maxn = 0, minn = 100;  // minn初始值设大一点
    for(int i = 0; i < 26; i++){
        if(count[i] > 0){  // 只考虑出现过的字母
            if(count[i] > maxn) maxn = count[i];
            if(count[i] < minn) minn = count[i];
        }
    }
    // 计算差值，传给cha
    cha = maxn - minn;
    // 调用质数判断函数
    zhishu(cha);
}

// 判断差值是否为质数，并输出结果
void zhishu(int cha)
{
    // 小于2的数不是质数
    if(cha < 2){
        printf("No Answer\n0");
        return;
    }
    // 从2到sqrt(cha)判断是否能被整除
    for(int i = 2; i <= sqrt(cha); i++){  // 补充i的类型int
        if(cha % i == 0){
            printf("No Answer\n0");
            return;  // 不是质数，直接返回
        }
    }
    // 能走到这一步，说明是质数
    printf("Lucky Word\n%d", cha);
}