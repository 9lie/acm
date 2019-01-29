# Ignatius and the Princess I

地址：https://cn.vjudge.net/problem/HDU-1026

# 思路

**BFS、路径还原**

多了一个fight的状态

# 代码

```cpp
#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <algorithm>
#define mod(x, m) ((x) % (m) + (m)) % (m)
#define endl '\n'
using namespace std;
char maze[101][101];
bool vis[101][101];
struct P{
    int x, y, s;
    int f;
}pre[101][101];
int dis[4][2] = {0,1,0,-1,1,0,-1,0};
int main() {
    int n, m;
    while (cin >> n >> m) {
        for (int i = 0; i < n; i++)
            scanf("%s", maze+i);
        queue<P> q;
        q.push(P{0,0,0,0});
        memset(vis, 0, sizeof(vis));

        int ans = 0;
        while (!q.empty()) {
            P p = q.front(); q.pop();
            if (p.f) {
                p.f--;
                p.s++;
                q.push(p);
            } else {
                if (p.x == n-1 && p.y == m-1) {
                    ans = p.s;
                    break;
                }

                P np;
                np.s = p.s + 1;
                for (int i = 0; i < 4; i++) {
                    np.x = p.x + dis[i][0], np.y = p.y + dis[i][1];
                    if (np.x >= 0 && np.x < n && np.y >= 0 && np.y < m && maze[np.x][np.y] != 'X' && !vis[np.x][np.y]) {
                        vis[np.x][np.y] = 1;
                        np.f = 0;
                        if (maze[np.x][np.y] >= '1' && maze[np.x][np.y] <= '9')
                            np.f = maze[np.x][np.y] - '0';
                        q.push(np);
                        pre[np.x][np.y] = p;
                    }
                }
            }
        }
        vector<P> vec;
        if (ans) {
            int px = n-1, py = m-1;
            vec.push_back(P{px, py, 0, 0});
            while (px || py) {
                int tx, ty;
                tx = pre[px][py].x;
                ty = pre[px][py].y;
                vec.push_back(P{tx, ty, 0, 0});
                px = tx, py = ty;
            }
            printf("It takes %d seconds to reach the target position, let me show you the way.\n", ans);
            reverse(vec.begin(), vec.end());
            int ca = 1;
            for (int i = 0; i < vec.size(); i++) {
                if (i == vec.size() - 1) break;
                else {
                    printf("%ds:(%d,%d)->(%d,%d)\n", ca++, vec[i].x, vec[i].y, vec[i+1].x, vec[i+1].y);
                    while (maze[vec[i+1].x][vec[i+1].y] >= '1' && maze[vec[i+1].x][vec[i+1].y] <= '9') {
                        printf("%ds:FIGHT AT (%d,%d)\n", ca++, vec[i+1].x, vec[i+1].y);
                        maze[vec[i+1].x][vec[i+1].y] = maze[vec[i+1].x][vec[i+1].y] - 1;
                    }
                }
            }
        } else {
            printf("God please help our poor hero.\n");
        }
        printf("FINISH\n");
    }
    return 0;
}
```