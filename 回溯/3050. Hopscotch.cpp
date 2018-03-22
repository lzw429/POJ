#include <iostream>
#include <set>
#include<vector>

using namespace std;

int grid[8][8];
set <vector<int>> s; // POJ 不支持 C++ 11 unordered_set

void DFS(int x, int y, int step, vector<int> &num) {
    if (step == 6) {
        s.insert(num);
        return;
    }
    if (x < 0 || y < 0 || x == 5 || y == 5)
        return;
    num.push_back(grid[x][y]);
    // 不需要设置vis标记
    DFS(x + 1, y, step + 1, num);
    DFS(x, y + 1, step + 1, num);
    DFS(x - 1, y, step + 1, num);
    DFS(x, y - 1, step + 1, num);
    num.erase(num.end() - 1); // POJ 不支持 C++ 11 pop_back()
}

int main() {
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
            scanf("%d", &grid[i][j]);
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++) {
            vector<int> num;
            DFS(i, j, 0, num);
        }
    printf("%d", s.size());
    return 0;
}
