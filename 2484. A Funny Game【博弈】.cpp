#include <iostream>

using namespace std;

int main() {
    int n;
    bool first = true;
    while (scanf("%d", &n)) {
        if (!n)
            return 0;
        if (!first)
            printf("\n");
        if (n <= 2)
            printf("Alice");
        else
            printf("Bob");
        first = false;
    }
    return 0;
}
