#include <iostream>
#include <algorithm>
#include <cstring>

#define MAXN 8
#define MAXM 30
#define INF 1e7
using namespace std;

int n, m, p, a, b; // 车票数，城市数，城市间道路数，起始城市编号，目的城市编号
int t[MAXN + 3]; // 车票上的马力
int d[MAXM + 5][MAXM + 5]; // 图的邻接矩阵，表示两城市之间的距离，-1表示没有边
double dp[1 << MAXN + 5][MAXM + 5]; // dp[S][v]：到达[剩下的车票集合为S]且[处于城市v]的状态所需要的最小花费

int main() {
    while (scanf("%d%d%d%d%d", &n, &m, &p, &a, &b)) {
        if (!n && !m && !a && !b)
            return 0;
        // 输入
        for (int i = 0; i < n; i++)
            scanf("%d", &t[i]);
        memset(d, -1, sizeof(d));
        for (int i = 0; i < p; i++) {
            int x, y, z;
            scanf("%d%d%d", &x, &y, &z); // 城市间道路及其距离
            d[x - 1][y - 1] = d[y - 1][x - 1] = z;
        }
        // 初始化
        for (int i = 0; i < (1 << n); i++)
            fill(dp[i], dp[i] + m, INF);
        dp[(1 << n) - 1][a - 1] = 0; // 在起点城市无需花费
        double res = INF;
        // 动态规划
        for (int S = (1 << n) - 1; S >= 0; S--) {
            res = min(res, dp[S][b - 1]);
            for (int v = 0; v < m; v++)   // 城市v
            {
                for (int i = 0; i < n; i++)   // 车票
                {
                    if ((S >> i) & 1)   // 当前编号为i的车票还未使用
                    {
                        for (int u = 0; u < m; u++) { // 城市u
                            if (d[u][v] >= 0) // 使用车票i从v移动到u可能是到达u的更小花费的方式
                                dp[S & ~(1 << i)][u] = min(dp[S & ~(1 << i)][u], dp[S][v] + (double) d[v][u] / t[i]);
                        }
                    }
                }
            }
        }
        // 输出结果
        if (res == INF)
            printf("Impossible\n"); // 无法到达
        else printf("%.3f\n", res);
    }
    return 0;
}
