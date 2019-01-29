# Prime Ring Problem

地址：https://cn.vjudge.net/problem/HDU-1016

# 思路

**DFS**

# 代码

```cpp
#include <iostream>
#include <vector>
#include <cstring>
#define mod(x, m) ((x) % (m) + (m)) % (m)
#define endl '\n'
using namespace std;
int primei[] = {3,5,7,11,13,17,19,23,29,31,37};
bool isprime[40] = {0}, vis[20] = {0};
int maze[20][20];
vector<int> ans;

void dfs(int i, int s, int n) {
    ans.emplace_back(i);
    if (s == n) {
        if (isprime[i+1]) {
            for (int j = 0; j < n; j++)
                cout << ans[j] << (j == n-1 ? '\n' :' ');
        }
        ans.pop_back();
        return;
    }
    for (int j = 0; maze[i][j]; j++) {
        if (maze[i][j] <= n && !vis[maze[i][j]]) {
            vis[maze[i][j]] = 1;
            dfs(maze[i][j], s+1, n);
            vis[maze[i][j]] = 0;
        }
    }
    ans.pop_back();
}

int main() {
    memset(maze, 0, sizeof(maze));
    for (int i = 0; i < 11; i++) isprime[primei[i]] = 1;
    for (int i = 1; i < 20; i++) {
        for (int k = 1, j = 0; k < 20; k++) {
            if (isprime[i+k] && i!= k && k != 1) {
                maze[i][j] = k;
                j++;
            }
        }
    }
    /*for (int i = 0; i < 20; i++) {
        cout << i << ' ';
        for (int j = 0; j < 20; j++)
            cout << maze[i][j] << (j == 19 ? '\n' : ' ');
    }*/
    int n, ca = 1;
    while (cin >> n) {
        printf("Case %d:\n", ca++);
        if (n == 1) cout << 1 << endl;
        else {
            vis[1] = 1;
            dfs(1, 1, n);
        }
        cout << endl;
    }
    return 0;
}
```