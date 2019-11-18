## 题目：CodeForces - 515A
地址：https://vjudge.net/problem/CodeForces-515A
---
其实这是一道非常简单的题目，但是因为被前面的题目吓到了，导致我直接跳过这道题

注意本题中坐标有4个象限，解决办法是全部转换为正的
## 代码：
```cpp
#include <iostream>
using namespace std;

int main() {
    long long int x, y, n;
    cin >> x >> y >> n;
    if (x < 0) x = -x;
    if (y < 0) y = -y;
    int r = n - x - y;
    if (r >= 0 && r % 2 == 0) cout << "Yes";
    else cout << "No";
    return 0;
}
```