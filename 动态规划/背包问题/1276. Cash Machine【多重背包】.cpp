#include <iostream>
#include <cstring>

using namespace std;

int cash, N; // N是钞票种数
int n[13], D[13]; // n是钞票数，D是钞票面额；
int dp[100010];

int main() {
    while (scanf("%d%d", &cash, &N) != EOF) { // cash 是金额上限，本题的重量和价值合一，金额上限可理解为背包重量上限
        // 输入与初始化
        for (int i = 0; i < N; i++)
            scanf("%d%d", &n[i], &D[i]);
        memset(dp, 0, sizeof(dp));
        // 多重背包
        for (int i = 0; i < N; i++) {  // 第i种钞票
            if (n[i] * D[i] > cash) { // 钞票充足，套用完全背包
                for (int j = D[i]; j <= cash; j++) { // j是重量
                    dp[j] = max(dp[j], dp[j - D[i]] + D[i]);
                }
            } else { // if n[i] * D[i] <= cash
                int num = n[i]; // 剩余钞票数
                for (int k = 1; num > 0; k <<= 1) {  // 钞票数；使用二进制优化，k为2的幂，依次0-1背包，可凑出任意数值
                    int mul = min(k, num);
                    for (int j = cash; j >= mul * D[i]; j--) { // j是重量
                        dp[j] = max(dp[j], dp[j - mul * D[i]] + mul * D[i]);
                    }
                    num -= mul;
                }
            }
        }
        // 输出
        printf("%d\n", dp[cash]);
    }
    return 0;
}
