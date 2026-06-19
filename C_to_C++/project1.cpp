#include<iostream>
#include<cstring>   //把.h改为开头加c

using namespace std;

int main(void)
{
    int n;
    cin >> n;     //等价于scanf("%d",&n);
    cout << "hello world!" << n++ << endl;
        /*
            cout  ==  printf
            endl  ==  "\n"
        */

        /*
            在没有 using namespace std 时，要写成
                std::cin >> n;
                std::cout << "hello world!";
                std::cout << std::endl;
        */

    /* bool变量：将0解释为 false(0),将非0解释为 ture(1) */

    bool flag1 = true;
    bool flag2 = -1;
    bool flag3 = false;
    bool flag4 = 0;
    cout << flag1 << " " << flag2 << " " << flag3 << " " << flag4 << endl;


    return 0;
}