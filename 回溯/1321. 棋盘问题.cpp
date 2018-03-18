#include <iostream>
#include <vector>

#define MAXN 8

using namespace std;

int n, k; // n是棋盘边长，k是棋子数目
int num, ans;

void DFS(int row, vector <vector<char>> &board, bool vis[]) {
    if (num == k) { // 已放置k个棋子

        ans++;
        return;
    }
    if (row == n) {
        return;
    }
    for (int col = 0; col < n; col++) { // 第row行放棋子
        if (board[row][col] == '#' && !vis[col])   // 棋盘内且该列尚未放置过
        {
            vis[col] = true;
            num++;
            DFS(row + 1, board, vis);
            vis[col] = false;
            num--;
        }
    }
    DFS(row + 1, board, vis); // 第row行不放棋子
}

int main() {
    while (cin >> n >> k) {
        if (n == -1 && k == -1)
            return 0;
        // 初始化
        ans = 0, num = 0;
        vector <vector<char>> board(MAXN + 1, vector<char>(MAXN + 1));
        bool vis[MAXN + 3] = {}; // 记录某列是否已放置过棋子
        // 输入
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                cin >> board[i][j];
        // 回溯
        DFS(0, board, vis);
        // 输出
        cout << ans << endl;
    }
    return 0;
}
