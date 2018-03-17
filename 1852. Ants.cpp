#include <iostream>
#include <vector>

using namespace std;

int main() {
    int cases;
    cin >> cases;
    for (int c = 0; c < cases; c++) {
        int L, n; // 长度和蚂蚁数量
        cin >> L >> n;
        vector<int> ants(n + 1, 0); // 蚂蚁初始位置
        for (int i = 0; i < n; i++)
            cin >> ants[i];
        int minT = 0; // 最短时间
        for (int i = 0; i < n; i++)
            minT = max(minT, min(ants[i], L - ants[i]));
        int maxT = 0;
        for (int i = 0; i < n; i++)
            maxT = max(maxT, max(ants[i], L - ants[i]));
        cout << minT << " " << maxT << endl;
    }
    return 0;
}
