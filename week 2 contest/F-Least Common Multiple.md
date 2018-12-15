# F-Least Common Multiple

来源：HDU - 1019

地址：https://vjudge.net/problem/HDU-1019

## 思路：

只要知道欧几里得算法，知道怎么求最大公因式，就可以求了

这道题题目描述比较坑，开始还被骗了，第二行是

>m, n1, n2, ... ,nm

居然第一个是这一行后面的数的个数。。。

另外，欧几里得算法注意数的大小顺序

## 代码：

```cpp
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll gcd(ll a, ll b) {
    if (b == 0) return a;
    else return gcd(b, a % b);
}

void lcm(ll &a, ll b) {
    a =  a * b / gcd(a, b);
}

int main() {
    int n;
    cin >> n;
    while (n--) {
        ll m, a, b;
        cin >> m >> a;
        for (int i = 0; i < m - 1; i++) {
            cin >> b;
            if (a < b) swap(a, b);
            lcm(a, b);
        }
        cout << a << endl;
    }
    return 0;
}
```