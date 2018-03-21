#include <iostream>
#include <climits>

#define MAXN 105
using namespace std;
int N;
const int M = 100005; // TS或TF最大为100000
int S[MAXN], F[MAXN];
int dp[2 * M]; // dp[i]表示S值为i时F的最大值；坐标平移：负数在前，正数在后
// 将S看做代价，F看做价值，0-1背包求解

int main() {
    while (scanf("%d", &N) != EOF) {
        for (int i = 0; i < N; i++)
            scanf("%d%d", &S[i], &F[i]);
        for (int i = 0; i < 2 * M; i++)
            dp[i] = INT_MIN;
        dp[100000] = 0; // 0前有十万个负数，0后有十万个正数

        for (int i = 0; i < N; i++) {
            if (S[i] >= 0) {
                for (int j = 2 * M - 1; j >= S[i]; j--) {
                    if (dp[j - S[i]] > INT_MIN) // 背包重量为 j - S[i] 的情况存在
                        dp[j] = max(dp[j], dp[j - S[i]] + F[i]);
                }
            } else { // if S[i] < 0，如果放入背包，背包变轻，逆序遍历
                for (int j = S[i]; j - S[i] < 2 * M; j++) {
                    if (dp[j - S[i]] > INT_MIN)
                        dp[j] = max(dp[j], dp[j - S[i]] + F[i]);
                }
            }
        }

        int ans = INT_MIN;
        for (int i = 100000; i < 2 * M; i++) {
            if (dp[i] >= 0)
                ans = max(ans, dp[i] + i - 100000); // dp[i] + i 即 TS + TF，然后恢复坐标平移
        }
        printf("%d\n", ans);
    }
    return 0;
}
