# C-Bone Collector

来源：HDU - 2602

地址：https://vjudge.net/problem/HDU-2602

## 思路：

**动态规划**

又是没怎么看明白，大概懂了题意

完全背包问题，一模一样

之前已经学过了，所有就会了

## 代码：

```cpp
#include <bits/stdc++.h>
using namespace std;
int dp[1005] = {0};
int val[1000] = {0};
int vol[1000] = {0};
int main() {
    int t, N, V;
    cin >> t;
    while (t--) {
        cin >> N >> V;
        for (int i = 0; i < N; i++) {
            scanf("%d", val + i);
        }
        for (int i = 0; i < N; i++) {
            scanf("%d", vol + i);
        }
        memset(dp, 0, sizeof(dp));
        for (int i = 0; i < N; i++) {
            for (int j = V; j >= vol[i]; j--) {
                dp[j] = max(dp[j], dp[j - vol[i]] + val[i]);
            }
        }
        cout << dp[V] << endl;
    }
    return 0;
}
```