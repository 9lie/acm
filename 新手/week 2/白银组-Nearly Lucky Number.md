# 白银组-Nearly Lucky Number

来源：CodeForces - 110A

地址：https://vjudge.net/problem/CodeForces-110A

## 思路：

每次取一个字符，如果是 **4** 或 **7** 计数加1，最后看计数是否为 **7** 或 **4**

## 代码：

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    char c;
    int n = 0;
    while (~scanf("%c", &c) && c != '\n') {
        if (c == '4' || c == '7') n++;
    }
    if (n == 4 || n == 7) printf("YES\n");
    else printf("NO\n");
    return 0;
}
```