## 数位dp

```cpp
int dp[10][10][2], num[10];
int dfs(int pos, int sta, bool lim, bool lead) {
  if (pos < 0) return 1;
  if (!lim && dp[pos][sta][lead] >= 0) return dp[pos][sta][lead];

  int cnt = 0, maxx = lim ? num[pos] : 9;
  for (int i = 0; i <= maxx; i++) {
    if (!lead && abs(sta - i) < 2) continue;
    cnt += dfs(pos - 1, i, lim && i == maxx, lead && i == 0);
  }
  return lim ? cnt : dp[pos][sta][lead] = cnt;
}

int solve(int n) {
  int len = 0;
  while (n) num[len++] = n%10, n /= 10;
  return dfs(len - 1, 0, 1, 1);
}
```

上面是bzoj1026，相邻两个数必须差大于或等于2

数位dp有几种问法

- 任意一位必须符合条件
- 任意相邻两位必须符合条件
- 存在一位符合条件
- 存在相邻两位符合条件
- 整个串符合条件

一般“存在”可以转化为“任意”的反面来求，运用补集思想

直接求法，hdu-3555，统计包含49的数的个数

```cpp
ll dp[20][2], num[20], n, z[20];
ll dfs(int pos, bool sta, bool lim) {
  if (pos < 0) return 0;
  if (!lim && dp[pos][sta] >= 0) return dp[pos][sta];

  ll cnt = 0, maxx = lim ? num[pos] : 9;
  for (int i = 0; i <= maxx; i++) {
    if (sta && i == 9) cnt += lim ? n % z[pos] + 1: z[pos]; // kk
    else cnt += dfs(pos - 1, i == 4 , lim && i == maxx);
  }
  return lim ? cnt : dp[pos][sta] = cnt;
}
z[0] = 1;
for (int i = 1; i < 20; i++) z[i] = z[i-1] * 10;
```

更一般的写法

```cpp
ll dfs(int pos, int sta, bool lim) {
  if (pos < 0) return sta == 2 ? 1 : 0;
  if (!lim && dp[pos][sta] >= 0) return dp[pos][sta];

  ll cnt = 0, maxx = lim ? num[pos] : 9, nsta;
  for (int i = 0; i <= maxx; i++) {
    if (sta == 1 && i == 9 || sta == 2) nsta = 2;
    else nsta = i == 4;
    cnt += dfs(pos - 1, nsta, lim && i == maxx);
  }
  return lim ? cnt : dp[pos][sta] = cnt;
}
```

一般考虑两位之间的关系时，需要考虑前导零

不要忘记把 `dp` 数组初始化为 -1

hdu-3652 需要考虑整个数字的情况

```cpp
int dp[10][4][14], num[10], m[10][10];
int dfs(int pos, int sta, bool lim, int mod) {
  if (pos < 0) return mod == 0 && sta == 2 ? 1 : 0;
  if (!lim && dp[pos][sta][mod] >= 0) return dp[pos][sta][mod];

  int cnt = 0, maxx = lim ? num[pos] : 9, nsta;
  for (int i = 0; i <= maxx; i++) {
    if (sta == 1 && i == 3 || sta == 2) nsta = 2;
    else nsta = i == 1;
    cnt += dfs(pos - 1, nsta, lim && i == maxx, (mod + m[pos][i]) % 13);
  }
  return lim ? cnt : dp[pos][sta][mod] = cnt;
}
```

大概和“存在”那种情况差不多，把取模一直往后传，`pos == -1` 的时候判断一下就可以了