#include <iostream>
using namespace std;

int R, C, res;
int a[110][110];
int dp[110][110];
int dir[5][3]= {{-1,0},{1,0},{0,-1},{0,1}};

int DFS(int x, int y)
{
    if(dp[x][y]) // ÒÑ¼ÆËã¹ıDFS(x, y)
        return dp[x][y];
    if (x < 0 || y < 0 || x >= R || y >=C)
        return 0;
    int ret =1;
    for (int i = 0; i < 4; i ++)
    {
        int x1 = x + dir[i][0], y1 = y + dir[i][1];
        if (x1 < 0 || x1 >= R || y1 < 0 || y1 >= C || a[x][y] <= a[x1][y1])
            continue;
        ret = max(ret, DFS(x1,y1) + 1);
    }
   return dp[x][y] = ret;
}

int main()
{
    cin >> R >> C;
    int res = 0;
    for (int i = 0; i < R; i++)
        for (int j = 0; j < C; j++)
            cin >> a[i][j];

    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            res = max(res, DFS(i, j));
        }
    }
    cout << res;
    return 0;
}
