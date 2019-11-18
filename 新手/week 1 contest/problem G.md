## 题目：HDU - 6292
地址：https://vjudge.net/problem/HDU-6292
---
这是一道非常简单的题目，但是那个时候我因为前面的题自闭了，到最后都没有看。。。

不用先全部储存再排列，只要每次输入进来就比一下大小就可以了
## 代码：
```cpp
#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        int js = INF, ts = INF;
        for (int j = 0; j < a; j++) {
            int t;
            scanf("%d", &t);
            js = min(t, js);
        }
        for (int j = 0; j < b; j++) {
            int t;
            scanf("%d", &t);
            ts = min(t, ts);
        }
        printf("Problem %d:\n", 1001 + i);
        printf("Shortest judge solution: %d bytes.\n", js);
        if (b != 0) {
            printf("Shortest team solution: %d bytes.\n", ts);
        } else {
            printf("Shortest team solution: N/A bytes.\n");
        }
    }
    return 0;
}

```