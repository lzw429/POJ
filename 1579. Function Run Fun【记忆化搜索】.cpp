#include <iostream>

using namespace std;

int a, b, c;
int arr[22][22][22];

int w(int a, int b, int c) {
    if (a <= 0 || b <= 0 || c <= 0)
        return 1;
    if (a > 20 || b > 20 || c > 20)
        return arr[20][20][20];
    if (arr[a][b][c]) // 已计算过 w(a, b, c)
        return arr[a][b][c];
    if (a < b && b < c)
        return arr[a][b][c] = w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c);
    return arr[a][b][c] = w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1);
}

int main() {
    arr[0][0][0] = 1;
    arr[20][20][20] = 1048576;
    while (cin >> a >> b >> c) {
        if (a == b && b == c && c == -1)
            return 0;
        cout << "w(" << a << ", " << b << ", " << c << ") = " << w(a, b, c) << endl;
    }
    return 0;
}
