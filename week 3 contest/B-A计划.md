# B-A计划

来源：HDU - 2102

地址：https://cn.vjudge.net/contest/276592#problem/B

## 思路

这是一道简单的**bfs**题目，必须理解好题目的条件

在解这道题的时候，将两个传送门重叠认为是可以走的，但其实仔细思考会发现这其实会是一个循环

题目说到

> 骑士们一进入时空传输机就会被转到另一层的相对位置

所有显然两个传送门重叠是死路

## 代码

```cpp
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int dir[4][2] = {1,0,-1,0,0,1,0,-1};
char floors[2][12][12];
bool used[2][12][12];

struct s {
    int f, y, x, t;
};

int main() {
    int c, n, m, t;
    scanf("%d", &c);
    while (c--) {
        memset(used, false, sizeof(used));
        string ans = "NO";
        scanf("%d%d%d", &n, &m, &t);
        for (int f = 0; f < 2; f++) {
            for (int y = 0; y < n; y++) {
                scanf("%s", floors[f][y]);
            }
        }

        queue<s> q;
        q.emplace(s{0, 0, 0, 0}); used[0][0][0] = true;

        while (!q.empty()) {
            s p = q.front(); q.pop();
            int nx, ny, nf;
            if (p.t > t) break;
            if (floors[p.f][p.y][p.x] == 'P') {
                ans = "YES";
                break;
            }

            for (int i = 0; i < 4; i++) {
                nx = p.x + dir[i][0]; ny = p.y + dir[i][1]; nf = p.f;
                if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
                if (floors[nf][ny][nx] == '#' && !used[nf][ny][nx]) {
                    used[nf][ny][nx] = true;
                    nf = (nf == 0 ? 1 : 0);
                }
                if (floors[nf][ny][nx] == '*' || used[nf][ny][nx] || floors[nf][ny][nx] == '#') continue;
                q.emplace(s{nf, ny, nx, p.t + 1});
                used[nf][ny][nx] = true;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
```