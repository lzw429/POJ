#include <iostream>
#include <queue>
#include <algorithm>

const int MAXN = 2510;
using namespace std;
int C, L; // C头牛，L瓶防晒霜
pair<int, int> cow[MAXN]; // minSPF & maxSPF
pair<int, int> bot[MAXN]; // SPF & cover
priority_queue<int, vector<int>, greater<int> > q; // 小顶堆

int main() {
    scanf("%d%d", &C, &L);
    for (int i = 0; i < C; i++)
        scanf("%d%d", &cow[i].first, &cow[i].second);
    for (int i = 0; i < L; i++)
        scanf("%d%d", &bot[i].first, &bot[i].second);
    sort(cow, cow + C);
    sort(bot, bot + L);
    // 贪心策略是让maxSPF较小的奶牛用SPF较小的防晒霜
    int cur = 0; // 正等待涂霜的奶牛的索引
    int ans = 0; // 可满足的最大奶牛数
    for (int i = 0; i < L; i++) { // 遍历防晒霜
        while (cur < C && cow[cur].first <= bot[i].first) { // 奶牛minSPF 满足这种防晒霜
            q.push(cow[cur].second); // 将该奶牛的 maxSPF 入堆
            cur++;
        }
        while (!q.empty() && bot[i].second) { // 队列非空 且 该种防晒霜还有剩余
            int maxSPF = q.top();
            q.pop();
            if (maxSPF >= bot[i].first) { // 奶牛maxSPF 满足这种防晒霜
                ans++;
                bot[i].second--; // 防晒霜数量减1
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}
