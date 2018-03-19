#include <iostream>
#include <cstring>

using namespace std;

int n, p, q;
bool found;
struct Path {
    int x, y;
} path[30];
bool vis[30][30];
int dir[8][2] = {-2, -1, -2, 1, -1, -2, -1, 2, 1, -2, 1, 2, 2, -1, 2, 1}; // 方向按字典序

void DFS(int x, int y, int step) {
    if (found)
        return;
    path[step].x = x;
    path[step].y = y;
    if (step == p * q) {
        found = true;
        return;
    }
    Path next;
    for (int i = 0; i < 8; i++)   // 8个方向
    {
        next.x = x + dir[i][0];
        next.y = y + dir[i][1];
        if (next.x < 1 || next.y < 1 || next.x > q || next.y > p || vis[next.x][next.y])
            continue;
        vis[next.x][next.y] = true;
        DFS(next.x, next.y, step + 1);
        vis[next.x][next.y] = false;
    }
    return;
}

int main() {
    cin >> n;
    for (int c = 1; c <= n; c++) {
        // 初始化
        cin >> p >> q; // 棋盘坐标字母在前，数字在后；p是数字个数，q是字母个数
        memset(path, 0, sizeof(path));
        memset(vis, false, sizeof(vis));
        found = false;
        vis[1][1] = true;
        for (int i = 1; i <= q; i++) {
            for (int j = 1; j <= p; j++) {
                vis[i][j] = true;
                DFS(i, j, 1);
                vis[i][j] = false;
                if (found)
                    break;
            }
            if (found)
                break;
        }
        cout << "Scenario #" << c << ":" << endl;
        if (!found)
            cout << "impossible" << endl;
        else {
            for (int i = 1; i <= p * q; i++)
                printf("%c%d", 'A' + path[i].x - 1, path[i].y);
            printf("\n");
        }
        if (c != n)
            printf("\n");
    }
    return 0;
}
