# H-A + B Problem II

来源：HDU - 1002

地址：https://vjudge.net/problem/HDU-1002

## 思路

用两个 `string` 储存，然后把两个字符串倒置，就可以很简单的从最低位开始加

结果也储存再字符串内，最后把结果再倒置一次

## 代码：

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, i = 1;
    cin >> n;
    while (n--) {
        string a, b, c;
        cin >> a >> b;
        printf("Case %d:\n", i++);
        cout << a << " + " << b << " = ";
        if (a.size() < b.size()) swap(a ,b);
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        int isnext = 0;
        for (int i = 0; i < a.size(); i++) {
            int tmp = 0, ai = a[i] - '0', bi = 0;
            if (i < b.size()) {
                bi = b[i] - '0';
            }
            tmp = ai + bi + isnext;
            isnext = 0;
            if (tmp > 9) {
                isnext = 1;
                tmp -= 10;
            }
            c.push_back(tmp + '0');
        }
        reverse(c.begin(), c.end());
        cout << c << endl;
        if (n != 0) cout << endl;
    }
    return 0;
}
```