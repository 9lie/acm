# Find a way

地址：https://cn.vjudge.net/problem/HDU-2612

# 思路

记录所有KFC的坐标，每次从KFC出发计算到两个人的坐标的距离和，如果无法到达就不要统计

会超时，可以用曼哈顿距离剪枝，当一个点到两个人的曼哈顿距离大于最已知的最小结果，直接跳出循环

# 代码

```cpp
#include <bits/stdc++.h>
#define mod(x, m) ((x) % (m) + (m)) % (m)
#define endl '\n'
using namespace std;
char maze[202][202];
int dis[4][2] = {1,0,-1,0,0,-1,0,1};
bool vis[202][202];
struct P {
    int x, y, t;
};
int main() {
    int n, m;
    P Y, M;
    while (~scanf("%d%d", &n, &m)) {
        vector<P> KFC;
        for (int i = 0; i < n; i++) {
            scanf("%s", maze+i);
            for (int j = 0; j < m; j++) {
                if (maze[i][j] == '@') {
                    KFC.emplace_back(P{i, j, 0});
                }
                if (maze[i][j] == 'Y') {
                    Y.x = i, Y.y = j;
                }
                if (maze[i][j] == 'M') {
                    M.x = i, M.y = j;
                }
            }
        }
        int ans = INT_MAX;
        //cout << ans << endl;
        for (int k = 0; k < KFC.size(); k++) {
            queue<P> q;
            q.push(KFC[k]);
            memset(vis, 0, sizeof(vis));
            int step = 0;
            bool fy = 0, fm = 0;

            while (!q.empty()) {
                P p = q.front(); q.pop();
                if (maze[p.x][p.y] == 'Y') {
                    step += p.t;
                    //cout << p.t << 'y' << endl;
                    fy = 1;
                } else if (maze[p.x][p.y] == 'M') {
                    step += p.t;
                    //cout << p.t << 'm'<< endl;
                    fm = 1;
                }
                if (fy && fm) break;

                int ly = fabs(p.x-Y.x)*11+fabs(p.y-Y.y)*11+p.t;
                int lm = fabs(p.x-M.x)*11+fabs(p.y-M.y)*11+p.t;
                //cout << ly << ' ' << lm << endl;
                if (fy && step+lm >= ans) continue;
                if (fm && step+ly >= ans) continue;

                int nx, ny;
                for (int i = 0; i < 4; i++) {
                    nx = p.x + dis[i][0]; ny = p.y + dis[i][1];
                    if (nx >= 0 && nx < n && ny >= 0 && ny < m && maze[nx][ny] != '#' && !vis[nx][ny]) {
                        //printf("%d,%d\n",nx, ny);
                        q.push(P{nx, ny, p.t+11});
                        vis[nx][ny] = 1;
                    }
                }
            }
            if (fy && fm) ans = min(ans, step);
        }
        //cout << ans << endl;
        printf("%d\n", ans);
    }
    return 0;
}
```