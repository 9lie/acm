# B-非常可乐

来源：HDU - 1495

地址：https://vjudge.net/problem/HDU-1495

## 思路

**广度优先搜索**

比赛的时候完全没有想到可以bfs

如果重可乐量为奇数，直接NO

如果两个杯子容积一样，直接1

把两个杯子的可乐量用一个数对来表示`(x, y)`，其中x代表大杯的可乐

可乐的倒来倒去就是(x, y)的不断变化，如果最后x等于可乐量的一半，就找到答案

因为最后要的是最小答案，所以用bfs是最合适的（dfs应该也可以，比较耗时）

可乐一个状态有6种倒法，1 -> 2, 1 -> 3, 2 -> 1, 2 -> 3, 3 -> 1, 3 -> 2

代码应该可以更简洁，这是直接按照思路写的

## 代码：

```cpp
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
struct S {
    int x, y;
    int step;
};

int main() {
    int s, a, b;
    while (~scanf("%d%d%d", &s, &a, &b) && s != 0) {
        if (s % 2 == 1) {
            printf("NO\n");
            continue;
        }
        if (a == b) {
            printf("1\n");
            continue;
        }
        if (a < b) swap(a, b);
        bool used[101][101] = {false};
        queue<S> q;
        int res = 0;
        used[0][0] = true;
        q.emplace(S{0, 0, 0});
        while (!q.empty()) {
            S t = q.front(); q.pop();
            if (t.x == s/2) {
                res = t.step + 1;
                break;
            }

            if (t.x > 0) {
                if (!used[0][t.y]) {
                    used[0][t.y] = true;
                    q.emplace(S{0, t.y, t.step + 1});
                }
                if (t.x <= b - t.y && !used[0][t.y + t.x]) {
                    used[0][t.y + t.x] = true;
                    q.emplace(S{0, t.y + t.x, t.step + 1});
                } else if (t.x > b - t.y && !used[t.x - (b - t.y)][b]) {
                    used[t.x - (b - t.y)][b] = true;
                    q.emplace(S{t.x - (b - t.y), b, t.step + 1});
                }
            }
            if (t.y > 0) {
                if (!used[t.x][0]) {
                    used[t.x][0] = true;
                    q.emplace(S{t.x, 0, t.step + 1});
                }
                if (t.y <= a - t.x && !used[t.x + t.y][0]) {
                    used[t.x + t.y][0] = true;
                    q.emplace(S{t.x + t.y, 0, t.step + 1});
                } else if (t.y > a - t.x && !used[a][t.y - (a - t.x)]) {
                    used[a][t.y - (a - t.x)] = true;
                    q.emplace(S{a, t.y - (a - t.x), t.step + 1});
                }
            }
            if (!used[t.x][b]) {
                used[t.x][b] = true;
                q.emplace(S{t.x, b, t.step + 1});
            }
            if (!used[a][t.y]) {
                used[a][t.y] = true;
                q.emplace(S{a, t.y, t.step + 1});
            }
        }
        if (res == 0) printf("NO\n");
        else printf("%d\n", res);
    }
    return 0;
}
```