#include <iostream>

using namespace std;

int cash, N;
int n[13], D[13]; // n是钞票数，D是钞票面额
int dp[100010];

int main() {
    while (cin >> cash >> N) {
        int ans = 0;
        for (int i = 0; i < N; i++) {
            cin >> n[i] >> D[i];
        }

        cout << ans << endl;
    }
    return 0;
}