#include <iostream>
#include <algorithm>

#define INF 0x3f3f3f3f
using namespace std;

int n, nums[15];
char c;

int comb(int s, int e) {
    int res = 0;
    if (nums[s] == 0) // 首位不能为0
        return INF;
    for (int i = s; i < e; i++)
        res = res * 10 + nums[i];
    return res;
}

int main() {
    scanf("%d\n", &n); // 测试样例数
    while (n--) {
        int size = 0;
        while (scanf("%c", &c), c != '\n') {
            if (c == ' ')
                continue;
            nums[size++] = c - '0'; // 数列升序，每个数字仅出现一次
        }
        int ans = INF;
        if (size == 2)
            ans = nums[1] - nums[0];
        else {
            do {
                // 要使两数之差尽量小，
                // 如果size是偶数，两数的位数应相同；如果size是奇数，两数的位数相差1；两种情况都可用size>>1
                int n1 = comb(0, (size >> 1));
                int n2 = comb((size >> 1), size);
                if (n1 != INF && n2 != INF)
                    ans = min(ans, abs(n1 - n2));
            } while (next_permutation(nums, nums + size));
        }
        printf("%d\n", ans);
    }
    return 0;
}
