## 题目：HDU - 2039
地址：https://vjudge.net/problem/HDU-2039
---
此题是一个提醒，在没用说明数据的类型时不要被样例误导

这道题中**三角形**的边并没有说明是整数

必须使用`double`类型来储存边的长度

## 代码
```cpp
#include <cstdio>
#include <iostream>
using namespace std;
int main () {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        double a, b, c;
        cin >> a >> b >> c;
        if (a + b > c && a + c > b && b + c > a) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }
    return 0;
}
```