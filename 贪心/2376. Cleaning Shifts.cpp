#include <iostream>
#include <algorithm>

#define MAXN 25010
using namespace std;
int N, T;
struct Cow {
    int s, e; // 开始时间，结束时间
} cow[MAXN];

bool cmp(Cow a, Cow b) {
    if (a.s == b.s)
        return a.e > b.e;
    return a.s < b.s;
}

int main() {
    // 最小区间覆盖问题
    scanf("%d%d", &N, &T); // N是区间数，T是区间长度
    for (int i = 0; i < N; i++)
        scanf("%d%d", &cow[i].s, &cow[i].e);
    sort(cow, cow + N, cmp);
    if (cow[0].s > 1) { // 不能覆盖第一个时间段
        printf("-1");
        return 0;
    }
    int end = 0, ans = 0, cur_cow = 0;
    while (end < T) { // 每循环一次，加一个区间
        int start = end + 1; // 下一区间的起始位置必须在start前
        for (int i = cur_cow; i < N; i++)
            if (cow[i].s <= start && cow[i].e >= start) // 区间长度可能为1
                end = (end > cow[i].e) ? end : cow[i].e;
            else if (cow[i].s > start) {
                cur_cow = i; // 与当前区间连不上，留作下次循环
                break;
            }
        if (start > end) // 查找后续区间后，max没有后移，即找不到解
            break;
        else ans++;
    }
    if (end < T)
        ans = -1;
    printf("%d", ans);
    return 0;
}
