## 题目：CodeForces-467A
地址：https://vjudge.net/problem/CodeForces-467A
---
每个房间必须两个人的空位才可以，第一次提交没注意
## 代码：
```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, p, q, res = 0;
    scanf("%d", &n);
    while (n--) {
        scanf("%d%d", &p, &q);
        if (q - p >= 2) res++;//两个人的剩余空间。。。
    }
    printf("%d", res);
    return 0;
}

```