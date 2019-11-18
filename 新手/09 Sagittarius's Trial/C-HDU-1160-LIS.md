# FatMouse's Speed

地址：https://cn.vjudge.net/problem/HDU-1160

# 思路

把体重排序，然后求速度最长上升或下降子序列，注意如果体重相同不能比较

# 代码

```cpp
#include <bits/stdc++.h>
#define mod(x, m) ((x) % (m) + (m)) % (m)
#define endl '\n'
using namespace std;
const int N = 1e3+5;
struct P {
    int w, s, i;
    bool operator < (P &a) {
        return w > a.w;
    }
}mouse[N];
int dp[N] = {0};
int main() {
    int n = 1, cur = 1;;
    while (~scanf("%d%d", &mouse[n].w, &mouse[n].s))
        mouse[n].i = n, n++;
    sort(mouse + 1, mouse + n);
    /*for (int i = 1; i < n; i++) {
        printf("%d %d %d\n", mouse[i].w, mouse[i].s, mouse[i].i);
    }*/
    dp[1] = 1;
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < i; j++) {
            if (mouse[i].w != mouse[j].w && mouse[i].s > mouse[j].s && dp[i] < dp[j] + 1) {
                dp[i] = dp[j] + 1;
            }
        }
        cur = (dp[cur] > dp[i] ? cur : i);
    }
    /*for (int i = 1; i < n; i++) {
        printf("%d %c", dp[i], (i == n-1 ? '\n' : ' '));
    }*/
    vector<int> ans;
    ans.push_back(mouse[cur].i);
    for (int i = cur; i > 0; i--) {
        if (dp[i] == dp[cur]-1) {
            ans.push_back(mouse[i].i);
            cur = i;
        }
    }
    //reverse(ans.begin(), ans.end());
    printf("%d\n", ans.size());
    for (int i = 0; i < ans.size(); i++)
        printf("%d\n", ans[i]);
    return 0;
}
```