#include <iostream>
#include<algorithm>

using namespace std;

int N, R;

int main() {
    while (cin >> R >> N) {
        if (R == -1 && N == -1)
            return 0;
        int ans = 0;
        int X[1010] = {0};
        for (int i = 0; i < N; i++)
            cin >> X[i];

        sort(X, X + N);
        int i = 0;
        while (i < N) {
            int s = X[i++]; // s 是没有被覆盖的最左的点的位置
            // 一直向右前进，直到距s的距离大于R的点
            while (i < N && X[i] <= s + R)
                i++;
            int p = X[i - 1]; // p 是新加上标记的点的位置
            // 一直向右前进，直到距p的距离大于R的点
            while (i < N && X[i] <= p + R)
                i++;
            ans++; // p 标记最左覆盖到s，最右覆盖到i
        }
        cout << ans << endl;
    }
    return 0;
}
