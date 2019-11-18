# Heavy Transportation

地址：https://cn.vjudge.net/problem/POJ-1797

# 思路

按照djikstra的思路贪心求解，每个点的操作为

d[u] = max(d[u], min(cost[v][u], d[v]));

# 代码

```cpp
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
#define endl '\n'
using namespace std;
int cost[1005][1005], d[1005], vis[1005];
const int inf = 0x3f3f3f3f;
int main() {
    int t, ca = 1;
    cin >> t;
    while (t--) {
        int n, m;
        scanf("%d%d", &n, &m);
        memset(cost, 0, sizeof(cost));
        for (int i = 0; i < m; i++) {
            int u, v, w;
            scanf("%d%d%d", &u, &v, &w);
            cost[u][v] = cost[v][u] = w;
        }
        memset(d, 0, sizeof(d));
        memset(vis, 0, sizeof(vis));
        d[1] = inf;
        while (true) {
            int v = -1;
            for (int u = 1; u <= n; u++) {
                if (!vis[u] && (v == -1 || d[u] > d[v])) v = u;
                //cout << v << endl;
            }

            if (v == -1) break;
            vis[v] = true;
            //cout << v << 'v' << d[v] << endl;

            for (int u = 1; u <= n; u++) {
                if (cost[u][v]) {
                    d[u] = max(d[u], min(cost[u][v], d[v]));
                    //cout << u << ' ' << d[u] << endl;
                }
            }
        }
        printf("Scenario #%d:\n%d\n\n", ca++, d[n]);
    }

    return 0;
}
```