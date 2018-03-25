#include <cstdio>
#include <cstring>

using namespace std;
int num[64];

int main() {
    int cases;
    scanf("%d", &cases);

    for (int c = 1; c <= cases; c++) {
        int n, p = 0;
        memset(num, 0, sizeof(num));
        scanf("%d", &n);
        // 找出所有使得 a*b = n^2 的整数对(a, b)，即求 n^2 的约数个数
        // 约数个数是奇数是因为 n 是 n^2 的约数，但 n 作为一个数只被计算了一次
        // 设 n^2 约数个数是p，(p + 1) / 2 即原方程解的个数，注意 x <= y
        // 要找 n^2 约数个数，可以通过找 n 的约数
        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0) { // i 是 n 的因子
                while (n % i == 0) {
                    num[p]++; // 一个因子的幂可能也是因子
                    n /= i;
                }
                p++;
            }
        }
        if (n != 1) { // 余下一个因子
            num[p]++;
            p++;
        }
        for (int i = 0; i < p; i++)
            num[i] *= 2; // n 的因子全部重复一次就是 n^2 的因子
        int ans = 1;
        for (int i = 0; i < p; i++)
            ans *= (num[i] + 1);
        printf("Scenario #%d:\n%d\n\n", c, (ans + 1) / 2);
    }
    return 0;
}
