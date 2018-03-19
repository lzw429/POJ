#include <iostream>

#define  MAXN 200000
using namespace std;

int N, K; // N个动物，K行描述
int cnt; // 假话数
int F[150010]; // 用于并查集

int find(int x) {
    if (F[x] == x)
        return x;
    return F[x] = find(F[x]);
}

void unite(int x, int y) {
    int fx = find(x);
    int fy = find(y);
    if (fx != fy) {
        F[fx] = fy;
    }
}

int main() {
    scanf("%d%d", &N, &K);
    int D, X, Y;
    for (int i = 0; i <= 3 * N; i++) {
        F[i] = i;
    }
    for (int i = 0; i < K; i++) {
        scanf("%d%d%d", &D, &X, &Y); // 使用cin会超时
        if (X < 0 || X > N || Y < 0 || Y > N) {
            cnt++;
            continue;
        }
        if (D == 1) { // X和Y是同类
            if (find(X) == find(Y + N) || find(X) == find(Y + 2 * N)) { // 如果已知X和Y不是同一类
                cnt++;
            } else {
                unite(X, Y);
                unite(X + N, Y + N);
                unite(X + 2 * N, Y + 2 * N);
            }
        } else if (D == 2) { // X吃Y
            if (find(X) == find(Y) || find(X) == find(Y + 2 * N)) { // 如果已知同一类或者X被Y吃
                cnt++;
            } else {
                unite(X, Y + N);
                unite(X + N, Y + 2 * N);
                unite(X + 2 * N, Y);
            }
        }
    }
    cout << cnt;
    return 0;
}
