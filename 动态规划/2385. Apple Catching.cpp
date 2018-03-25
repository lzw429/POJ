#include <iostream>
#include <cstring>

#define MAXT 1010
#define MAXW 35
using namespace std;
int T, W; // 掉落时间和最大移动次数
int dp[MAXT][MAXW]; // 前i秒移动j次能获取的最大苹果数
int fall[2][MAXT]; // fall[i][t] 表示第(i+1)棵树第t秒是否有苹果下落

int main() {
    memset(fall, false, sizeof(fall));
    memset(dp, 0, sizeof(dp));
    scanf("%d%d", &T, &W);
    for (int i = 1; i <= T; i++) {
        int tree;
        scanf("%d", &tree);
        fall[tree - 1][i] = 1;
    }
    dp[1][0] = fall[0][1]; // 从树1开始
    dp[1][1] = fall[1][1];
    for (int i = 2; i <= T; i++) { // 时间
        for (int j = 0; j <= W && j <= i; j++) { // 移动次数
            if (j == 0)
                dp[i][j] = dp[i - 1][j] + fall[0][i];
            else
                dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]) + fall[j % 2][i];
        }
    }
    printf("%d\n", dp[T][W]);
    return 0;
}
