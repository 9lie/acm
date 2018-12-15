# A-Oil Deposits

来源：HDU - 1241

地址：https://vjudge.net/problem/HDU-1241

## 思路：

其实我没怎么看懂这道题。。。

不过通过题目的样例可以知道是 **dfs**

循环每一个点，如果等于 **@** 那么就进行深搜，把和这个点相连的点代替成 **\***

## 代码：

```cpp
#include <bits/stdc++.h>
using namespace std;

int n, m;
char maps[105][105];
int dir [8][2] = {1,1,1,0,1,-1,0,1,0,-1,-1,1,-1,0,-1,-1};

void s(int i, int j) {
    if (i < 0 || i >= n || j < 0 || j >= m || maps[i][j] == '*') return;
    maps[i][j] = '*';
    for (int k = 0; k < 8; k++) {
        s(i + dir[k][0], j + dir[k][1]);
    }
}

int main() {
    while (~scanf("%d%d", &n, &m) && n != 0 && m != 0) {
        for (int i = 0; i < n; i++) {
            scanf("%s", maps[i]);
        }
        int res = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (maps[i][j] == '@') {
                    res++;
                    s(i, j);
                }
            }
        }
        printf("%d\n", res);
    }
    return 0;
}
```