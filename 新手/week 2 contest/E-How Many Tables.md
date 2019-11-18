# E-How Many Tables

来源：HDU - 1213

地址：https://vjudge.net/problem/HDU-1213

## 思路：

**并查集**

题意很简单，就是考并查集

这次并查集改进了一下写法，好看了一点，也简洁了一点

## 代码：

```cpp
#include <bits/stdc++.h>
using namespace std;

int p[1001] = {0};

int fd(int a) {
    if (p[a] == a) return a;
    return fd(p[a]);
}

void un(int a, int b) {
    a = fd(a);
    b = fd(b);
    p[a] = b;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, a, b;
        cin >> n >> m;
        for (int i = 1; i <= n; i++) p[i] = i;
        for (int i = 0; i < m; i++) {
            cin >> a >> b;
            un(a, b);
        }
        int r1 = 0, r2 = 0;
        for (int i = 1; i <= n; i++) {
            //cout << p[i] << " " << i << "|";
            if (p[i] == i) r1++;
        }
        cout << r1 << endl;
    }
    return 0;
}
```