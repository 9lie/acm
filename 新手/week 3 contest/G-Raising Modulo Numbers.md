# G-Raising Modulo Numbers

来源：POJ - 1995

地址：https://cn.vjudge.net/contest/276592#problem/G

# 思路

快速幂

# 代码

```cpp
#include <cstdio>
#include <iostream>
using namespace std;
#define endl '\n'

int solve();

int main()
{
    solve();
	return 0;
}
//********************************************************

long long powm(long long x, long long n, long long mod) {
    if (x == 0) return 0;
    long long res = 1;
    while (n) {
        if (n&1) res = res * x % mod;
        x = x * x % mod;
        n >>= 1;
    }
    return res;
}

int solve() {
    int n;
    scanf("%d", &n);
    while (n--) {
        int mod, h, ans = 0;
        long long a, b;
        scanf("%d%d", &mod, &h);
        for (int i = 0; i < h; i++) {
            scanf("%lld%lld", &a, &b);
            ans = (ans + powm(a, b, mod)) % mod;
        }
        printf("%d\n", ans);
    }
    return 0;
}
```