#include <cstdio>
#include <iostream>

using namespace std;
int t[1000010]; // 开立方函数
int main() {
    int a, b, c, n;
    for (int i = 1; i <= 100; i++)
        t[i * i * i] = i;
    cin >> n;
    for (a = 2; a <= n; a++) // a * a * a = b * b * b + c * c * c + (a3 - b3- c3)
        for (b = 2; b < a; b++)
            for (c = b; c < a; c++) {
                int a3 = a * a * a;
                int b3 = b * b * b;
                int c3 = c * c * c;
                if (a3 - b3 - c3 > 0 && t[a3 - b3 - c3] >= c) // 第三个数大于c
                    printf("Cube = %d, Triple = (%d,%d,%d)\n", a, b, c, t[a3 - b3 - c3]);
            }
    return 0;
}