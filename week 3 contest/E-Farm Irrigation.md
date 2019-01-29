# E-Farm Irrigation

来源：HDU - 1198

地址：https://cn.vjudge.net/problem/HDU-1198

## 思路

**并查集**

主要的难点在于检测两个地的管子是否相连（强行难点）

每一种类型的第用一个**4位2进制数字**来表示，每一位代表一个方向

检测一个方向有没有管子只要用位运算就可以了，类似掩码

## 代码

```cpp
#include <bits/stdc++.h>
using namespace std;

char land[53][53];
int pipe[11] = {9, 12, 3, 6, 10, 5, 13, 11, 7, 14, 15};
// 用二进制4位来表示一种管子
// 上右下左

int par[2500];
int fp(int n) {
    if (par[n] == n) return n;
    return par[n] = fp(par[n]);
}
void un(int x, int y) {
    x = fp(x);
    y = fp(y);
    par[x] = y;
}

int main() {
    int n, m;
    while (~scanf("%d%d", &n, &m) && n > 0) {
        int ans = 0;
        for (int i = 0; i < n * m; i++)
            par[i] = i;
        for (int i = 0; i < n; i++)
            scanf("%s", land + i);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (i != n - 1) {
                    int a = pipe[land[i][j] - 'A'] & 2;
                    int b = pipe[land[i + 1][j] - 'A'] & 8;
                    if (a && b) un(i*m+j, i*m+j+m);
                }
                if (j != m - 1) {
                    int a = pipe[land[i][j] - 'A'] & 4;
                    int b = pipe[land[i][j + 1] - 'A'] & 1;
                    if (a && b) un(i*m+j, i*m+j+1);
                }
            }
        }
        for (int i = 0; i < n * m; i++) {
            if (par[i] == i) ans++;
        }
        printf("%d\n", ans);
    }
    return 0;
}
```