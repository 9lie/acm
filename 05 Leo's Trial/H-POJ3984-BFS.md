# 迷宫问题

地址：https://cn.vjudge.net/problem/POJ-3984

# 思路

**BFS**

简单的BFS，需要记录路径，用一个pre数组记录前一个点

# 代码

```cpp
#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>
#include <vector>
#define mod(x, m) ((x) % (m) + (m)) % (m)
#define endl '\n'
using namespace std;
struct P{
    int x, y;
};
int vis[5][5];
P pre[5][5];
int maze[5][5];
int dis[4][2] = {0,1,0,-1,1,0,-1,0};
int main() {
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
            scanf("%d", &maze[i][j]);

    memset(vis, 0, sizeof(vis));
    queue<P> q;
    q.push(P{0, 0});
    vis[0][0] = 1;

    while (!q.empty()) {
        P p = q.front(); q.pop();
        if (p.x == 4 && p.y == 4) break;
        int nx, ny;
        for (int i = 0; i < 4; i++) {
            nx = p.x + dis[i][0]; ny = p.y + dis[i][1];
            if (nx >= 0 && nx < 5 && ny >= 0 && ny < 5 && !maze[nx][ny] && !vis[nx][ny]) {
                q.push(P{nx, ny});
                vis[nx][ny] = 1;
                pre[nx][ny] = P{p.x, p.y};
                //cout << pre[nx][ny].x << endl;
            }
        }
    }
    int px = 4, py = 4;
    vector<P> res;
    res.push_back(P{px, py});
    while (px || py) {
        P tp = pre[px][py];
        px = tp.x;
        py = tp.y;
        res.push_back(P{px, py});
    }
    /*for (int i = 0; i <= 4; i++)
        for (int j = 0; j <= 4; j++)
            cout << pre[i][j].x << ':' << pre[i][j].y << (j == 4 ? '\n' : ' ');*/
    for (int i = res.size()-1; i >= 0; i--) {
        printf("(%d, %d)\n", res[i].x, res[i].y);
    }
    return 0;
}
```