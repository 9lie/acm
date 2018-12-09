## 题目：HDU - 2526
地址：https://vjudge.net/problem/HDU-2526
---
写完这道题发现比想象中要简单得多

而且通过前面一些题的训练，现在面对这种文字处理的题也不是很慌了

8个音符可以对应**二进制**的0到7，简化判断的过程

面对未知长度的字符串时，用`vector`储存

要注意的是，对于`vector`数组的长度要用`size()`而不是`length()`

如果要清空一个`vector`可以用`a = vector<int>()`

并且还学会了一个技巧

在使用`scanf()`时，可以用类似`scanf("%d\n", &n)`来避免接下来取字符时会取到`\n`

并且，在输出音符的时候，可以只用两个数组轮流储存

要做到这一点，可以在循环前确定好当前数组和下一个数组，并在每次循环结束后交换两个变量
## 代码：
```cpp
#include <bits/stdc++.h>
using namespace std;

int b[8];

int findn(int i, vector<int> &arr) {
    int n = 0;
    if (i != 0 && arr[i - 1] == 1) n += 4;
    if (arr[i] == 1) n += 2;
    if (i + 1 != arr.size() && arr[i + 1] == 1) n += 1;
    return b[n];
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        vector<int> a[2];
        int m;
        scanf("%d", &m);
        for (int j = 0; j < 8; j++) {
            char ts[4];
            int ti, tn = 0;
            scanf("%s %d\n", ts, &ti);
            if (ts[0] == '1') tn += 4;
            if (ts[1] == '1') tn += 2;
            if (ts[2] == '1') tn += 1;
            b[tn] = ti;
        }
        char c;
        while ((~scanf("%c", &c)) && c != '\n') {
            a[0].push_back(c - '0');
            printf("%c", c);
        }
        printf("\n");
        int cur = 0, next = 1;
        for (int j = 0; j < m - 1; j++) {
            a[next] = vector<int>();
            for (int k = 0; k < a[cur].size(); k++) {
                int f = findn(k, a[cur]);
                a[next].push_back(f);
                printf("%d", f);
            }
            printf("\n");
            swap(cur, next);
        }
    }
    return 0;
}
```