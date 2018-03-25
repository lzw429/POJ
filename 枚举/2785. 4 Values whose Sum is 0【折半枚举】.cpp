#include <iostream>
#include <algorithm>

#define MAXN 4010
using namespace std;
int A[MAXN], B[MAXN], C[MAXN], D[MAXN];
int CD[MAXN * MAXN]; // C和D中数字的组合方法

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d%d%d%d", &A[i], &B[i], &C[i], &D[i]);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            CD[i * n + j] = C[i] + D[j];

    sort(CD, CD + n * n);
    long long res = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int cd = -(A[i] + B[j]); // CD 中的查找目标
            res += upper_bound(CD, CD + n * n, cd) - lower_bound(CD, CD + n * n, cd);
            // lower_bound 返回 CD 中等于 cd 的首个元素的索引
            // upper_bound 返回 CD 中大于 cd 的首个元素的索引
        }
    }
    printf("%lld\n", res);
    return 0;
}
