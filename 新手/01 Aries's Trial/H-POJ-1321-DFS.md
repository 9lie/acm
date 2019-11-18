# 棋盘问题

地址：https://cn.vjudge.net/problem/POJ-1321

# 思路

**DFS**

# 代码

```cpp
//#include <bits/stdc++.h>
#include <cstdio>
#include <cstring>
using namespace std;
#define endl '\n'
int solve();
#undef LOCAL_TEST
int main()
{
    #ifdef LOCAL_TEST
	clock_t clock_start = clock();
        if (freopen("poj1321", "r", stdin) == 0) {
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
char chess[10][10];
bool used[10];
int n, k, ans;
void dfs(int row, int rest) {
    if (rest == 0) {
        ans++;
        return;
    }
    for (int i = row; n - i >= rest; i++) {
        for (int j = 0; j < n; j++) {
            if (chess[i][j] == '#' && !used[j]) {
                used[j] = true;
                dfs(i + 1, rest - 1);
                used[j] = false;
            }
        }
    }
}

int solve() {
    while (~scanf("%d%d", &n, &k) && n > 0) {
        ans = 0;
        memset(used, false, sizeof(used));
        for (int i = 0; i < n; i++)
            scanf("%s", chess + i);
        dfs(0, k);
        printf("%d\n", ans);
    }
    return 0;
}
```