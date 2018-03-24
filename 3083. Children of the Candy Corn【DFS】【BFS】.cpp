#include <iostream>
#include <queue>
#include <cstring>

#define EDGE 45
using namespace std;
int n, w, h; // n是测试样例数；x范围在h内，y范围在w内
int sx, sy, ex, ey;
char maze[EDGE][EDGE];
const int dl[4][2] = {0, -1, -1, 0, 0, 1, 1, 0}; // 左0 上1 右2 下3
const int dr[4][2] = {0, 1, -1, 0, 0, -1, 1, 0}; // 右0 上1 左2 下3
bool vis[EDGE * EDGE];

int DFS(int x, int y, int d, int step, const int dir[][2]) {
    for (int i = 0; i < 4; i++) {
        int j = (d + 3 + i) % 4;
        int dx = x + dir[j][0]; // 不需要vis标记
        int dy = y + dir[j][1];
        if (dx == ex && dy == ey)
            return step + 1;
        if (dx < 0 || dx >= h || dy < 0 || dy >= w || maze[dx][dy] == '#')
            continue;
        return DFS(dx, dy, j, step + 1, dir);
    }
}

int BFS(int x, int y) { // 最短路
    if (x < 0 || x >= h || y < 0 || y >= w)
        return -1;
    queue<int> q; // 坐标x * w + y
    int lv = 1; // BFS层数
    q.push(x * w + y);
    q.push(-1); // 层间分隔
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        if (cur == -1) {
            lv++;
            if (q.size())
                q.push(-1);
        } else { // if cur != -1
            if (vis[cur]) continue;
            vis[cur] = true;
            int cx = cur / w;
            int cy = cur % w;
            for (int i = 0; i < 4; i++) {
                int dx = cx + dl[i][0];
                int dy = cy + dl[i][1];
                if (dx < 0 || dx >= h || dy < 0 || dy >= w || vis[dx * w + dy] || maze[dx][dy] == '#')
                    continue;
                if (dx == ex && dy == ey)
                    return lv + 1; // cur 是第 lv 层，(dx, dy)是第 lv+1 层
                else if (maze[dx][dy] == '.')
                    q.push(dx * w + dy);
            }
        }
    }
    return lv;
}

int main() {
    int d1, d2;
    scanf("%d", &n);
    while (n--) {
        memset(maze, 0, sizeof(maze));
        memset(vis, false, sizeof(vis));
        scanf("%d%d", &w, &h);
        for (int i = 0; i < h; i++)
            scanf("%s", maze[i]);
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if (maze[i][j] == 'S') {
                    sx = i;
                    sy = j;
                } else if (maze[i][j] == 'E') {
                    ex = i;
                    ey = j;
                }
            }
        }
        // S、E 均在图的边界上，边界除了S、E 均为墙
        // 左墙优先搜索 左0 上1 右2 下3
        // 右墙优先搜索 右0 上1 左2 下3
        if (sx == 0) {
            d1 = d2 = 3;
        } else if (sx == h - 1) {
            d1 = d2 = 1;
        } else if (sy == 0) {
            d1 = 2;
            d2 = 0;
        } else if (sy == w - 1) {
            d1 = 0;
            d2 = 2;
        }
        printf("%d %d %d\n", DFS(sx, sy, d1, 1, dl), DFS(sx, sy, d2, 1, dr), BFS(sx, sy));
    }
    return 0;
}
