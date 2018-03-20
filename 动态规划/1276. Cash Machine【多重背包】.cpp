#include <iostream>

using namespace std;

int cash, N; // N是钞票种数
int n[13], D[13]; // n是钞票数，D是钞票面额
bool dp[100010]; // dp[i]表示

int main() {
    while (scanf("%d%d", &cash, &N)) { // cash 是金额上限
        int ans = 0;
        memset(dp, 0, sizeof(dp));
        for (int i = 0; i < N; i++)
            scanf("%d%d", &n[i], &D[i]);
        dp[0] = 1;
        for (int i = 0; i < n; i++) {
            for (int j = cash; j >= 1; j--) {
                if (dp[j]) {
                    for (int k = 1; k <= n[i]; k++) { // 钞票数
                        if (j + D[i] * k <= cash) {
                            dp[j + D[i] * k] = 1;
                            ans = max(ans, j + D[i] * k);
                        } else break;
                    }
                }
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}