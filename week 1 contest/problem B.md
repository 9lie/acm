## 题目：HDU-1995
地址：https://vjudge.net/problem/HDU-1995
---
比赛的时候没能仔细思考这道题，如果那个时候在多思考一点说不定就做出来了

虽然题目问第k块的移动次数，但是因为k以上的块移动对k没有影响，所有可以看作(n - k + 1)块移动第1块

把除了第n块以外的看做一个整体，(n - 1)块移动第一块的次数是n块时移动第一块的次数的两倍

所有我们可以推测答案是2的次方，然后用计算器验证了一下，得出答案是：

**2 ^ (n - k)**

然后又有一个问题，那就是用codeblock时的`pow()`函数计算整数不精确

所以写了一个整数的快速幂函数，顺便复习了一下快速幂怎么写
## 代码：
```cpp
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll powint(ll x, ll n) {
    ll res = 1;
    while (n > 0) {
        if (n & 1 == 1) res *= x;
        x *= x;
        n >>= 1;
    }
    return res;
}

int main() {
    int n;
    scanf("%d", &n);
    while (n--) {
        int a, b;
        scanf("%d%d", &a, &b);
        printf("%lld\n", powint(2, a - b));
    }
    return 0;
}
```