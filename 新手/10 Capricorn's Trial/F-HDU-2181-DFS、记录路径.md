# 哈密顿绕行世界问题

地址：https://cn.vjudge.net/problem/HDU-2181

# 思路

**DFS**

# 代码

```cpp
#include <bits/stdc++.h>
#include <cstdio>
#define endl '\n'
using namespace std;
struct P{
    int a[3];
}p[21];
int vis[21], ca = 1, load[21];

void dfs(int k) {
    if (k == 19) {
        for (int i = 0; i < 3; i++) {
            if (p[load[k]].a[i] == load[0]) {
                printf("%d:  ", ca++);
                for (int i = 0; i < 20; i++) {
                    printf("%d ", load[i]);
                }
                printf("%d\n", load[0]);
            }
        }
    } else {
        for (int i = 0; i < 3; i++) {
            if (!vis[p[load[k]].a[i]]) {
                vis[p[load[k]].a[i]] = 1;
                load[k+1] = p[load[k]].a[i];
                dfs(k+1);
                vis[p[load[k]].a[i]] = 0;
            }
        }
    }
}

int main() {
    memset(vis, 0, sizeof(vis));
    for (int i = 1; i <= 20; i++) {
        scanf("%d%d%d", &p[i].a[0], &p[i].a[1], &p[i].a[2]);
        sort(p[i].a, p[i].a+3);
    }
    int a;
    while (cin >> a && a) {
        load[0] = a;
        vis[a] = 1;
        dfs(0);
        vis[a] = 0;
        ca = 1;
    }
    return 0;
}
```