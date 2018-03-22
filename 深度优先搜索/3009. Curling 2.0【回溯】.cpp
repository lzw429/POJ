#include <iostream>

using namespace std;

int w, h; // 宽度和高度
int board[25][25]; // 地图：0空地 1障碍 2开始点 3目标点
const int dir[4][2] = {-1, 0, 1, 0, 0, -1, 0, 1};
int minStep, si, sj;

void DFS(int x, int y, int step) {
    if (step >= 10 || step > minStep)
        return;
    for (int d = 0; d < 4; d++) { // 4个方向
        int cx = x;
        int cy = y;
        while (cx >= 0 && cx < h && cy >= 0 && cy < w) { // while 使石头在某一方向持续运动，直到遇到障碍或到达目的点
            switch (board[cx][cy]) {
                case 0: // 空地，继续运动
                    cx += dir[d][0];
                    cy += dir[d][1];
                    break;
                case 3: // 到达目的点，记录步数
                    if (step + 1 < minStep)
                        minStep = step + 1;
                    cx = -1; // break while，开始下一方向的循环
                    break;
                case 1: // 遇到障碍
                    if (!(cx - dir[d][0] == x && cy - dir[d][1] == y)) {// 石头和障碍之间有空地
                        board[cx][cy] = 0; // 障碍消失
                        DFS(cx - dir[d][0], cy - dir[d][1], step + 1);
                        board[cx][cy] = 1; // 回溯，开始下一方向的循环
                    }
                    cx = -1;
                    break;
                default:
                    break;
            }
        }
    }
}

int main() {
    // 撞击在10次以内，撞到的障碍物将消失
    // 失败条件：撞击超过10次；飞出地图外
    while (scanf("%d%d", &w, &h))   // h行w列
    {
        if (!w && !h)return 0;
        for (int i = 0; i < h; i++)
            for (int j = 0; j < w; j++)
                scanf("%d", &board[i][j]);
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if (board[i][j] == 2) { // 找到开始点坐标
                    si = i;
                    sj = j;
                    break;
                }
            }
        }
        board[si][sj] = 0; // 开始点记为空地
        minStep = 11;
        DFS(si, sj, 0);
        if (minStep > 10) // 未搜到 或 步骤超过10步
            minStep = -1;
        printf("%d\n", minStep);
    }
    return 0;
}
