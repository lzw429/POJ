#include <iostream>
#include <vector>

using namespace std;
typedef vector<int> vec;
typedef vector <vec> mat;

int n, k, m;

mat mul(const mat &A, const mat &B) { // 矩阵乘法

    mat C(A.size(), vec(B[0].size()));
    for (int i = 0; i < A.size(); i++) {
        for (int k = 0; k < B.size(); k++) {
            for (int j = 0; j < B[0].size(); j++)
                C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % m;
        }
    }
    return C;
}

mat pow(mat A, int n) { // 矩阵快速幂 A^n

    mat B(A.size(), vec(A.size()));
    for (int i = 0; i < A.size(); i++)
        B[i][i] = 1; // 构建单位矩阵
    while (n > 0) {
        if (n & 1)
            B = mul(B, A);
        A = mul(A, A);
        n >>= 1;
    }
    return B;
}

int main() {
    scanf("%d%d%d", &n, &k, &m);
    mat A(n, vec(n));
    mat B(n * 2, vec(n * 2));
    // 输入
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &A[i][j]);
            B[i][j] = A[i][j];
        }
        B[n + i][i] = B[n + i][n + i] = 1;
    }
    B = pow(B, k + 1); // I + A + A^2 + ... + A^k
    // 输出
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int a = B[n + i][j] % m;
            if (i == j)     // 减去I
                a = (a + m - 1) % m;
            printf("%d%c", a, (j + 1 == n) ? '\n' : ' '); // 判断是否在行末
        }
    }
    return 0;
}
