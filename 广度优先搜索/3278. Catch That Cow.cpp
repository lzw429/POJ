#include <iostream>
#include <queue>

#define MAXN 100010
using namespace std;
int N, K; // FJ开始的位置和牛的位置
queue<int> q;
bool vis[MAXN];

int main() {
    int lv = 1;
    scanf("%d%d", &N, &K);
    q.push(N);
    q.push(-1);
    if (N >= K) { // 不要漏掉等于的情况！
        printf("%d", N - K);
        return 0;
    }
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        if (cur == -1) {
            lv++;
            if (q.size())
                q.push(-1);
        } else {
            if (vis[cur])continue;
            vis[cur] = true;
            if (cur - 1 == K || cur + 1 == K || cur * 2 == K)
                break;
            else {
                if (cur > 0) // 不能往负数搜
                    q.push(cur - 1);
                if (cur < K) {
                    q.push(cur + 1);
                    if (cur <= 50000) // 小心数组越界
                        q.push(cur * 2);
                }
            }
        }
    }
    printf("%d", lv);
    return 0;
}
