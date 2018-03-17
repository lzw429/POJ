#include <iostream>

#define MAXN 110
using namespace std;
int line, ans = 0;
int a[MAXN][MAXN]; // 三角形中的数字范围[0, 99]
int dp[MAXN][MAXN]; // 自底向上，dp[i][j]表示从(i, j)到底部的最大数字和

int DP(int i, int j) {
    if (dp[i][j])
        return dp[i][j];
    if (i == line - 1) { // 最后一行
        return dp[i][j] = a[i][j];
    }
    return dp[i][j] = max(DP(i + 1, j), DP(i + 1, j + 1)) + a[i][j];
}

int main() {
    cin >> line; // 行数范围[1, 100]
    for (int i = 0; i < line; i++)
        for (int j = 0; j <= i; j++)
            cin >> a[i][j];
    cout << DP(0, 0);;
    return 0;
}
