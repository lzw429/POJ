#include <iostream>
#include <cstring>

#define MAXN 25
using namespace std;

int W, H, cnt;
char map[MAXN][MAXN];

void DFS(int x, int y) {
    if (x < 0 || x >= H || y < 0 || y >= W || map[x][y] == '#')
        return;
    cnt++;
    map[x][y] = '#'; // vis标记
    DFS(x + 1, y);
    DFS(x - 1, y);
    DFS(x, y + 1);
    DFS(x, y - 1);
    return;
}

int main() {
    while (scanf("%d%d", &W, &H)) {
        if (!W && !H)return 0;
        int x, y; // 记录@坐标
        cnt = 0;
        memset(map, '.', sizeof(map));
        for (int i = 0; i < H; i++) {
            scanf("%s", map[i]);
        }
        for (int i = 0; i < H; i++) {
            for (int j = 0; j < W; j++) {
                if (map[i][j] == '@') {
                    x = i, y = j;
                }
            }
        }
        DFS(x, y);
        printf("%d\n", cnt);
    }
    return 0;
}
