#include <iostream>

#define MAXM 12890
#define MAXN 3410
using namespace std;

int N, M; // N是物品件数，M是背包最大载重
int W[MAXN], D[MAXN]; // W是物品重量，D是物品价值
int dp[MAXM]; // dp[j]表示载重j内可获取的最大价值

int main() {
    cin>>N>>M;
    for (int i = 0; i < N; i++)
        cin >> W[i] >> D[i];
    for (int i = 0; i < N; i++) {
        for (int j = M; j >= W[i]; j--)
            dp[j] = max(dp[j - W[i]] + D[i], dp[j]);
    }
    cout << dp[M] << endl;
    return 0;
}
