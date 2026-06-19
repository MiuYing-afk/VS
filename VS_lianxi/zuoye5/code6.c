/*
5. 问需男人、女人、小孩各若干？（穷举法）。
【问题描述】
请编写程序: 有40块砖，40人搬。
男人搬4块，女人搬3块，两个小孩抬一砖。
要求一次全搬完。
问需男人、女人、小孩各若干？（穷举法，给出所有可能的情况）。
【样例输入】
无
【样例输出】
第1种:0个男人,8个女人,32个小孩
第2种: ……
*/

#include<stdio.h>

int main()
{
    int men,women,kids;
    int cnt=1;
    for(men=0;men<10;men++){
        for(women=0;women<13;women++){
            for(kids=0;kids<40;kids++){
                if(men*4+women*3+kids/2==40&&men+women+kids==40&&kids%2==0)
                    printf("第%d种:%d个男人,%d个女人,%d个小孩\n",cnt++,men,women,kids);
            }
        }
    }

    return 0;
}