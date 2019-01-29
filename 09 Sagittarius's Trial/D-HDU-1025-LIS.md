# Constructing Roads In JGShining's Kingdom

地址：https://cn.vjudge.net/problem/HDU-1025

# 思路

其实有前面的那一道题的提示应该可以猜出来这道题也是LIS

不过这一道题如果用前面的O(n^2)的解法会超时

有一种O(nlogn)的贪心+二分的解法

每次取一个数a[i]，如果大于最后的数，插入d[]到最后

否则二分查找,d[j-1] < a[i] <= d[j]，用a[i]替换d[j]

这个替换不会改变原先的LIS的长度，并且给后面的字母插入提高了可能性

# 代码

```cpp
#include <bits/stdc++.h>
#define mod(x, m) ((x) % (m) + (m)) % (m)
#define endl '\n'
using namespace std;
/*struct P{
    int x, y;
    vector<int> c;
    bool operator < (const P &a) const {
        return x < a.x && y < a.y;
    }
    bool operator > (const P &a) const {
        return x > a.x && y > a.y;
    }
    bool operator == (P &a) {
        return x > a.x && y < a.y || x < a.x && y > a.y;
    }
}c[500005], d[500005];*/
int c[500005], d[500005];
int main() {
    int n, ca = 1, x, y;
    while (~scanf("%d", &n)) {
        for (int i = 0; i < n; i++) {
            scanf("%d%d", &x, &y);
            c[x] = y;
        }
        int len = 1;
        d[1] = c[1];
        for (int i = 1; i <= n; i++) {
            //cout << (c[i] > d[len-1]) << endl;
            if (c[i] > d[len]) d[++len] = c[i];
            else *upper_bound(d+1, d+len+1, c[i]) = c[i];
        }
        /*for (int i = 0; i < len; i++) {
            printf("%d ", c[i].x);
        }*/
        //cout << len << endl;
        printf("Case %d:\nMy king, at most %d road%s can be built.\n\n", ca++, len, (len == 1 ? "" : "s"));
    }
    return 0;
}
/*
理解错了
虽然这样也是求LIS，但是需要的是x从小到大排列，输入的数据不一定是从小到大
其实可以不用结构储存的，可以就用数组
*/
```