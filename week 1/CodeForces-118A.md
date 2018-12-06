## 题目：CodeForces-118A
题目地址 ：https://vjudge.net/problem/CodeForces-118A
---
水题，一边检查一边输出
## 代码：
```cpp
#include <bits/stdc++.h>
using namespace std;
char vowes[] = {'a', 'e', 'i', 'o', 'u', 'y'};
int main() {
    char a[101];
    while (~scanf("%s", a)) {
        for (int i = 0; a[i] != '\0'; i++) {
            char b = a[i];
            if (b <= 90) {
                b = b + 32;
            }
            for (int j = 0; j < 6; j++) {
                if (b == vowels[j]) {
                    b = '\0';
                    break;
                }
            }
            if (b != '\0') printf(".%c", b);
        }
    }
    return 0;
}
```