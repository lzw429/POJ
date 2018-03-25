#include <iostream>

#define MAXN 1000000
const int MOD = 1e9;
using namespace std;
int N;
int a[MAXN];

int main() {
    scanf("%d", &N);
    a[1] = 1;
    a[2] = 2;
    // 当N为奇数时，最小加数为1，a[N] = a[N-1]
    // 当N为偶数时，最小加数为1的集合数等于a[N-1]；最小加数不为1意味着集合中所有数均为偶数，集合数等于a[N/2]
    for (int i = 3; i <= N; i++) {
        if ((i % 2) == 0) // 如果是偶数
            a[i] = a[i / 2];
        a[i] = (a[i] + a[i - 1]) % MOD;
    }
    printf("%d", a[N]);
    return 0;
}
