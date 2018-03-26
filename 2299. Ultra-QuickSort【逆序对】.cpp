#include <iostream>
#include <algorithm>

const int MAXN = 500010;
using namespace std;
int n, a[MAXN];
long long ans;

void merge(int l, int mid, int r) {
    int i = l, j = mid + 1;
    while (i <= mid && j <= r) {
        if (a[i] <= a[j])
            i++;
        else {
            j++;
            ans += mid - i + 1; // 左右两区间都是有序的，a[i]>a[j] 表示 a[i]~a[mid] 均大于 a[j]
        }
    }
    sort(a + l, a + r + 1); // 对a[l] ~ a[r]排序
    return;
}

void mergeSort(int l, int r) {
    if (l < r) {
        int mid = (l + r) / 2;
        mergeSort(l, mid);
        mergeSort(mid + 1, r);
        merge(l, mid, r);
    }
    return;
}

int main() {
    while (scanf("%d", &n) != EOF) {
        if (!n)return 0;
        for (int i = 0; i < n; i++)
            scanf("%d", &a[i]);
        // 使用归并排序的方法求数列的逆序对数
        ans = 0;
        mergeSort(0, n - 1);
        printf("%lld\n", ans);
    }
    return 0;
}
