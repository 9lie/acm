# cantor expansion-康托展开

## 介绍

对于一个长度为n排列，记X为比这个排列小的排列的个数

```
X = a[n](n-1)! + a[n - 1](n-2)! + ... + a[1]0!
```

a[n] 表示在第n位右边比第n位小的数字的个数，最左为第1位

a[n](n-1)! 表示如果左边的数字都相等，剩下的数字的全排列中比当前小的个数

## 代码

```cpp
long long fac[10];
void init_fac(int n) {
    fac[0] = 1;
    for (int i = 1; i <= n; i++)
        fac[i] = fac[i - 1] * i;
}
int cantor(int *a, int n) {
    int x = 0;
    for (int i = 0; i < n; i++) {
        int smaller = 0;
        for (int j = i + 1; j < n; j++) {
            if (a[j] < a[i]) smaller++;
        }
        x += fac[n - i - 1] * smaller;
    }
    return x;
}
```

## hint

既然都有**map**了，为什么还学这个