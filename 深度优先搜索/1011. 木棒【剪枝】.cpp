#include <iostream>
#include <algorithm>
#include <cstring>

#define MAXN 70
using namespace std;

int n, stick[MAXN], len; // stick记录木棒长度，len为搜索结果
bool vis[MAXN]; // 标记木棒是否已被组合
bool found; // 是否已搜索到结果

bool cmp(int a, int b) {
    return a > b;
}

void DFS(int step, int cur_len, int i) { // i为当前处理的木棒，cur_len为当前正拼接木棒的长度，step为已被拼接的木棒数
    if (found)
        return;
    if (!cur_len) { // 开始拼接新的一根
        int k = 0;
        while (vis[k]) // 找到当前未用的首个最长木棒
            k++;
        vis[k] = true;
        DFS(step + 1, stick[k], k + 1);
        vis[k] = false;
        return;
    }
    if (cur_len == len) {
        if (step == n) // 所有的n根木棒都被拼接
            found = true;
        else
            DFS(step, 0, 0); // 开始拼接下一根
        return;
    }
    for (int j = i; j < n; j++) {
        if (!vis[j] && cur_len + stick[j] <= len) {
            if (!vis[j - 1] && stick[j] == stick[j - 1]) // 剪枝：如果当前木棒和前一木棒等长且前一木棒没有被使用，应该跳过当前木棒
                continue;
            vis[j] = true;
            DFS(step + 1, cur_len + stick[j], j + 1);
            vis[j] = false;
        }
    }
}

int main() {
    while (scanf("%d", &n) && n) {
        int sum = 0;
        found = false;
        for (int i = 0; i < n; i++) {
            scanf("%d", &stick[i]);
            sum += stick[i];
        }
        sort(stick, stick + n, cmp); // 从大到小排序：若两根较长的木棒无法拼接为一定长度，则更短的木棒也无法拼接
        for (len = stick[0]; len < sum; len++) {
            if (sum % len == 0) {
                memset(vis, false, sizeof(vis));
                DFS(0, 0, 0);
                if (found)
                    break;
            }
        }
        printf("%d\n", len);
    }
    return 0;
}
