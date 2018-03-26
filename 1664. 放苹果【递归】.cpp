#include <iostream>

using namespace std;

int t, M, N, ans;

int Apple(int m, int n) {
    if (m == 0 || n == 1) // 一个盘子或无苹果
        return 1;
    if (m < n)
        return Apple(m, m); // m个苹果最多分到m个盘子里
    return Apple(m - n, n) + Apple(m, n - 1); // n个盘子全放 + 在(n-1)个盘子内放
}

int main() {
    cin >> t; // 测试数据数量
    while (t--) {
        cin >> M >> N; // M个同样的苹果放在N个同样的盘子里
        cout << Apple(M, N) << endl;
    }
    return 0;
}