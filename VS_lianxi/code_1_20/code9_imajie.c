#include <stdio.h>

int main() {
    int n;
    double zong = 0.0;
    
    scanf("%d", &n);
    
    // 将利润转换为等级（以10万元为单位）
    int level = n / 100000;
    if (level > 10) level = 10;  // 超过100万统一处理
    
    switch (level) {
        case 0:  // profit ≤ 10万
            zong = n * 0.10;
            break;
            
        case 1:  // 10万 < profit ≤ 20万
            zong = 100000 * 0.10 + (n - 100000) * 0.075;
            break;
            
        case 2:  // 20万 < profit ≤ 40万
        case 3:
            zong = 100000 * 0.10 + 100000 * 0.075 + (n - 200000) * 0.05;
            break;
            
        case 4:  // 40万 < profit ≤ 60万
        case 5:
            zong = 100000 * 0.10 + 100000 * 0.075 + 200000 * 0.05 + (n - 400000) * 0.03;
            break;
            
        case 6:  // 60万 < profit ≤ 100万
        case 7:
        case 8:
        case 9:
            zong = 100000 * 0.10 + 100000 * 0.075 + 200000 * 0.05 + 200000 * 0.03 + (n - 600000) * 0.015;
            break;
            
        case 10:  // profit > 100万
            zong = 100000 * 0.10 + 100000 * 0.075 + 200000 * 0.05 + 200000 * 0.03 + 400000 * 0.015 + (n - 1000000) * 0.01;
            break;
    }
    
    printf("%.2lf\n", zong);
    
    return 0;
}
