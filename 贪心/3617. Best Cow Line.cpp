#include <iostream>
#include <vector>

#define MAXN 2000

using namespace std;

int N;
char S[MAXN + 1];

int main() {
    int N;
    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> S[i];
    int a = 0, b = N - 1, cnt = 0;
    while (a <= b) {
        if (cnt == 80) { // 输出要求
            cnt = 0;
            cout << endl;
        }
        bool left = false;
        for (int i = 0; a + i <= b; i++) {
            if (S[a + i] < S[b - i]) {
                left = true;
                break;
            } else if (S[a + i] > S[b - i]) {
                left = false;
                break;
            }
        }
        if (left)
            cout << S[a++];
        else cout << S[b--];
        cnt++;
    }
    cout << endl;
    return 0;
}
