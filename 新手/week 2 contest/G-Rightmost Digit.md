# G-Rightmost Digit

来源：HDU - 1061

地址：https://vjudge.net/problem/HDU-1061

## 思路：

**快速幂**

求 `n^n`

因为c++自带的pow求整数时不精确，之前的一些训练题的练习中用过几次快速幂，所有这里就直接会写

然后就是配合同余定理就可以很简单的解出这道题

这也是我第一道做出来的题目

## 代码：

```cpp
#include <bits/stdc++.h>
using namespace std;
int powm(long long a) {
    int res = 1;
    long long n = a;
    a = a % 10;
    while (n > 0) {
        if (n & 1) res = res * a % 10;
        a = a * a % 10;
        n >>= 1;
    }
    return res;
}
int main() {
    long long n;
    cin >> n;
    while (n--) {
        long long a;
        cin >> a;
        cout << powm(a) << endl;
    }
    return 0;
}
```