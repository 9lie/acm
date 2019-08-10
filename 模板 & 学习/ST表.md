## ST表

```cpp
void build_st(int n) {
  for (int i = 1; (1 << i) < n; i++)
    for (int j = 0; j <= n - (1 << i); j++)
      st[i][j] = max(st[i-1][j], st[i-1][j + (1 << (i-1))]);
}
// 0-index
int query(int l, int r) {
  int k = __lg(r - l + 1);
  return max(st[k][l], st[k][r - (1<<k) + 1]);
}
```

