#include <iostream>
#include <vector>

#define MOD 10007
using namespace std;
typedef vector<int> vec;
typedef vector <vec> mat;
typedef long long ll;

// 矩阵乘法
mat mul(mat &A, mat &B) {
    mat C(A.size(), vec(B[0].size()));
    for (int i = 0; i < A.size(); i++) {
        for (int k = 0; k < B.size(); k++) { // B行数和A列数相等
            for (int j = 0; j < B[0].size(); j++) {
                C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % MOD;
            }
        }
    }
    return C;
}

// 计算A^n，A必然是方阵
mat pow(mat A, ll n) {
    mat B(A.size(), vec(A.size()));
    for (int i = 0; i < A.size(); i++) {
        B[i][i] = 1; // 构建单位矩阵
    }
    while (n > 0) {
        if (n & 1) B = mul(B, A);
        A = mul(A, A);
        n >>= 1;
    }
    return B;
}

int main() {
    int T, N;
    scanf("%d", &T);
    while (T--) {
        mat A(3, vec(3));
        A[0][0] = 2;
        A[0][1] = 1;
        A[0][2] = 0;
        A[1][0] = 2;
        A[1][1] = 2;
        A[1][2] = 2;
        A[2][0] = 0;
        A[2][1] = 1;
        A[2][2] = 2;
        scanf("%d", &N);
        A = pow(A, N);
        printf("%d\n", A[0][0]);
    }
    return 0;
}
