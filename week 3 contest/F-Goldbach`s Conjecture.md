# F-Goldbach`s Conjecture

来源：LightOJ - 1259

地址：https://cn.vjudge.net/problem/LightOJ-1259

# 思路

素数筛，本题我用的是线性筛，正好那几天背了下来，然而很容易忘记原理

```cpp
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
#define endl '\n'

int solve();

int main()
{
    solve();
	return 0;
}
//********************************************************
const int N = 1e7 + 1;
bool is_prime[N];
bool used[N];
vector<int> prime;

void sieve() {
    for (int i = 2; i < N; i++) is_prime[i] = true;
    for (int i = 2; i < N; i++) {
        if (is_prime[i]) prime.emplace_back(i);
        for (int j = 0; j < prime.size() && i * prime[j] < N; j++) {
            is_prime[prime[j] * i] = false;
            if (i % prime[j] == 0) break;
        }
    }
}

int solve() {
    int n;
    scanf("%d", &n);
    sieve();
    for (int j = 1; j <= n; j++) {
        int t, ans = 0;
        scanf("%d", &t);
        memset(used, false, sizeof(used));
        for (int i = 0; prime[i] < t && !used[prime[i]]; i++) {
            if (is_prime[t - prime[i]]) ans++;
            used[t - prime[i]] = true;
        }
        printf("Case %d: %d\n", j, ans);
    }
    return 0;
}
```