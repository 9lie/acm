# Catch That Cow

地址：https://cn.vjudge.net/problem/POJ-3278

# 思路

因为只能向前乘2，如果超过了目标，就只能一步一步减回来，这是就可以直接计算步数不用循环

# 代码

```cpp
#include <queue>
#include <map>
#include <iostream>
#define emplace push
using namespace std;
#define endl '\n'
int solve();
int main()
{
    solve();
	return 0;
}
//********************************************************
typedef pair<int, int> pii;
const int N = 1e5 + 1;
map<int, bool> vis;
int solve() {
    int a, b;
    cin >> a >> b;
    if (b <= a) {
        cout << a - b << endl;
        return 0;
    }
    queue<pii> q;
    q.emplace(pii(a, 0));
    vis[a] = 1;

    int mins = N;
    while (!q.empty()) {
        pii p = q.front(); q.pop();
        if (p.first >= b) {
            mins = min(mins, p.first - b + p.second);
            if (p.second >= mins) break;
            continue;
        }
        if (p.first + 1 < N && !vis[p.first+1]) {
            q.emplace(pii(p.first+1, p.second+1));
            vis[p.first+1] = 1;
        }
        if (p.first - 1 > 0 && !vis[p.first-1]) {
            q.emplace(pii(p.first-1, p.second+1));
            vis[p.first-1] = 1;
        }
        if (p.first * 2 < N && !vis[p.first*2]) {
            q.emplace(pii(p.first*2, p.second+1));
            vis[p.first*2] = 1;
        }
    }
    cout << mins << endl;
    return 0;
}
```