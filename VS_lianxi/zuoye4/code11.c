/*
11. 最好的赛车
【问题描述】
有4名专家对4款赛车进行评论。
A说：2号赛车是最好的。
B说：4号赛车是最好的。
C说：3号赛车不是最好的。
D说：B说错了。
事实上只有一款赛车是最好的，且只有一名专家说对了，其他3人都说错了，编程输出最好的赛车编号。
【输入形式】
无
【输出形式】
参见样例输出
【样例输入】
无
【样例输出】
最好的赛车编号为3
*/

#include <stdio.h>
int main() {
    // 枚举最好的赛车编号（1 - 4）
    for (int best = 1; best <= 4; best++) {
        // 专家 A 的判断：2 号是最好的
        int a_right = (best == 2);
        // 专家 B 的判断：4 号是最好的
        int b_right = (best == 4);
        // 专家 C 的判断：3 号不是最好的
        int c_right = (best != 3);
        // 专家 D 的判断：B 说错了（即 B 的判断为假）
        int d_right = !b_right;

        // 统计说对的专家人数
        int count = a_right + b_right + c_right + d_right;

        // 若只有 1 名专家说对，输出结果并结束程序
        if (count == 1) {
            printf("最好的赛车编号为%d\n", best);
            return 0;
        }
    }
    return 0;
}
