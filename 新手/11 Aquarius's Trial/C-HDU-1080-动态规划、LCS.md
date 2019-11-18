# Human Gene Functions

地址：https://cn.vjudge.net/problem/HDU-1080

# 思路

LCS升级版，深入了解LCS是怎么比较的，比较了什么

初始化，dp的第一行和第一列是只有空的时候配对得到的值，在一般的LCS里面就只需要填充0就可以了

比较，dp[i][j] 的值是从三个值比较得出来的，dp[i-1][j-1]+a[i]与b[j]匹配的值，dp[i][j-1]+a[i]与空匹配值，dp[i-1][j]+b[j]与空匹配值

# 代码

```cpp
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
const int inf = 0x3f3f3f3f;
int dp[105][105];
int s[30][30];
void add(char a, char b, int n) {
    s[a-'@'][b-'@'] = s[b-'@'][a-'@'] = n;
    //cout << s[a-'@'][b-'@'] << endl;
    // 'A' - '@' = 1;
}
int query(char a, char b) {
    return s[a-'@'][b-'@'];
}
string D = "ACGT@";
int sorce[5][5] =
{5,-1,-2,-1,-3,
-1,5,-3,-2,-4,
-2,-3,5,-2,-2,
-1,-2,-2,5,-1,
-3,-4,-2,-1,-inf};

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            add(D[i], D[j], sorce[i][j]);
        }
    }
    while (n--) {
        string a, b;
        int k;
        cin >> k >> a >> k >> b;
        dp[0][0] = 0;
        for (int i = 0; i < a.size(); i++) {
            dp[0][i+1] = dp[0][i] + query(a[i], '@');
            //printf("%d ", dp[0][i+1]);
        }
        //printf("\n");
        for (int i = 0; i < b.size(); i++) {
            dp[i+1][0] = dp[i][0] + query(b[i], '@');
            for (int j = 0;  j < a.size(); j++) {
                dp[i+1][j+1] = max(query('@', a[j]) + dp[i+1][j], query('@', b[i]) + dp[i][j+1]);
                //cout << query('@', a[j]) << ' ' << query('@', b[i]);
                dp[i+1][j+1] = max(dp[i+1][j+1], query(a[j], b[i]) + dp[i][j]);
                //printf("%d ", dp[i+1][j+1]);
            }
            //printf("\n");
        }
        cout << dp[b.size()][a.size()] << endl;
    }
    return 0;
}
```