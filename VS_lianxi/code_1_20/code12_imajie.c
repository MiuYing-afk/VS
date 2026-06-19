#include <stdio.h>
#include <math.h>

int main() {
    double x, y;
    scanf("%lf %lf", &x, &y);
    
    const double EPSILON = 1e-10;
    
    // 使用更清晰的逻辑判断顺序
    if (fabs(x) < EPSILON) {
        if (fabs(y) < EPSILON) {
            printf("该点在原点");
        } else {
            printf("该点在y轴上");
        }
    } else if (fabs(y) < EPSILON) {
        printf("该点在x轴上");
    } else if (x > 0) {
        printf("该点在第%s象限", y > 0 ? "一" : "四");
    } else {
        printf("该点在第%s象限", y > 0 ? "二" : "三");
    }
    
    return 0;
}
