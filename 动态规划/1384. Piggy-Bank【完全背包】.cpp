#include <iostream>

#define MAXN 510
#define MAXW 10010
#define INF 1e9
using namespace std;

int T; // 测试用例数
int E, F; // 空罐重量和满罐重量
int N; // 硬币种数，每种个数无限
int P[MAXN], W[MAXN]; // 硬币价值与硬币重量
int dp[MAXW]; // 使用滚动数组，dp[i]表示总重量为i的硬币的最小价值

int main() {
    cin >> T;
    while (T--) {
        cin >> E >> F >> N;
        int weight = F - E; // 硬币重量需恰好等于weight
        // 输入数据
        for (int i = 0; i < N; i++)
            cin >> P[i] >> W[i];
        // dp初始化
        for (int i = 0; i <= weight; i++)
            dp[i] = INF;
        dp[0] = 0;
        // 递推过程
        for (int i = 0; i < N; i++)
            for (int j = W[i]; j <= weight; j++)
                dp[j] = min(dp[j], dp[j - W[i]] + P[i]);
        // 输出结果
        if (dp[weight] == INF)
            cout << "This is impossible." << endl;
        else
            cout << "The minimum amount of money in the piggy-bank is " << dp[weight] << "." << endl;
    }
    return 0;
}
