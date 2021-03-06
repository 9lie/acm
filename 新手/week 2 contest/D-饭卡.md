# D-饭卡

来源：HDU - 2546

地址：https://vjudge.net/problem/HDU-2546

## 思路：

**动态规划**

虽然也有想过动态规划，但是因为比赛时其中一部无法证明是否正确，所以迟迟无法动手

### 方法：

将最后一个把钱从5元以上减到5元以下的菜钱记为 **ACE**

将所有的菜钱排列，找到最大的那个，将这个数作为 **ACE**

然后在其他的钱中找出最接近5元的组合，这一步可以用动态规划解决

然后我们要证明这个方法得出来的是最优解

### 证明：

当最后余额不会低于5元时，这个方法必定成立（这时无论ACE取何值结果都是一样的）

当最后余额会低于5元时，用反证法，记 **m** 为一开始卡的余额

设所有菜的价格的集合为 **S**，每个元素为菜的价格

设用这个方法得到的解所选取的元素记为集合 **A**, 从小到大排列为

```
a1, a2, ..., an, ACE
```

然后，再把剩余的元素的集合记为 **A`**

我们可以得到

```
a1 + a2 + ... + an = An <= m - 5

ACE + An > m - 5
```

因为此时的An已经最优，所有我们假设存在另外一个元素作为 **ACE** 可以得到更优解，将这个元素记为 **ace**

因为ACE是 **S** 中的最大值，所以一定有 `ACE > ace`

设另一个解的集合为 **B** ，剩余的元素的集合记为 **B`**，有

```
B = {b1, b2, ..., bn, ace}

b1 + b2 + ... + bn = Bn <= m -5

ace + Bn > ACE + An > m - 5
```

可得，`Bn > An`

记 a1, a2, ... an 的集合为{an}, b1, b2, ..., bn 的集合为{bn}

因为{an}是动态规划得到的最优解，要使得 Bn > An, 必须使 ACE 属于 {bn}

我们只需要把{an}中的某一个元素替换成ACE就可以得到{bn}，并且不需要替换其他元素

证明：

我们将{bn}中的ACE替换回去，得到的一定是S中除了ACE的元素中可以挑选的最优解，即{an}，所以{an}转为{bn}只需将ACE替换进去，证毕

我们设被替换出来的元素为 **c**，则 c 大于 B` 中的其他任何一个元素

证明：

如果存在另一个元素 **d** 属于B`大于 c，则 c < d < ACE

因为ACE可以替换c，则d也可以替换c，那么d替换c得到的集合比{an}更优，矛盾，所以不存在元素属于B`大于c。证毕

这时，我们就要在 B` 和 c 组成的集合中选择一个元素作为 ace

为了使结果最优（最大），选择其中最大的c作为ace，所以

```
ace = c

An - c + ACE = Bn

Bn + ace = An - c + ACE + c = An + ACE
```

这与`Bn + ace > An + ACE`相矛盾，所以不存在比An + ACE的更优解

证毕

好吧，其实自己在想的时候挺好理解的，但是写出来为了追求严谨就变成这样了

也可能是存在更简单的理解方法，但是没想出来。。。

## 代码：

```cpp
#include <bits/stdc++.h>
using namespace std;
int dp[1000] = {0};
int main() {
    int n, m;
    dp[0] = 0;
    while (~scanf("%d", &n) && n != 0) {
        vector<int> a;
        for (int i = 0; i < n; i++) {
            int tmp;
            scanf("%d", &tmp);
            a.emplace_back(tmp);
        }
        scanf("%d", &m);
        if (m < 5) {
            printf("%d\n", m);
            continue;
        }
        memset(dp, 0, sizeof(dp));
        sort(a.begin(), a.end());
        for (int i = 0; i < n - 1; i++) {
            for (int j = m - 5; j >= a[i]; j--) {
                dp[j] = max(dp[j], dp[j - a[i]] + a[i]);
            }
        }
        printf("%d\n", m - dp[m - 5] - a.back());
    }
    return 0;
}
```
