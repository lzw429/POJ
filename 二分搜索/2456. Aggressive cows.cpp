#include <iostream>
#include <algorithm>

#define MAXN 100010
const int INF = 0x3f3f3f3f;
using namespace std;
int N, M; // 小屋数和奶牛数
int x[MAXN]; // 小屋位置

bool check(int d) { // 判断牛之间的距离是否至少为d
    int last = 0; // 小屋索引
    for (int i = 1; i < M; i++) {
        int cur = last + 1;
        while (cur < N && x[cur] - x[last] < d) {
            cur++;
        }
        if (cur == N) // cur 范围0...N-1
            return false;
        last = cur;
    }
    return true;
}

int main() {
    scanf("%d%d", &N, &M);
    for (int i = 0; i < N; i++)
        scanf("%d", &x[i]);

    sort(x, x + N);
    int lb = 0, ub = INF;
    while (ub - lb > 1) { // 二分搜索
        int mid = (lb + ub) / 2;
        if (check(mid))lb = mid;
        else ub = mid;
    }
    printf("%d\n", lb);
    return 0;
}