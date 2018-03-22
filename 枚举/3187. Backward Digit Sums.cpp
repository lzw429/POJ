#include <iostream>
#include <algorithm>

using namespace std;
int n, sum;
int nums[15];
int a[15];
int b[15];
// a、b 放在getSum()中作初始化过的局部数组会WA，如果你知道原因请提Issue

int getSum() {
    int size = n;
    for (int i = 0; i < n; i++)
        a[i] = nums[i];
    while (size > 1) {
        for (int i = 0; i < size - 1; i++)
            b[i] = a[i] + a[i + 1];
        size--;
        if (size == 1)
            return b[0];
        for (int i = 0; i < size - 1; i++)
            a[i] = b[i] + b[i + 1];
        size--;
        if (size == 1)
            return a[0];
    }
}

int main() {
    scanf("%d%d", &n, &sum);
    for (int i = 0; i < n; i++)
        nums[i] = i + 1;
    do {
        if (getSum() == sum) {
            for (int i = 0; i < n; i++)
                printf("%d ", nums[i]);
            return 0;
        }
    } while (next_permutation(nums, nums + n));
    return 0;
}
