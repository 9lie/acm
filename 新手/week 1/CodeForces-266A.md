## 题目：CodeForces-266A
地址：https://vjudge.net/problem/CodeForces-266A
---
把石头看成多组：
(RR)(GGG)(BBB)
每次检查一个字符，如果下一个字符与本字符相同，count + 1
## 代码：
```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    char a[51];
    scanf("%d%s", &n, a);
    char cur = 0;
    int res = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] != cur) {
            cur = a[i];
        } else {
            res++;
        }
    }
    printf("%d", res);
    return 0;
}

```