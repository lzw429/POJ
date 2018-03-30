#include <iostream>
#include <cstring>

#define MAXN 205 // 最大砖头种数
#define MAXM 25 // 一位客户的最大需求
#define MAXC 1010 // 每块砖最大铜含量
const int INF = 0x3f3f3f3f;
using namespace std;
int N, C, M, CMin, CMax;
int c[MAXN], p[MAXN], dp[MAXM][MAXC * MAXM]; // dp[k][j]表示前i个砖头选k个放入铜为j克的背包的费用

int main() {
    scanf("%d", &N); // 砖的种数
    for (int i = 1; i <= N; i++)
        scanf("%d%d", &c[i], &p[i]); // 铜含量与价格

    memset(dp, INF, sizeof(dp));
    dp[0][0] = 0;
    for (int i = 1; i <= N; i++) {
        for (int k = 20; k >= 1; k--) { // 砖头数和铜含量是二维背包
            for (int j = MAXC * MAXM - 1; j >= c[i]; j--)
                // 三维 dp[i][k][j] = min(dp[i - 1][k][j], dp[i - 1][k - 1][j - c[i]] + p[i])
                // 降低为二维，k、j 逆序
                dp[k][j] = min(dp[k][j], dp[k - 1][j - c[i]] + p[i]);
        }
    }

    scanf("%d", &C); // 客户数
    for (int i = 0; i < C; i++) {
        scanf("%d%d%d", &M, &CMin, &CMax); // 欲购买的砖头数，浓度范围
        int ans = INF;
        for (int k = M * CMin; k <= M * CMax; k++)
            ans = min(ans, dp[M][k]);
        if (ans == INF)
            printf("impossible\n");
        else printf("%d\n", ans);
    }
    return 0;
}
