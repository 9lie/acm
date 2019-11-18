## 题目：HDU - 2005
地址：https://vjudge.net/problem/HDU-2005
---
这道题也突出了我字符串处理能力不足的毛病

其实本来是很简单的一道题

因为以前有写过实验报告，所有有思路
## 代码：
```cpp
#include <iostream>
using namespace std;
int m[] = {31,28,31,30,31,30,31,31,30,31,30,31};
int main() {
    char str[15];
    while (~scanf("%s", str)) {
        int n = 0;
        int a[3] = {0};
        for (int i = 0; str[i] != 0; i++) {
            if (str[i] == '/') n++;
            else {
                a[n] = (a[n] * 10 + str[i] - '0');
            }
        };
        int add = 1;
        int res = a[2];
        for (int i = 0; i < a[1] - 1; i++) {
            res += m[i];
        }
        if (a[0] % 4 == 0) {
            if (a[0] % 100 == 0 && a[0] % 400 != 0) {
                add = 0;
            }
        } else add = 0;
        if (a[1] > 2) res += add;
        cout << res << endl;
    }
    return 0;
}
```