#include <iostream>
#include <cstring>

#define MAXN 110
#define MAXM 100010
using namespace std;
int n, m;
int A[MAXN], C[MAXN]; // 硬币价值与数量
int dp[MAXM], que[MAXM]; // dp[i]表示能否凑出金额i

int main() {
    while (cin >> n >> m) {
        if (!n && !m)return 0;
        memset(dp, 0, sizeof(dp));
        for (int i = 1; i <= n; i++)
            scanf("%d", &A[i]);
        for (int i = 1; i <= n; i++)
            scanf("%d", &C[i]);

        dp[0] = 1;
        for (int i = 1; i <= n; i++) {
            int maxi = A[i] * C[i]; // 第i种硬币的最大金额
            if (C[i] == 1) { // 转化为 0-1 背包
                for (int j = m; j >= A[i]; j--)
                    dp[j] = max(dp[j], dp[j - A[i]]);
            } else if (maxi >= m) { // 转化为完全背包
                for (int j = A[i]; j <= m; j++)
                    dp[j] = max(dp[j], dp[j - A[i]]);
            } else {
                for (int j = 0; j < A[i]; j++) {
                    int head = 0, tail = 0; // 单调队列的头尾索引
                    for (int k = j; k <= m; k += A[i]) {
                        if (head != tail && k - que[head] > maxi) // 当前种类的硬币凑不够，出队列
                            head++;
                        if (dp[k])
                            que[tail++] = k; // 入队列
                        else if (head != tail)
                            dp[k] = 1; // k 与队列中元素的差是 A[i] 的倍数
                    }
                }
            }
        }
        int ans = 0;
        for (int i = 1; i <= m; i++)
            if (dp[i])
                ans++;
        printf("%d\n", ans);
    }
    return 0;
}
