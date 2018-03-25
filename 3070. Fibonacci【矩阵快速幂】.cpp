#include <iostream>
#include <vector>

#define MOD 10000
using namespace std;
typedef vector<int> vec;
typedef vector <vec> mat;

mat mul(const mat &A, const mat &B) {
    mat C(A.size(), vec(B[0].size()));
    for (int i = 0; i < A.size(); i++) {
        for (int k = 0; k < B.size(); k++) {
            for (int j = 0; j < B[0].size(); j++) {
                C[i][j] = (C[i][j] + (A[i][k] * B[k][j]) % MOD) % MOD;
            }
        }
    }
    return C;
}

mat pow(mat A, int n) {
    mat An(A.size(), vec(A.size()));
    // An 初始化为单位矩阵
    for (int i = 0; i < A.size(); i++)
        An[i][i] = 1;
    while (n > 0) {
        if (n & 1)
            An = mul(A, An);
        A = mul(A, A);
        n >>= 1;
    }
    return An;
}

int main() {
    int n;
    mat Fib(2, vec(2));
    mat ans(2, vec(2));
    Fib[0][0] = 1;
    Fib[0][1] = 1;
    Fib[1][0] = 1;
    Fib[1][1] = 0;
    while (scanf("%d", &n) != EOF) {
        if (n == -1)
            return 0;

        ans = pow(Fib, n);
        printf("%d\n", ans[0][1]);
    }
    return 0;
}
