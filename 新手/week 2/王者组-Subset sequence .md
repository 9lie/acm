# 王者组-Subset sequence

来源：HDU - 2062

地址：https://vjudge.net/problem/HDU-2062

## 思路

 首先，找规律

 ```
1
len : 1

1
1 2
2
2 1
len : 2 * (1 + 1) = 4

1
1 2
1 2 3
1 3
1 3 2
2
2 1
2 1 3
2 3
2 3 1
3
3 1
3 1 2
3 2
3 2 1
len : 3 * (4 + 1) = 15
 ```

 可以很清楚的发现，每一组都包含前一组的样子(形式)

 第 **n** 组可以分成 **n** 小组，每小组的样子是前一大组每一行加一个数字，并在最开始加单独的一行

 对于每个小组，第 **1** 个小组第一个数是 **1** ，以此类推

 所有，对于第 **n** 组的第 **m** 个序列，我们可以很简单地找到这个序列的第 **1** 个数字

 计算第 **n** 组的序列数为 **l**

计算 **i = l / n** ， **i** 为每个小组的序列数

计算 **k = m / i + 1** ， **k** 为 **m** 所在的小组的序号

这里要注意，如果 m 整除 i，k 需要再加 1

这样，我们就找到了这个序列的第一个数字 **k**

这里我们需要定义一个数组

```cpp
long long num[21];
for (int i = 1; i <= 20; i++) {
    if (i <= n) num[i] = i;
    else num[i] = 0;
}
```
这段代码初始化了一个有n个数数组，第 **i** 个数是 **i**，其他数字为 **0**

我们要找的第一个数就是**这个序列的第 k 个不是0的数**

为什么这么说，看后面就知道了

取出这个数后，把这个位置补0

然后用同样的方法找第二个数到最后一个数

找第二个数的时候，其实就是在第 **n - 1** 组找第一个数

只有通过 **n** 和 **m** 确定在第 **n - 1** 组的第几个序列，就可循环上面的方法一直找到最后一个

但是取出数字的时候，有一些数字已经在前面取过了，所以用上面的数组保存**没有取的数字**

每次取第 **k** 个数时，取的就是**没有取过的数字**中的第 **k** 个

### 其他

这道题还让我认识了一些有用的函数

```cpp
itao(int, char *, int) //第三个参数为进制
ltoa(long long, char *, int)
```

这个函数可以很方便地把数字转换为字符串

## 代码：

```cpp
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll l[21] = {0};
int num[21] = {0};

string findn(int n) {
    for (int i = 1; i <= 20; i++) {
        if (num[i] != 0) n--;
        if (n == 0) {
            char a[2];
            ltoa(num[i], a, 10);
            num[i] = 0;
            return string(a);
        }
    }
}

string solve(ll a, ll b) {
    string str;
    if (a == 1) return findn(1);
    ll k = b / (l[a - 1] + 1);
    ll r = b % (l[a - 1] + 1);
    if (r != 0) k += 1;
    str = str + findn(k);
    if (r == 1) return str;
    if (r == 0) r = l[a - 1] + 1;
    str.push_back(' ');
    return str + solve(a - 1, r - 1);
}

int main() {
    for (int i = 1; i <= 20; i++) {
        l[i] = i * (l[i - 1] + 1);
    }
    ll a, b;
    while (~scanf("%lld%lld", &a, &b)) {
        for (int i = 1; i <= 20; i++) {
            if (i <= a) num[i] = i;
            else num[i] = 0;
        }
        cout << solve(a, b) << endl;
    }
    return 0;
}
```