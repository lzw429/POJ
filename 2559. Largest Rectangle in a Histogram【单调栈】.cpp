#include <iostream>

#define MAXN 100010
using namespace std;

int n, h[MAXN];
int L[MAXN], R[MAXN];
int st[MAXN]; // 单调栈

int main() {
    while (scanf("%d", &n), n) {
        for (int i = 0; i < n; i++)
            scanf("%d", &h[i]); // 大量输入，使用scanf而不是cin
        // 计算L
        int t = 0; // 栈的大小
        for (int i = 0; i < n; i++) {
            while (t > 0 && h[st[t - 1]] >= h[i])
                t--;
            L[i] = (t == 0) ? 0 : (st[t - 1] + 1); // L[i]=(j<=i并且h[j-1]<h[i]的最大的j)
            st[t++] = i;
        }
        // 计算R
        t = 0; // 栈清空
        for (int i = n - 1; i >= 0; i--) {
            while (t > 0 && h[st[t - 1]] >= h[i])
                t--;
            R[i] = (t == 0) ? n : st[t - 1]; // R[i]=(j>i并且h[j]>h[i]的最小的j)
            st[t++] = i;
        }
        // 找出最大面积
        long long res = 0; // 注意防止溢出
        for (int i = 0; i < n; i++)
            res = max(res, (long long) h[i] * (R[i] - L[i]));
        printf("%lld\n", res);
    }
    return 0;
}
