## 题目: CodeForces - 4A
地址: https://vjudge.net/problem/CodeForces-4A
---
耐心读题，并且注意特殊情况`2`就没用问题了

## 代码
```cpp
#include <cstdio>
using namespace std;

int main () {
    int  n;
    scanf("%d", &n);
    if (n % 2 == 0 && n != 2) {
        printf("YES");
    } else {
        printf("NO");
    }
    return 0;
}
```