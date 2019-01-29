# Dungeon Master

地址：https://cn.vjudge.net/problem/POJ-2251

# 思路

**BFS**

和不同的走迷宫一样，就是多了两个方向

# 代码

```cpp
//#include <bits/stdc++.h>
#include <cstdio>
#include <queue>
#include <cstring>
#include <ctime>
#include <iostream>
using namespace std;
#define endl '\n'
int solve();
int main()
{
    #ifdef LOCAL_TEST
	clock_t clock_start = clock();
        if (freopen("poj2251", "r", stdin) == 0) {
            freopen("CON", "r", stdin);
            cerr << "--- Test by hand ---" << endl;
        } else {
            cerr << "--- Test by file ---" << endl;
        }
    #endif // LOCAL_TEST

    solve();

    #ifdef LOCAL_TEST
        cerr << "time: " << clock() - clock_start << " ms" << endl;
    #endif // LOCAL_TEST
	return 0;
}
//********************************************************
struct s{
    int x, y, z, t;
};
char maze[31][31][31];
bool used[31][31][31];
int dir[6][3] = {0,0,1,0,0,-1,0,1,0,0,-1,0,1,0,0,-1,0,0};
int solve() {
    int c, n, m;
    while (~scanf("%d%d%d", &c, &n, &m) && c != 0) {
        int ans = 0;
        memset(used, false, sizeof(used));
        for (int i = 0; i < c; i++)
            for (int j = 0; j < n; j++)
                scanf("%s", maze[i][j]);

        queue<s> q;
        for (int i = 0; i < c; i++) {
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < m; k++) {
                    if (maze[i][j][k] == 'S') {
                        q.push(s{k,j,i,0});
                        used[i][j][k] = false;
                        break;
                    }
                }
                if (!q.empty()) break;
            }
            if (!q.empty()) break;
        }

        while (!q.empty()) {
            s p = q.front(); q.pop();
            int x = p.x, y = p.y, z = p.z, nx, ny, nz;
            for (int i = 0; i < 6; i++) {
                nx = x + dir[i][0]; ny = y + dir[i][1]; nz = z + dir[i][2];
                if (nx < 0 || nx >= m || ny < 0 || ny >= n || nz < 0 || nz >= c || used[nz][ny][nx] || maze[nz][ny][nx] == '#') continue;
                if (maze[nz][ny][nx] == 'E') {
                    ans = p.t + 1;
                    break;
                }
                q.push(s{nx, ny, nz, p.t+1});
                used[nz][ny][nx] = true;
            }
            if (ans > 0) break;
        }
        if (ans) printf("Escaped in %d minute(s).\n", ans);
        else printf("Trapped!\n");
    }
    return 0;
}
```