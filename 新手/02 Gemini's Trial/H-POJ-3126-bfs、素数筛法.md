# Prime Path

地址：https://cn.vjudge.net/problem/POJ-3126

# 思路

**BFS、素数筛法**

先筛素数，然后BFS状态的改变就是数字的改变

# 代码

```cpp
#include <iostream>
#include <queue>
#include <map>
#include <cstring>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;
const int N = 9999;
bool is_prime[N + 1] = {false};

void sieve() {
    for (int i = 2; i <= N; i++) is_prime[i] = true;
    for (int i = 2; (ll)i * i <= N; i++) {
        if (is_prime[i]) {
            for (int j = 2 * i; j <= N; j += i) {
                is_prime[j] = false;
            }
        }
    }
}
bool vis[N + 1];
int main() {
    int n, a, b;
    sieve();
    cin >> n;
    while (n--) {
        cin >> a >> b;
        queue<pii> q;
        q.push(pii(a, 0));
        memset(vis, 0, sizeof(vis));
        vis[a] = 1;

        int ans = -1;
        while (!q.empty()) {
            pii p = q.front(); q.pop();
            if (p.first == b) {
                ans = p.second;
                break;
            }
            int np = 0, dit[4];
            dit[3] = p.first / 1000;
            dit[0] = p.first % 10;
            dit[1] = p.first % 100 / 10;
            dit[2] = p.first / 100 % 10;
            for (int i = 1; i <= 9; i += 2) {
                np = p.first - dit[0] + i;
                //printf("%d\n", np);
                if (!vis[np] && is_prime[np]) {
                    vis[np] = 1;
                    q.push(pii(np, p.second + 1));
                    //printf("%d\n", np);
                }
            }
            for (int i = 1, k = 10; i <= 2; i++, k *= 10) {
                for (int j = 0; j < 10; j++) {
                    np = p.first + (j - dit[i]) * k;

                    if (!vis[np] && is_prime[np]) {
                        vis[np] = 1;
                        q.push(pii(np, p.second + 1));
                        //printf("%d\n", np);
                    }
                }
            }
            for (int i = 1; i < 10; i++) {
                np = p.first + (i - dit[3]) * 1000;
                if (!vis[np] && is_prime[np]) {
                    vis[np] = 1;
                    q.push(pii(np, p.second + 1));
                    //printf("%d\n", np);
                }
            }
        }
        if (ans < 0) cout << "Impossible" << endl;
        else cout << ans << endl;
    }
    return 0;
}
```