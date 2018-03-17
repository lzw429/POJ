#include <iostream>

using namespace std;

int N, M;
char field[110][110];

void DFS(int x, int y) {
    if (x < 0 || y < 0 || x >= N || y >= M || field[x][y] == '.')
        return;
    field[x][y] = '.';
    for (int i = -1; i <= 1; i++)
        for (int j = -1; j <= 1; j++)
            if (!(i == 0 && j == 0))
                DFS(x + i, y + j);
}

int main() {
    int cnt = 0;
    cin >> N >> M;
    for (int i = 0; i < N; i++)
        scanf("%s", field[i]);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (field[i][j] == 'W') {
                cnt++;
                DFS(i, j);
            }
        }
    }
    cout << cnt;
    return 0;
}
