#include <iostream>
#include <cstring>

const int MAXN = 110;
const int INF = 0x3f3f3f3f;
using namespace std;
int N, s, e; // 站台数、起点和终点
bool vis[MAXN];
int dist[MAXN]; // 表示从起点到点i的距离
int g[MAXN][MAXN]; // g[i][j] 表示是否连通，0直接连通，1需手动调节，INF不连通

void Dijkstra() {
    memset(vis, false, sizeof(vis));
    for (int i = 1; i <= N; i++)
        dist[i] = g[s][i];
    dist[s] = 0;
    vis[s] = true;

    for (int i = 1; i <= N; i++) { // 循环N次，将所有点标记
        int u, m = INF;
        for (int v = 1; v <= N; v++) { // 在所有未标记的站台，选出dist值最小的u
            if (!vis[v] && dist[v] <= m)
                m = dist[u = v];
        }
        vis[u] = true;
        for (int v = 1; v <= N; v++)
            dist[v] = min(dist[v], dist[u] + g[u][v]);
    }
    if (dist[e] == INF)
        printf("-1\n");
    else
        printf("%d\n", dist[e]);
}

int main() {
    scanf("%d%d%d", &N, &s, &e);
    for (int i = 1; i <= N; i++) {
        dist[i] = INF;
        for (int j = 1; j <= N; j++)
            g[i][j] = INF;
    }
    int p, v; // p铁路数，v铁路通向的目的站台
    for (int u = 1; u <= N; u++) {
        scanf("%d", &p);
        for (int j = 1; j <= p; j++) {
            scanf("%d", &v);
            if (j == 1)g[u][v] = 0; // 默认
            else g[u][v] = 1; // 需手动调节
        }
    }
    Dijkstra();
    return 0;
}
