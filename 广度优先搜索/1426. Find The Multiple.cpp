#include <iostream>

bool found;
using namespace std;

int n;

void DFS(unsigned long long num, int step) {
    if (found || step == 19) // 该搜索深度足够
        return;
    if ((num % n) != 0) {
        DFS(num * 10, step + 1);
        DFS(num * 10 + 1, step + 1);
    } else {
        printf("%I64u\n", num);
        found = true;
    }
}

int main() {
    while (scanf("%d", &n)) {
        if (!n)
            return 0;
        found = false;
        DFS(1, 0);
    }
    return 0;
}
