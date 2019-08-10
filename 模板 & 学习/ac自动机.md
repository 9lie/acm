## ac自动机

```cpp
#include <bits/stdc++.h>
using namespace std;

struct Trie {
  static const int N = 1e5 + 1, sz = 128;
  int next[N][sz], fail[N], end[N];
  int root, tot;
  int newNode() {
    for (int i = 0; i < sz; i++) next[tot][i] = -1;
    end[tot++] = -1;
    return tot-1;
  }

  void init() {
    tot = 0;
    root = newNode();
  }

  void insert(string &s, int id) {
    int p = root;
    for (int i = 0; s[i]; i++) {
      if (next[p][s[i]] == -1) next[p][s[i]] = newNode();
      p = next[p][s[i]];
    }
    end[p] = id;
  }

  void build() {
    queue<int> que;
    fail[root] = root;
    for (int i = 0; i < sz; i++) {
      if (next[root][i] == -1) {
        next[root][i] = root;
      } else {
        fail[next[root][i]] = root;
        que.push(next[root][i]);
      }
    }

    while (!que.empty()) {
      int p = que.front(); que.pop();

      for (int i = 0; i < sz; i++) {
        if (next[p][i] == -1) {
          next[p][i] = next[fail[p]][i];
        } else {
          fail[next[p][i]] = next[fail[p]][i];
          que.push(next[p][i]);
        }
      }
    }
  }

  bool used[510];
  bool query(string &s, int id, int n) {
    int p = root;
    memset(used, 0, sizeof(used));
    bool flag = 0;
    for (int i = 0; s[i]; i++) {
      p = next[p][s[i]];
      int u = p;
      while (u != root) {
        if (end[u] != -1) // code here
          used[end[u]] = flag = 1;
        u = fail[u];
      }
    }

    if (!flag) return 0;
    cout << "web " << id << ":";
    for (int i = 1; i <= n; i++)
      if (used[i]) cout << " " << i;
    cout << '\n';
    return 1;
  }
} ac;

int main() {
  ios::sync_with_stdio(false); cin.tie(0);

  int n, m;
  string s;
  while (cin >> n) {
    ac.init();
    for (int i = 1; i <= n; i++) {
      cin >> s;
      ac.insert(s, i);
    }
    ac.build();

    cin >> m;
    int tot = 0;
    for (int i = 1; i <= m; i++) {
      cin >> s;
      tot += ac.query(s, i, n);
    }
    cout << "total: " << tot << '\n';
  }

  return 0;
}
```

## 配合矩阵快速幂

```cpp
/*while (!que.empty()) {
  int p = que.front();
  que.pop();*/
  if (end[fail[p]] == 0) end[p] = 0; // 传递fail标记，标记什么传什么
```

获得可达矩阵 poj-2778

这道题是获得除了模式串以外的串，所以end[p] = 0;

```cpp
for (int i = 0; i < tot; i++)
  for （int j = 0; j < 26; j++)
    if (end[next[i][j]]) res.mat[i][next[i][j]]++;
return res;
```

通过 `n` 次快速幂可以得到通路为 `n` 的可达性矩阵

## 配合dp

可以用 `dp[i][j]` 表示长度为 `i` 当前节点为 `j` 的值，然后用ac自动机进行转移

可以加一维 `[k]` 表示包含了那几个串，二进制压缩状态

有时 `i` 可以不用，而是用类似滚动数组的方法