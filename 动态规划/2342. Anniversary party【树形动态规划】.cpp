#include <iostream>

#define MAXN 6010
using namespace std;
int n;
int dp[MAXN][2], par[MAXN]; // dp[i][0]表示不去，dp[i][1]表示去
bool vis[MAXN];

void tree_dp(int node) {
    vis[node] = true;
    for (int i = 1; i <= n; i++) {
        if (!vis[i] && par[i] == node) { // 找到子结点
            tree_dp(i); // 递归调用子结点
            dp[node][1] += dp[i][0]; // 上司来，下属不来
            dp[node][0] += max(dp[i][1], dp[i][0]); // 上司不来，考虑下属
        }
    }
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &dp[i][1]); // 欢乐评级
    int root = 0; // 记录父结点
    int L, K;
    while (scanf("%d%d", &L, &K), L || K) { // K是L的上司
        par[L] = K;
        if (root == L)
            root = K;
    }
    while (par[root])
        root = par[root]; // 找到最大上司
    tree_dp(root);
    printf("%d\n", max(dp[root][0], dp[root][1]));
    return 0;
}
